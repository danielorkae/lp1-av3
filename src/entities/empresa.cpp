#include "entities/empresa.hpp"
#include "empresa.hpp"

using namespace std;

fstream abrirArquivo(string nomeArquivo);
fstream abrirArquivo(string nomeArquivo, ios_base::openmode modo);

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

fstream abrirArquivo(string nomeArquivo)
{
    return abrirArquivo(nomeArquivo, ios_base::in | ios_base::app);
}

fstream abrirArquivo(string nomeArquivo, ios_base::openmode modo)
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

        fstream file;
        file.open(filePath, modo);

        if (!file.is_open())
        {
            throw runtime_error("Erro ao abrir o arquivo: " + nomeArquivo);
        }

        return file;
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
        fstream arquivo = abrirArquivo("funcoes.txt");

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
                string matricula = linha;
                buscaFuncionario(matricula);
            }
            else if (linha.find("calculaSalarioFuncionario()") == 0)
            {
                // Extrai a matrícula do funcionário da próxima linha
                getline(arquivo, linha);
                string matricula = linha;
                calculaSalarioFuncionario(matricula);
            }
            else if (linha == "calculaTodoOsSalarios()")
            {
                calculaTodoOsSalarios();
            }
            else if (linha.find("calcularRecisao()") == 0 || linha.find("calcularRescisao()") == 0)
            {
                // Extrai a matrícula, ano, mês e dia da próxima linha
                string matriculaStr, anoStr, mesStr, diaStr;
                getline(arquivo, matriculaStr);
                getline(arquivo, anoStr);
                getline(arquivo, mesStr);
                getline(arquivo, diaStr);
                string matricula = matriculaStr;
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
    fstream file = abrirArquivo("empresa.txt");

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

void Empresa::carregarAsg()
{
    try
    {
        fstream arquivo = abrirArquivo("asg.txt");

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
}

void Empresa::carregarVendedor()
{
    try
    {
        fstream arquivo = abrirArquivo("vendedor.txt");

        string linha;
        while (getline(arquivo, linha))
        {
            if (linha.find("VENDEDOR Nº:") != string::npos)
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
                char categoria = linha[0];
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

                // Criar objeto Vendedor e adicionar ao vetor
                Vendedor vendedor(nomeFuncionario, cpfFuncionario, dataNascimento, endereco, estadoCivil,
                                  numeroFilhos, salarioBase, matriculaFuncionario, dataIngresso,
                                  categoria);
                vendedores.push_back(vendedor);
            }
        }

        arquivo.close();
    }
    catch (const exception &ex)
    {
        // Tratamento de erro
        cerr << "Erro: " << ex.what() << endl;
    }
}

void Empresa::carregarGerente()
{
    try
    {
        fstream arquivo = abrirArquivo("gerente.txt");

        string linha;
        while (getline(arquivo, linha))
        {
            if (linha.find("GERENTE Nº:") != string::npos)
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
                float participacaoLucros = stof(linha);
                getline(arquivo, linha);
                int faltas = stoi(linha);

                getline(arquivo, linha); // Linha de separação "***** Data de ingresso (ano, mes, dia) ****"
                getline(arquivo, linha);
                int anoIngresso = stoi(linha);
                getline(arquivo, linha);
                int mesIngresso = stoi(linha);
                getline(arquivo, linha);
                int diaIngresso = stoi(linha);
                Data dataIngresso{anoIngresso, mesIngresso, diaIngresso};

                // Criar objeto Gerente e adicionar ao vetor
                Gerente gerente(nomeFuncionario, cpfFuncionario, dataNascimento, endereco, estadoCivil,
                                numeroFilhos, salarioBase, matriculaFuncionario, dataIngresso,
                                participacaoLucros);
                gerentes.push_back(gerente);
            }
        }

        arquivo.close();
    }
    catch (const exception &ex)
    {
        // Tratamento de erro
        cerr << "Erro: " << ex.what() << endl;
    }
}

