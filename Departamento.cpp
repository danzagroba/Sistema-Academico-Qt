#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"

#include "Disciplina.h"

Departamento::Departamento(int i)
{
	id = i;
	//ObjLDisciplinas = new Lista<Disciplina>();
	pObjLDisciplinas = new std::vector<Disciplina*>;
}

Departamento::~Departamento()
{
	if (pObjLDisciplinas)
	{
		delete pObjLDisciplinas;
	}
}

int Departamento::getId()
{
	return id;
}

void Departamento::setNome(char* n)
{
    //strcpy(nome, n);
	nome = n;

	//ObjLDisciplinas->setNome(n);
}

const string Departamento::getNome() const
{
    return nome;
}


void Departamento::setUniversidade ( Universidade* u )
{
   univ = u;
}

Universidade* Departamento::getUniversidade ( )
{
   return univ;
}

void Departamento::setDisciplina ( Disciplina* d )
{  
	//ObjLDisciplinas->setInfo (d);
	pObjLDisciplinas->push_back(d);
}

void Departamento::listeDisciplinas ( )
{
    //ObjLDisciplinas->listeInfos();

	int tam = (int)pObjLDisciplinas->size();
	
	for (int i = 0; i < tam; i++)
	{
		Disciplina* aux = NULL;
		aux = (*pObjLDisciplinas)[i];
		cout << aux->getNome()	 << endl;
	}
}

void Departamento::listeDisciplinas2 ( )
{
    //ObjLDisciplinas->listeDisciplinas2();
}

