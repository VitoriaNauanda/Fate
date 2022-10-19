#ifndef FADA_H
#define FADA_H

#include "Fate.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
class Fada
{
public:
    Fada();
    Fada(int);
    Fada(const Fada &);
    ~Fada();

    struct BruxoSangue{
        string nome;
        string tipoPoder;
        double forcaAtaque;
    };
    int getNumPoderes( ) const;
    int getNumFada()const;
    void setNumPoderes( int );
    void setNumFada( int );
    void cadastrarPoderesFada( const string & );
    void registerFadas(int);
    void printFadas()const;
    void printListaPoderes( ) const;
    void transformacao();
    void printDadosBruxoSangue(const BruxoSangue &);
    void verificarForcaBruxoSangue(const BruxoSangue &);
private:
   int numPoderes;
   int numPoderesCadastrados;
   vector<string *> poderes;
   int numFada;
   int *fadaPtr;
   int fadaSize;
   int nextEntrieInFada;
   void alocarFadas( int );
   
   Fate *myFate;
};

#endif // FADA_H