#ifndef ASG_HPP
#define ASG_HPP

#include <iostream>
#include "entities/pessoa.hpp"
#include "entities/funcionario.hpp"

using namespace std;

/**
 * @brief Classe concreta que representa um ASG (Auxiliar de Serviços Gerais).
 */
class Asg : public Pessoa, public Funcionario
{
private:
    float adicionalInsalubridade; /**< Adicional de insalubridade do ASG */

public:
    /**
     * @brief Construtor padrão.
     */
    Asg();

    /**
     * @brief Construtor que inicializa um ASG com todos os parâmetros.
     * @param nome O nome do ASG.
     * @param cpf O CPF do ASG.
     * @param dataNascimento A data de nascimento do ASG.
     * @param enderecoPessoal O endereço pessoal do ASG.
     * @param estadoCivil O estado civil do ASG.
     * @param qtdFilhos A quantidade de filhos do ASG.
     * @param salario O salário do ASG.
     * @param matricula A matrícula do ASG.
     * @param ingressoEmpresa A data de ingresso na empresa do ASG.
     * @param adicionalInsalubridade O adicional de insalubridade do ASG.
     */
    Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
        string estadoCivil, int qtdFilhos, float salario, string matricula,
        Data ingressoEmpresa, float adicionalInsalubridade);

    /**
     * @brief Obtém o adicional de insalubridade do ASG.
     * @return O adicional de insalubridade do ASG.
     */
    float getAdicionalInsalubridade() const;

    /**
     * @brief Define o adicional de insalubridade do ASG.
     * @param adicionalInsalubridade O adicional de insalubridade do ASG.
     */
    void setAdicionalInsalubridade(float adicionalInsalubridade);

    /**
     * @brief Calcula o salário do ASG com base no número de dias de faltas, adicional de insalubridade
     * e adicional por filho.
     * @param diasFaltas O número de dias de faltas do ASG.
     * @return O salário calculado do ASG.
     */
    float calcularSalario(int diasFaltas);

    /**
     * @brief Calcula o valor da rescisão do ASG com base na data de desligamento.
     * @param desligamento A data de desligamento do ASG.
     * @return O valor da rescisão calculado do ASG.
     */
    float calcularRescisao(Data desligamento);

    /**
     * @brief Imprime os dados do ASG.
     */
    void imprimirDados();
};

#endif // ASG_HPP
