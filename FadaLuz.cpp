#include "FadaLuz.h"
#include "Fada.h"

#include <iostream>
#include <cmath>
#include <iostream>

using std::cout;

FadaLuz::FadaLuz():Fada(){}

FadaLuz::FadaLuz(const string &name,const string &estiloLuta, const int idade, const int numPoderes, const string &habilidades):Fada(name,estiloLuta,idade, numPoderes){
    this->habilidades = habilidades;
}

FadaLuz::FadaLuz(const FadaLuz &other, const string &name,const string &estiloLuta, const int idade, const int numPoderes,const string &tipoTemperaemnto):Fada(name,estiloLuta,idade,numPoderes){
   this->habilidades = other.habilidades;
}
FadaLuz::~FadaLuz(){
       
}

string FadaLuz::getHabilidade() const{
    return habilidades;
}
int FadaLuz::getRapidezLuz()const{
    return rapidezLuz;
}
int FadaLuz::getDirecao()const{
    return direcao;
}
void FadaLuz::setHabilidade(const string &habilidades){
    this->habilidades = habilidades;
}
void  FadaLuz::setRapidezLuz(int rapidezLuz){
    if(rapidezLuz < 0){
        rapidezLuz = 0;
        return;
    }
    this->rapidezLuz = rapidezLuz;
}
void FadaLuz::setDirecao(int direcao){
    if(direcao < 0){
        direcao = 0;
        return;
    }
    this->direcao = direcao;
}
void FadaLuz::obstruirVisao(){
    if(verificaIdade(getIdade())){
        cout << "Está apto a cegar outra fada" << '\n';
        transformacao();
    }
}
int FadaLuz::calculaVelocidadeLuz(){
    return rapidezLuz * direcao;
}
ostream &operator<<(ostream &out, const  FadaLuz &fadaLuz){

    out << static_cast<Fada>(fadaLuz);
    out <<"Tipo de Habilidade" << '\n';
    out << fadaLuz.habilidades << '\n';
    out <<'\n';
    
    out <<'\n';
    return out;
}

void FadaLuz::operator=(const FadaLuz &fadaLuz){
   this->habilidades = fadaLuz.habilidades;
}
bool FadaLuz::operator==(const FadaLuz &fadaLuz)const{
    if(static_cast< Fada  >(* this ) == static_cast < Fada >( fadaLuz )){
        return false;
    }
    if(rapidezLuz == 0){
        cout << "Necessita de mais velocidade" << '\n';
        return true;
    }
    return false;
}
bool FadaLuz::operator!=(const FadaLuz &fadaLuz)const{
    return !(*this == fadaLuz);
}

void FadaLuz::operator!(){
    if(!rapidezLuz > 0){
        cout <<"Nao eh possivel alcancar os olhos do inimigo"<< '\n';
      
    }
}