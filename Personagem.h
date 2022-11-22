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
    
    void setName( const string &);
    void setIdade(int);

    bool verificaIdade( int);


private:
    string name;    
    int idade;
};


#endif //PERSONAGEM_H