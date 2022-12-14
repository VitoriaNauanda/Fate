#ifndef ESPECIALISTACOMUM_H
#define ESPECIALISTACOMUM_H

#include "Especialista.h"
#include <string>
using std::string;

class EspecialistaComum : public Especialista
{
    friend ostream &operator<<( ostream &, const EspecialistaComum & );
public:
    EspecialistaComum();
    EspecialistaComum(const string &, const string &, const int,int, bool,bool);
    EspecialistaComum(const EspecialistaComum &, const string &, const string &, const int,int, bool,bool);
    ~EspecialistaComum();
   

    bool getConhecerLinguagemAntiga()const;
    bool getMoldarMetal()const;
    int getForca() const;
    int getDistancia() const;
    int getTempo() const;
    void setForca(int);
    void setPes(bool);
    void setDistancia(int);
    void setTempo(int);
    void setConhecerLinguagemAntiga(bool);
    void setMoldarMetal(bool moldarMetal = true);

    void lutar();
    int calculaCorrida();
     
    void criarPocoes();
    void criarArmas();
    

    bool operator!=( const EspecialistaComum & ) const;
    bool operator==( const EspecialistaComum & )const;
    bool operator!() const;
    void operator=( const EspecialistaComum & );
private:
   bool conhecerLinguagemAntiga;
   bool moldarMetal;
   int forca;
   bool pes;
   int distancia;
   int tempo;
};

#endif //ESPECIALISTACOMUM_H