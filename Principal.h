#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

//#include "Lista.h"
#include "Professor.h"
#include "Universidade.h"
#include "Departamento.h"
#include "Disciplina.h"
#include "Aluno.h"
#include "Estagiario.h"

class Principal
{
 private:

    // A T E N Ç Ã O !!!
    // A ORDEM DA DECLARAÇÃO DOS OBJETOS/VARIÁVEIS (AGREGADOS) NUMA CLASSE AFETA 
    // A ORDEM DA CHAMADA(OU DA EXECUÇÃO) DE SEUS CONTRUTORES A PARTIR DO CONSTRUTOR
    // DESTA CLASSE AGREGADORA. NESTE CASO, A CLASSE QUE OS AGREGA É A PRINCIPAL!

    // Contadores para identificadores;
	int cont_idDisc;
	int cont_idDepart;
	int cont_idAluno;

    // Universidades
    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;

    // Departamentos
    Departamento EletronicaUTFPR;
    Departamento MatematicaUTFPR;
    Departamento FisicaUTFPR;

    Departamento MatematicaPrinceton;
    Departamento FisicaPrinceton;

    Departamento MatematicaCambridge;
    Departamento FisicaCambridge;

    // Professores
    Professor	Simao;
    Professor	Einstein;
    Professor	Newton;

    // Disciplinas
    Disciplina	Computacao1_2006;
    Disciplina	Introd_Alg_2007;
    Disciplina	Computacao2_2007;
    Disciplina	Metodos2_2007;    
	
	// Alunos
    Aluno		AAA;
    Aluno		BBB;
    Aluno		CCC;
    Aluno		DDD;
    Aluno		EEE;

	Estagiario  Fulano;
	Estagiario  Ciclano;

    int			diaAtual;
    int			mesAtual;
    int			anoAtual;

    //Lista<Universidade>	LUniversidades;
	//Lista<Departamento>	LDepartamentos;
	//Lista<Disciplina>	LDisciplinas;
	//Lista<Aluno>		LAlunos;
	//Lista<Pessoa>		LPessoas;

	list<Universidade*>	LUniversidades;
	list<Departamento*>	LDepartamentos;
	list<Disciplina*> 	LDisciplinas;
	list<Aluno*>		LAlunos;
	list<Pessoa*>		LPessoas;

	list<Universidade*>::iterator	IteradorLUniversidades;
	list<Departamento*>::iterator	IteradorLDepartamentos;
	list<Disciplina*>::iterator		IteradorLDisciplinas;
	list<Aluno*>::iterator			IteradorLAlunos;
	list<Pessoa*>::iterator			IteradorLPessoas;

  public:

    Principal ( int dia, int mes, int ano );

    // Inicializações...
    void Inicializa();
    void InicializaUnivesidades();
    void InicializaDepartamentos();
    void InicializaProfessores();
    void InicializaAlunos();
    void InicializaDisciplinas();
	void InicializaEstagiarios();

    void Executar();
    
    void CalcIdadeProfs();
    void UnivOndeProfsTrabalham();
    void DepOndeProfsTrabalham();
	void ListeDiscDeptos ( );
	void ListeAlunosDisc();
	void ListeProventosPessoas();

	void CadDisciplina();
	void CadDepartamento();
	void CadUniversidade();
	void CadAluno();

	void GravarTudo();
	void GravarUniversidades();
	void GravarDepartamentos();
	void GravarDisciplinas();
	void GravarAlunos();
	void GravarProfessores();

	void RecuperarTudo();
	void RecuperarUniversidades();
	void RecuperarDepartamentos();
	void RecuperarDisciplinas();
	void RecuperarAlunos();
	void RecuperarProfessores();

	void MenuCad();
	void MenuExe();
	void MenuGravar();
	void MenuRecuperar();
	void Menu();

};

#endif
