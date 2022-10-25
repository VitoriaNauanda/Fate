#include "Escola.h"
#include "Escola.cpp"
#include "Fada.h"
#include "Fada.cpp"
#include "Especialista.h"
#include "Especialista.cpp"
#include "Data.h"
#include "Data.cpp"
#include <vector>
using std::vector;


int main(){
    Escola fate;
    Fada fada;
    Especialista especialista;
    vector<string *>alunos;
    alunos.push_back(new string( "Bloom"));
    alunos.push_back(new string( "Musa"));
    for( int i = 0; i < alunos.size(); i++ )
		fate.cadastrarAlunoFate( *alunos[i] );
    vector<string *>alunosFada;
   fada.registerFadas(alunos.size());
   
    vector<string *>professores;
    professores.push_back(new string( "Andreas"));
    professores.push_back(new string( "Farah"));
    for( int i = 0; i < professores.size(); i++ )
		fate.registerProfessores(*professores[i]);

    fate.fortaleza();
    Escola other1;
    

    vector<string *> poderes;
    poderes.push_back(new string( "Fogo"));
    poderes.push_back(new string( "Mente"));
    for( int i = 0; i < poderes.size(); i++ )
		fada.cadastrarPoderesFada( *poderes[i] );
    Fada other2 ;
    
    fada.transformacao();
    vector<string *> armas;
    armas.push_back(new string( "Espada"));
    armas.push_back(new string( "Punhal"));
    for( int i = 0; i < armas.size(); i++ )
		  especialista.cadastrarArmasEspecialista( *armas[i] );
    
    Especialista other3;
    especialista.verificaEstado();
    
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
    
    cout<<fate;
    cout<<fada;
    cout<<especialista;

    return 0;
}