void Empresa::carregaDono()
{
    try
    {
        fstream arquivo = abrirArquivo("dono.txt");

        string linha;
        while (getline(arquivo, linha))
        {
            if (linha.find("##### DADOS PESSOAIS") != string::npos)
            {
                getline(arquivo, linha);
                string nomeDono = linha;
                getline(arquivo, linha);
                string cpfDono = linha;
                getline(arquivo, linha);
                int numeroFilhos = stoi(linha);

                getline(arquivo, linha);
                string estadoCivil = linha;

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

                getline(arquivo, linha);
                int anoNascimento = stoi(linha);
                getline(arquivo, linha);
                int mesNascimento = stoi(linha);
                getline(arquivo, linha);
                int diaNascimento = stoi(linha);
                Data dataNascimento{anoNascimento, mesNascimento, diaNascimento};

                dono.setNome(nomeDono);
                dono.setCpf(cpfDono);
                dono.setDataNascimento(dataNascimento);
                dono.setEnderecoPessoal(endereco);
                dono.setEstadoCivil(estadoCivil);
                dono.setQtdFilhos(numeroFilhos);

                break; // Se encontrou os dados do dono, não precisa continuar lendo o arquivo
            }
        }

        arquivo.close();
    }
    catch (const exception &ex)
    {
        // Tratamento de erro
        cerr << "Erro: " << ex.what() << endl;
    }
}

void Empresa::salvarAsgs()
{
    fstream arquivo = abrirArquivo("asgs.txt", ios_base::out | ios_base::trunc);

    for (const auto &asg : asgs)
    {
        arquivo << "ASG Nº: " << asg.getMatricula() << endl;
        arquivo << "##### DADOS PESSOAIS #####" << endl;
        arquivo << asg.getNome() << endl;
        arquivo << asg.getCpf() << endl;
        arquivo << asg.getQtdFilhos() << endl;
        arquivo << asg.getEstadoCivil() << endl;

        arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
        arquivo << asg.getEnderecoPessoal().cidade << endl;
        arquivo << asg.getEnderecoPessoal().cep << endl;
        arquivo << asg.getEnderecoPessoal().bairro << endl;
        arquivo << asg.getEnderecoPessoal().rua << endl;
        arquivo << asg.getEnderecoPessoal().numero << endl;

        arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
        arquivo << asg.getDataNascimento().ano << endl;
        arquivo << asg.getDataNascimento().mes << endl;
        arquivo << asg.getDataNascimento().dia << endl;

        arquivo << "##### DADOS FUNCIONAIS #####" << endl;
        arquivo << asg.getMatricula() << endl;
        arquivo << asg.getSalario() << endl;
        arquivo << asg.getAdicionalInsalubridade() << endl;
        arquivo << "0" << endl;
        
        arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
        arquivo << asg.getIngressoEmpresa().ano << endl;
        arquivo << asg.getIngressoEmpresa().mes << endl;
        arquivo << asg.getIngressoEmpresa().dia << endl;
        arquivo << endl; // Linha em branco para separar os registros
    }
    arquivo.close();
    cout << "Arquivo asgs.txt salvo com sucesso!" << endl;
}

void Empresa::salvarVendedores()
{
    fstream arquivo = abrirArquivo("vendedores.txt", ios_base::out | ios_base::trunc);

    arquivo << "##############################################" << endl;
    arquivo << "VENDEDOR Nº: " << vendedores.size() << endl;

    for (const Vendedor &vendedor : vendedores)
    {
        arquivo << "##### DADOS PESSOAIS #####" << endl;
        arquivo << vendedor.getNome() << endl;
        arquivo << vendedor.getCpf() << endl;
        arquivo << vendedor.getQtdFilhos() << endl;
        arquivo << vendedor.getEstadoCivil() << endl;

        arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
        arquivo << vendedor.getEnderecoPessoal().cidade << endl;
        arquivo << vendedor.getEnderecoPessoal().cep << endl;
        arquivo << vendedor.getEnderecoPessoal().bairro << endl;
        arquivo << vendedor.getEnderecoPessoal().rua << endl;
        arquivo << vendedor.getEnderecoPessoal().numero << endl;

        arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
        arquivo << vendedor.getDataNascimento().ano << endl;
        arquivo << vendedor.getDataNascimento().mes << endl;
        arquivo << vendedor.getDataNascimento().dia << endl;

        arquivo << "##### DADOS FUNCIONAIS #####" << endl;
        arquivo << vendedor.getMatricula() << endl;
        arquivo << vendedor.getSalario() << endl;
        arquivo << vendedor.getTipoVendedor() << endl;
        arquivo << 0 << endl;

        arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
        arquivo << vendedor.getIngressoEmpresa().ano << endl;
        arquivo << vendedor.getIngressoEmpresa().mes << endl;
        arquivo << vendedor.getIngressoEmpresa().dia << endl;
    }

    arquivo.close();
}

