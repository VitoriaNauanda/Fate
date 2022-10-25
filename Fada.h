#ifndef FADA_H
#define FADA_H

#include "Escola.h"

#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
class Fada
{
    friend ostream &operator<<( ostream &, const Fada & );
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
    static int getNumPoderesFada( );
    void setNumPoderes( int );
    void setNumFada( int );
    void cadastrarPoderesFada( const string & );
    void registerFadas(int);

    void transformacao();
    void printDadosBruxoSangue(const BruxoSangue &);
    void verificarForcaBruxoSangue(const BruxoSangue &);

    bool operator!=( const Fada & ) const;
private:
   int numPoderes;
   int numPoderesCadastrados;
   vector<string *> poderes;
   int numFada;
   int *fadaPtr;
   int fadaSize;
   int nextEntrieInFada;
   void alocarFadas( int );
  
   static int numPoderesFada;
   const float FORCA;
   
};

#endif // FADA_H