#include "entities/asg.hpp"

Asg::Asg() : Pessoa(), Funcionario(), adicionalInsalubridade(0.0)
{
    // Construtor padrão
}

Asg::Asg(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal,
         std::string estadoCivil, int qtdFilhos, float salario, std::string matricula,
         Data ingressoEmpresa, float adicionalInsalubridade)
    : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
      Funcionario(salario, matricula, ingressoEmpresa),
      adicionalInsalubridade(adicionalInsalubridade)
{
    // Construtor com todos os parâmetros
}

float Asg::getAdicionalInsalubridade() const
{
    return adicionalInsalubridade;
}

void Asg::setAdicionalInsalubridade(float adicionalInsalubridade)
{
    this->adicionalInsalubridade = adicionalInsalubridade;
}

float Asg::calcularSalario(int diasFaltas)
{
    // Cálculo do salário do ASG considerando os dias de faltas, adicional de insalubridade e adicional por filho
    float salarioBase = getSalario();
    float salarioDescontado = salarioBase - (salarioBase / 30) * diasFaltas;
    float salarioFinal = salarioDescontado + adicionalInsalubridade + (getQtdFilhos() * 100.0f);
    return salarioFinal;
}

float Asg::calcularRecisao(Data desligamento)
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
    float salarioRecisao = salarioBaseAnual * tempoTrabalho;

    return salarioRecisao;
}
