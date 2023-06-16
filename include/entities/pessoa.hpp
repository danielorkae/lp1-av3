#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include "util.hpp"

/**
 * @brief Classe que representa uma pessoa.
 */
class Pessoa
{
private:
    std::string nome;         /**< Nome da pessoa */
    std::string cpf;          /**< CPF da pessoa */
    Data dataNascimento;      /**< Data de nascimento da pessoa */
    Endereco enderecoPessoal; /**< Endereço pessoal da pessoa */
    std::string estadoCivil;  /**< Estado civil da pessoa */
    int qtdFilhos;            /**< Quantidade de filhos da pessoa */

public:
    /**
     * @brief Construtor padrão.
     */
    Pessoa();

    /**
     * @brief Construtor que inicializa uma pessoa com todos os parâmetros.
     * @param nome O nome da pessoa.
     * @param cpf O CPF da pessoa.
     * @param dataNascimento A data de nascimento da pessoa.
     * @param enderecoPessoal O endereço pessoal da pessoa.
     * @param estadoCivil O estado civil da pessoa.
     * @param qtdFilhos A quantidade de filhos da pessoa.
     */
    Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal,
           std::string estadoCivil, int qtdFilhos);

    /**
     * @brief Obtém o nome da pessoa.
     * @return O nome da pessoa.
     */
    std::string getNome() const;

    /**
     * @brief Define o nome da pessoa.
     * @param nome O nome da pessoa.
     */
    void setNome(std::string nome);

    /**
     * @brief Obtém o CPF da pessoa.
     * @return O CPF da pessoa.
     */
    std::string getCpf() const;

    /**
     * @brief Define o CPF da pessoa.
     * @param cpf O CPF da pessoa.
     */
    void setCpf(std::string cpf);

    /**
     * @brief Obtém a data de nascimento da pessoa.
     * @return A data de nascimento da pessoa.
     */
    Data getDataNascimento() const;

    /**
     * @brief Define a data de nascimento da pessoa.
     * @param dataNascimento A data de nascimento da pessoa.
     */
    void setDataNascimento(Data dataNascimento);

    /**
     * @brief Obtém o endereço pessoal da pessoa.
     * @return O endereço pessoal da pessoa.
     */
    Endereco getEnderecoPessoal() const;

    /**
     * @brief Define o endereço pessoal da pessoa.
     * @param enderecoPessoal O endereço pessoal da pessoa.
     */
    void setEnderecoPessoal(Endereco enderecoPessoal);

    /**
     * @brief Obtém o estado civil da pessoa.
     * @return O estado civil da pessoa.
     */
    std::string getEstadoCivil() const;

    /**
     * @brief Define o estado civil da pessoa.
     * @param estadoCivil O estado civil da pessoa.
     */
    void setEstadoCivil(std::string estadoCivil);

    /**
     * @brief Obtém a quantidade de filhos da pessoa.
     * @return A quantidade de filhos da pessoa.
     */
    int getQtdFilhos() const;

    /**
     * @brief Define a quantidade de filhos da pessoa.
     * @param qtdFilhos A quantidade de filhos da pessoa.
     */
    void setQtdFilhos(int qtdFilhos);

    /**
     * @brief Imprime os dados da pessoa.
     */
    virtual void imprimirDados();
};

#endif // PESSOA_HPP
