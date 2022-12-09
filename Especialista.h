#ifndef ESPECIALISTA_H
#define ESPECIALISTA_H

#include <string>
#include <vector>
#include "Escola.h"
#include "Personagem.h"
using std::string;
using std::vector;
using std::ostream;
class Especialista : Personagem
{
    friend ostream &operator<<( ostream &, const Especialista & );
public: 

    Especialista();
    Especialista(int);
    Especialista(const string &,const string &,const int,int);
    Especialista(const Especialista &, const string &,const string &,const int,int);
    ~Especialista();

    int getNumArmas( ) const;
    int getNumAtaque()const;
    string getArma() const;
    static int getNumArmarioAlfea( );
    void setNumArmas( int );
    void setNumAtaque( int );
    void setArma( const string & );
    void cadastrarArmasEspecialista( const string & );
    
    void registerAtaques(int);
   
    void verificaEstado();
    void fortaleza();

    bool operator!=( const Especialista & ) const;
    bool operator==( const Especialista & )const;
    bool operator!() const;
    void operator=( const Especialista & );
private:
    int numArmas;
    int numArmasCadastradas;
    vector<string *> armas;
    static int numArmarioAlfea;
    int numAtaque;
    int *ataquesPtr;
    int ataquesSize;
    int nextEntrieInAtaque;
    void alocarAtaque( int );
    string arma;
   
};

#endif // ESPECIALISTA_H