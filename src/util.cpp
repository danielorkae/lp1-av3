#include "util.hpp"

bool anoBissexto(int ano);
int obterDiasNoMes(int mes, int ano);

bool anoBissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int obterDiasNoMes(int mes, int ano)
{
    if (mes == 2)
    {
        return anoBissexto(ano) ? 29 : 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

Data dataDiff(Data dataMenor, Data dataMaior)
{
    Data diferenca;
    diferenca.ano = dataMaior.ano - dataMenor.ano;
    diferenca.mes = dataMaior.mes - dataMenor.mes;
    diferenca.dia = dataMaior.dia - dataMenor.dia;

    if (diferenca.mes <= 0)
    {
        diferenca.ano--;
        diferenca.mes += 12;
    }

    if (diferenca.dia <= 0)
    {
        int mesAnterior = dataMaior.mes - 1;

        if (mesAnterior == 0)
        {
            mesAnterior = 12;
        }

        diferenca.mes--;
        int diasNoMesAnterior = obterDiasNoMes(mesAnterior, dataMaior.ano);
        diferenca.dia += diasNoMesAnterior;
    }

    return diferenca;
}
