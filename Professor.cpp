#include "stdafx.h"
#include "Professor.h"

Professor::Professor(int diaNa, int mesNa, int anoNa, string nome):
Pessoa(diaNa, mesNa, anoNa, nome)
{
	inicializa();
}

Professor::Professor()
:Pessoa()
{
	inicializa();
}

Professor::~Professor()
{
	inicializa();
}

void Professor::setUnivFiliado(Universidade* u)
{
     UnivFiliado = u;
}

void Professor::setDepartamento(Departamento* dep)
{
    DptoFiliado = dep;
}


void Professor::OndeTrabalho()
{
     //printf("\n %s trabalha para a %s \n", nomeP, UnivFiliado->getNome());
	 cout << endl << nomeP << " trabalha para a " << UnivFiliado->getNome() << "." << endl;
}

void Professor::QualDepartamentoTrabalho()
{
     /*printf("\n %s trabalha para a %s no departamento de % s \n",
                nomeP,
                UnivFiliado->getNome(),
                DptoFiliado->getNome()
            );  */

	 cout << endl << " "
		  << nomeP
		  << " trabalha para a " 
		  << UnivFiliado->getNome()
		  << " no departamento de "
		  <<  DptoFiliado->getNome()
		  << "." << endl;
}

void Professor::setSalario(float s)
{
	salario = s;
}

float Professor::getSalario()
{
	return salario;
}

void Professor::setBolsaProjeto(float bp)
{
	bolsa_projeto = bp;
}

float Professor::getBolsaProjeto()
{
	return bolsa_projeto;
}


void Professor::inicializa()
{
  salario = 0;
  bolsa_projeto = 0;
}

void Professor::informaProventos ( )
{
    cout << "O valor da salário do Prof. "  << nomeP
         << "  é " <<  (salario+bolsa_projeto) << endl;
}
