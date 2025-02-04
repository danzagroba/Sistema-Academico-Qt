
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

     // Associação para com uma Universidade.
     Universidade* univ;
     // Associação para com várias Disciplinas.
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

