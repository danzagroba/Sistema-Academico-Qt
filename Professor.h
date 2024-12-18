
#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_

#include "Pessoa.h"
#include "Universidade.h"

class Professor : public Pessoa
{
private:
   Universidade* UnivFiliado;
   Departamento* DptoFiliado;
   float         salario;
   float		 bolsa_projeto;
   
public:
    Professor(int diaNa, int mesNa, int anoNa, string nome = "");
    Professor();
    ~Professor();

	void inicializa();
    void setUnivFiliado(Universidade* u);
    void setDepartamento(Departamento* dep);
    void OndeTrabalho();
    void QualDepartamentoTrabalho();

	void setSalario(float s);
    float getSalario();

	void setBolsaProjeto(float bp);
	float getBolsaProjeto();

    void informaProventos();

};

#endif
