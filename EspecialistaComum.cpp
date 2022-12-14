#include "EspecialistaComum.h"
#include "Especialista.h"
#include <iostream>
using std::cout;

#include <string>
using std::string;

EspecialistaComum::EspecialistaComum():Especialista(){

}
EspecialistaComum::EspecialistaComum(const string &name, const string &estiloLuta, const int idade,int numArmas, bool conhecerLinguagemAntiga,bool moldarMetal):Especialista(name,estiloLuta,idade,numArmas){
    this->conhecerLinguagemAntiga = conhecerLinguagemAntiga;
    this->moldarMetal = moldarMetal;
}
EspecialistaComum::EspecialistaComum(const EspecialistaComum &otherComum, const string &name, const string &estiloLuta, const int idade,int numArmas, bool conhecerLinguagemAntiga,bool moldarMetal):Especialista(name,estiloLuta,idade,numArmas){
    this->conhecerLinguagemAntiga = otherComum.conhecerLinguagemAntiga;
    this->moldarMetal = otherComum.moldarMetal;
}
EspecialistaComum::~EspecialistaComum(){

}
bool EspecialistaComum::getConhecerLinguagemAntiga()const{
    return conhecerLinguagemAntiga;
}
bool EspecialistaComum::getMoldarMetal()const{
    return moldarMetal;
}
int EspecialistaComum::getForca()const{
    return forca;
}

int EspecialistaComum::getDistancia()const{
    return distancia;
}
int EspecialistaComum::getTempo()const{
    return tempo;
}
void EspecialistaComum::setForca(int forca){
     if(forca < 0){
        forca =0;
        return;
    }
    this->forca = forca;
    
}

void EspecialistaComum::setPes(bool pes = true){
    this -> pes = pes;
}
void EspecialistaComum::setDistancia(int distancia){
    if(distancia < 0){
        distancia =0;
        return;
    }
    this->distancia = distancia;
}

void EspecialistaComum::setTempo(int tempo){
    if(tempo < 0){
        tempo =0;
        return;
    }
    this->tempo = tempo;
}

void EspecialistaComum::setConhecerLinguagemAntiga(bool conhecerLinguagemAntiga){
    this->conhecerLinguagemAntiga = conhecerLinguagemAntiga;
}

void EspecialistaComum::setMoldarMetal(bool moldarMetal){
    this->moldarMetal = moldarMetal;
}

void EspecialistaComum::criarPocoes(){
    if(conhecerLinguagemAntiga == true){
        cout << "Eh possivel criar novas pocoes"<< '\n';
    }
     cout << "  Nao eh possivel criar novas pocoes"<< '\n';
}
void EspecialistaComum::criarArmas(){
    if(moldarMetal){
        cout << "Eh possivel criar novas armas"<< '\n';
    }
    cout << "Nao eh possivel criar novas armas"<< '\n';
}

void EspecialistaComum:: lutar(){
    setForca(40);
    bool pessoaMagica = true;
    cout <<"Vamos lutar" << '\n';
    verificaEstado();
}

int EspecialistaComum:: calculaCorrida(){
    setDistancia(20);
    setTempo(5);
    return getDistancia()/getTempo();    
}


ostream &operator<<(ostream &out, const EspecialistaComum &especialistaComum){
    
    out << static_cast<Especialista>(especialistaComum);
    out << "Conhecer Linguagem Antiga" << '\n';
    out << especialistaComum.conhecerLinguagemAntiga <<'\n';
    out << "Moldar Metal" << '\n';
    out << especialistaComum.moldarMetal <<'\n';
    out << "Forca " << especialistaComum.forca << '\n';
    out << "Pes" << especialistaComum.pes << '\n';
    out << "Distancia " << especialistaComum.distancia << '\n';
    out << "Tempo " << especialistaComum.tempo << '\n';
    out <<'\n';
    return out;
}
bool EspecialistaComum::operator!=( const EspecialistaComum &tempo ) const{
    if(forca != 0)
        return true;
    return false;
    
}
bool EspecialistaComum:: operator==( const EspecialistaComum &tempo )const{
    if(static_cast< Especialista  >(* this ) == static_cast < Especialista >( forca )){
        return false;
    }
    if(forca == 0){
        cout <<"Nao estamos bem"<<"\n";
        return true;
    }
    return false;
}
bool EspecialistaComum:: operator!() const{
    if(!forca >0){
        cout <<"Precisamos melhorar" << '\n';
        return false;
    }
    return true;
}

void  EspecialistaComum::operator=( const EspecialistaComum &otherComum ){

    this->conhecerLinguagemAntiga = otherComum.conhecerLinguagemAntiga;
    this->moldarMetal = otherComum.moldarMetal;
}