void Empresa::salvarGerentes()
{
    fstream arquivo = abrirArquivo("gerentes.txt", ios_base::out);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    arquivo << "##############################################" << endl;
    arquivo << "GERENTE Nº: " << gerentes.size() << endl;

    for (const Gerente &gerente : gerentes)
    {
        arquivo << "##### DADOS PESSOAIS #####" << endl;
        arquivo << gerente.getNome() << endl;
        arquivo << gerente.getCpf() << endl;
        arquivo << gerente.getQtdFilhos() << endl;
        arquivo << gerente.getEstadoCivil() << endl;

        arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
        arquivo << gerente.getEnderecoPessoal().cidade << endl;
        arquivo << gerente.getEnderecoPessoal().cep << endl;
        arquivo << gerente.getEnderecoPessoal().bairro << endl;
        arquivo << gerente.getEnderecoPessoal().rua << endl;
        arquivo << gerente.getEnderecoPessoal().numero << endl;

        arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
        arquivo << gerente.getDataNascimento().ano << endl;
        arquivo << gerente.getDataNascimento().mes << endl;
        arquivo << gerente.getDataNascimento().dia << endl;

        arquivo << "##### DADOS FUNCIONAIS #####" << endl;
        arquivo << gerente.getMatricula() << endl;
        arquivo << gerente.getSalario() << endl;
        arquivo << gerente.getParticipacaoLucros() << endl;
        arquivo << 0 << endl;

        arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
        arquivo << gerente.getIngressoEmpresa().ano << endl;
        arquivo << gerente.getIngressoEmpresa().mes << endl;
        arquivo << gerente.getIngressoEmpresa().dia << endl;
    }

    arquivo.close();
}

void Empresa::imprimeAsgs()
{
    for (auto asg : asgs)
    {
        asg.imprimirDados();
    }
}

void Empresa::imprimeVendedores()
{
    for (auto vendedor : vendedores)
    {
        vendedor.imprimirDados();
    }
}

void Empresa::imprimeGerentes()
{
    for (auto gerente : gerentes)
    {
        gerente.imprimirDados();
    }
}

void Empresa::imprimeDono()
{
    dono.imprimirDados();
}

Funcionario *Empresa::buscaFuncionario(string matricula)
{
    for (auto &asg : asgs)
    {
        if (asg.getMatricula() == matricula)
        {
            asg.imprimirDados();
            return &asg;
        }
    }

    for (auto &vendedor : vendedores)
    {
        if (vendedor.getMatricula() == matricula)
        {
            vendedor.imprimirDados();
            return &vendedor;
        }
    }

    for (auto &gerente : gerentes)
    {
        if (gerente.getMatricula() == matricula)
        {
            gerente.imprimirDados();
            return &gerente;
        }
    }

    cout << "Funcionário não encontrado no sistema" << endl;
    return nullptr;
}

void Empresa::calculaSalarioFuncionario(string matricula)
{
    // NOTE: O cálculo do salário é feito com base no número de dias de faltas,
    // mas as faltas não foi usada em outro lugar do sistema.

    Funcionario *funcionario = buscaFuncionario(matricula);

    if (funcionario != nullptr)
    {
        cout << "Salário: " << funcionario->calcularSalario(0) << endl
             << endl;
    }
}

