#ifndef _ALUNO_H_
#define _ALUNO_H_

#include "Departamento.h"
#include "Pessoa.h"

class Aluno : public Pessoa
{ 
 private:
    int				id;
    int				RA;
    //char			nome[150];
    Departamento*	DeptoAssociado;

public:
    Aluno (int diaNa, int mesNa, int anoNa, string nome = "");
    Aluno ( int i );
	Aluno ( );
    ~Aluno	( );

    void setRA(int ra);
    int getRA();

    void setDepartamento ( Departamento* d );
    Departamento* getDepartamento ( );
	
	void setId(int i);
	int getId();
};
	
/*class Int
{
	int valor;
public:
	int operator ++(int ghost)
	{
		valor++;
		return valor;
	}

	operator int()
	{
		return valor;
	}
	Int(int v) 
	{ 
		valor = v; 
	}

};*/

#endif
