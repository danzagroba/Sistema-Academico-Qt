#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade():
ObjLDepartamentos()
{
}

Universidade::~Universidade()
{
}

const string Universidade::getNome()
{
   return nome;
}

void Universidade::setNome(char* n)
{
   //strcpy(nome, n);
   nome = n;

   //ObjLDepartamentos.setNome(n);
}

void Universidade::setDepartamento (Departamento* d)
{
    //ObjLDepartamentos.setInfo(d);
	ObjLDepartamentos.push_back(d);
}

void Universidade::listeDepartamentos()
{
    //ObjLDepartamentos.listeInfos();

	int tam = (int)ObjLDepartamentos.size();
	for (int i = 0; i < tam; i++)
	{
		cout << (ObjLDepartamentos[i])->getNome() << endl;
	}
}

void Universidade::listeDepartamentos2()
{
    //ObjLDepartamentos.listeDepartamentos2();
}
