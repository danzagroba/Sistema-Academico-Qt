// Prof. Dr. Jean M. Simao - DAINF/UTFPR Curitiba-Central
// Sistema original por: Monitor Vitor C. M. Correa
// Modificado e expandido por: Daniel I. Zagroba (26/02/2025)

#include "Principal.h"
#include <QMessageBox>
#include <string.h>
#include <iostream>
#include <fstream>
#include <filesystem>
using std::cout;
using std::endl;
using std::cin;


Principal::Principal() :
    // contadores da quantidade de objetos existentes
    cont_idUniv(0),
    cont_idAluno(0),
    cont_idDisc(0),
    cont_idDepart(0)
{

}
Principal::~Principal() {

}

// funcoes para cadastro de novos objetos
void Principal::CadUniversidade(const char* univ)
{
    if(univ != NULL && strcmp(univ, "") != 0)
    {
        if(LUniversidades.localizar(univ) == NULL)
        {
            Universidade* puniv = new Universidade(cont_idUniv++);
            puniv->setNome(univ);
            LUniversidades.incluaUniversidade(puniv);
            QMessageBox messageBox;
            messageBox.information(0,"Sucesso","Universidade cadastrada!");
            messageBox.setFixedSize(500,200);
        }
        else
        {
            // Mensagem de aviso
            QMessageBox messageBox;
            messageBox.warning(0,"Erro","Essa universidade ja esta cadastrada");
            messageBox.setFixedSize(500,200);
        }
    }
    else
    {
        // Mensagem de aviso
        QMessageBox messageBox;
        messageBox.warning(0,"Erro","O campo da universidade esta vazio");
        messageBox.setFixedSize(500,200);
    }
}

void Principal::CadDepartamento(const char* univ, const char* depart)
{
    if (univ != NULL && std::strcmp(univ, "") != 0)
    {
        if(depart != NULL && std::strcmp(depart, "") != 0)
        {
            Universidade* puniv = LUniversidades.localizar(univ);
            if(puniv != NULL)
            {
                if(LDepartamentos.localizar(depart) == NULL)
                {
                    Departamento* pdepart = new Departamento(cont_idDepart++);
                    pdepart->setNome(depart);
                    puniv->setDepartamento(pdepart);
                    LDepartamentos.incluaDepartamento(pdepart);
                    QMessageBox messageBox;
                    messageBox.information(0,"Sucesso","Departamento cadastrado!");
                    messageBox.setFixedSize(500,200);
                }
                else
                {
                    // Mensagem de aviso
                    QMessageBox messageBox;
                    messageBox.warning(0,"Erro","Esse departamente ja foi cadastrado");
                    messageBox.setFixedSize(500,200);
                }
            }
            else
            {
                // Mensagem de aviso
                QMessageBox messageBox;
                messageBox.warning(0,"Erro","A universidade nao esta cadastrada");
                messageBox.setFixedSize(500,200);
            }
        }
        else
        {
            // Mensagem de aviso
            QMessageBox messageBox;
            messageBox.warning(0,"Erro","O campo de departamento esta vazio");
            messageBox.setFixedSize(500,200);
        }
    }
    else
    {
        // Mensagem de aviso
        QMessageBox messageBox;
        messageBox.warning(0,"Erro","O campo da universidade esta vazio");
        messageBox.setFixedSize(500,200);
    }
}

void Principal::CadDisciplina(const char* depart, const char* disci) {
    if (depart != NULL && std::strcmp(depart, "") != 0)
    {
        if(disci != NULL && std::strcmp(disci, "") != 0)
        {
            Departamento* pdepart = LDepartamentos.localizar(depart);
            if(pdepart != NULL)
            {
                if(LDisciplinas.localizar(disci) == NULL)
                {
                    Disciplina* pdisc = new Disciplina(cont_idDisc++);
                    pdisc->setNome(disci);
                    pdepart->setDisciplina(pdisc);
                    LDisciplinas.incluaDisciplina(pdisc);
                    QMessageBox messageBox;
                    messageBox.information(0,"Sucesso","Disciplina cadastrada!");
                    messageBox.setFixedSize(500,200);
                }
                else
                {
                    // Mensagem de aviso
                    QMessageBox messageBox;
                    messageBox.warning(0,"Erro","Essa disciplina ja esta cadastrada");
                    messageBox.setFixedSize(500,200);
                }
            }
            else
            {
                // Mensagem de aviso
                QMessageBox messageBox;
                messageBox.warning(0,"Erro","O departamento nao esta cadastrado");
                messageBox.setFixedSize(500,200);
            }
        }
        else
        {
            // Mensagem de aviso
            QMessageBox messageBox;
            messageBox.warning(0,"Erro","O campo da disciplina esta vazio");
            messageBox.setFixedSize(500,200);
        }
    }
    else
    {
        // Mensagem de aviso
        QMessageBox messageBox;
        messageBox.warning(0,"Erro","O campo de departamento esta vazio");
        messageBox.setFixedSize(500,200);
    }
}

