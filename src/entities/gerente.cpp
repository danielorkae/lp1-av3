#include "entities/gerente.hpp"

Gerente::Gerente() : participacaoLucros(0.0f)
{
}

Gerente::Gerente(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
                 string estadoCivil, int qtdFilhos, float salario, string matricula,
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

void Gerente::imprimirDados()
{
    cout << "=== Dados do Gerente ===" << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CPF: " << getCpf() << endl;
    cout << "Endereço: " << getEnderecoPessoal().rua << ", " << getEnderecoPessoal().numero << ", "
         << getEnderecoPessoal().bairro << ", " << getEnderecoPessoal().cidade << ", "
         << getEnderecoPessoal().cep << endl;
    cout << "Data de nascimento: " << getDataNascimento().dia << "/" << getDataNascimento().mes << "/"
         << getDataNascimento().ano << endl;
    cout << "Estado civil: " << getEstadoCivil() << endl;
    cout << "Quantidade de filhos: " << getQtdFilhos() << endl;
    cout << "Salário: " << getSalario() << endl;
    cout << "Matrícula: " << getMatricula() << endl;
    cout << "Data de ingresso na empresa: " << getIngressoEmpresa().dia << "/" << getIngressoEmpresa().mes << "/"
         << getIngressoEmpresa().ano << endl;
    cout << "Participação nos lucros: " << getParticipacaoLucros() << endl;
    cout << endl
         << endl;
}
