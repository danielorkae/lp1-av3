#include "entities/vendedor.hpp"

Vendedor::Vendedor() : Pessoa(), Funcionario(), tipoVendedor(' ')
{
    // Construtor padrão
}

Vendedor::Vendedor(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal,
                   std::string estadoCivil, int qtdFilhos, std::string salario, std::string matricula,
                   Data ingressoEmpresa, char tipoVendedor)
    : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
      Funcionario(salario, matricula, ingressoEmpresa),
      tipoVendedor(tipoVendedor)
{
    // Construtor com todos os parâmetros
}

char Vendedor::getTipoVendedor() const
{
    return tipoVendedor;
}

void Vendedor::setTipoVendedor(char tipoVendedor)
{
    this->tipoVendedor = tipoVendedor;
}

double Vendedor::calcularSalario(int diasFaltas)
{
    // Cálculo do salário do Vendedor considerando os dias de faltas
    double salarioBase = std::stod(getSalario());
    double salarioDia = salarioBase / 30.0;
    double descontoFaltas = salarioDia * diasFaltas;
    double salarioFinal = salarioBase - descontoFaltas;

    // TODO: Adicionar regras do vendedor

    return salarioFinal;
}

double Vendedor::calcularRecisao(Data desligamento)
{
    // Cálculo da rescisão do Vendedor com base na data de desligamento
    // TODO: Ver cálculo da rescisão do ASG

    return 0.0;
}
