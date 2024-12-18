
#ifndef _ESTAGIARIO_H_
#define _ESTAGIARIO_H_

#include "Aluno.h"

class Estagiario : public Aluno
//class Estagiario : protected Aluno
{
private:
protected:
  float BolsaEstudo;

public:
  Estagiario (int diaNa, int mesNa, int anoNa, string nome = "");
  Estagiario();
  ~Estagiario();

  void inicializa();
  void setBolsaEstudo(float b);
  float getBolsaEstudo();

  void informaProventos();

  // void setNome(char *n) { Pessoa::setNome(n); }

};
#endif