void Principal::CadAluno(const char* disci, const char* aluno, int ra)
{
    Aluno* pal;
    if(disci != NULL && std::strcmp(disci, "") != 0)
    {
        if(aluno != NULL && std::strcmp(aluno, "") != 0)
        {
            if(ra != 0)
            {
                Disciplina* pdisc = LDisciplinas.localizar(disci);
                if(pdisc != NULL)
                {
                    if(LAlunos.localizar(ra)== NULL)
                    {
                        pal = new Aluno(cont_idAluno++);
                        pal->setNome(aluno);
                        pal->setRA(ra);
                        pdisc->setAluno(pal);
                        LAlunos.incluaAluno(pal);
                        QMessageBox messageBox;
                        messageBox.information(0,"Sucesso","Aluno cadastrado!");
                        messageBox.setFixedSize(500,200);
                    }
                    else
                    {
                        // Mensagem de aviso
                        QMessageBox messageBox;
                        messageBox.warning(0,"Erro","Ja existe aluno com tal RA");
                        messageBox.setFixedSize(500,200);
                    }
                }
                else
                {
                    // Mensagem de aviso
                    QMessageBox messageBox;
                    messageBox.warning(0,"Erro","A disciplina nao esta cadastrada");
                    messageBox.setFixedSize(500,200);
                }
            }
            else
            {
                // Mensagem de aviso
                QMessageBox messageBox;
                messageBox.warning(0,"Erro","RA invalido");
                messageBox.setFixedSize(500,200);
            }
        }
        else
        {
            // Mensagem de aviso
            QMessageBox messageBox;
            messageBox.warning(0,"Erro","O campo de aluno esta vazio");
            messageBox.setFixedSize(500,200);
        }
    }
    else
    {
        // Mensagem de aviso
        QMessageBox messageBox;
        messageBox.warning(0,"Erro", "O campo da disciplina esta vazio");
        messageBox.setFixedSize(500,200);
    }
}


