#include <iostream>
#include "entities/empresa.hpp"

/**
 * @brief O projeto é uma aplicação de gerenciamento de funcionários
 * em uma empresa. Permite cadastrar e manipular informações de diferentes tipos
 * de funcionários, como vendedores, gerentes e auxiliares de serviços gerais
 * (ASGs). Além disso, possibilita salvar os dados dos funcionários em arquivos
 * e realizar operações como cálculo de salários e busca por informações
 * específicas.
 * 
 * @author Daniel Lopes
 * @date 2023-07-04
 *
 * @return int
 */
int main()
{
    // Criar uma instância da classe Empresa dinamicamente
    Empresa *empresa = new Empresa();

    // Chamar a função carregarFuncoes()
    empresa->carregarFuncoes();

    // Resto do código...

    // Liberar a memória alocada pela instância da classe Empresa
    delete empresa;

    return 0;
}
