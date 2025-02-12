#include "stdafx.h"
#include "Disciplina.h"

Disciplina::Disciplina(int i, int na, string ac):
ObjLAlunos()
{ 
	id = i;
    DeptoAssociado		= NULL;  
 
    //strcpy (area_conhecimento, ac ); 
	area_conhecimento = ac;
}

Disciplina::~Disciplina()
{ 
   DeptoAssociado  = NULL;
}

void  Disciplina::setId ( int i ) 		
{ 
	id = i; 	
}

int   Disciplina::getId ( )  		
{  
	return id;  	
}

void  Disciplina::setNome(string n)
{  
	//strcpy(nome, n);  
	nome = n;
}

const string Disciplina::getNome()
{  
	return nome;  
}

void Disciplina::setDepartamento(Departamento* d)
{
  // Cada vez que um Departamento é associado a uma Disciplina,
  // esta Disciplina passa a fazer parte da lista de disciplina 
  // do Departamento, por meio do comando abaixo.
  DeptoAssociado = d;
  DeptoAssociado->setDisciplina ( this );
}

Departamento* Disciplina::getDepartamento ( )
{
  return  DeptoAssociado;
}


void Disciplina::setAluno ( Aluno* a )
{
	//ObjLAlunos.setInfo(a, a->getNome());
	ObjLAlunos.push_back(a);
	
}

void Disciplina::listeAlunos()
{
    //ObjLAlunos.listeInfos();
	Iterador = ObjLAlunos.begin();
	while (Iterador != ObjLAlunos.end())
	{
		cout << (*Iterador)->getNome() << endl;
		Iterador++;
	}
}

vector<Aluno*>::iterator Disciplina::getAlunosBegin()
{
    return ObjLAlunos.begin();
}

vector<Aluno*>::iterator Disciplina::getAlunosEnd()
{
    return ObjLAlunos.end();
}
