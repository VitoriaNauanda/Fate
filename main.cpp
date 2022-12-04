#include "Escola.h"
#include "Escola.cpp"
#include "Fada.h"
#include "Fada.cpp"
#include "Especialista.h"
#include "Especialista.cpp"
#include "Data.h"
#include "Data.cpp"
#include "Personagem.h"
#include "Personagem.cpp"
#include "FadaLuz.h"
#include "FadaLuz.cpp"
#include "FadaFogo.h"
#include "FadaFogo.cpp"
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
  FadaFogo fada4;
	FadaLuz fada5;
  Especialista especialista;
 
  Personagem personagem;
 
  string nome1 = "Bloom";
  string nome2 = "Musa";
  string nome3 = "Stella";

  string poder1 = "Fogo";
  string poder2 = "Mente";
  string poder3 = "Luz";

  string arma1 = "Punhal";
  string arma2 = "Espada";
  personagem.setName("Aisha");
  personagem.setName("Aisha");
  personagem.setIdade(18);
  fada1.setEstiloLuta("Poderes");
  especialista.setEstiloLuta("Corporal");
  fada1.setIdade(16);
	fada4.setTipoTemperamento("Tempestuoso");
  fada5.setHabilidade("Cegar");
	especialista.setIdade(20);
  fada4.setNivelFogo(100);
  fada4.controlaPortal();
  fada5.mensagemAlfea();
  fada5.setRapidezLuz(20);
  fada5.setDirecao(40);
  fada5.calculaVelocidadeLuz();
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
  cout << personagem;

  for (int i = 0; i < alunos.size(); i++)
    delete alunos[i];
  for (int i = 0; i < armas.size(); i++)
    delete armas[i];

  return 0;
}