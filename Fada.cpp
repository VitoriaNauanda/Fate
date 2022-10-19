#include "Fada.h"

#include <cmath>
#include <iostream>
using std::cout;


Fada::Fada():numPoderesCadastrados(0){

}
Fada::Fada(int numPoderes):numPoderesCadastrados(0){
    setNumPoderes( numPoderes ); 
    nextEntrieInFada = 0;
    fadaSize = 0;
    numFada++;
    setNumFada(numFada);
    myFate = new Fate();
    cout<<"Vamos para Alfea"<<'\n';
}
Fada::Fada(const Fada &other):numPoderesCadastrados(0){
    numPoderes++;
    numFada++;
    nextEntrieInFada=0;
    fadaSize = 0;
    setNumPoderes(other.numPoderes); 
    myFate = new Fate();
    this->poderes.resize( other.poderes.size() );
    for( auto i = 0; i < other.poderes.size( ); i++ )
        this->poderes[ i ] = other.poderes[ i ];    
    
    this->nextEntrieInFada = other.nextEntrieInFada;
    this->fadaPtr = new int[this->fadaSize];
    for(int i = 0; i < nextEntrieInFada; i++)
        this -> fadaPtr[i] = other.fadaPtr[i]; 
}
Fada::~Fada(){
    numPoderes--;
    numFada--;

    delete[] fadaPtr;
    for( auto i = 0; i < poderes.size( ); i++ )
        delete this->poderes[ i ]; 
     this -> poderes.clear();
    cout<<"Saindo de Alfea"<<'\n';
    delete myFate;
    
}
int Fada::getNumPoderes()const{
    return numPoderes;
}
int Fada::getNumFada( ) const {
    return numFada;
}
void Fada::setNumPoderes(int numPoderes){
    if(numPoderes > 0){
        this->numPoderes = numPoderes;
    }
    this->numPoderesCadastrados = 0;
}
void Fada::setNumFada(int numFada) {
    if(numFada < 0){
        numFada =0;
        return;
    }
    this ->numFada = numFada;
    registerFadas(numFada);
}
void Fada::cadastrarPoderesFada(const string &novoPoder){
    if( poderes.size( ) < numPoderes ) 
    {
        numPoderesCadastrados++;
        poderes.push_back( new string(novoPoder) );        
        return;
    }

    cout << "Nao eh possivel cadastrar " << novoPoder << '\n';

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

void Fada::alocarFadas( int numFada ) {
    
    int *fadasTemp = new int[ fadaSize ];
    for ( int i = 0; i < nextEntrieInFada; i++ )
        fadaPtr[ i ] = fadasTemp[ i ];

    delete [] fadaPtr;

    //Aumenta a memória em 50%
    fadaSize += int( ceil( fadaSize * 0.5 ) );
    fadaPtr = new int[ fadaSize ]; 
    for ( int i = 0; i < nextEntrieInFada; i++ )
        fadaPtr[ i ] = fadasTemp[ i ];
    fadaPtr[ nextEntrieInFada++ ] = (numFada);

    delete [] fadasTemp;     
}

void Fada::printFadas( ) const {

    cout << "\nFada de Fate: "<<'\n';
    for( int i = 0; i < nextEntrieInFada; i++ )
        cout << fadaPtr[i] << "\n";

}
void Fada::printListaPoderes( ) const
{
    for( int i = 0; i < poderes.size( ); i++ )
        cout << poderes[i] << '\t' << *poderes[ i ] << '\n';
}
void Fada::transformacao(){
    if(nextEntrieInFada>=1){
        if(numPoderes>=1){
            cout<<"Poderá se transformar" <<'\n';
        }
        cout <<"Estudar mais as técnicas e história de transformação"<<'\n';
    }
    cout <<"Ainda não é possível se transformar e nem usar poderes"<<'\n';
}

void Fada::printDadosBruxoSangue(const BruxoSangue &bs){
   cout << "Nome: " << bs.nome << '\n';
   cout << "tipo Poder: " << bs.tipoPoder << '\n'; 
   cout << "forca Ataque: "  << bs.forcaAtaque << '\n';
}
void Fada:: verificarForcaBruxoSangue(const BruxoSangue &bs){
    if(bs.forcaAtaque >= 50){
       cout<<"Reforcar barreira de protecao"<<'\n';
       printDadosBruxoSangue(bs);
    }
}
