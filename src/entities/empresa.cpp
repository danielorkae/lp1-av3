#include <iostream>
#include <fstream>
#include "empresa.hpp"

Empresa::Empresa()
    : faturamentoMensal(0.0f) {}

Empresa::Empresa(const std::string &nomeEmpresa, const std::string &cnpj, float faturamentoMensal)
    : nomeEmpresa(nomeEmpresa), cnpj(cnpj), faturamentoMensal(faturamentoMensal) {}

float Empresa::getFaturamentoMensal() const
{
    return faturamentoMensal;
}

void Empresa::setFaturamentoMensal(float faturamentoMensal)
{
    this->faturamentoMensal = faturamentoMensal;
}

std::string Empresa::getNomeEmpresa() const
{
    return nomeEmpresa;
}

void Empresa::setNomeEmpresa(const std::string &nomeEmpresa)
{
    this->nomeEmpresa = nomeEmpresa;
}

std::string Empresa::getCnpj() const
{
    return cnpj;
}

void Empresa::setCnpj(const std::string &cnpj)
{
    this->cnpj = cnpj;
}

const Pessoa &Empresa::getDono() const
{
    return dono;
}

const std::vector<Asg> &Empresa::getAsgs() const
{
    return asgs;
}

const std::vector<Vendedor> &Empresa::getVendedores() const
{
    return vendedores;
}

const std::vector<Gerente> &Empresa::getGerentes() const
{
    return gerentes;
}

void Empresa::carregaFuncoes()
{
    // TODO: Implementar a leitura do arquivo "funcoes.txt" e chamar cada função presente nas linhas do arquivo.
}

void Empresa::carregarEmpresa()
{
    // TODO: Implementar a leitura do arquivo "empresa.txt" e carregar os dados da empresa.
}

void Empresa::carregarAsg()
{
    // TODO: Implementar a leitura do arquivo "asg.txt" e carregar os dados dos ASGs.
}

void Empresa::carregarVendedor()
{
    // TODO: Implementar a leitura do arquivo "vendedor.txt" e carregar os dados dos Vendedores.
}

void Empresa::carregarGerente()
{
    // TODO: Implementar a leitura do arquivo "gerente.txt" e carregar os dados dos Gerentes.
}

void Empresa::carregaDono()
{
    // TODO: Implementar a leitura do arquivo "dono.txt" e carregar os dados do dono.
}

void Empresa::imprimeAsgs()
{
    // TODO: Implementar a função para imprimir os atributos de todos os ASGs.
}

void Empresa::imprimeVendedores()
{
    // TODO: Implementar a função para imprimir os atributos de todos os Vendedores.
}

void Empresa::imprimeGerentes()
{
    // TODO: Implementar a função para imprimir os atributos de todos os Gerentes.
}

void Empresa::imprimeDono()
{
    // TODO: Implementar a função para imprimir os atributos do dono.
}

void Empresa::buscaFuncionario(int matricula)
{
    // TODO: Implementar a função para buscar um funcionário pelo número de matrícula.
    // Caso não encontre, imprimir a mensagem "Funcionário não encontrado no sistema".
}

void Empresa::calculaSalarioFuncionario(int matricula)
{
    // TODO: Implementar a função para calcular o salário de um funcionário pelo número de matrícula.
    // Caso não encontre, imprimir a mensagem "Funcionário não encontrado no sistema".
}

void Empresa::calculaTodoOsSalarios()
{
    // TODO: Implementar a função para calcular os salários de todos os funcionários e salvar os resultados em um arquivo.
    // Os resultados também devem ser mostrados no console.
}

void Empresa::calcularRecisao(int matricula, const Data &desligamento)
{
    // TODO: Implementar a função para calcular o valor da rescisão de um funcionário pelo número de matrícula e data de desligamento.
    // Caso não encontre, imprimir a mensagem "Funcionário não encontrado no sistema".
}
