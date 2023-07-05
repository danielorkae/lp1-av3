#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>
#include "pessoa.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

using namespace std;

/**
 * @brief Classe que representa uma Empresa.
 */
class Empresa
{
private:
    float faturamentoMensal;     /**< Faturamento mensal da empresa */
    string nomeEmpresa;          /**< Nome da empresa */
    string cnpj;                 /**< CNPJ da empresa */
    Pessoa dono;                 /**< Dono da empresa */
    vector<Asg> asgs;            /**< Vetor de ASGs */
    vector<Vendedor> vendedores; /**< Vetor de Vendedores */
    vector<Gerente> gerentes;    /**< Vetor de Gerentes */

public:
    /**
     * @brief rutor padrão.
     */
    Empresa();

    /**
     * @brief rutor que inicializa uma empresa com os atributos fornecidos.
     * @param nomeEmpresa O nome da empresa.
     * @param cnpj O CNPJ da empresa.
     * @param faturamentoMensal O faturamento mensal da empresa.
     */
    Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal);

    // Métodos de acesso

    /**
     * @brief Obtém o faturamento mensal da empresa.
     * @return O faturamento mensal da empresa.
     */
    float getFaturamentoMensal();

    /**
     * @brief Define o faturamento mensal da empresa.
     * @param faturamentoMensal O faturamento mensal da empresa.
     */
    void setFaturamentoMensal(float faturamentoMensal);

    /**
     * @brief Obtém o nome da empresa.
     * @return O nome da empresa.
     */
    string getNomeEmpresa();

    /**
     * @brief Define o nome da empresa.
     * @param nomeEmpresa O nome da empresa.
     */
    void setNomeEmpresa(string nomeEmpresa);

    /**
     * @brief Obtém o CNPJ da empresa.
     * @return O CNPJ da empresa.
     */
    string getCnpj();

    /**
     * @brief Define o CNPJ da empresa.
     * @param cnpj O CNPJ da empresa.
     */
    void setCnpj(string cnpj);

    /**
     * @brief Obtém o dono da empresa.
     * @return O dono da empresa.
     */
    Pessoa &getDono();

    /**
     * @brief Obtém o vetor de ASGs da empresa.
     * @return O vetor de ASGs da empresa.
     */
    vector<Asg> &getAsgs();

    /**
     * @brief Obtém o vetor de Vendedores da empresa.
     * @return O vetor de Vendedores da empresa.
     */
    vector<Vendedor> &getVendedores();

    /**
     * @brief Obtém o vetor de Gerentes da empresa.
     * @return O vetor de Gerentes da empresa.
     */
    vector<Gerente> &getGerentes();

    // Métodos

    /**
     * @brief Carrega as funções a partir do arquivo "funcoes.txt".
     */
    void carregarFuncoes();

    /**
     * @brief Carrega os dados da empresa a partir do arquivo "empresa.txt".
     */
    void carregarEmpresa();

    /**
     * @brief Carrega os dados dos ASGs a partir do arquivo "asg.txt".
     */
    void carregarAsg();

    /**
     * @brief Carrega os dados dos Vendedores a partir do arquivo "vendedor.txt".
     */
    void carregarVendedor();

    /**
     * @brief Carrega os dados dos Gerentes a partir do arquivo "gerente.txt".
     */
    void carregarGerente();

    /**
     * @brief Carrega os dados do dono a partir do arquivo "dono.txt".
     */
    void carregaDono();

    /**
     * @brief Salva os dados dos ASGs no arquivo "asg.txt".
     */
    void salvarAsgs();

    /**
     * @brief Salva os dados dos Vendedores no arquivo "vendedor.txt".
     */
    void salvarVendedores();

    /**
     * @brief Salva os dados dos Gerentes no arquivo "gerente.txt".
     */
    void salvarGerentes();

    /**
     * @brief Imprime os atributos de todos os ASGs.
     */
    void imprimeAsgs();

    /**
     * @brief Imprime os atributos de todos os Vendedores.
     */
    void imprimeVendedores();

    /**
     * @brief Imprime os atributos de todos os Gerentes.
     */
    void imprimeGerentes();

    /**
     * @brief Imprime os atributos do dono.
     */
    void imprimeDono();

    /**
     * @brief Busca um funcionário pelo número de matrícula.
     * @param matricula O número de matrícula do funcionário a ser buscado.
     */
    Funcionario *buscaFuncionario(string matricula);

    /**
     * @brief Calcula o salário de um funcionário pelo número de matrícula.
     * @param matricula O número de matrícula do funcionário.
     */
    void calculaSalarioFuncionario(string matricula);

    /**
     * @brief Calcula os salários de todos os funcionários e salva os resultados em um arquivo.
     */
    void calculaTodoOsSalarios();

    /**
     * @brief Calcula o valor da rescisão de um funcionário pelo número de matrícula e data de desligamento.
     * @param matricula O número de matrícula do funcionário.
     * @param desligamento A data de desligamento do funcionário.
     */
    void calcularRescisao(string matricula, Data desligamento);

    /**
     * @brief Demite um funcionário pelo número de matrícula e data de desligamento.
     *
     * @param matricula
     * @param desligamento
     */
    void demitirFuncionario(string matricula, Data desligamento);
};

#endif // EMPRESA_HPP
