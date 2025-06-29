#pragma once
//#include <vcl.h>
#include "ListaUniversidades.h"
#include "ListaDepartamentos.h"
#include "ListaDisciplinas.h"
#include "ListaAlunos.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Principal
{
private:
    // Contadores para identificadores;
    int cont_idUniv;
    int cont_idAluno;
    int cont_idDisc;
    int cont_idDepart;
public:
    Principal();
    ~Principal();
    void CadDisciplina(const char* depart, const char* disci);
    void CadDepartamento(const char* univ, const char* depart);
    void CadUniversidade(const char* univ);
    void CadAluno(const char* disci, const char* aluno, int ra);
    void GravarTudo();
    void GravarUniversidades();
    void GravarDepartamentos();
    void GravarDisciplinas();
    void GravarAlunos();
    void RecuperarTudo();
    void RecuperarUniversidades();
    void RecuperarDepartamentos();
    void RecuperarDisciplinas();
    void RecuperarAlunos();

    list<Universidade*>::iterator	IteradorLUniversidades;
    list<Departamento*>::iterator	IteradorLDepartamentos;
    list<Disciplina*>::iterator		IteradorLDisciplinas;
    list<Aluno*>::iterator			IteradorLAlunos;

    // Listas
    ListaUniversidades LUniversidades;
    ListaDepartamentos LDepartamentos;
    ListaDisciplinas LDisciplinas;
    ListaAlunos LAlunos;
};
