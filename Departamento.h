
#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_

#include "stdafx.h"

class Universidade;
class Disciplina;

// template<class TIPO> class Lista;
      
class Departamento
{
  private:
     int id;
     string nome;

     // Associa��o para com uma Universidade.
     Universidade* univ;
     // Associa��o para com v�rias Disciplinas.
     //Lista<Disciplina>* ObjLDisciplinas;
	 std::vector<Disciplina*> *pObjLDisciplinas;

  public:
     Departamento(int i);
     ~Departamento();

	 int getId();

     void setNome(const char* n);
     const string getNome() const;

     void setUniversidade(Universidade* u);
     Universidade* getUniversidade();

     void setDisciplina ( Disciplina* d );
     void listeDisciplinas();
     void listeDisciplinas2();
};

#endif

