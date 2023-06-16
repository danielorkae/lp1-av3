#include "entities/gerente.hpp"

Gerente::Gerente() : participacaoLucros(0.0f)
{
}

Gerente::Gerente(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal,
                 std::string estadoCivil, int qtdFilhos, float salario, std::string matricula,
                 Data ingressoEmpresa, float participacaoLucros)
    : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
      Funcionario(salario, matricula, ingressoEmpresa),
      participacaoLucros(participacaoLucros)
{
}

float Gerente::getParticipacaoLucros() const
{
    return participacaoLucros;
}

void Gerente::setParticipacaoLucros(float participacaoLucros)
{
    this->participacaoLucros = participacaoLucros;
}

float Gerente::calcularSalario(int diasFaltas)
{
    float salarioBase = getSalario();

    // Descontar as faltas do salário base
    salarioBase -= (salarioBase / 30) * diasFaltas;

    // Somar a participação nos lucros
    salarioBase += participacaoLucros;

    // Adicionar o adicional por filho
    salarioBase += getQtdFilhos() * 100.0f;

    return salarioBase;
}

float Gerente::calcularRescisao(Data desligamento)
{
    Data dataIngresso = getIngressoEmpresa();

    // Converter a data de ingresso para fração de ano
    float fracaoAnoIngresso = static_cast<float>(dataIngresso.dia) / 365.0f;
    fracaoAnoIngresso += static_cast<float>(dataIngresso.mes) / 12.0f;
    fracaoAnoIngresso += static_cast<float>(dataIngresso.ano);

    // Converter a data de desligamento para fração de ano
    float fracaoAnoDesligamento = static_cast<float>(desligamento.dia) / 365.0f;
    fracaoAnoDesligamento += static_cast<float>(desligamento.mes) / 12.0f;
    fracaoAnoDesligamento += static_cast<float>(desligamento.ano);

    // Calcular o tempo de trabalho em anos
    float tempoTrabalho = fracaoAnoDesligamento - fracaoAnoIngresso;

    // Calcular a rescisão considerando o salário base por ano trabalhado
    float salarioBaseAnual = getSalario();
    float salarioRescisao = salarioBaseAnual * tempoTrabalho;

    return salarioRescisao;
}
