

#include <iostream>
#include "Personagem.h"
using std::cout;

Personagem::Personagem():estiloLuta("Poderes"){}

Personagem::Personagem(const string &name, const string &estiloLuta, int idade){
    this->name = name;
    this ->estiloLuta = estiloLuta;
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

string Personagem::getLocalOrigem()const{
    return localOrigem;
}
string Personagem::getConteudoCarta()const{
    return conteudoCarta;
}

void Personagem:: setPessoaMagica( bool pessoaMagica = false ) {
    this->pessoaMagica = pessoaMagica;
}
void Personagem::setLocalOrigem(const string &localOrigem){
    this->localOrigem = localOrigem;
}

void Personagem::setConteudoCarta(const string &conteudoCarta){
    this->conteudoCarta = conteudoCarta;
}
bool Personagem::getPessoaMagica()const{
    return pessoaMagica;
}
bool Personagem:: isPessoaMagica( ) {
    return getPessoaMagica();
}

void Personagem :: atravessarPortal( ){
    if(this->pessoaMagica == true){
        cout << "Pode atravessar o portal" << '\n';
    }
    cout << "Não pode atravessar o portal" << '\n';
}

void Personagem :: recebeCartaConvocacao() { 
    if(this->pessoaMagica == true){
        cout << "Pode receber a carta" << '\n';
        if(conteudoCarta == "Nao"){
            cout << "Nao pode estudar em Alfea" << '\n';
        }
        cout << "Pode estudar em Alfea" << '\n';
    }
}
void Personagem :: printPersonagem(){
    cout <<"Nome personagem: "  << this->name << '\n';
    cout << "Idade personagem: " << this->idade <<'\n';
    cout << "Estilo Luta: "<<this->estiloLuta <<'\n';
    cout << "Personagem magico" << this->pessoaMagica <<'\n';
    cout << "Local origem: " << this->localOrigem << '\n';
    cout << "Conteudo carta: " << this->conteudoCarta << '\n';
}

/*
ostream &operator<<(ostream &out, const  Personagem &personagem){
    out <<"Nome personagem: " << '\n';
    out << personagem.name << '\n';
    out << "Idade personagem: " << '\n';
    out << personagem.idade <<'\n';
    out << "Estilo Luta: "<< '\n';
    out << personagem.estiloLuta <<'\n';
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
*/