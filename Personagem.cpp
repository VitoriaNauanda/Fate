

#include <iostream>
#include "Personagem.h"
using std::cout;

Personagem::Personagem(){}

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

bool Personagem:: verificaIdade( int idade){
    if(idade >= 16){
        return true;
    }
    return false;
 }
ostream &operator<<(ostream &out, const  Personagem &personagem){
    out <<"Nome personagem: " << '\n';
    out << personagem.getName() << '\n';
    out << "Idade personagem: " << '\n';
    out << personagem.getIdade() <<'\n';
   
    return out;
}

void Personagem::operator=(const Personagem &personagem){
    this -> name = personagem.name;
    this -> idade = personagem.idade;
}
bool Personagem::operator==(const Personagem &personagem)const{
    return true;
}
bool Personagem::operator!=(const Personagem &personagem)const{
    return !(*this == personagem);
}

void Personagem::operator!(){
    
}
