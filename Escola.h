#ifndef ESCOLA_H
#define ESCOLA_H

#include "Fada.h"
#include "Especialista.h"
#include "Data.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
class Escola
{
    friend ostream &operator<<( ostream &, const Escola & );
public:
    Escola();
    Escola(int,const Fada &,const Data & = Data( 28,01,2004));
     Escola(int, const Especialista &);
    Escola(const Escola &);
    ~Escola();
    int getNumAlunos( ) const;
    int getNumProfessor()const;
    static int getNumAlunosAlfea( );
    void setNumAlunos( int );
    void setNumProfessor( int );
    void cadastrarAlunoFate( const string & );
    void registerProfessores(const string &);

    void fortaleza();
    
   
    bool operator!=( const Escola & ) const;
private:
    
    int numAlunos;
    int numAlunosCadastrados;
    vector<string *> alunos;
    static int numAlunosAlfea;
    int numProfessor;
    string *  *professoresPtr;
    int professoresSize;
    int nextEntrieInProfessores;
    void alocarProfessores(const string & );
    
    const static Data DATALANCAMENTOSERIE;
    Fada fadaPoderes;
    Especialista especialistaArmas;
    
    string tipoAluno;
};

#endif // ESCOLA_H