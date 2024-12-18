#include "stdafx.h"
#include "Principal.h"

// A T E N Ç Ã O
// A ordem de chamada dos construtores dos objetos (agredados) nesta classe
// é definida pela sua ordem de declaração na classe Principal e NÃO (estra-
// nhamente) pela sua ordem de chamada aqui (a partir do construtor da Principal).

Principal::Principal ( int dia, int mes, int ano ):
// "geradores" de identificação
cont_idAluno		(0),
cont_idDisc			(0),
cont_idDepart		(0),
// Contrutores dos objetos da Classe Disciplina
Computacao1_2006	(cont_idDisc++),
Introd_Alg_2007		(cont_idDisc++),
Computacao2_2007	(cont_idDisc++),
Metodos2_2007		(cont_idDisc++),
// Contrutores dos objetos da Classe Aluno
AAA					(cont_idAluno++),
BBB					(cont_idAluno++),
CCC					(cont_idAluno++),
DDD					(cont_idAluno++),
EEE					(cont_idAluno++),
//Contrutores dos Objetos da Classe Departamento
EletronicaUTFPR		(cont_idDepart++),	
MatematicaUTFPR		(cont_idDepart++),
FisicaUTFPR			(cont_idDepart++),
MatematicaPrinceton	(cont_idDepart++),
FisicaPrinceton		(cont_idDepart++),
MatematicaCambridge	(cont_idDepart++),
FisicaCambridge		(cont_idDepart++)
{   
    diaAtual  = dia; 
    mesAtual  = mes; 
    anoAtual  = ano;
    Inicializa ( ); 

	//AAA.setId(cont_idAluno++); 

}

void Principal::Inicializa ( )
{   
	InicializaAlunos ( );
    InicializaUnivesidades ( );
    InicializaDepartamentos ( );
    InicializaProfessores ( );
    InicializaDisciplinas ( );
	InicializaEstagiarios ( );
}

void Principal::InicializaAlunos()
{ 
	Pessoa* ponteiroPessoa;
	Aluno*  ponteiroAluno;

	AAA.setNome	("AAA");
	//LAlunos.setInfo(&AAA, AAA.getNome());	
	LAlunos.push_back(&AAA);
	ponteiroAluno = &AAA;
	ponteiroPessoa = static_cast<Pessoa*>(ponteiroAluno);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);

	BBB.setNome	("BBB");
	//LAlunos.setInfo(&BBB, BBB.getNome());
	LAlunos.push_back(&BBB);
	ponteiroAluno = &BBB;
	ponteiroPessoa = static_cast<Pessoa*>(ponteiroAluno);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);

	CCC.setNome	("CCC");
	//LAlunos.setInfo(&CCC, CCC.getNome());
	LAlunos.push_back(&CCC);
	ponteiroAluno = &CCC;
	ponteiroPessoa = static_cast<Pessoa*>(ponteiroAluno);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);

	DDD.setNome	("DDD");
	//LAlunos.setInfo(&DDD, DDD.getNome());
	LAlunos.push_back(&DDD);
	ponteiroAluno = &DDD;
	ponteiroPessoa = static_cast<Pessoa*>(ponteiroAluno);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);

	EEE.setNome	("EEE");
	//LAlunos.setInfo(&EEE, EEE.getNome());
	LAlunos.push_back(&EEE);
	ponteiroAluno = &EEE;
	ponteiroPessoa = static_cast<Pessoa*>(ponteiroAluno);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);
}

