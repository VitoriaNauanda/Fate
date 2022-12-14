#ifndef ESPECIALISTAINIMIGO_H
#define ESPECIALISTAINIMIGO_H

#include "Especialista.h"
#include <string>
using std::string;

class EspecialistaInimigo : public Especialista
{
    friend ostream &operator<<( ostream &, const EspecialistaInimigo & );
public:
    EspecialistaInimigo();
    EspecialistaInimigo(const string &, const string &, const int,int, const string &, int, bool);
    EspecialistaInimigo(const EspecialistaInimigo &, const string &, const string &, const int,int, const string &, int, bool);
    ~EspecialistaInimigo();
    

    string getMotivacao() const;
    int getNivelInteligencia() const;
    bool getCarteiraVeiculo()const;
    void setMotivacao(const string &);
    void setNivelInteligencia(int);
    void setPossuiDisturbio(bool);
    void setCarteiraVeiculo(bool);
    void criarBombaNuclear(int);
    void pilotarVeiculo();

    bool operator!=( const EspecialistaInimigo & ) const;
    bool operator==( const EspecialistaInimigo & )const;
    bool operator!() const;
    void operator=( const EspecialistaInimigo & );
private:
   string motivacao;
   int nivelInteligencia;
   bool possuiDisturbio;
   bool  carteiraVeiculo;
};

#endif //ESPECIALISTAINIMIGO_H