#include <iostream>
#include <fstream>
#include <sstream>
#include "entities/empresa.hpp"

// Implementação dos construtores
Empresa::Empresa()
    : faturamentoMensal(0.0), nomeEmpresa(""), cnpj(""), dono(), asgs(), vendedores(), gerentes() {}

Empresa::Empresa(float faturamentoMensal, const std::string &nomeEmpresa, const std::string &cnpj, const Pessoa &dono)
    : faturamentoMensal(faturamentoMensal), nomeEmpresa(nomeEmpresa), cnpj(cnpj), dono(dono), asgs(), vendedores(), gerentes() {}

// Implementação dos getters e setters
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

Pessoa Empresa::getDono() const
{
    return dono;
}

void Empresa::setDono(const Pessoa &dono)
{
    this->dono = dono;
}

// Implementação dos métodos
bool Empresa::carregarDados(const std::string &nomeArquivo)
{
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo)
    {
        std::cout << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return false;
    }

    // TODO: Implementar a leitura dos dados do arquivo e preencher os vetores de ASGs, vendedores e gerentes

    arquivo.close();
    return true;
}

void Empresa::imprimirAtributos() const
{
    std::cout << "Nome da empresa: " << nomeEmpresa << std::endl;
    std::cout << "CNPJ: " << cnpj << std::endl;
    std::cout << "Faturamento mensal: R$" << faturamentoMensal << std::endl;
    std::cout << "Dono da empresa: " << dono.getNome() << std::endl;

    // TODO: Imprimir os atributos dos ASGs, vendedores e gerentes
}

Funcionario *Empresa::buscarFuncionarioPorMatricula(const std::string &matricula)
{
    for (auto &asg : asgs)
    {
        if (asg.getMatricula() == matricula)
        {
            return &asg;
        }
    }

    for (auto &vendedor : vendedores)
    {
        if (vendedor.getMatricula() == matricula)
        {
            return &vendedor;
        }
    }

    for (auto &gerente : gerentes)
    {
        if (gerente.getMatricula() == matricula)
        {
            return &gerente;
        }
    }

    return nullptr; // Funcionário não encontrado
}

void Empresa::calcularSalarios()
{
    // TODO: Calcular salários dos ASGs

    // TODO: Calcular salários dos vendedores

    // TODO: Calcular salários dos gerentes
}

void Empresa::calcularRecisoes(const Data &desligamento)
{
    // TODO: Calcular rescisões dos ASGs

    // TODO: Calcular rescisões dos vendedores

    // TODO: Calcular rescisões dos gerentes
}
