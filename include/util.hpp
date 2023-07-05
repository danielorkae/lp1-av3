#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>

typedef struct
{
    int ano;
    int mes;
    int dia;
} Data;

typedef struct
{
    std::string cidade;
    std::string bairro;
    std::string rua;
    std::string cep;
    int numero;
} Endereco;

Data dataDiff(Data dataMenor, Data dataMaior);

#endif // UTIL_HPP
