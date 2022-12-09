#include "FadaFogo.h"
#include "Fada.h"
#include "Fada.cpp"
#include <iostream>
#include <cmath>
#include <iostream>

using std::cout;

FadaFogo::FadaFogo():Fada(){}

FadaFogo::FadaFogo(const string &name, const int idade, const int numPoderes, const string &tipoTemperamento):Fada(name,idade, numPoderes){
    this->tipoTemperamento = tipoTemperamento;
}

FadaFogo::FadaFogo(const FadaFogo &other, const string &name, const int idade, const int numPoderes,const string &tipoTemperaemnto):Fada(name,idade,numPoderes){
   this->tipoTemperamento = other.tipoTemperamento;
}

string FadaFogo::getTipoTemperamento() const{
    return tipoTemperamento;
}
int FadaFogo::getNivelFogo()const{
    return nivelFogo;
}

void FadaFogo::setTipoTemperamento(const string &tipoTemperamento){
    this->tipoTemperamento = tipoTemperamento;
}
void FadaFogo::setNivelFogo(int nivelFogo){
    if(nivelFogo < 0){
        nivelFogo = 0;
        return ;
    }
    this -> nivelFogo = nivelFogo;
}
void FadaFogo::validaProtecao(){
    if(verificaIdade(getIdade())){
        cout << "Está apto a usar poderes e proteger a escola" << '\n';
        transformacao();
    }
}
void FadaFogo::controlaPortal(){
    if(!nivelFogo){
        cout << "Nao eh possivel abrir um portal" << '\n';
    }
     cout << "Eh possivel abrir um portal" << '\n';
}
ostream &operator<<(ostream &out, const  FadaFogo &fadaFogo){

    out << static_cast<Fada>(fadaFogo);
    out <<"Tipo de temperamento" << '\n';
    out << fadaFogo.tipoTemperamento << '\n';
    out <<'\n';
    out <<"Nivel Fogo" << '\n';
    out << fadaFogo.nivelFogo << '\n';
    out <<'\n';
    return out;
}

void FadaFogo::operator=(const FadaFogo &personagem){
   this->tipoTemperamento = personagem.tipoTemperamento;
}
bool FadaFogo::operator==(const FadaFogo &personagem)const{    
    if(static_cast< Fada  >(* this ) == static_cast < Fada >( personagem)){
        return false;
    }
    if(nivelFogo == 0){
        cout << "Precisamos aumentar o nivel de fogos" << '\n';
        return true;
    }
    return false;
}
bool FadaFogo::operator!=(const FadaFogo &personagem)const{
    return !(*this == personagem);
}

void FadaFogo::operator!(){
    if(!nivelFogo > 0){
        cout << "Nao eh possivel abrir portais "<< '\n';
    }
}