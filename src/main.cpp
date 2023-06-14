#include <iostream>
#include "entities/empresa.hpp"

int main()
{
    // Criar uma instância da classe Empresa dinamicamente
    Empresa *empresa = new Empresa();

    // Chamar a função carregarDados()
    empresa->carregarDados("dados_empresa.txt");

    // Resto do código...

    // Liberar a memória alocada pela instância da classe Empresa
    delete empresa;

    return 0;
}
