#include "entities/empresa.hpp"

using namespace std;

Empresa::Empresa()
{
    //
}

Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal)
    : nomeEmpresa(nomeEmpresa),
      cnpj(cnpj),
      faturamentoMensal(faturamentoMensal)
{
    //
}

float Empresa::getFaturamentoMensal()
{
    return faturamentoMensal;
}

void Empresa::setFaturamentoMensal(float faturamentoMensal)
{
    this->faturamentoMensal = faturamentoMensal;
}

string Empresa::getNomeEmpresa()
{
    return nomeEmpresa;
}

void Empresa::setNomeEmpresa(string nomeEmpresa)
{
    this->nomeEmpresa = nomeEmpresa;
}

string Empresa::getCnpj()
{
    return cnpj;
}

void Empresa::setCnpj(string cnpj)
{
    this->cnpj = cnpj;
}

Pessoa &Empresa::getDono()
{
    return dono;
}

vector<Asg> &Empresa::getAsgs()
{
    return asgs;
}

vector<Vendedor> &Empresa::getVendedores()
{
    return vendedores;
}

vector<Gerente> &Empresa::getGerentes()
{
    return gerentes;
}

void Empresa::carregarFuncoes()
{
    try
    {
        // Obtém o diretório do arquivo executável
        filesystem::path currentPath = filesystem::current_path();

        // Constrói o caminho completo para o arquivo "funcoes.txt"
        filesystem::path filePath = currentPath / "data" / "funcoes.txt";

        // Verifica se o arquivo existe
        if (!filesystem::exists(filePath))
        {
            throw runtime_error("Erro: arquivo 'funcoes.txt' não encontrado.");
        }

        // Abre o arquivo em modo de leitura
        ifstream arquivo(filePath);
        if (!arquivo.is_open())
        {
            throw runtime_error("Erro ao abrir o arquivo 'funcoes.txt'.");
        }

        // Lê cada linha do arquivo e executa a função correspondente
        string linha;
        while (getline(arquivo, linha))
        {
            if (linha == "carregarEmpresa()")
            {
                carregarEmpresa();
            }
            else if (linha == "carregarAsg()")
            {
                carregarAsg();
            }
            else if (linha == "carregarVendedor()")
            {
                carregarVendedor();
            }
            else if (linha == "carregarGerente()")
            {
                carregarGerente();
            }
            else if (linha == "carregaDono()")
            {
                carregaDono();
            }
            else if (linha == "imprimeAsgs()")
            {
                imprimeAsgs();
            }
            else if (linha == "imprimeVendedores()")
            {
                imprimeVendedores();
            }
            else if (linha == "imprimeGerentes()")
            {
                imprimeGerentes();
            }
            else if (linha == "imprimeDono()")
            {
                imprimeDono();
            }
            else if (linha.find("buscaFuncionario()") == 0)
            {
                // Extrai a matrícula do funcionário da próxima linha
                getline(arquivo, linha);
                int matricula = stoi(linha);
                buscaFuncionario(matricula);
            }
            else if (linha.find("calculaSalarioFuncionario()") == 0)
            {
                // Extrai a matrícula do funcionário da próxima linha
                getline(arquivo, linha);
                int matricula = stoi(linha);
                calculaSalarioFuncionario(matricula);
            }
            else if (linha == "calculaTodoOsSalarios()")
            {
                calculaTodosSalarios();
            }
            else if (linha.find("calcularRescisao()") == 0)
            {
                // Extrai a matrícula, ano, mês e dia da próxima linha
                string matriculaStr, anoStr, mesStr, diaStr;
                getline(arquivo, matriculaStr);
                getline(arquivo, anoStr);
                getline(arquivo, mesStr);
                getline(arquivo, diaStr);
                int matricula = stoi(matriculaStr);
                int ano = stoi(anoStr);
                int mes = stoi(mesStr);
                int dia = stoi(diaStr);
                Data desligamento{ano, mes, dia};
                calcularRescisao(matricula, desligamento);
            }
            else
            {
                throw runtime_error("Erro: função desconhecida: " + linha);
            }
        }

        // Fecha o arquivo
        arquivo.close();
    }
    catch (const exception &ex)
    {
        cout << "Erro ao executar as funções: " << ex.what() << endl;
    }
}

void Empresa::carregarEmpresa()
{
    // Obtém o diretório do arquivo executável
    filesystem::path currentPath = filesystem::current_path();

    // Constrói o caminho completo para o arquivo "empresa.txt"
    filesystem::path filePath = currentPath / "data" / "empresa.txt";

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "O arquivo empresa.txt não pôde ser aberto." << std::endl;
        return;
    }

    std::string line;
    // Ignora as linhas de separação iniciais
    std::getline(file, line);
    std::getline(file, line);

    // Lê o nome da empresa
    std::getline(file, line);
    std::string nomeEmpresa = line;

    // Lê o CNPJ da empresa
    std::getline(file, line);
    std::string cnpj = line;

    // Lê o faturamento mensal da empresa
    std::getline(file, line);
    float faturamentoMensal;
    std::istringstream(line) >> faturamentoMensal;

    // Atualiza os atributos da empresa
    setNomeEmpresa(nomeEmpresa);
    setCnpj(cnpj);
    setFaturamentoMensal(faturamentoMensal);

    file.close();
}

void Empresa::carregarAsg()
{
    ifstream file("asg.txt");
    if (!file.is_open())
    {
        cerr << "O arquivo asg.txt não pôde ser aberto." << endl;
        return;
    }

    // Carrega os dados dos ASGs a partir do arquivo
    // ...

    file.close();
}

void Empresa::carregarVendedor()
{
    ifstream file("vendedor.txt");
    if (!file.is_open())
    {
        cerr << "O arquivo vendedor.txt não pôde ser aberto." << endl;
        return;
    }

    // Carrega os dados dos Vendedores a partir do arquivo
    // ...

    file.close();
}

void Empresa::carregarGerente()
{
    ifstream file("gerente.txt");
    if (!file.is_open())
    {
        cerr << "O arquivo gerente.txt não pôde ser aberto." << endl;
        return;
    }

    // Carrega os dados dos Gerentes a partir do arquivo
    // ...

    file.close();
}

void Empresa::carregaDono()
{
    ifstream file("dono.txt");
    if (!file.is_open())
    {
        cerr << "O arquivo dono.txt não pôde ser aberto." << endl;
        return;
    }

    // Carrega os dados do dono da empresa a partir do arquivo
    // ...

    file.close();
}

void Empresa::imprimeAsgs()
{
    for (auto asg : asgs)
    {
        // asg.imprimirAtributos();
    }
}

void Empresa::imprimeVendedores()
{
    for (auto vendedor : vendedores)
    {
        // vendedor.imprimirAtributos();
    }
}

void Empresa::imprimeGerentes()
{
    for (auto gerente : gerentes)
    {
        // gerente.imprimirAtributos();
    }
}

void Empresa::imprimeDono()
{
    // dono.imprimirAtributos();
}

void Empresa::buscaFuncionario(int matricula)
{
    // Busca o funcionário pelo número de matrícula
    // ...
}

void Empresa::calculaSalarioFuncionario(int matricula)
{
    // Calcula o salário do funcionário pelo número de matrícula
    // ...
}

void Empresa::calculaTodosSalarios()
{
    // Calcula os salários de todos os funcionários e salva os resultados em um arquivo
    // ...
}

void Empresa::calcularRescisao(int matricula, Data desligamento)
{
    // Calcula o valor da rescisão de um funcionário pelo número de matrícula e data de desligamento
    // ...
}
