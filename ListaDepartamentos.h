#pragma once
#include <list>
#include "Departamento.h"

using namespace std;
class ListaDepartamentos
{
private:
	std::list<Departamento*> LDepartamentos;
public:
    ListaDepartamentos();
	~ListaDepartamentos();
	void incluaDepartamento(Departamento* pdi);
	Departamento* localizar(const char* n);
	std::list<Departamento*>::iterator getBegin();
	std::list<Departamento*>::iterator getEnd();
};
