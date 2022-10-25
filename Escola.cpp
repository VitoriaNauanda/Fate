#include "Escola.h"
#include "Fada.h"

#include "Especialista.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::ostream;

const Data Escola::DATALANCAMENTOSERIE = Data( 22, 1, 2021 );
int Escola::numAlunosAlfea = 0;
int Escola::getNumAlunosAlfea( )
{ 
    return numAlunosAlfea; 
}

Escola::Escola():numAlunosCadastrados(0), fadaPoderes(), especialistaArmas(){
   nextEntrieInProfessores = 0; 
   professoresSize = 0;
   numProfessor++;
   setNumProfessor(numProfessor);
   cout <<"Ensina alunos"<<'\n';
}

Escola::Escola(int numAlunos, const Fada &fadaPoder, const Data &dataOut):numAlunosCadastrados(0), tipoAluno("fadaPoder"){
    setNumAlunos( numAlunos );
    nextEntrieInProfessores = 0;
    professoresSize = 0;
    numProfessor++;
    
    setNumProfessor(numProfessor);
   
    
}
Escola::Escola(int numAlunos, const Especialista &armas):numAlunosCadastrados(0), tipoAluno("armas"){
    setNumAlunos( numAlunos );
    nextEntrieInProfessores = 0;
    professoresSize = 0;
    numProfessor++;
    setNumProfessor(numProfessor);
    
    
}
Escola::Escola(const Escola &other):numAlunosCadastrados(0), fadaPoderes(other.fadaPoderes), especialistaArmas(other.especialistaArmas){
    numAlunos++;
    numProfessor++;
    nextEntrieInProfessores = 0; 
    professoresSize = 0;
    
    setNumAlunos(other.numAlunos); 
    
    this->alunos.resize( other.alunos.size() );
    for( auto i = 0; i < other.alunos.size( ); i++ )
        this->alunos[ i ] = other.alunos[ i ]; 
    
    this->nextEntrieInProfessores = other.nextEntrieInProfessores;
    this->professoresPtr = new string*[this->professoresSize];
    for(int i = 0; i < nextEntrieInProfessores; i++)
        this -> professoresPtr[i] = other.professoresPtr[i];   
}
Escola::~Escola(){
    numAlunos--;
    numProfessor--;
    delete[] professoresPtr;
    for( auto i = 0; i < alunos.size( ); i++ )
        delete this->alunos[ i ]; 
    this -> alunos.clear();
    cout <<"Expulsa alunos"<<'\n';
}

void Escola::setNumAlunos(int numAlunos){
    if (Escola::numAlunosAlfea > 0 )
       Escola::numAlunosAlfea -= this->numAlunos;
        
    if ( numAlunos <= 0 )
    {
        numAlunos = 0;
        return;
    }    
   
    this->numAlunos = numAlunos;
    Escola::numAlunosAlfea += this->numAlunos;
}
void Escola::setNumProfessor(int numProfessor) {
    if(numProfessor < 0){
        numProfessor =0;
        return;
    }
    this ->numProfessor = numProfessor;
    
}
int Escola:: getNumAlunos()const{
    return this->numAlunos;
}
int Escola::getNumProfessor( ) const {
    return numProfessor;
}
void Escola::cadastrarAlunoFate(const string &novoAluno){
    if( alunos.size( ) < numAlunos ) 
    {
        numAlunosCadastrados++;
        alunos.push_back( new string(novoAluno) );        
        return;
    }

    cout << "Nao eh possivel cadastrar " << novoAluno << '.' << " Turma cheia.\n";

}


void Escola::registerProfessores( const string & newProfessor){
    cout << "\nRegistrando Professores de Alfea" <<"\n";

     if ( nextEntrieInProfessores < professoresSize ) {
        professoresPtr[ nextEntrieInProfessores++ ] = new string(newProfessor);
        return;
    }

    if (professoresSize == 0){
        professoresSize = 1;
        professoresPtr = new string*[ professoresSize ];
        professoresPtr[nextEntrieInProfessores++] = new string (newProfessor);
        return;
    }

    alocarProfessores( newProfessor );

}

void Escola::alocarProfessores( const string &newProfessor ) {
    
   string * *professoresTemp = new string *[ professoresSize ];
    for ( int i = 0; i < nextEntrieInProfessores; i++ )
        professoresPtr[ i ] = professoresTemp[ i ];

    delete [] professoresPtr;

    //Aumenta a memória em 50%
    professoresSize += int( ceil( professoresSize * 0.5 ) );
    professoresPtr = new string*[ professoresSize ]; 
    for ( int i = 0; i < nextEntrieInProfessores; i++ )
        professoresPtr[ i ] = professoresTemp[ i ];
    professoresPtr[ nextEntrieInProfessores++ ] = new string (newProfessor);

    delete [] professoresTemp;     
}


void Escola::fortaleza(){
    if(nextEntrieInProfessores !=1){
        cout << "Alfea merece atenção da rainha!"<< '\n';
        
    }
}


ostream &operator<<(ostream &out, const Escola &escola){
    out <<"Os alunos sao:" << '\n';
    for( int i = 0; i < escola.alunos.size( ); i++ )
        out << escola.alunos[i] << '\t' << *escola.alunos[ i ] << '\n';
    out << "\nProfessores de Fate: "<<'\n';
    for( int i = 0; i < escola.nextEntrieInProfessores; i++ )
        out << *escola.professoresPtr[i] << "\n";
    out<<"A data de lancamento da serie eh:"<<'\n';
    escola.DATALANCAMENTOSERIE.print();
    out <<'\n';
  
    return out;
}

 bool Escola:: operator!=( const Escola & ) const{
    if(!numAlunos >0)
        return false;
 }