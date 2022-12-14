#ifndef FADALUZ_H
#define FADALUZ_H

#include "Fada.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;

class FadaLuz: public Fada
{
    friend ostream &operator<<( ostream &, const FadaLuz & );
public:
    FadaLuz();
    FadaLuz(const string &,const string &,const int, const int ,const string&);
    FadaLuz(const FadaLuz &,const string &,const string &,const int, int, const string&);
    ~FadaLuz();

    string getHabilidade()const;
    int getRapidezLuz()const;
    int getDirecao()const;
    void setHabilidade( const string &);
    void setRapidezLuz( int);
    void setDirecao(int);
    void obstruirVisao();
    int calculaVelocidadeLuz();

    //uso do virtual de Fada
    void transformacao();
    void mensagemAlfea();
    void printPersonagem();
    void operator=(const FadaLuz &);
    bool operator==(const FadaLuz &)const;
    bool operator!=(const FadaLuz &)const;
    void operator!();
private:
  
   string habilidades;
   int rapidezLuz;
   int direcao;
};

#endif // FADALUZ_H