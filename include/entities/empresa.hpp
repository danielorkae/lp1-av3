#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <string>
#include <vector>
#include "pessoa.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

/**
 * @brief Classe que representa uma Empresa.
 */
class Empresa {
private:
    float faturamentoMensal; /**< Faturamento mensal da empresa */
    std::string nomeEmpresa; /**< Nome da empresa */
    std::string cnpj; /**< CNPJ da empresa */
    Pessoa dono; /**< Dono da empresa */
    std::vector<Asg> asgs; /**< Vetor de ASGs */
    std::vector<Vendedor> vendedores; /**< Vetor de Vendedores */
    std::vector<Gerente> gerentes; /**< Vetor de Gerentes */

public:
    /**
     * @brief Construtor padrão.
     */
    Empresa();

    /**
     * @brief Construtor que inicializa uma empresa com os atributos fornecidos.
     * @param nomeEmpresa O nome da empresa.
     * @param cnpj O CNPJ da empresa.
     * @param faturamentoMensal O faturamento mensal da empresa.
     */
    Empresa(const std::string& nomeEmpresa, const std::string& cnpj, float faturamentoMensal);

    // Métodos de acesso

    /**
     * @brief Obtém o faturamento mensal da empresa.
     * @return O faturamento mensal da empresa.
     */
    float getFaturamentoMensal() const;

    /**
     * @brief Define o faturamento mensal da empresa.
     * @param faturamentoMensal O faturamento mensal da empresa.
     */
    void setFaturamentoMensal(float faturamentoMensal);

    /**
     * @brief Obtém o nome da empresa.
     * @return O nome da empresa.
     */
    std::string getNomeEmpresa() const;

    /**
     * @brief Define o nome da empresa.
     * @param nomeEmpresa O nome da empresa.
     */
    void setNomeEmpresa(const std::string& nomeEmpresa);

    /**
     * @brief Obtém o CNPJ da empresa.
     * @return O CNPJ da empresa.
     */
    std::string getCnpj() const;

    /**
     * @brief Define o CNPJ da empresa.
     * @param cnpj O CNPJ da empresa.
     */
    void setCnpj(const std::string& cnpj);

    /**
     * @brief Obtém o dono da empresa.
     * @return O dono da empresa.
     */
    const Pessoa& getDono() const;

    /**
     * @brief Obtém o vetor de ASGs da empresa.
     * @return O vetor de ASGs da empresa.
     */
    const std::vector<Asg>& getAsgs() const;

    /**
     * @brief Obtém o vetor de Vendedores da empresa.
     * @return O vetor de Vendedores da empresa.
     */
    const std::vector<Vendedor>& getVendedores() const;

    /**
     * @brief Obtém o vetor de Gerentes da empresa.
     * @return O vetor de Gerentes da empresa.
     */
    const std::vector<Gerente>& getGerentes() const;

    // Métodos

    /**
     * @brief Carrega as funções a partir do arquivo "funcoes.txt".
     */
    void carregaFuncoes();

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
    void buscaFuncionario(int matricula);

    /**
     * @brief Calcula o salário de um funcionário pelo número de matrícula.
     * @param matricula O número de matrícula do funcionário.
     */
    void calculaSalarioFuncionario(int matricula);

    /**
     * @brief Calcula os salários de todos os funcionários e salva os resultados em um arquivo.
     */
    void calculaTodoOsSalarios();

    /**
     * @brief Calcula o valor da rescisão de um funcionário pelo número de matrícula e data de desligamento.
     * @param matricula O número de matrícula do funcionário.
     * @param desligamento A data de desligamento do funcionário.
     */
    void calcularRecisao(int matricula, const Data& desligamento);
};

#endif // EMPRESA_HPP