// funcoes para a gravacao de objetos em arquivo
void Principal::GravarTudo() {
    GravarUniversidades();
    GravarDepartamentos();
    GravarDisciplinas();
    GravarAlunos();
    QMessageBox messageBox;
    messageBox.information(0,"Sucesso", "Todo sistema academico salvo!");
    messageBox.setFixedSize(500,200);
}
void Principal::GravarUniversidades() {

    std::ofstream out("universidades.dat", std::ios::out);
    if (out.is_open()) {
        IteradorLUniversidades = LUniversidades.getBegin();

        while (IteradorLUniversidades != LUniversidades.getEnd()) {
            std::string nome = ((*IteradorLUniversidades))->getNome();
            int id = ((*IteradorLUniversidades))->getId();
            out << nome << " " << id << "\n";
            IteradorLUniversidades++;
        }

        out.close();
    } else {
        QMessageBox::warning(0, "Erro", "Erro ao abrir arquivo");
    }
}
void Principal::GravarDepartamentos() {
    std::ofstream out("departamentos.dat", std::ios::out);

    if (out.is_open()) {
        std::list<Departamento*>::iterator IteradorLDepartamentos = LDepartamentos.getBegin();
        while (IteradorLDepartamentos!= LDepartamentos.getEnd()) {
            Departamento* aux = (*(IteradorLDepartamentos));
            std::string str(aux->getNome() + std::string(" ") + std::to_string(aux->getId()) + std::string(" ") + aux->getUniversidade()->getNome());
            out << str << endl;
            IteradorLDepartamentos++;
        }

        out.close();
    }
    else
    {
        QMessageBox::warning(0, "Erro", "Erro ao abrir arquivo");
    }
}
void Principal::GravarDisciplinas() {
    std::ofstream out("disciplinas.dat", std::ios::out);
    if (out.is_open()) {
        list<Disciplina*>::iterator IteradorLDisciplinas = LDisciplinas.getBegin();
        while (IteradorLDisciplinas!= LDisciplinas.getEnd()) {
            Disciplina* aux = (*(IteradorLDisciplinas));
            std::string str(aux->getNome() + std::string(" ") + std::to_string(aux->getId()) + std::string(" ") + aux->getDepartamento()->getNome());
            out << str << endl;
            IteradorLDisciplinas++;
        }
        out.close();
    }
    else
    {
        QMessageBox::warning(0, "Erro", "Erro ao abrir arquivo");
    }
}
void Principal::GravarAlunos() {
    std::ofstream out("alunos.dat", std::ios::out);
    if (out) {
        IteradorLAlunos = LAlunos.getBegin();
        while (IteradorLAlunos!= LAlunos.getEnd()) {
            Aluno* aux = (*(IteradorLAlunos));
            std::string str(aux->getNome() + std::string(" ") + std::to_string(aux->getRA()) + std::string(" ") + std::to_string(aux->getId()) + std::string(" ") + aux->getDisciplina()->getNome());
            out << str << endl;
            IteradorLAlunos++;
        }

        out.close();
    }
    else
    {
        QMessageBox::warning(0, "Erro", "Erro ao abrir arquivo");
    }
}
// funcoes para a recuperacao de objetos em arquivo
void Principal::RecuperarTudo() {
    RecuperarUniversidades();
    RecuperarDepartamentos();
    RecuperarDisciplinas();
    RecuperarAlunos();
    QMessageBox::information(0,"Sucesso", "Todo sistema academico recuperado!");

}
void Principal::RecuperarUniversidades() {
    std::ifstream in("universidades.dat", std::ios::in);
    if (in.is_open()) {
        char nome[150];
        int id;
        while (in >> nome >> id) {
            Universidade* puniv = new Universidade(id);
            puniv->setNome(nome);
            LUniversidades.incluaUniversidade(puniv);
            cont_idUniv++;
        }
        in.close();
    }
    else
    {
        QMessageBox::warning(0, "Erro", "Erro ao abrir arquivo");
    }
}
void Principal::RecuperarDepartamentos() {
    std::ifstream in("departamentos.dat", std::ios::in);
    if (in.is_open()) {
        char nome[150], nomeuniv[150];
        int id;
        while (in >> nome >> id >> nomeuniv) {
            Universidade* puniv = LUniversidades.localizar(nomeuniv);
            if (puniv) {
                Departamento* pdep = new Departamento(id);
                pdep->setNome(nome);
                puniv->setDepartamento(pdep);
                LDepartamentos.incluaDepartamento(pdep);
                cont_idDepart++;
            }
        }
        in.close();
    }
    else
    {
        QMessageBox::warning(0, "Erro", "Erro ao abrir arquivo");
    }
}
void Principal::RecuperarDisciplinas() {
    std::ifstream in("disciplinas.dat", std::ios::in);
    if (in.is_open()) {
        char nome[150], nomedep[150];
        int id;
        while (in >> nome >> id >> nomedep) {
            Departamento* pdep = LDepartamentos.localizar(nomedep);
            if (pdep) {
                Disciplina* pdisc = new Disciplina(id);
                pdisc->setNome(nome);
                pdep->setDisciplina(pdisc);
                LDisciplinas.incluaDisciplina(pdisc);
                cont_idDisc++;
            }
        }
        in.close();
    }
    else
    {
        QMessageBox::warning(0, "Erro", "Erro ao abrir arquivo");
    }
}
void Principal::RecuperarAlunos() {
    std::ifstream in("alunos.dat", std::ios::in);
    if (in.is_open()) {
        char nome[150], nomedisc[150];
        int id, RA;
        while (in >> nome >> RA >> id >> nomedisc) {
            Disciplina* pdisc = LDisciplinas.localizar(nomedisc);
            if (pdisc) {
                Aluno* pal = new Aluno(id);
                pal->setNome(nome);
                pal->setRA(RA);
                pdisc->setAluno(pal);
                LAlunos.incluaAluno(pal);
                cont_idAluno++;
            }
        }
        in.close();
    }
    else
    {
        QMessageBox::warning(0, "Erro", "Erro ao abrir arquivo");
    }
}
