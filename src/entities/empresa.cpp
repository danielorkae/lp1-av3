#include "entities/empresa.hpp"

using namespace std;

ifstream abrirArquivo(string nomeArquivo);

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

ifstream abrirArquivo(string nomeArquivo)
{
    try
    {
        // Obtém o diretório do arquivo executável
        filesystem::path currentPath = filesystem::current_path();

        // Constrói o caminho completo para o arquivo
        filesystem::path filePath = currentPath / "data" / nomeArquivo;

        // Verifica se o arquivo existe
        if (!filesystem::exists(filePath))
        {
            throw runtime_error("Erro: arquivo " + nomeArquivo + " não encontrado.");
        }

        ifstream arquivo(nomeArquivo);

        if (!arquivo.is_open())
        {
            throw runtime_error("Erro ao abrir o arquivo: " + nomeArquivo);
        }

        return arquivo;
    }
    catch (const exception &ex)
    {
        cerr << ex.what() << endl;
        throw; // Re-lança a exceção para ser tratada em outro lugar, se necessário
    }
}

void Empresa::carregarFuncoes()
{
    try
    {
        // Abre o arquivo em modo de leitura
        ifstream arquivo = abrirArquivo("funcoes.txt");

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
    ifstream file = abrirArquivo("empresa.txt");

    string line;
    // Ignora as linhas de separação iniciais
    getline(file, line);
    getline(file, line);

    // Lê o nome da empresa
    getline(file, line);
    string nomeEmpresa = line;

    // Lê o CNPJ da empresa
    getline(file, line);
    string cnpj = line;

    // Lê o faturamento mensal da empresa
    getline(file, line);
    float faturamentoMensal;
    istringstream(line) >> faturamentoMensal;

    // Atualiza os atributos da empresa
    setNomeEmpresa(nomeEmpresa);
    setCnpj(cnpj);
    setFaturamentoMensal(faturamentoMensal);

    file.close();
}

vector<Asg> carregarAsg()
{
    vector<Asg> asgs;

    try
    {
        ifstream arquivo = abrirArquivo("asg.txt");

        string linha;
        while (getline(arquivo, linha))
        {
            if (linha.find("ASG Nº:") != string::npos)
            {
                getline(arquivo, linha); // Ignorar linha "##### DADOS PESSOAIS #####"
                getline(arquivo, linha);
                string nomeFuncionario = linha;
                getline(arquivo, linha);
                string cpfFuncionario = linha;
                getline(arquivo, linha);
                int numeroFilhos = stoi(linha);
                getline(arquivo, linha);
                string estadoCivil = linha;

                getline(arquivo, linha); // Linha de separação "***** Endereço (cidade, cep, bairro, rua e numero) ****"
                getline(arquivo, linha);
                string cidade = linha;
                getline(arquivo, linha);
                string cep = linha;
                getline(arquivo, linha);
                string bairro = linha;
                getline(arquivo, linha);
                string rua = linha;
                getline(arquivo, linha);
                int numero = stoi(linha);
                Endereco endereco{cidade, cep, bairro, rua, numero};

                getline(arquivo, linha); // Linha de separação "***** Data de nascimento (ano, mes, dia) ****"
                getline(arquivo, linha);
                int anoNascimento = stoi(linha);
                getline(arquivo, linha);
                int mesNascimento = stoi(linha);
                getline(arquivo, linha);
                int diaNascimento = stoi(linha);
                Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};

                getline(arquivo, linha); // Ignorar linha "##### DADOS FUNCIONAIS #####"
                getline(arquivo, linha);
                string matriculaFuncionario = linha;
                getline(arquivo, linha);
                float salarioBase = stof(linha);
                getline(arquivo, linha);
                float porcentagemInsalubridade = stof(linha);
                getline(arquivo, linha);
                int diasFalta = stoi(linha);

                getline(arquivo, linha); // Linha de separação "***** Data de ingresso (ano, mes, dia) ****"
                getline(arquivo, linha);
                int anoIngresso = stoi(linha);
                getline(arquivo, linha);
                int mesIngresso = stoi(linha);
                getline(arquivo, linha);
                int diaIngresso = stoi(linha);
                Data dataIngresso{anoIngresso, mesIngresso, diaIngresso};

                // Criar objeto Asg e adicionar ao vetor
                Asg asg(nomeFuncionario, cpfFuncionario, dataNascimento, endereco, estadoCivil,
                        numeroFilhos, salarioBase, matriculaFuncionario, dataIngresso,
                        porcentagemInsalubridade);
                asgs.push_back(asg);
            }
        }

        arquivo.close();
    }
    catch (const exception &ex)
    {
        // Tratamento de erro
        cerr << "Erro: " << ex.what() << endl;
    }

    return asgs;
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
