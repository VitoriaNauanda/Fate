

#include <iostream>
#include "Personagem.h"
using std::cout;

Personagem::Personagem():estiloLuta("Poderes"){}

Personagem::Personagem(const string &name, int idade){
    this->name = name;
    this->idade = idade;
   
}

Personagem::~Personagem(){

}

Personagem::Personagem(const Personagem &outro){
    this->name = outro.name;
    this->idade = outro.idade;
   
}
string Personagem::getName() const{
    return name;
}

int Personagem::getIdade() const{
    return idade;
}
string Personagem::getEstiloLuta()const{
    return estiloLuta;
}

void Personagem::setName(const string &name){
    this -> name = name;
}
void Personagem::setIdade(int idade){
    if(idade < 0){
        idade = 0;
        return ;
    }
    this -> idade = idade;
}
void Personagem::setEstiloLuta(const string &estiloLuta){
    this -> estiloLuta = estiloLuta;
}
bool Personagem:: verificaIdade( int idade){
    if(idade >= 16){
        return true;
    }
    return false;
}
void Personagem::modoAtaque( const string &modoAtaque){
    if(modoAtaque == estiloLuta){
        cout << "É uma fada" << '\n';
    }
     cout << "É um especialista" << '\n';
}
ostream &operator<<(ostream &out, const  Personagem &personagem){
    out <<"Nome personagem: " << '\n';
    out << personagem.name << '\n';
    out << "Idade personagem: " << '\n';
    out << personagem.idade <<'\n';
    out << "Estilo Luta: "<< '\n';
    out << personagem.estiloLuta <<'n';
    return out;
}

void Personagem::operator=(const Personagem &personagem){
    this -> name = personagem.name;
    this -> idade = personagem.idade;
}
bool Personagem::operator==(const Personagem &personagem)const{
    if(idade == 0){
        cout << "Eh necessario esperar mais" << '\n';
        return true;
    }
    return false;
}
bool Personagem::operator!=(const Personagem &personagem)const{
    return !(*this == personagem);
}

void Personagem::operator!(){
    if(estiloLuta == ""){
        cout << "É preciso adicionar um estilo de luta" << '\n';
    }
}
