#ifndef ESPECIALISTA_H
#define ESPECIALISTA_H

#include <string>
#include <vector>
#include "Fate.h"
using std::string;
using std::vector;

class Especialista
{
public:

    Especialista();
    Especialista(int);
    Especialista(const Especialista &);
    ~Especialista();

    int getNumArmas( ) const;
    int getNumAtaque()const;
    static int getNumArmarioAlfea( );
    void setNumArmas( int );
    void setNumAtaque( int );
    void cadastrarArmasEspecialista( const string & );
    void printListaArmas( ) const;
    void registerAtaques(int);
    void printAtaques() const;
    void verificaEstado();
    void fortaleza();
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

    Fate *myEspecialista;
};

#endif // ESPECIALISTA_H