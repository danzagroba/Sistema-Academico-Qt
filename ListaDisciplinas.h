#pragma once
#include <list>
#include "Disciplina.h"

using namespace std;

class ListaDisciplinas
{
private:
	list<Disciplina*> LDisciplinas;
public:
    ListaDisciplinas();
	~ListaDisciplinas();
	void incluaDisciplina(Disciplina* pdi);
	Disciplina* localizar(const char* n);
	std::list<Disciplina*>::iterator getBegin();
	std::list<Disciplina*>::iterator getEnd();
};
