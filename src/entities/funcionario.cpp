#include "entities/funcionario.hpp"

Funcionario::Funcionario()
{
    // Construtor padrão
}

Funcionario::Funcionario(std::string salario, std::string matricula, Data ingressoEmpresa)
    : salario(salario),
      matricula(matricula),
      ingressoEmpresa(ingressoEmpresa)
{
    // Construtor com todos os parâmetros
}

std::string Funcionario::getSalario() const
{
    return salario;
}

void Funcionario::setSalario(std::string salario)
{
    this->salario = salario;
}

std::string Funcionario::getMatricula() const
{
    return matricula;
}

void Funcionario::setMatricula(std::string matricula)
{
    this->matricula = matricula;
}

Data Funcionario::getIngressoEmpresa() const
{
    return ingressoEmpresa;
}

void Funcionario::setIngressoEmpresa(Data ingressoEmpresa)
{
    this->ingressoEmpresa = ingressoEmpresa;
}
