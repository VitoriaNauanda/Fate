#include "Fada.h"
#include "Escola.h"
#include "Personagem.h"

#include <cmath>
#include <iostream>
using std::cout;

int Fada::numPoderesFada = 0;
int Fada::getNumPoderesFada( )
{ 
    return numPoderesFada; 
}
Fada::Fada():numPoderesCadastrados(0), FORCA(50.0), Personagem(){
    nextEntrieInFada = 0;
    fadaSize = 0;
    numFada++;
}
Fada ::Fada(int numPoderes):numPoderesCadastrados(0), FORCA(50.0){
    this -> numPoderes = numPoderes;
    nextEntrieInFada = 0;
    fadaSize = 0;
    numFada++;
}

Fada::Fada(const string &name, const string &estiloLuta,const int idade, int numPoderes):numPoderesCadastrados(0), FORCA(50.0), Personagem(name,estiloLuta,idade){
    
    setNumPoderes( numPoderes ); 
    nextEntrieInFada = 0;
    fadaSize = 0;
    numFada++;
    setNumFada(numFada);
  
    cout<<"Vamos para Alfea"<<'\n';
}
Fada::Fada(const Fada &other, const string &name, const string &estiloLuta, const int idade, int numPoderes):numPoderesCadastrados(0), FORCA(50.0), Personagem(name,estiloLuta,idade){
    numPoderes++;
    numFada++;
    
    setNumPoderes(other.numPoderes); 
    
    this->poderes.resize( other.poderes.size() );
    for( auto i = 0; i < other.poderes.size( ); i++ )
        this->poderes[ i ] = other.poderes[ i ];    
    
    this->fadaSize = other.fadaSize;
    this->nextEntrieInFada = other.nextEntrieInFada;
    this->fadaPtr = new int[this->fadaSize];
    for(int i = 0; i < nextEntrieInFada; i++)
        this -> fadaPtr[i] = other.fadaPtr[i]; 
}
Fada::~Fada(){
    numPoderes--;
    numFada--;

    delete [] fadaPtr;
    for( auto i = 0; i < poderes.size( ); i++ )
        delete this->poderes[ i ]; 
    this->poderes.clear();
    
    cout<<"Saindo de Alfea"<<'\n';
    
}
int Fada::getNumPoderes()const{
    return numPoderes;
}
int Fada::getNumFada( ) const {
    return numFada;
}

string Fada::getNomePoder() const{
    return nomePoder;
}
void Fada::setNumPoderes(int numPoderes){
    if(Fada::numPoderesFada > 0)
        Fada::numPoderesFada -= this->numPoderes;
    
    if ( numPoderes <= 0 )
    {
        numPoderes = 0;
        return;
    }    
   
    this->numPoderes = numPoderes;
    Fada::numPoderesFada += this->numPoderes;
}
void Fada::setNumFada(int numFada) {
    if(numFada < 0){
        numFada =0;
        return;
    }
    this ->numFada = numFada;
    registerFadas(numFada);
}

void Fada::setNomePoder(const string &nomePoder){
    this -> nomePoder = nomePoder;
}
void Fada::cadastrarPoderesFada(const string &novoPoder){
    
    numPoderesCadastrados++;
    poderes.push_back( new string(novoPoder) );        
    return;
    

    

}
void Fada::registerFadas( int numFada){
    cout << "\nRegistrando Fadas de Alfea" <<"\n";

     if ( nextEntrieInFada < fadaSize ) {
        fadaPtr[ nextEntrieInFada++ ] = numFada;
        return;
    }

    if (fadaSize == 0){
        fadaSize = 1;
        fadaPtr = new int[ fadaSize ];
        fadaPtr[nextEntrieInFada++] = numFada;
        return;
    }

    alocarFadas( numFada );

}

void Fada::alocarFadas( int newFada ) {
    
    int *fadasTemp = new int[ fadaSize ];
    for ( int i = 0; i < nextEntrieInFada; i++ )
        fadasTemp[ i ] = fadaPtr[ i ];

    delete [] fadaPtr;

    //Aumenta a memória em 50%
    fadaSize += int( ceil( fadaSize * 0.5 ) );
    fadaPtr = new int[ fadaSize ]; 
    for ( int i = 0; i < nextEntrieInFada; i++ )
        fadaPtr[ i ] = fadasTemp[ i ];
    fadaPtr[ nextEntrieInFada++ ] = (newFada);

    delete [] fadasTemp;     
}

