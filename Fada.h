#ifndef FADA_H
#define FADA_H

#include "Escola.h"

#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;

struct BruxoSangue{
    string nome;
    string tipoPoder;
    double forcaAtaque;
};
class Fada
{
    friend ostream &operator<<( ostream &, const Fada & );
public:
    Fada();
    Fada(int);
    Fada(const Fada &);
    ~Fada();


    int getNumPoderes( ) const;
    int getNumFada()const;
    string getName()const;
    string getNomePoder()const;
    static int getNumPoderesFada( );
    void setNumPoderes( int );
    void setNumFada( int );
    void setName( const string &);
    void setNomePoder( const string &);
    void cadastrarPoderesFada( const string & );
    void registerFadas(int);

    void transformacao();
    void printDadosBruxoSangue(const BruxoSangue &);
    void verificarForcaBruxoSangue(const BruxoSangue &);

    bool operator!=( const Fada & ) const;
    bool operator==( const Fada & )const;
    bool operator!() const;
    void operator=( const Fada & );
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
   string name;
   string nomePoder;
   
};

#endif // FADA_H