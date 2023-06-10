#include "entities/asg.hpp"

Asg::Asg() : Pessoa(), Funcionario(), adicionalInsalubridade(0.0)
{
    // Construtor padrão
}

Asg::Asg(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal,
         std::string estadoCivil, int qtdFilhos, std::string salario, std::string matricula,
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

double Asg::calcularSalario(int diasFaltas)
{
    // Cálculo do salário do ASG considerando os dias de faltas
    double salarioBase = std::stod(getSalario());
    double salarioDia = salarioBase / 30.0;
    double descontoFaltas = salarioDia * diasFaltas;
    double salarioFinal = salarioBase - descontoFaltas + adicionalInsalubridade;

    return salarioFinal;
}

double Asg::calcularRecisao(Data desligamento)
{
    // Cálculo da rescisão do ASG com base na data de desligamento
    // TODO: Ver cálculo da rescisão do ASG

    return 0.0;
}
