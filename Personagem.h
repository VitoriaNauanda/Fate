#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "ostream"
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
class Personagem
{
    friend ostream &operator<<( ostream &, const Personagem & );
public:
    Personagem();
    Personagem(const string &,int);
    Personagem(const Personagem &);
    ~Personagem();
    string getName()const;
   
    int getIdade()const;
    string getEstiloLuta()const;
    void setName( const string &);
    void setIdade(int);
    void setEstiloLuta(const string &);
    bool verificaIdade( int);
    void operator=(const Personagem &);
    bool operator==(const Personagem &)const;
    bool operator!=(const Personagem &)const;
    void operator!();
    void modoAtaque(const string &);
private:
    string name;    
    string estiloLuta;
    int idade;
   
};


#endif //PERSONAGEM_H