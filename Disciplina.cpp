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
  DeptoAssociado = d;
}

Departamento* Disciplina::getDepartamento ( )
{
  return  DeptoAssociado;
}


void Disciplina::setAluno ( Aluno* a )
{
	ObjLAlunos.push_back(a);
    a->setDisciplina(this);
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
