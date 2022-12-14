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
    //friend ostream &operator<<( ostream &, const Personagem & );
public:
    Personagem();
    Personagem(const string &,const string &,int);
    Personagem(const Personagem &);
    virtual ~Personagem();
    string getName()const;
   
    int getIdade()const;
    string getEstiloLuta()const;
    void setName( const string &);
    void setIdade(int);
    void setEstiloLuta(const string &);
    bool verificaIdade( int);

    virtual void atravessarPortal();
    virtual void recebeCartaConvocacao();
    bool isPessoaMagica();
    void printPersonagem();
    void modoAtaque(const string &);

    string getLocalOrigem() const;
    string getConteudoCarta() const;
    bool getPessoaMagica() const;
    void setPessoaMagica(bool pessoaMagica);
    void setLocalOrigem(const string&);
    void setConteudoCarta(const string&);
    /*
    void operator=(const Personagem &);
    bool operator==(const Personagem &)const;
    bool operator!=(const Personagem &)const;
    void operator!();
   
    */

protected:
    string name;    
    string estiloLuta;
    int idade;

    bool pessoaMagica;
    string localOrigem;
    string conteudoCarta;
   
};


#endif //PERSONAGEM_H