void Principal::InicializaEstagiarios ( )
{
	Pessoa*		ponteiroPessoa;
	Aluno*		ponteiroAluno;
	Estagiario*	ponteiroEstagiario;

	// ************************************
    Fulano.setNome	("Fulano");
	Fulano.setBolsaEstudo (800);
	ponteiroEstagiario	= &Fulano;

	ponteiroAluno  = static_cast<Aluno*>(ponteiroEstagiario);
	//ponteiroAluno  = dynamic_cast<Aluno*>(ponteiroEstagiario);
	//LAlunos.setInfo(ponteiroAluno, ponteiroAluno->getNome());
	LAlunos.push_back(ponteiroAluno);

	ponteiroPessoa = static_cast<Pessoa*>(ponteiroAluno);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);

	// ************************************
    Ciclano.setNome	("Ciclano");
	Ciclano.setBolsaEstudo(801);
	ponteiroEstagiario	= &Ciclano;

	ponteiroAluno  = static_cast<Aluno*>(ponteiroEstagiario);
	//ponteiroAluno  = dynamic_cast<Aluno*>(ponteiroEstagiario);
	//LAlunos.setInfo(ponteiroAluno, ponteiroAluno->getNome());
	LAlunos.push_back(ponteiroAluno);

	ponteiroPessoa = static_cast<Pessoa*>(ponteiroAluno);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);

}

void Principal::InicializaUnivesidades ( )
{  
    // Registro do(s) nome(s) da(s) universidade(s)
    UTFPR.setNome     ( "UTFPR"		);
	//LUniversidades.setInfo( &UTFPR, UTFPR.getNome() );
	LUniversidades.push_back(&UTFPR);

    Princeton.setNome ( "Princeton" );
	//LUniversidades.setInfo( &Princeton, Princeton.getNome() );
	LUniversidades.push_back(&Princeton);

    Cambridge.setNome ( "Cambridge" );
	//LUniversidades.setInfo( &Cambridge, Cambridge.getNome() );
	LUniversidades.push_back(&Cambridge);
}

void Principal::InicializaDepartamentos ( )
{ 
    // Registro do(s) nome(s) do(s) departamento(s)
    EletronicaUTFPR.setNome		( "Eletronica UTFPR" );
	MatematicaUTFPR.setNome		( "Matematica UTFPR" );
    FisicaUTFPR.setNome			( "Fisica UTFPR" );
    MatematicaPrinceton.setNome ( "Matematica Princeton" );
    FisicaPrinceton.setNome		( "Fisica Pirnceton" );
    MatematicaCambridge.setNome ( "Matematica Cambridge" );
    FisicaCambridge.setNome		( "Fisica Cambridge" );   

	//LDepartamentos.setInfo(&EletronicaUTFPR, EletronicaUTFPR.getNome());
	LDepartamentos.push_back(&EletronicaUTFPR);
	//LDepartamentos.setInfo(&MatematicaUTFPR, MatematicaUTFPR.getNome());
	LDepartamentos.push_back(&MatematicaUTFPR);
	//LDepartamentos.setInfo(&FisicaUTFPR, FisicaUTFPR.getNome());
	LDepartamentos.push_back(&FisicaUTFPR);
	//LDepartamentos.setInfo(&MatematicaPrinceton, MatematicaPrinceton.getNome());
	LDepartamentos.push_back(&MatematicaPrinceton);
	//LDepartamentos.setInfo(&FisicaPrinceton, FisicaPrinceton.getNome());
	LDepartamentos.push_back(&FisicaPrinceton);
	//LDepartamentos.setInfo(&MatematicaCambridge, MatematicaCambridge.getNome());
	LDepartamentos.push_back(&MatematicaCambridge);
	//LDepartamentos.setInfo(&FisicaCambridge, FisicaCambridge.getNome());
	LDepartamentos.push_back(&FisicaCambridge);
     
    // "Agregação" do(s) Departamento(s) a(s) Universidade(s).
    UTFPR.setDepartamento		( &EletronicaUTFPR );
    UTFPR.setDepartamento		( &MatematicaUTFPR );
    UTFPR.setDepartamento		( &FisicaUTFPR );

    Princeton.setDepartamento	( &MatematicaPrinceton );
    Princeton.setDepartamento	( &FisicaPrinceton );
    Cambridge.setDepartamento	( &MatematicaCambridge );
    Cambridge.setDepartamento	( &FisicaCambridge );
}

