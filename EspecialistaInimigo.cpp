#include "EspecialistaInimigo.h"

#include "Especialista.h"
#include <iostream>
using std::cout;

#include <string>
using std::string;

EspecialistaInimigo::EspecialistaInimigo():Especialista(){

}

EspecialistaInimigo::EspecialistaInimigo(const string &name, const string &estiloLuta, const int idade,int numArmas, const string &motivacao, int nivelInteligencia, bool possuiDisturbio):Especialista(name,estiloLuta,idade,numArmas){
    this->motivacao = motivacao;
    this->nivelInteligencia = nivelInteligencia;
}

EspecialistaInimigo::EspecialistaInimigo(const EspecialistaInimigo &otherInimiga, const string &name, const string &estiloLuta, const int idade,int numArmas, const string &motivacao, int nivelInteligencia, bool possuiDisturbio):Especialista(name,estiloLuta,idade,numArmas){
    this->motivacao = otherInimiga.motivacao;
    this->nivelInteligencia = otherInimiga.nivelInteligencia;
}

EspecialistaInimigo::~EspecialistaInimigo(){

}

string EspecialistaInimigo::getMotivacao()const{
    return motivacao;
}
bool EspecialistaInimigo::getCarteiraVeiculo()const{
    return carteiraVeiculo;
}
int EspecialistaInimigo::getNivelInteligencia()const{
    return nivelInteligencia;
}
void EspecialistaInimigo::setCarteiraVeiculo(bool carteiraVeiculo){
    this->carteiraVeiculo = carteiraVeiculo;
}
void EspecialistaInimigo::setMotivacao(const string &motivacao){
    this->motivacao = motivacao;
}
void EspecialistaInimigo::setNivelInteligencia(int nivelInteligencia){
    if(nivelInteligencia < 0){
        nivelInteligencia = 0;
        return;
    }
    this->nivelInteligencia = nivelInteligencia;
}
void EspecialistaInimigo::setPossuiDisturbio(bool possuiDisturbio){
    this->possuiDisturbio = possuiDisturbio;
}

void EspecialistaInimigo::criarBombaNuclear(int nivelInteligencia){
    if(nivelInteligencia >= nivelInteligencia){
        cout << "Eh possivel criar uma bomba nuclear"<<'\n';
        if(numArmas > 0){
            cout << "Eh possivel vencere"<<'\n';
        }else{
            cout << "nao eh possivel vencere"<<'\n';
        }

    }
    verificaEstado();
}
void EspecialistaInimigo::pilotarVeiculo(){
    if(carteiraVeiculo==true){
        cout << "Pode pilotar aeronaves dos dois mundos "<< "\n";
    }
    cout << "Nao pode pilotar aeronaves dos dois mundos "<< "\n";
}

ostream &operator<<(ostream &out, const EspecialistaInimigo &especialistaInimigo){
    out << static_cast<Especialista>(especialistaInimigo);
    out << "Moticacao "<< especialistaInimigo.motivacao << "\n";
    out << "Nivel inteligencia "<< especialistaInimigo.nivelInteligencia << "\n";
    out << "Possui disturbio "<< especialistaInimigo.possuiDisturbio << "\n";
    out << "Carteira Veiculo "<< especialistaInimigo.carteiraVeiculo << '\n';
    out <<'\n';
    
    return out;
}
bool EspecialistaInimigo::operator!=( const EspecialistaInimigo &nivelInteligencia ) const{
    if(numArmas!=0)
        return true;
    return false;
    
}
bool EspecialistaInimigo:: operator==( const EspecialistaInimigo &nivelInteligencia )const{
    if(static_cast< Especialista  >(* this ) == static_cast < Especialista >( numArmas )){
        return false;
    }
    if(numArmas == 0){
        cout <<"Nao estamos bem"<<"\n";
        return true;
    }
    return false;
}
bool EspecialistaInimigo:: operator!() const{
    if(!numAtaque >0){
        cout <<"Precisamos melhorar" << '\n';
        return false;
    }
    return true;
}

void  EspecialistaInimigo::operator=( const EspecialistaInimigo &otherInimiga ){

   this->motivacao = otherInimiga.motivacao;
   this->nivelInteligencia = otherInimiga.nivelInteligencia;
}
