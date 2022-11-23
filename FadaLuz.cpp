#include "FadaLuz.h"
#include "Fada.h"
#include "Fada.cpp"
#include <iostream>
#include <cmath>
#include <iostream>

using std::cout;

FadaLuz::FadaLuz():Fada(){}

FadaLuz::FadaLuz(const string &name, const int idade, const int numPoderes, const string &habilidades):Fada(name,idade, numPoderes){
    this->habilidades = habilidades;
}

FadaLuz::FadaLuz(const FadaLuz &other, const string &name, const int idade, const int numPoderes,const string &tipoTemperaemnto):Fada(name,idade,numPoderes){
   this->habilidades = other.habilidades;
}

string FadaLuz::getHabilidade() const{
    return habilidades;
}

void FadaLuz::setHabilidade(const string &habilidades){
    this->habilidades = habilidades;
}
void FadaLuz::obstruirVisao(){
    if(verificaIdade(getIdade())){
        cout << "Está apto a cegar outra fada" << '\n';
        transformacao();
    }
}

ostream &operator<<(ostream &out, const  FadaLuz &fadaLuz){

    out << static_cast<Fada>(fadaLuz);
    out <<"Tipo de Habilidade" << '\n';
    out << fadaLuz.getHabilidade() << '\n';
    out <<'\n';
    
    out <<'\n';
    return out;
}

void FadaLuz::operator=(const FadaLuz &personagem){
   this->habilidades = personagem.habilidades;
}
bool FadaLuz::operator==(const FadaLuz &personagem)const{
    return true;
}
bool FadaLuz::operator!=(const FadaLuz &personagem)const{
    return !(*this == personagem);
}

void FadaLuz::operator!(){
    
}