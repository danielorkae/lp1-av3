#include "entities/vendedor.hpp"

Vendedor::Vendedor()
{
    // Construtor padrão
}

Vendedor::Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
                   string estadoCivil, int qtdFilhos, float salario, string matricula,
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

float Vendedor::calcularSalario(int diasFaltas)
{
    float salarioBase = getSalario();

    // Descontar as faltas do salário base
    salarioBase -= (salarioBase / 30) * diasFaltas;

    // Adicionar a gratificação conforme o tipo de vendedor
    float gratificacao = 0.0f;
    if (tipoVendedor == 'A')
    {
        gratificacao = salarioBase * 0.25f;
    }
    else if (tipoVendedor == 'B')
    {
        gratificacao = salarioBase * 0.10f;
    }
    else if (tipoVendedor == 'C')
    {
        gratificacao = salarioBase * 0.05f;
    }

    salarioBase += gratificacao;

    // Adicionar o adicional por filho
    salarioBase += getQtdFilhos() * 100.0f;

    return salarioBase;
}

float Vendedor::calcularRescisao(Data desligamento)
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

void Vendedor::imprimirDados()
{
    cout << "=== Dados do vendedor ===" << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "CPF: " << getCpf() << endl;
    cout << "Data de nascimento: " << getDataNascimento().dia << "/" << getDataNascimento().mes << "/"
         << getDataNascimento().ano << endl;
    cout << "Endereço: " << getEnderecoPessoal().rua << ", " << getEnderecoPessoal().numero << ", "
         << getEnderecoPessoal().bairro << ", " << getEnderecoPessoal().cidade << ", "
         << getEnderecoPessoal().cep << endl;
    cout << "Estado civil: " << getEstadoCivil() << endl;
    cout << "Quantidade de filhos: " << getQtdFilhos() << endl;
    cout << "Salário: " << getSalario() << endl;
    cout << "Matrícula: " << getMatricula() << endl;
    cout << "Data de ingresso na empresa: " << getIngressoEmpresa().dia << "/" << getIngressoEmpresa().mes << "/"
         << getIngressoEmpresa().ano << endl;
    cout << "Tipo de vendedor: " << tipoVendedor << endl;
    cout << endl
         << endl;
}
