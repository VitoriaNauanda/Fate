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

#include "EspecialistaComum.h"
#include "EspecialistaComum.cpp"
#include "EspecialistaInimigo.h"
#include "EspecialistaInimigo.cpp"

#include <iostream>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::vector;

int main()
{
/*
  Escola fate;

  FadaFogo fada4;
	FadaLuz fada5;
  Especialista especialista;
  EspecialistaComum especialistaComum;
  EspecialistaInimigo inimigo;
 

  string nome1 = "Bloom";
  string nome2 = "Musa";
  string nome3 = "Stella";

  string poder1 = "Fogo";
  string poder2 = "Mente";
  string poder3 = "Luz";

  string arma1 = "Punhal";
  string arma2 = "Espada";
 
  fada4.setEstiloLuta("Poderes");
  especialista.setName("Sky");
  especialista.setEstiloLuta("Corporal");
  fada4.setIdade(16);
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
  fada5.setName(nome1);
  
  alunos.push_back(new string(fada4.getName()));
  fada4.setName(nome2);
  alunos.push_back(new string(fada4.getName()));
  fada5.setName(nome3);
  alunos.push_back(new string(fada5.getName()));

  for (int i = 0; i < alunos.size(); i++)
    fate.cadastrarAlunoFate(*alunos[i]);

  fada4.registerFadas(alunos.size());

  fate.registerProfessores("Andreas");
  vector<string *> poderes;
  fada5.setNomePoder(poder1);
  poderes.push_back(new string(fada5.getNomePoder()));
  fada5.setNomePoder(poder2);
  poderes.push_back(new string(fada5.getNomePoder()));
  fada4.setNomePoder(poder3);
  poderes.push_back(new string(fada4.getNomePoder()));    
 
  for (int i = 0; i < poderes.size(); i++)
    fada4.cadastrarPoderesFada(*poderes[i]);

  for (int i = 0; i < poderes.size(); i++)
    fada5.cadastrarPoderesFada(*poderes[i]);

  fada4.transformacao();
  
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
  fada4.verificarForcaBruxoSangue(bruxo);
  cout<<"ESTILO LUTA: "<< fada5.getEstiloLuta()<<'\n';

  especialista.setPessoaMagica(true);
  especialista.verificaEstado();
  especialista.atravessarPortal();
  especialista.recebeCartaConvocacao();
  cout << especialista;

  cout << fate;
  cout <<'\n';

    especialistaComum.setConhecerLinguagemAntiga(true);
  especialistaComum.setMoldarMetal(true);
  especialistaComum.setForca(40);
  especialistaComum.lutar();
  especialistaComum.calculaCorrida();
  especialistaComum.criarPocoes();
  especialistaComum.criarArmas();
  cout << especialistaComum;

  

  cout << "ESPECIALISTA INIMIGO" <<'\n';
  inimigo.setMotivacao("Infancia perdida");
  inimigo.setPossuiDisturbio(true);
  inimigo.setCarteiraVeiculo(true);
  inimigo.setNivelInteligencia(100);
  inimigo.criarBombaNuclear(inimigo.getNivelInteligencia());
  inimigo.verificaEstado();
  inimigo.pilotarVeiculo();
  cout << inimigo;
  */
  cout<<"VECTOR DE PONTEIROS"<< '\n';
  //Vector de ponteiro sem Dynamic e sem o typeId
  vector<Personagem *> personas;
  personas.push_back(new Especialista("Andreas", "Corporal",45,4));
  personas.push_back(new Especialista("Riven", "Corporal",18,5));
  personas.push_back(new Especialista("Sky", "Corporal",18,10));

  for (Personagem *personagem : personas){
    personagem ->recebeCartaConvocacao();
  }

  for (Personagem *personagem : personas){
    delete personagem;
  }
  //Vector de ponteiro com Dynamic e com o typeId
  vector<Personagem *> seres(3);
  seres[0] = new Especialista("Andreas", "Corporal",45,4) ;
  seres[1] = new Especialista("Riven", "Corporal",18,5);
  seres[2] = new Especialista("Sky", "Corporal",18,10);

  for(size_t i = 0; i <seres.size(); i++){
    seres[i]->printPersonagem();
    Especialista *especialitaPtr = dynamic_cast<Especialista*> (seres[i]);
    string nome = especialitaPtr-> getName();
    cout << nome << "usando o dynamic_cast" << '\n';
    string modoLuta = especialitaPtr-> getEstiloLuta();
    cout << modoLuta << "usando o dynamic_cast" << '\n';
    int idade = especialitaPtr-> getIdade();
    cout << idade << "usando o dynamic_cast" << '\n';
    int arma = especialitaPtr-> getNumArmas();
    cout << arma << "usando o dynamic_cast" << '\n';
  }
  for(size_t j = 0; j < seres.size(); j++){
    cout << "Deletando objeto de "<< typeid(*seres[j]).name()<<"\n\n";
    delete seres[j];
  }
/*
  
  for (int i = 0; i < alunos.size(); i++)
    delete alunos[i];
  for (int i = 0; i < armas.size(); i++)
    delete armas[i];
  for (int i = 0; i < poderes.size(); i++)
    delete poderes[i];
*/
  
  return 0;
}