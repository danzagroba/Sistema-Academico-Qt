#pragma once
#include <iostream>
#include <list>
#include "Universidade.h"

class ListaUniversidades
{
private:
    std::list<Universidade*> LUniversidades;
public:
    ListaUniversidades();
	~ListaUniversidades();
	void incluaUniversidade(Universidade* pdi);
	Universidade* localizar(const char* univ);
	std::list<Universidade*>::iterator getBegin();
	std::list<Universidade*>::iterator getEnd();
    bool isEmpty();
};
