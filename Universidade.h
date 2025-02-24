
#ifndef _UNIVERSIDADE_H_
#define _UNIVERSIDADE_H_

//#include "Lista.h"
#include "Departamento.h"

class Universidade
{
  private:
      string nome;
      int id;
      //Lista<Departamento> ObjLDepartamentos;
	  std::vector<Departamento*> ObjLDepartamentos;

  public:
      Universidade(int idd);
      ~Universidade();

      void setNome(const char* n);
      const string getNome();

	  void setDepartamento(Departamento* d);
      void listeDepartamentos();

      vector<Departamento*>::iterator getDepartamentosBegin();
      vector<Departamento*>::iterator getDepartamentosEnd();
      int getId();

};

#endif
