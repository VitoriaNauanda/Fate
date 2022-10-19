#ifndef FATE_H
#define FATE_H

#include "Data.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
class Fate
{
    friend ostream &operator<<( ostream &, const Fate & );
public:
    Fate();
    Fate(int,const Data & = Data( 28,01,2004));
    Fate(const Fate &);
    ~Fate();
    int getNumAlunos( ) const;
    int getNumProfessor()const;
    static int getNumAlunosAlfea( );
    void setNumAlunos( int );
    void setNumProfessor( int );
    void cadastrarAlunoFate( const string & );
    void registerProfessores(int);
    void printListaAlunos( ) const;
    void printProfessores( ) const;
    void fortaleza();
    static void mostrarInfo( );
  
private:
    
    int numAlunos;
    int numAlunosCadastrados;
    vector<string *> alunos;
    static int numAlunosAlfea;
    int numProfessor;
    int *professoresPtr;
    int professoresSize;
    int nextEntrieInProfessores;
    void alocarProfessores( int );
    
    const static Data DATALANCAMENTOSERIE;
   
};

#endif // FATE_H