void Principal::InicializaProfessores ( )
{   
	Pessoa*		ponteiroPessoa;
	Professor*  ponteiroProfessor;

    // Inicialização do(s) ojeto(s) da classe Professor
    Simao.Inicializa	( 3, 10, 1976, "Jean Simão" );
	Einstein.Inicializa ( 14, 3, 1879, "Albert Einstein" );
    Newton.Inicializa	( 4, 1, 1643, "Isaac Newton" );

	Simao.setBolsaProjeto(1000);
	Simao.setSalario(4000);

	Einstein.setSalario(25000);
	Newton.setSalario(25000);
	 
    // "Filiação" a universidade.
    Simao.setUnivFiliado	( &UTFPR );
    Einstein.setUnivFiliado ( &Princeton );
    Newton.setUnivFiliado	( &Cambridge );

    // Area de Conhecimento.
    // Simao.setDominio		( "Computação“ );
    // Einstein.setDominio	( "Física" );
    // Newton.setDominio	( "Matemática-Física" );

    // "Filiação" ao departamento.
    Simao.setDepartamento	( &EletronicaUTFPR );
    Einstein.setDepartamento( &FisicaPrinceton );
    Newton.setDepartamento	( &MatematicaCambridge );

	ponteiroProfessor = &Simao;
    ponteiroPessoa = static_cast<Pessoa*>(ponteiroProfessor);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);

	ponteiroProfessor = &Einstein;
    ponteiroPessoa = static_cast<Pessoa*>(ponteiroProfessor);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);

	ponteiroProfessor = &Newton;
    ponteiroPessoa = static_cast<Pessoa*>(ponteiroProfessor);
	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);
 }

void Principal::InicializaDisciplinas ( )
{
    Computacao1_2006.setNome	( "Computacao I 2006" );
    Introd_Alg_2007.setNome		( "Introducao de Algoritmos de Programacao 2007" );
	Computacao2_2007.setNome	( "Computao II" );
	Metodos2_2007.setNome		( "Métodos II" );

	//LDisciplinas.setInfo (&Computacao1_2006, Computacao1_2006.getNome());
	LDisciplinas.push_back(&Computacao1_2006);
	//LDisciplinas.setInfo (&Introd_Alg_2007, Introd_Alg_2007.getNome());
	LDisciplinas.push_back(&Introd_Alg_2007);
	//LDisciplinas.setInfo (&Computacao2_2007, Computacao2_2007.getNome());
	LDisciplinas.push_back(&Computacao2_2007);
	//LDisciplinas.setInfo (&Metodos2_2007, Metodos2_2007.getNome());
	LDisciplinas.push_back(&Metodos2_2007);

    Computacao1_2006.setDepartamento  ( &EletronicaUTFPR );
    Introd_Alg_2007.setDepartamento	  ( &EletronicaUTFPR );
    Computacao2_2007.setDepartamento  ( &EletronicaUTFPR );
    Metodos2_2007.setDepartamento     ( &EletronicaUTFPR );

    Metodos2_2007.setAluno ( &AAA );
    Metodos2_2007.setAluno ( &BBB );
    Metodos2_2007.setAluno ( &CCC );
    Metodos2_2007.setAluno ( &DDD );
    Metodos2_2007.setAluno ( &EEE );

	Computacao2_2007.setAluno ( &AAA );
    Computacao2_2007.setAluno ( &EEE );
    Computacao2_2007.setAluno ( &DDD );
}

void Principal::CalcIdadeProfs ( )
{
    // Cálculo da idade.
    Simao.Calc_Idade    ( diaAtual, mesAtual, anoAtual );
    Einstein.Calc_Idade ( diaAtual, mesAtual, anoAtual );
    Newton.Calc_Idade	( diaAtual, mesAtual, anoAtual );
    printf ("\n");
}

void Principal::UnivOndeProfsTrabalham ( )
{
    // Universidade que a Pessoa trabalha.
    Simao.OndeTrabalho ( );
    Einstein.OndeTrabalho ( );
    Newton.OndeTrabalho ( );
    
	cout << endl;
}

void Principal::DepOndeProfsTrabalham ( )
{
    // Departamento que a Pessoa trabalha.
    Simao.QualDepartamentoTrabalho ( );
    Einstein.QualDepartamentoTrabalho ( );
    Newton.QualDepartamentoTrabalho ( );
    //printf ( "\n" );
	cout << endl;
}

