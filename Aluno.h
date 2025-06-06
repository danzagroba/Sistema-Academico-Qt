#ifndef _ALUNO_H_
#define _ALUNO_H_

#include "Departamento.h"

class Aluno
{
private:

    int RA;
    Disciplina* pDiscAssociada;
    int id;
    string nome;

public:

    Aluno(int i);
    ~Aluno();

    void setNome(const char* n);
    string getNome();

    void setRA(int ra);
    int getRA();

    void setDisciplina(Disciplina* pd);
    Disciplina* getDisciplina();

    void setId(int i);
    int getId();
};
	

#endif
