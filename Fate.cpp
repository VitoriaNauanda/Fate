#include "Fate.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::ostream;

const Data Fate::DATALANCAMENTOSERIE = Data( 22, 1, 2021 );
int Fate::numAlunosAlfea = 0;
int Fate::getNumAlunosAlfea( )
{ 
    return numAlunosAlfea; 
}

Fate::Fate():numAlunosCadastrados(0){
   nextEntrieInProfessores = 0; 
   professoresSize = 0;
   numProfessor++;
   setNumProfessor(numProfessor);
   cout <<"Ensina alunos"<<'\n';
}

Fate::Fate(int numAlunos, const Data &dataOut):numAlunosCadastrados(0){
    setNumAlunos( numAlunos );
    nextEntrieInProfessores = 0;
    professoresSize = 0;
    numProfessor++;
    setNumProfessor(numProfessor);
}
Fate::Fate(const Fate &other):numAlunosCadastrados(0){
    numAlunos++;
    numProfessor++;
    nextEntrieInProfessores = 0; 
    professoresSize = 0;

    setNumAlunos(other.numAlunos); 
    this->alunos.resize( other.alunos.size() );
    for( auto i = 0; i < other.alunos.size( ); i++ )
        this->alunos[ i ] = other.alunos[ i ]; 
    
    this->nextEntrieInProfessores = other.nextEntrieInProfessores;
    this->professoresPtr = new int[this->professoresSize];
    for(int i = 0; i < nextEntrieInProfessores; i++)
        this -> professoresPtr[i] = other.professoresPtr[i];   
}
Fate::~Fate(){
    numAlunos--;
    numProfessor--;
    delete[] professoresPtr;
    for( auto i = 0; i < alunos.size( ); i++ )
        delete this->alunos[ i ]; 
    this -> alunos.clear();
    cout <<"Expulsa alunos"<<'\n';
}

void Fate::setNumAlunos(int numAlunos){
    if (Fate::numAlunosAlfea > 0 )
        Fate::numAlunosAlfea -= this->numAlunos;
        
    if ( numAlunos <= 0 )
    {
        numAlunos = 0;
        return;
    }    
   
    this->numAlunos = numAlunos;
    Fate::numAlunosAlfea += this->numAlunos;
}
void Fate::setNumProfessor(int numProfessor) {
    if(numProfessor < 0){
        numProfessor =0;
        return;
    }
    this ->numProfessor = numProfessor;
    registerProfessores(numProfessor);
}
int Fate:: getNumAlunos()const{
    return this->numAlunos;
}
int Fate::getNumProfessor( ) const {
    return numProfessor;
}
void Fate::cadastrarAlunoFate(const string &novoAluno){
    if( alunos.size( ) < numAlunos ) 
    {
        numAlunosCadastrados++;
        alunos.push_back( new string(novoAluno) );        
        return;
    }

    cout << "Nao eh possivel cadastrar " << novoAluno << '.' << " Turma cheia.\n";

}
void Fate::printListaAlunos( ) const
{
    for( int i = 0; i < alunos.size( ); i++ )
        cout << alunos[i] << '\t' << *alunos[ i ] << '\n';
}

void Fate::registerProfessores( int numProfessor){
    cout << "\nRegistrando Professores de Alfea" <<"\n";

     if ( nextEntrieInProfessores < professoresSize ) {
        professoresPtr[ nextEntrieInProfessores++ ] = numProfessor;
        return;
    }

    if (professoresSize == 0){
        professoresSize = 1;
        professoresPtr = new int[ professoresSize ];
        professoresPtr[nextEntrieInProfessores++] = numProfessor;
        return;
    }

    alocarProfessores( numProfessor );

}

void Fate::alocarProfessores( int numProfessor ) {
    
    int *professoresTemp = new int[ professoresSize ];
    for ( int i = 0; i < nextEntrieInProfessores; i++ )
        professoresPtr[ i ] = professoresTemp[ i ];

    delete [] professoresPtr;

    //Aumenta a memória em 50%
    professoresSize += int( ceil( professoresSize * 0.5 ) );
    professoresPtr = new int[ professoresSize ]; 
    for ( int i = 0; i < nextEntrieInProfessores; i++ )
        professoresPtr[ i ] = professoresTemp[ i ];
    professoresPtr[ nextEntrieInProfessores++ ] = (numProfessor);

    delete [] professoresTemp;     
}

void Fate::printProfessores( ) const {

    cout << "\nProfessores de Fate: "<<'\n';
    for( int i = 0; i < nextEntrieInProfessores; i++ )
        cout << professoresPtr[i] << "\n";

}
void Fate::fortaleza(){
    if(nextEntrieInProfessores ==1){
        cout << "Alfea merece atenção da rainha!"<< '\n';
        printProfessores();
    }
}
void Fate::mostrarInfo( )
{
	cout << "A data de lancamento da serie eh: ";
	DATALANCAMENTOSERIE.print( );
	cout << '\n';
		 
}

ostream &operator<<(ostream &out, const Fate &fate){
    out<<"A data de lancamento da serie eh:"<<'\n';
    fate.DATALANCAMENTOSERIE.print();
    out <<'\n';
    out << "\nEh possivel ter mais temporadas de Fate" <<'\n';
    return out;
}
