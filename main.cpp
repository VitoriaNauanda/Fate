#include "Escola.h"
#include "Escola.cpp"
#include "Fada.h"
#include "Fada.cpp"
#include "Especialista.h"
#include "Especialista.cpp"
#include "Data.h"
#include "Data.cpp"
#include <iostream>
#include <vector>
using std::string;
using std::vector;
using std::cout;

int main()
{
  Escola fate;
  Fada fada1;
  Fada fada2;
  Fada fada3;
  Especialista especialista;
  string nome1 = "Bloom";
  string nome2 = "Musa";
  string nome3 = "Stella";

  string poder1 = "Fogo";
  string poder2 = "Mente";
  string poder3 = "Luz";

  string arma1 = "Punhal";
  string arma2 = "Espada";
  
  vector<string *> alunos;
  fada1.setName(nome1);
  alunos.push_back(new string(fada1.getName()));
  fada2.setName(nome2);
  alunos.push_back(new string(fada2.getName()));
  fada3.setName(nome3);
  alunos.push_back(new string(fada3.getName()));

  for (int i = 0; i < alunos.size(); i++)
    fate.cadastrarAlunoFate(*alunos[i]);

  fada1.registerFadas(alunos.size());

  fate.registerProfessores("Andreas");

  fada1.setNomePoder(poder1);
  fada1.cadastrarPoderesFada(fada1.getNomePoder());
  fada2.setNomePoder(poder2);
  fada2.cadastrarPoderesFada(fada2.getNomePoder());
  fada3.setNomePoder(poder3);
  fada3.cadastrarPoderesFada(fada3.getNomePoder());    

  fada2 = fada1;
  cout << fada1;
  cout << fada2;

  fada1.transformacao();
  vector<string *> armas;
  especialista.setArma(arma1);
  armas.push_back(new string(especialista.getArma()));
  especialista.setArma(arma2);
  armas.push_back(new string(especialista.getArma()));
  for (int i = 0; i < armas.size(); i++)
    especialista.cadastrarArmasEspecialista(*armas[i]);

  especialista.verificaEstado();
  fate.fortaleza();

  BruxoSangue bruxo;
  bruxo.nome = "Isobel";
  bruxo.tipoPoder = "gelo";
  bruxo.forcaAtaque = 75;
  fada1.verificarForcaBruxoSangue(bruxo);
 
  cout << fate;
  cout << fada1;
  cout << especialista;

  for (int i = 0; i < alunos.size(); i++)
    delete alunos[i];
  for (int i = 0; i < armas.size(); i++)
    delete armas[i];

  return 0;
}