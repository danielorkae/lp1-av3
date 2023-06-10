#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <string>
#include <vector>
#include "entities/asg.hpp"
#include "entities/vendedor.hpp"
#include "entities/gerente.hpp"

/**
 * @brief Classe que representa uma Empresa de Calçados.
 */
class Empresa
{
private:
    float faturamentoMensal;          /**< Faturamento mensal da empresa. */
    std::string nomeEmpresa;          /**< Nome da empresa. */
    std::string cnpj;                 /**< CNPJ da empresa. */
    Pessoa dono;                      /**< Dono da empresa. */
    std::vector<Asg> asgs;            /**< Lista de ASGs da empresa. */
    std::vector<Vendedor> vendedores; /**< Lista de vendedores da empresa. */
    std::vector<Gerente> gerentes;    /**< Lista de gerentes da empresa. */

public:
    /**
     * @brief Construtor padrão.
     */
    Empresa();

    /**
     * @brief Construtor que inicializa uma Empresa com todos os parâmetros.
     * @param faturamentoMensal O faturamento mensal da empresa.
     * @param nomeEmpresa O nome da empresa.
     * @param cnpj O CNPJ da empresa.
     * @param dono O dono da empresa.
     */
    Empresa(float faturamentoMensal, std::string nomeEmpresa, std::string cnpj, const Pessoa &dono);

    /**
     * @brief Obtém o faturamento mensal da empresa.
     * @return O faturamento mensal.
     */
    float getFaturamentoMensal() const;

    /**
     * @brief Define o faturamento mensal da empresa.
     * @param faturamentoMensal O faturamento mensal.
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
    void setNomeEmpresa(const std::string &nomeEmpresa);

    /**
     * @brief Obtém o CNPJ da empresa.
     * @return O CNPJ da empresa.
     */
    std::string getCnpj() const;

    /**
     * @brief Define o CNPJ da empresa.
     * @param cnpj O CNPJ da empresa.
     */
    void setCnpj(const std::string &cnpj);

    /**
     * @brief Obtém o dono da empresa.
     * @return O dono da empresa.
     */
    Pessoa getDono() const;

    /**
     * @brief Define o dono da empresa.
     * @param dono O dono da empresa.
     */
    void setDono(const Pessoa &dono);

    /**
     * @brief Carrega os dados da empresa a partir de um arquivo.
     * @param nomeArquivo O nome do arquivo a ser carregado.
     * @return True se os dados foram carregados com sucesso, False caso contrário.
     */
    bool carregarDados(const std::string &nomeArquivo);

    /**
     * @brief Imprime os atributos da empresa.
     */
    void imprimirAtributos() const;

    /**
     * @brief Busca um funcionário pelo número de matrícula.
     * @param matricula A matrícula do funcionário a ser buscado.
     * @return O ponteiro para o funcionário encontrado, ou nullptr se não encontrado.
     */
    Funcionario *buscarFuncionarioPorMatricula(const std::string &matricula);

    /**
     * @brief Calcula os salários de todos os funcionários da empresa.
     */
    void calcularSalarios();

    /**
     * @brief Calcula as rescisões de todos os funcionários da empresa com base na data de desligamento.
     * @param desligamento A data de desligamento dos funcionários.
     */
    void calcularRecisoes(const Data &desligamento);
};

#endif // EMPRESA_HPP