void Fada::transformacao(){
    
    if(nextEntrieInFada>=1){
        if(numPoderes!=0){
            cout<<"Pode se transformar" <<'\n';
        }
        cout <<"Estudar mais as tecnicas e historia de transformacao"<<'\n';
       
    }
    cout <<"Ainda nao eh possivel se transformar e nem usar poderes"<<'\n';
}

void Fada::printDadosBruxoSangue(BruxoSangue bs){
   cout << "Nome: " << bs.nome << '\n';
   cout << "Tipo Poder: " << bs.tipoPoder << '\n'; 
   cout << "Forca Ataque: "  << bs.forcaAtaque << '\n';
}
void Fada:: verificarForcaBruxoSangue(BruxoSangue bs){
    if(bs.forcaAtaque >= FORCA){
       cout<<"Reforcar barreira de protecao"<<'\n';
       printDadosBruxoSangue(bs);
    }
}

void Fada::mensagemAlfea(){
    if(this->verificaIdade(this->getIdade()))
        cout << "Pode estudar em Alfea" << '\n';
        modoAtaque(getEstiloLuta());
}

void Fada :: atravessarPortal( ){
   if(!isPessoaMagica()){
    cout << "Nao eh possivel atravessar portal"<<'\n';
   }
   if(isPessoaMagica()){
    cout << "Eh possivel atravessar portal"<<'\n';
   }
}

void Fada :: recebeCartaConvocacao() { 
    
    if(!isPessoaMagica()){
        cout << "Nao pode receber a carta, pois nao eh uma pessoa magica" << '\n';
        cout << "Nao pode estudar em Alfea" << '\n';
    }
   if(isPessoaMagica()){
        cout << "Pode estudar em Alfea" << '\n';
   }
}

void Fada::printFada(){
    Personagem::printPersonagem();
    cout << "Minha lista de poderes eh: "<< '\n';
    for( int i = 0; i < poderes.size( ); i++ )
        cout << poderes[i] << '\t' << *poderes[ i ] << '\n';
       
    cout << "\nQuantidade de Fadas: "<<'\n';
    for( int i = 0; i < nextEntrieInFada; i++ )
        cout << fadaPtr[i] << "\n";

    cout <<'\n';
}
/*
ostream &operator<<(ostream &out, const  Fada &fada){

    //out << static_cast<Personagem>(fada);
    
    out << "Minha lista de poderes eh: "<< '\n';
    for( int i = 0; i < fada.poderes.size( ); i++ )
        out << fada.poderes[i] << '\t' << *fada.poderes[ i ] << '\n';
       
    out << "\nQuantidade de Fadas: "<<'\n';
    for( int i = 0; i < fada.nextEntrieInFada; i++ )
        out << fada.fadaPtr[i] << "\n";

    out <<'\n';
    
    out <<'\n';
    return out;
}

 bool Fada::operator!=( const Fada &numPoderes) const{
    cout << "   Operador de != Fada" << '\n';
    if(numPoderes != 0)
        return true;
    return false;
 }
 bool Fada::operator==( const Fada &numPoderes )const{
   
    if(static_cast< Personagem  >(* this ) == static_cast < Personagem >( numPoderes)){
        return false;
    }
   
    if(numPoderes == 0){
        cout <<"Precisamos de mais poderes"<<'\n';
        return true;
    }
    return false;
 }
 bool Fada:: operator!() const{
    if(!numFada > 0){
        cout << "Alfea necessita de fadas! " << '\n';
        return false;
    }
    return true;
 } 

void  Fada::operator=( const Fada & other){
 
    setNumPoderes(other.numPoderes); 
    
    this->poderes.resize( other.poderes.size() );
    for( auto i = 0; i < other.poderes.size( ); i++ )
        this->poderes[ i ] = other.poderes[ i ];    
    
    this->nextEntrieInFada = other.nextEntrieInFada;
    this->fadaPtr = new int[this->fadaSize];
    this->fadaSize = other.fadaSize;
    for(int i = 0; i < nextEntrieInFada; i++)
        this -> fadaPtr[i] = other.fadaPtr[i]; 
    
}

*/