void Empresa::calculaTodoOsSalarios()
{
    ofstream arquivo("resultados.txt");

    float totalSalariosASG = 0.0;
    float totalSalariosVendedores = 0.0;
    float totalSalariosGerentes = 0.0;
    float totalSalariosGeral = 0.0;

    arquivo << "Resultados dos cálculos de salários:\n\n";

    // Cálculos para cada ASG
    arquivo << "ASGs:\n";
    for (auto &asg : asgs)
    {
        float salario = asg.calcularSalario(0);
        totalSalariosASG += salario;
        arquivo << "Nome: " << asg.getNome() << ", Cargo: ASG, Salário: " << salario << "\n";
    }
    arquivo << "Total de salários de ASGs: " << totalSalariosASG << "\n\n";

    // Cálculos para cada Vendedor
    arquivo << "Vendedores:\n";
    for (auto &vendedor : vendedores)
    {
        float salario = vendedor.calcularSalario(0);
        totalSalariosVendedores += salario;
        arquivo << "Nome: " << vendedor.getNome() << ", Cargo: Vendedor, Salário: " << salario << "\n";
    }
    arquivo << "Total de salários de Vendedores: " << totalSalariosVendedores << "\n\n";

    // Cálculos para cada Gerente
    arquivo << "Gerentes:\n";
    for (auto &gerente : gerentes)
    {
        float salario = gerente.calcularSalario(0);
        totalSalariosGerentes += salario;
        arquivo << "Nome: " << gerente.getNome() << ", Cargo: Gerente, Salário: " << salario << "\n";
    }
    arquivo << "Total de salários de Gerentes: " << totalSalariosGerentes << "\n\n";

    // Cálculo do total geral de salários
    totalSalariosGeral = totalSalariosASG + totalSalariosVendedores + totalSalariosGerentes;
    arquivo << "Total de salários geral: " << totalSalariosGeral << "\n";

    arquivo.close();

    // Exibição no console
    ifstream arquivoLido("resultados.txt");
    cout << arquivoLido.rdbuf() << endl;
    arquivoLido.close();
}

void Empresa::calcularRescisao(string matricula, Data desligamento)
{
    Funcionario *funcionario = buscaFuncionario(matricula);

    if (funcionario != nullptr)
    {
        cout << "Recisão do Funcionário: " << funcionario->calcularRescisao(desligamento) << endl
             << endl;
    }
}

void Empresa::demitirFuncionario(string matricula, Data desligamento)
{
    const string nomeArquivo = "relatorioDemissional.txt";
    ofstream arquivo(nomeArquivo);

    Funcionario *funcionario = nullptr;
    Pessoa *pessoa = nullptr;
    string cargo = "";

    auto asg = asgs.begin();
    while (asg != asgs.end())
    {
        if (asg->getMatricula() == matricula)
        {
            funcionario = &(*asg);
            pessoa = &(*asg);
            cargo = "ASG";
            asgs.erase(asg);
            break;
        }
        ++asg;
    }

    if (funcionario != nullptr)
    {
        salvarAsgs();
    }
    else
    {
        auto vendedor = vendedores.begin();
        while (vendedor != vendedores.end())
        {
            if (vendedor->getMatricula() == matricula)
            {
                funcionario = &(*vendedor);
                pessoa = &(*vendedor);
                cargo = "Vendedor";
                break;
            }

            ++vendedor;
        }
    }

    if (funcionario != = nullptr)
    {
        salvarVendedores();
    }
    else
    {
        auto gerente = gerentes.begin();
        while (gerente != gerentes.end())
        {
            if (gerente->getMatricula() == matricula)
            {
                funcionario = &(*gerente);
                pessoa = &(*gerente);
                cargo = "Gerente";
                break;
            }

            ++gerente;
        }
    }

    if (funcionario != nullptr)
    {
        salvarGerentes();
    }
    else
    {
        cout << "Funcionário não encontrado no sistema" << endl;
        return;
    }

    float rescisao = funcionario->calcularRescisao(desligamento);

    Data tempoDeTrabalho = dataDiff(desligamento, funcionario->getIngressoEmpresa());

    arquivo << "##############################\n";
    arquivo << "Relatorio Demissional\n";
    arquivo << "##############################\n";
    arquivo << "Cargo: " << cargo << "\n";
    arquivo << "Nome: " << pessoa->getNome() << "\n";
    arquivo << "CPF: " << pessoa->getCpf() << "\n";
    arquivo << "Matrícula: " << funcionario->getMatricula() << "\n";
    arquivo << "Data de ingresso: " << funcionario->getIngressoEmpresa().dia << "/" << funcionario->getIngressoEmpresa().mes << "/" << funcionario->getIngressoEmpresa().ano << "\n";
    arquivo << "Data de demissão: " << desligamento.dia << "/" << desligamento.mes << "/" << desligamento.ano << "\n";
    arquivo << "******************************\n";
    arquivo << "Valor de rescisão: R$ " << rescisao << "\n";
    arquivo << "******************************\n";
    arquivo << "Tempo de Trabalho: " << tempoDeTrabalho.ano - desligamento.ano << " anos, " << tempoDeTrabalho.mes - desligamento.mes << " meses e " << tempoDeTrabalho.dia - desligamento.dia << " dias\n";
}
