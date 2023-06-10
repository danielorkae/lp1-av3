#include "domain/pessoa.hpp"

Pessoa::Pessoa()
{
    // Construtor padrão
}

Pessoa::Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal,
               std::string estadoCivil, int qtdFilhos)
    : nome(nome),
      cpf(cpf),
      dataNascimento(dataNascimento),
      enderecoPessoal(enderecoPessoal),
      estadoCivil(estadoCivil),
      qtdFilhos(qtdFilhos)
{
    // Construtor com todos os parâmetros
}

std::string Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(std::string nome)
{
    this->nome = nome;
}

std::string Pessoa::getCpf() const
{
    return cpf;
}

void Pessoa::setCpf(std::string cpf)
{
    this->cpf = cpf;
}

Data Pessoa::getDataNascimento() const
{
    return dataNascimento;
}

void Pessoa::setDataNascimento(Data dataNascimento)
{
    this->dataNascimento = dataNascimento;
}

Endereco Pessoa::getEnderecoPessoal() const
{
    return enderecoPessoal;
}

void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal)
{
    this->enderecoPessoal = enderecoPessoal;
}

std::string Pessoa::getEstadoCivil() const
{
    return estadoCivil;
}

void Pessoa::setEstadoCivil(std::string estadoCivil)
{
    this->estadoCivil = estadoCivil;
}

int Pessoa::getQtdFilhos() const
{
    return qtdFilhos;
}

void Pessoa::setQtdFilhos(int qtdFilhos)
{
    this->qtdFilhos = qtdFilhos;
}
