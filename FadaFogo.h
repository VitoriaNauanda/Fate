#ifndef FADAFOGO_H
#define FADAFOGO_H

#include "Fada.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;

class FadaFogo: public Fada
{
    friend ostream &operator<<( ostream &, const FadaFogo & );
public:
    FadaFogo();
    FadaFogo(const string &,const int, const int ,const string&);
    FadaFogo(const FadaFogo &,const string &,const int, int, const string&);
    ~FadaFogo();

    string getTipoTemperamento()const;
    void setTipoTemperamento( const string &);
    void validaProtecao();

 
    void operator=(const FadaFogo &);
    bool operator==(const FadaFogo &)const;
    bool operator!=(const FadaFogo &)const;
    void operator!();
 
private:
  
   string tipoTemperamento;
};

#endif // FADAFOGO_H