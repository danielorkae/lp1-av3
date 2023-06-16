#include "entities/asg.hpp"

Asg::Asg() : Pessoa(), Funcionario(), adicionalInsalubridade(0.0)
{
    // Construtor padrão
}

Asg::Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
         string estadoCivil, int qtdFilhos, float salario, string matricula,
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

float Asg::calcularRescisao(Data desligamento)
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

void Asg::imprimirDados()
{
    cout << "=== Dados do ASG ===" << endl;
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
    cout << "Adicional de insalubridade: " << adicionalInsalubridade << endl;
    cout << endl
         << endl;
}
