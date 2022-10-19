#include "Fate.h"
#include "Fate.cpp"
#include "Fada.h"
#include "Fada.cpp"
#include "Especialista.h"
#include "Especialista.cpp"
#include "Data.h"
#include "Data.cpp"
#include <vector>
using std::vector;

int main(){
    Fate fate;
    Fada fada;
    Especialista especialista;
    vector<string *>alunos;
    alunos.push_back(new string( "Bloom"));
    alunos.push_back(new string( "Musa"));
    for( int i = 0; i < alunos.size(); i++ )
		  fate.cadastrarAlunoFate( *alunos[i] );
    fate.printListaAlunos();
    fate.mostrarInfo();
    Fate other1;
    other1.printListaAlunos();

    vector<string *> poderes;
    poderes.push_back(new string( "Fogo"));
    poderes.push_back(new string( "Mente"));
    for( int i = 0; i < poderes.size(); i++ )
		  fada.cadastrarPoderesFada( *poderes[i] );
    fada.printListaPoderes();
    Fada other2;
    other2.printListaPoderes( );

    vector<string *> armas;
    armas.push_back(new string( "Espada"));
    armas.push_back(new string( "Punhal"));
    for( int i = 0; i < armas.size(); i++ )
		  especialista.cadastrarArmasEspecialista( *armas[i] );
    especialista.printListaArmas();
    Especialista other3;
    other3.printListaArmas();
    
    Fada myFada;
    Especialista mySoldado;
    Fada::BruxoSangue bruxo;
    bruxo.nome = "Isobel";
    bruxo.tipoPoder = "gelo";
    bruxo.forcaAtaque = 75;
    fada.verificarForcaBruxoSangue(bruxo);
    for(int i=0; i<alunos.size(); i++)
        delete alunos[i];
    for(int i=0; i<poderes.size(); i++)
        delete poderes[i];
    for(int i=0; i<armas.size(); i++)
        delete armas[i];
   
    return 0;
}