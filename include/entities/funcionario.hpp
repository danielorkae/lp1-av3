#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include "util.hpp"

/**
 * @brief Classe abstrata que representa um funcionário.
 */
class Funcionario
{
private:
    float salario;         /**< Salário do funcionário */
    std::string matricula; /**< Matrícula do funcionário */
    Data ingressoEmpresa;  /**< Data de ingresso na empresa */

public:
    /**
     * @brief Construtor padrão.
     */
    Funcionario();

    /**
     * @brief Construtor que inicializa um funcionário com todos os parâmetros.
     * @param salario O salário do funcionário.
     * @param matricula A matrícula do funcionário.
     * @param ingressoEmpresa A data de ingresso na empresa.
     */
    Funcionario(float salario, std::string matricula, Data ingressoEmpresa);

    /**
     * @brief Obtém o salário do funcionário.
     * @return O salário do funcionário.
     */
    float getSalario() const;

    /**
     * @brief Define o salário do funcionário.
     * @param salario O salário do funcionário.
     */
    void setSalario(float salario);

    /**
     * @brief Obtém a matrícula do funcionário.
     * @return A matrícula do funcionário.
     */
    std::string getMatricula() const;

    /**
     * @brief Define a matrícula do funcionário.
     * @param matricula A matrícula do funcionário.
     */
    void setMatricula(std::string matricula);

    /**
     * @brief Obtém a data de ingresso na empresa do funcionário.
     * @return A data de ingresso na empresa do funcionário.
     */
    Data getIngressoEmpresa() const;

    /**
     * @brief Define a data de ingresso na empresa do funcionário.
     * @param ingressoEmpresa A data de ingresso na empresa do funcionário.
     */
    void setIngressoEmpresa(Data ingressoEmpresa);

    /**
     * @brief Calcula o salário do funcionário considerando os dias de faltas.
     * @param diasFaltas O número de dias de faltas do funcionário.
     * @return O salário calculado.
     */
    virtual float calcularSalario(int diasFaltas) = 0;

    /**
     * @brief Calcula a rescisão do funcionário com base na data de desligamento.
     * @param desligamento A data de desligamento do funcionário.
     * @return O valor da rescisão calculado.
     */
    virtual float calcularRescisao(Data desligamento) = 0;
};

#endif // FUNCIONARIO_HPP
