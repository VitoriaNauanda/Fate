#include "Escola.h"
#include "Escola.cpp"
#include "Fada.h"
#include "Fada.cpp"
#include "Especialista.h"
#include "Especialista.cpp"
#include "Data.h"
#include "Data.cpp"
#include <vector>
using std::string;
using std::vector;

int main()
{
  Escola fate;
  Fada fada;
  Especialista especialista;
  string nome1 = "Bloom";
  string nome2 = "Musa";

  string poder1 = "Fogo";
  string poder2 = "Mente";

  string arma1 = "Punhal";
  string arma2 = "Espada";
  vector<string *> alunos;
  fada.setName(nome1);
  alunos.push_back(new string(fada.getName()));
  fada.setName(nome2);
  alunos.push_back(new string(fada.getName()));
  for (int i = 0; i < alunos.size(); i++)
    fate.cadastrarAlunoFate(*alunos[i]);

  fada.registerFadas(alunos.size());

  vector<string *> professores;
  professores.push_back(new string("Andreas"));
  professores.push_back(new string("Farah"));
  for (int i = 0; i < professores.size(); i++)
    fate.registerProfessores(*professores[i]);

  Escola other1 = Escola(fate);

  vector<string *> poderes;
  fada.setNomePoder(poder1);
  poderes.push_back(new string(fada.getNomePoder()));
  fada.setNomePoder(poder2);
  poderes.push_back(new string(fada.getNomePoder()));
  for (int i = 0; i < poderes.size(); i++)
    fada.cadastrarPoderesFada(*poderes[i]);
  Fada other2 = Fada(fada);

  fada.transformacao();
  vector<string *> armas;
  especialista.setArma(arma1);
  armas.push_back(new string(especialista.getArma()));
  especialista.setArma(arma2);
  armas.push_back(new string(especialista.getArma()));
  for (int i = 0; i < armas.size(); i++)
    especialista.cadastrarArmasEspecialista(*armas[i]);

  Especialista other3 = Especialista(especialista);
  especialista.verificaEstado();
  fate.fortaleza();

  BruxoSangue bruxo;
  bruxo.nome = "Isobel";
  bruxo.tipoPoder = "gelo";
  bruxo.forcaAtaque = 75;
  fada.verificarForcaBruxoSangue(bruxo);
 
  cout << fate;
  cout << fada;
  cout << especialista;

  for (int i = 0; i < alunos.size(); i++)
    delete alunos[i];
  for (int i = 0; i < poderes.size(); i++)
    delete poderes[i];
  for (int i = 0; i < armas.size(); i++)
    delete armas[i];

  

  return 0;
}