void Principal::ListeDiscDeptos()
{
    EletronicaUTFPR.listeDisciplinas();
 	cout << endl;
}

void Principal::ListeAlunosDisc()
{
    Metodos2_2007.listeAlunos();
    cout << endl;

    Computacao2_2007.listeAlunos();  
    cout << endl;

	//Metodos2_2007.listeAlunos2();
    //cout << endl;
}

void Principal::ListeProventosPessoas()
{
	//Elemento<Pessoa>*	ponteiroElementoPessoa;
	//Pessoa*				ponteiroPessoa;
	//ponteiroElementoPessoa  = LPessoas.getPrimeiro();
	//while ( ponteiroElementoPessoa != NULL )
	//{
	//	ponteiroPessoa = ponteiroElementoPessoa->getInfo();
	//	ponteiroPessoa->informaProventos();
	//	ponteiroElementoPessoa = ponteiroElementoPessoa->getProximo();
	//}

    IteradorLPessoas = LPessoas.begin();
	while (IteradorLPessoas != LPessoas.end())
	{
		(*IteradorLPessoas)->informaProventos();
		IteradorLPessoas++;
	}

	
}

void Principal::Executar()
{
    //CalcIdadeProfs();
    //UnivOndeProfsTrabalham();
    //DepOndeProfsTrabalham();
	//ListeDiscDeptos();
    //ListeAlunosDisc();
	Menu();
}

void Principal::CadDisciplina()
{
	

}

void Principal::CadDepartamento()
{
    char nomeUniversidade[150];
	char nomeDepartamento[150];
	Universidade* univ = NULL;
	Departamento* depart = NULL;

	cout << "Qual o nome da universidade do departamento" << endl;
	cin  >> nomeUniversidade;

	//univ = LUniversidades.localizar(nomeUniversidade);
	IteradorLUniversidades = LUniversidades.begin();
	while (IteradorLUniversidades != LUniversidades.end())
	{
		//if ( 0 == strcmp(nomeUniversidade,(*IteradorLUniversidades)->getNome()) )
		if ( nomeUniversidade == (*IteradorLUniversidades)->getNome() )
		{
		   univ = *IteradorLUniversidades;	
		   //cout << "Achei!!!" << endl;
		}
		IteradorLUniversidades++;
	}
	
	if ( univ != NULL )
	{
		cout << "Qual o nome do departamento" << endl;
		cin >> nomeDepartamento;
	    depart = new Departamento(cont_idDepart);
		cont_idDepart++;
		depart->setNome(nomeDepartamento);
		//LDepartamentos.setInfo(depart, depart->getNome());
		LDepartamentos.push_back(depart);
	}
	else
	{
		cout << "Universidade inexistente." << endl;
		system ("Pause");
	}
}

void Principal::CadUniversidade()
{
    char nomeUniversidade[150];
	Universidade* univ;

	cout << "Qual o nome da universidade" << endl;
	cin  >> nomeUniversidade;

    univ = new Universidade();
	univ->setNome(nomeUniversidade);

	//LUniversidades.setInfo(univ, univ->getNome());
	LUniversidades.push_back(univ);
}

void Principal::CadAluno()
{
    char	nomeAluno[150];
	int		ra;
	Aluno*	ponteiroAluno;
	Pessoa* ponteiroPessoa;

	cout << "Qual o nome do aluno. " << endl;
	cin  >> nomeAluno;

	cout << "Qual o RA do aluno."	<< endl;
	cin  >> ra;

    ponteiroAluno = new Aluno(cont_idAluno++);
	ponteiroAluno->setNome(nomeAluno);
	ponteiroAluno->setRA(ra);

	//LAlunos.setInfo(ponteiroAluno, ponteiroAluno->getNome());
	LAlunos.push_back(ponteiroAluno);

	// Logo abaixo a forma moderna de fazer cast
	ponteiroPessoa = static_cast<Pessoa*>(ponteiroAluno);

	// Logo abaixo a forma antiga e desaconselhavel de fazer cast
	//ponteiroPessoa = (Pessoa*)ponteiroAluno;     

	//LPessoas.setInfo(ponteiroPessoa, ponteiroPessoa->getNome());
	LPessoas.push_back(ponteiroPessoa);
}

