
#include "stdafx.h"
#include "Aluno.h"


Aluno::Aluno(int i)
{
	id = i;
	RA = 0;
}

Aluno::~Aluno()
{

}

void Aluno::setRA(int ra)
{ 
	RA = ra;
}
 
int Aluno::getRA()
{
	return RA;
}

void Aluno::setDisciplina(Disciplina* pd)
{
    pDiscAssociada = pd;
}

Disciplina* Aluno::getDisciplina()
{
    return pDiscAssociada;
}

void Aluno::setId(int i)
{
	id = i;
}


int Aluno::getId()
{
	return id;
}

void Aluno::setNome(const char* n){
    nome=n;
}

string Aluno::getNome(){
    return nome;
}
