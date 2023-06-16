#include <iostream>
#include "entities/empresa.hpp"

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
