#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include "entities/pessoa.hpp"
#include "entities/funcionario.hpp"

using namespace std;

/**
 * @brief Classe concreta que representa um Vendedor.
 */
class Vendedor : public Pessoa, public Funcionario
{
private:
    char tipoVendedor; /**< Tipo de vendedor */

public:
    /**
     * @brief Construtor padrão.
     */
    Vendedor();

    /**
     * @brief Construtor que inicializa um Vendedor com todos os parâmetros.
     * @param nome O nome do Vendedor.
     * @param cpf O CPF do Vendedor.
     * @param dataNascimento A data de nascimento do Vendedor.
     * @param enderecoPessoal O endereço pessoal do Vendedor.
     * @param estadoCivil O estado civil do Vendedor.
     * @param qtdFilhos A quantidade de filhos do Vendedor.
     * @param salario O salário do Vendedor.
     * @param matricula A matrícula do Vendedor.
     * @param ingressoEmpresa A data de ingresso na empresa do Vendedor.
     * @param tipoVendedor O tipo de vendedor.
     */
    Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
             string estadoCivil, int qtdFilhos, float salario, string matricula,
             Data ingressoEmpresa, char tipoVendedor);

    /**
     * @brief Obtém o tipo de vendedor.
     * @return O tipo de vendedor.
     */
    char getTipoVendedor() const;

    /**
     * @brief Define o tipo de vendedor.
     * @param tipoVendedor O tipo de vendedor.
     */
    void setTipoVendedor(char tipoVendedor);

    /**
     * @brief Calcula o salário do Vendedor considerando os dias de faltas.
     * @param diasFaltas O número de dias de faltas do Vendedor.
     * @return O salário calculado.
     */
    float calcularSalario(int diasFaltas);

    /**
     * @brief Calcula a rescisão do Vendedor com base na data de desligamento.
     * @param desligamento A data de desligamento do Vendedor.
     * @return O valor da rescisão calculado.
     */
    float calcularRescisao(Data desligamento);

    /**
     * @brief Imprime os dados do Vendedor.
     */
    void imprimirDados();
};

#endif // VENDEDOR_HPP
