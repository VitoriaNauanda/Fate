#include "Especialista.h"
#include <iostream>
#include <cmath>
using std::cout;

int Especialista::numArmarioAlfea = 0;
int Especialista::getNumArmarioAlfea( )
{ 
    return numArmarioAlfea; 
}
Especialista::Especialista():numArmasCadastradas(0){

}

Especialista::Especialista(int numArmas):numArmasCadastradas(0){
   nextEntrieInAtaque = 0; 
   ataquesSize = 0;
   numAtaque++;
   setNumAtaque(numAtaque);
   setNumArmas( numArmas ); 
   myEspecialista = new Fate();
   cout<<"Vamos para Alfea"<<'\n'; 
}
Especialista::Especialista(const Especialista &other):numArmasCadastradas(0){
    numArmas++;
    numAtaque++;
    nextEntrieInAtaque = 0;
    ataquesSize = 0;
    setNumArmas(other.numArmas); 
    this->armas.resize( other.armas.size() );
    for( auto i = 0; i < other.armas.size( ); i++ )
        this->armas[ i ] = other.armas[ i ];    
    
    this->nextEntrieInAtaque = other.nextEntrieInAtaque;
    this->ataquesPtr = new int[this->ataquesSize];
    for(int i = 0; i < nextEntrieInAtaque; i++)
        this -> ataquesPtr[i] = other.ataquesPtr[i];  
}
Especialista::~Especialista(){
    numArmas--;
    numAtaque--;
    delete[] ataquesPtr;
    for( auto i = 0; i < armas.size( ); i++ )
        delete this->armas[ i ]; 
    this -> armas.clear();
    delete myEspecialista;
    cout<<"Saindo de Alfea"<<'\n';
}

void Especialista::setNumArmas(int numArmas){
    if (Especialista::numArmarioAlfea > 0 )
        Especialista::numArmarioAlfea -= this->numArmas;
        
    if ( numArmas <= 0 )
    {
        numArmas = 0;
        return;
    }    
   
    this->numArmas = numArmas;
    Especialista::numArmarioAlfea += this->numArmas;
}
void Especialista::setNumAtaque(int numAtaque) {
    if(numAtaque < 0){
        numAtaque =0;
        return;
    }
    this ->numAtaque = numAtaque;
    registerAtaques(numAtaque);
}
int Especialista:: getNumArmas()const{
    return this->numArmas;
}
int Especialista::getNumAtaque( ) const {
    return numAtaque;
}

void Especialista::cadastrarArmasEspecialista(const string &novaArma){
    if( armas.size( ) < numArmas ) 
    {
        numArmasCadastradas++;
        armas.push_back( new string(novaArma) );        
        return;
    }

    cout << "Nao eh possivel cadastrar " << novaArma << '.' << " Armário cheio.\n";

}
void Especialista::printListaArmas( ) const
{
    for( int i = 0; i < armas.size( ); i++ )
        cout << armas[i] << '\t' << *armas[ i ] << '\n';
}
void Especialista::registerAtaques( int numAtaque){
    cout << "\nRegistrando Ataques de Alfea" <<"\n";

     if ( nextEntrieInAtaque < ataquesSize ) {
        ataquesPtr[ nextEntrieInAtaque++ ] = numAtaque;
        return;
    }

    if (ataquesSize == 0){
        ataquesSize = 1;
        ataquesPtr = new int[ ataquesSize ];
        ataquesPtr[nextEntrieInAtaque++] = numAtaque;
        return;
    }

    alocarAtaque( numAtaque );

}

void Especialista::alocarAtaque( int numAtaque ) {
    
    int *ataquesTemp = new int[ ataquesSize ];
    for ( int i = 0; i < nextEntrieInAtaque; i++ )
        ataquesPtr[ i ] = ataquesTemp[ i ];

    delete [] ataquesPtr;

    //Aumenta a memória em 50%
    ataquesSize += int( ceil( ataquesSize * 0.5 ) );
    ataquesPtr = new int[ ataquesSize ]; 
    for ( int i = 0; i < nextEntrieInAtaque; i++ )
        ataquesPtr[ i ] = ataquesTemp[ i ];
    ataquesPtr[ nextEntrieInAtaque++ ] = (numAtaque);

    delete [] ataquesTemp;     
}

void Especialista::printAtaques( ) const {

    cout << "\nAtaques de Alfea: "<<'\n';
    for( int i = 0; i < nextEntrieInAtaque; i++ )
        cout << ataquesPtr[i] << "\n";

}
void Especialista::verificaEstado()  {
    if(nextEntrieInAtaque < 1){
        cout<< "Reforçar o treinamento"<<'\n';
    }
    if(numArmas > 0 and nextEntrieInAtaque >=1){
        cout<<"Rumo ao ataque"<<'\n';
    }
}