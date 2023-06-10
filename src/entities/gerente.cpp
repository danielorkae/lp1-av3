#include "entities/gerente.hpp"

Gerente::Gerente() : Pessoa(), Funcionario(), participacaoLucros(0.0f) {}

Gerente::Gerente(const std::string &nome, const std::string &cpf, const Data &dataNascimento, const Endereco &enderecoPessoal,
                 const std::string &estadoCivil, int qtdFilhos, const std::string &salario, const std::string &matricula,
                 const Data &ingressoEmpresa, float participacaoLucros)
    : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
      Funcionario(salario, matricula, ingressoEmpresa),
      participacaoLucros(participacaoLucros) {}

float Gerente::getParticipacaoLucros() const
{
    return participacaoLucros;
}

void Gerente::setParticipacaoLucros(float participacaoLucros)
{
    this->participacaoLucros = participacaoLucros;
}

double Gerente::calcularSalario(int diasFaltas)
{
    double salario = 0;
    // TODO: Ver regra de salário do gernete.
    return salario;
}

double Gerente::calcularRecisao(const Data &desligamento)
{
    double recisao = 0;
    // TODO: Ver regra de recisão do gerente.
    return recisao;
}
