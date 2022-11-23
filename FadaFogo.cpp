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

void FadaFogo::setTipoTemperamento(const string &tipoTemperamento){
    this->tipoTemperamento = tipoTemperamento;
}
void FadaFogo::validaProtecao(){
    if(verificaIdade(getIdade())){
        cout << "Está apto a usar poderes e proteger a escola" << '\n';
        transformacao();
    }
}

ostream &operator<<(ostream &out, const  FadaFogo &fadaFogo){

    out << static_cast<Fada>(fadaFogo);
    out <<"Tipo de temperamento" << '\n';
    out << fadaFogo.getTipoTemperamento() << '\n';
    out <<'\n';
    
    out <<'\n';
    return out;
}

void FadaFogo::operator=(const FadaFogo &personagem){
   this->tipoTemperamento = personagem.tipoTemperamento;
}
bool FadaFogo::operator==(const FadaFogo &personagem)const{
    return true;
}
bool FadaFogo::operator!=(const FadaFogo &personagem)const{
    return !(*this == personagem);
}

void FadaFogo::operator!(){
    
}
