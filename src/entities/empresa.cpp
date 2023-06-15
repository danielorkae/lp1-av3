#include <iostream>
#include <fstream>
#include <filesystem>
#include "entities/empresa.hpp"

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

void Empresa::carregarFuncoes()
{
    try
    {
        // Obtém o diretório do arquivo executável
        std::filesystem::path currentPath = std::filesystem::current_path();

        // Constrói o caminho completo para o arquivo "funcoes.txt"
        std::filesystem::path filePath = currentPath / "data" / "funcoes.txt";

        // Verifica se o arquivo existe
        if (!std::filesystem::exists(filePath))
        {
            throw std::runtime_error("Erro: arquivo 'funcoes.txt' não encontrado.");
        }

        // Abre o arquivo em modo de leitura
        std::ifstream arquivo(filePath);
        if (!arquivo.is_open())
        {
            throw std::runtime_error("Erro ao abrir o arquivo 'funcoes.txt'.");
        }

        // Lê cada linha do arquivo e executa a função correspondente
        std::string linha;
        while (std::getline(arquivo, linha))
        {
            if (linha == "carregarEmpresa()")
            {
                carregarEmpresa();
            }
            else if (linha == "carregarAsg()")
            {
                carregarAsg();
            }
            else if (linha == "carregarVendedor()")
            {
                carregarVendedor();
            }
            else if (linha == "carregarGerente()")
            {
                carregarGerente();
            }
            else if (linha == "carregaDono()")
            {
                carregaDono();
            }
            else if (linha == "imprimeAsgs()")
            {
                imprimeAsgs();
            }
            else if (linha == "imprimeVendedores()")
            {
                imprimeVendedores();
            }
            else if (linha == "imprimeGerentes()")
            {
                imprimeGerentes();
            }
            else if (linha == "imprimeDono()")
            {
                imprimeDono();
            }
            else if (linha.find("buscaFuncionario()") == 0)
            {
                // Extrai a matrícula do funcionário da próxima linha
                std::getline(arquivo, linha);
                int matricula = std::stoi(linha);
                buscaFuncionario(matricula);
            }
            else if (linha.find("calculaSalarioFuncionario()") == 0)
            {
                // Extrai a matrícula do funcionário da próxima linha
                std::getline(arquivo, linha);
                int matricula = std::stoi(linha);
                calculaSalarioFuncionario(matricula);
            }
            else if (linha == "calculaTodoOsSalarios()")
            {
                calculaTodoOsSalarios();
            }
            else if (linha.find("calcularRecisao()") == 0)
            {
                // Extrai a matrícula, ano, mês e dia da próxima linha
                std::string matriculaStr, anoStr, mesStr, diaStr;
                std::getline(arquivo, matriculaStr);
                std::getline(arquivo, anoStr);
                std::getline(arquivo, mesStr);
                std::getline(arquivo, diaStr);
                int matricula = std::stoi(matriculaStr);
                int ano = std::stoi(anoStr);
                int mes = std::stoi(mesStr);
                int dia = std::stoi(diaStr);
                Data desligamento{ano, mes, dia};
                calcularRecisao(matricula, desligamento);
            }
            else
            {
                throw std::runtime_error("Erro: função desconhecida: " + linha);
            }
        }

        // Fecha o arquivo
        arquivo.close();
    }
    catch (const std::exception &ex)
    {
        std::cout << "Erro ao executar as funções: " << ex.what() << std::endl;
    }
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