void Principal::GravarTudo()
{
}

void Principal::GravarUniversidades()
{
}

void Principal::GravarDepartamentos()
{
}

void Principal::GravarDisciplinas()
{
}

void Principal::GravarAlunos()
{
//	LAlunos.graveAlunos();
}

void Principal::GravarProfessores()
{
}

void Principal::RecuperarTudo()
{
}

void Principal::RecuperarUniversidades()
{
}

void Principal::RecuperarDepartamentos()
{
}

void Principal::RecuperarDisciplinas()
{
}

void Principal::RecuperarAlunos()
{
	//LAlunos.recupereAlunos();
}

void Principal::RecuperarProfessores()
{
}

void Principal::MenuCad()
{
    int op = -1;

    while (op != 5)
    {
		system("cls");
        cout << "  Informe sua opção:			"	<< endl;
        cout << "  1 - Cadastrar Disciplina.	"	<< endl;
        cout << "  2 - Cadastrar Departamentos. "	<< endl;
        cout << "  3 - Cadastrar Universidade.	"	<< endl;
		cout << "  4 - Cadastrar Aluno.			"	<< endl;
        cout << "  5 – Sair. "						<< endl;
        cin >> op;

        switch (op)
        {
            case 1 :{ CadDisciplina ();	 }
                break;

            case 2: { CadDepartamento(); }
				break;

			case 3:	{ CadUniversidade(); }
				break;

			case 4:	{ CadAluno(); }
				break;

            case 5:	{ cout << " FIM " << endl; }
                break;

            default:{                      
					  cout << "Opção Inválida - Pressione uma tecla." << endl;
					  getchar();
				    }
        }
    }
}

void Principal::MenuExe()
{
    int op = -1;
    while ( op != 8 )
    {
		system("cls");
        cout << "  Informe sua opção:		"	<< endl;
        cout << "  1 - Listar Disciplinas.  "	<< endl;
        cout << "  2 - Listar Departamentos."	<< endl;
        cout << "  3 - Listar Universidade. "	<< endl;
		cout << "  4 - Listar Alunos. "			<< endl;
		cout << "  5 - Listar Professores."		<< endl;
		cout << "  6 - Listar Pessoas."			<< endl;
		cout << "  7 - Listar Proventos."		<< endl;
        cout << "  8 – Sair. "					<< endl;
        cin  >> op;

        switch ( op )
        {
			case 1:  { 
 					   //LDisciplinas.listeInfos();
						IteradorLDisciplinas = LDisciplinas.begin();
						while (IteradorLDisciplinas != LDisciplinas.end())
						{
							cout << (*IteradorLDisciplinas)->getNome() << endl;
							IteradorLDisciplinas++;
						}

					   system ("Pause");	
					 }
                break;
			case 2:  { 
				       //LDepartamentos.listeInfos();
					    IteradorLDepartamentos = LDepartamentos.begin();
						while (IteradorLDepartamentos != LDepartamentos.end())
						{
							cout << (*IteradorLDepartamentos )->getNome() << endl;
							IteradorLDepartamentos++;
						}
					   system ("Pause");
					 }
				break;
			case 3:  { 
				        //LUniversidades.listeInfos(); 
						IteradorLUniversidades = LUniversidades.begin();
						while (IteradorLUniversidades != LUniversidades.end())
						{
							cout << (*IteradorLUniversidades )->getNome() << endl;
							IteradorLUniversidades++;
						}
				       system ("Pause");
					 }
				break;
			case 4:  { 
					    //LAlunos.listeInfos(); 
					    IteradorLAlunos = LAlunos.begin();
						while (IteradorLAlunos != LAlunos.end())
						{
							cout << (*IteradorLAlunos)->getNome() << endl;
							IteradorLAlunos++;
						}
						system ("Pause");
				   
					 }
                break;
	        case 5:  { 
						DepOndeProfsTrabalham(); 
						system ("Pause");
					 }
                break; 
            case 6:  {      
						//LPessoas.listeInfos();

						IteradorLPessoas = LPessoas.begin();
						while (IteradorLPessoas != LPessoas.end())
						{
							cout << (*IteradorLPessoas)->getNome() << endl;
							IteradorLPessoas++;
						}

						/*
						ostream_iterator< Pessoa* > Saida ( cout, " " );
						copy( LPessoas.begin(), LPessoas.end(), Saida );
						*/

						system ("Pause");
					 }
                break;
			case 7:  { 
						ListeProventosPessoas(); 
						system ("Pause");
					 }
                break;
			case 8:  { 
						cout << " FIM " << endl; 
					 }
                break;
            default: { 
					   cout << "Opção Inválida - Pressione uma tecla." << endl;
					   getchar(); 
					 }
        }
    }
}

