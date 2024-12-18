
#include "stdafx.h"
#include "Aluno.h"

Aluno::Aluno (int diaNa, int mesNa, int anoNa, string nome):
Pessoa (diaNa, mesNa, anoNa, nome)
{

}

Aluno::Aluno(int i):
Pessoa()
{
	id = i;
	RA = 0;
}

Aluno::Aluno ( ):
Pessoa()
{

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

void Aluno::setDepartamento ( Departamento* d )
{
	DeptoAssociado = d;
}

Departamento* Aluno::getDepartamento ()
{
	return DeptoAssociado;
}

void Aluno::setId(int i)
{
	id = i;
}


int Aluno::getId()
{
	return id;
}