void Principal::MenuGravar()
{
	int op = -1; 
    while (op != 6)
    {
		system("cls");
        cout << "  Informe sua opção:			"	<< endl;
		cout << "  0 - Gravar Tudo.				"	<< endl;
        cout << "  1 - Gravar Universidades.	"	<< endl;
        cout << "  2 - Gravar Departamentos.	"	<< endl;
		cout << "  3 - Gravar Disciplinas.		"	<< endl;
		cout << "  4 - Gravar Alunos.			"	<< endl;
		cout << "  5 - Gravar Professores.		"	<< endl;
        cout << "  6 – Sair.					"	<< endl;
        cin >> op;

        switch (op)
        {
			case 0: {	GravarTudo();			 }
                break;
            case 1: {	GravarUniversidades();	 }
                break;
            case 2: {	GravarDepartamentos();	 }
				break;
			case 3: {	GravarDisciplinas();	 }
				break;
			case 4: {	GravarAlunos();			 }
				break;
			case 5: {	GravarProfessores();	 }
				break;
			case 6: {	cout << " FIM " << endl; }
                break;
            default: { cout << "Opção Inválida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }	
}

void Principal::MenuRecuperar()
{
	int op = -1;
    
    while (op != 6)
    {
		system("cls");

        cout << "  Informe sua opção:			"	<< endl;
		cout << "  0 - Recuperar Tudo.			"	<< endl;
        cout << "  1 - Recuperar Universidades.	"	<< endl;
        cout << "  2 - Recuperar Departamentos.	"	<< endl;
		cout << "  3 - Recuperar Disciplinas.	"	<< endl;
		cout << "  4 - Recuperar Alunos.		"	<< endl;
		cout << "  5 - Recuperar Professores.	"	<< endl;
        cout << "  6 – Sair.					"	<< endl;
        cin >> op;

        switch (op)
        {
			case 0: {	RecuperarTudo();			 }
                break;
            case 1: {	RecuperarUniversidades();	 }
                break;
            case 2: {	RecuperarDepartamentos();	 }
				break;
			case 3: {	RecuperarDisciplinas();	 }
				break;
			case 4: {	RecuperarAlunos();			 }
				break;
			case 5: {	RecuperarProfessores();	 }
				break;
			case 6: {	cout << " FIM " << endl; }
                break;
            default: { cout << "Opção Inválida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }	
}

void Principal::Menu()
{
	int op = -1;
    while (op != 5)
    {
		system("cls");
        cout << "  Informe sua opção:"	<< endl;
        cout << "  1 - Cadastrar.	 "	<< endl;
        cout << "  2 - Executar.	 "	<< endl;
		cout << "  3 - Gravar.		 "  << endl;
		cout << "  4 - Recuperar.	 "  << endl;
        cout << "  5 – Sair.		 "	<< endl;
        cin >> op;

        switch (op)
        {
            case 1: {	MenuCad();			}
                break;
            case 2: {	MenuExe();			}
				break;
			case 3: {	MenuGravar();		}
				break;
			case 4: {	MenuRecuperar();	}
				break;
			case 5: {	cout << " FIM " << endl; }
                break;
            default: { cout << "Opção Inválida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }	
}
