#include "entities/empresa.hpp"

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

        fstream file(filePath, modo);

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
            else if (linha.find("demitirFuncionario()") == 0)
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
                demitirFuncionario(matricula, desligamento);
            }
            else if (linha == "contratarFuncionario()")
            {
                contratarFuncionario();
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
        std::cout << "Erro ao executar as funções: " << ex.what() << endl;
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
                Endereco endereco{cidade, bairro, rua, cep, numero};

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
                Endereco endereco{cidade, bairro, rua, cep, numero};

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
                Endereco endereco{cidade, bairro, rua, cep, numero};

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
                Endereco endereco{cidade, bairro, rua, cep, numero};

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
    try
    {

        fstream arquivo = abrirArquivo("asg.txt", ios_base::out | ios_base::trunc);

        stringstream buffer;

        std::cout << ">>> Salvando Asgs..." << endl;

        int i = 0;
        for (const auto &asg : asgs)
        {
            buffer << "#########################################################" << endl;
            buffer << "ASG Nº: " << i++ << endl;
            buffer << "##### DADOS PESSOAIS #####" << endl;
            buffer << asg.getNome() << endl;
            buffer << asg.getCpf() << endl;
            buffer << asg.getQtdFilhos() << endl;
            buffer << asg.getEstadoCivil() << endl;

            buffer << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            buffer << asg.getEnderecoPessoal().cidade << endl;
            buffer << asg.getEnderecoPessoal().cep << endl;
            buffer << asg.getEnderecoPessoal().bairro << endl;
            buffer << asg.getEnderecoPessoal().rua << endl;
            buffer << asg.getEnderecoPessoal().numero << endl;

            buffer << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            buffer << asg.getDataNascimento().ano << endl;
            buffer << asg.getDataNascimento().mes << endl;
            buffer << asg.getDataNascimento().dia << endl;

            buffer << "##### DADOS FUNCIONAIS #####" << endl;
            buffer << asg.getMatricula() << endl;
            buffer << asg.getSalario() << endl;
            buffer << asg.getAdicionalInsalubridade() << endl;
            buffer << "0" << endl;

            buffer << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            buffer << asg.getIngressoEmpresa().ano << endl;
            buffer << asg.getIngressoEmpresa().mes << endl;
            buffer << asg.getIngressoEmpresa().dia << endl;
        }

        std::cout << buffer.str() << endl;

        arquivo << buffer.str();
        arquivo.close();

        buffer.clear();
    }
    catch (const exception &ex)
    {
        // Tratamento de erro
        cerr << "Erro: " << ex.what() << endl;
    }
}

void Empresa::salvarVendedores()
{
    try
    {

        fstream arquivo = abrirArquivo("vendedor.txt", ios_base::out | ios_base::trunc);

        stringstream buffer;

        std::cout << ">>> Salvando vendedores..." << endl;

        int i = 0;
        for (const Vendedor &vendedor : vendedores)
        {
            buffer << "#########################################################" << endl;
            buffer << "VENDEDOR Nº: " << i++ << endl;
            buffer << "##### DADOS PESSOAIS #####" << endl;
            buffer << vendedor.getNome() << endl;
            buffer << vendedor.getCpf() << endl;
            buffer << vendedor.getQtdFilhos() << endl;
            buffer << vendedor.getEstadoCivil() << endl;

            buffer << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            buffer << vendedor.getEnderecoPessoal().cidade << endl;
            buffer << vendedor.getEnderecoPessoal().cep << endl;
            buffer << vendedor.getEnderecoPessoal().bairro << endl;
            buffer << vendedor.getEnderecoPessoal().rua << endl;
            buffer << vendedor.getEnderecoPessoal().numero << endl;

            buffer << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            buffer << vendedor.getDataNascimento().ano << endl;
            buffer << vendedor.getDataNascimento().mes << endl;
            buffer << vendedor.getDataNascimento().dia << endl;

            buffer << "##### DADOS FUNCIONAIS #####" << endl;
            buffer << vendedor.getMatricula() << endl;
            buffer << vendedor.getSalario() << endl;
            buffer << vendedor.getTipoVendedor() << endl;
            buffer << 0 << endl;

            buffer << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            buffer << vendedor.getIngressoEmpresa().ano << endl;
            buffer << vendedor.getIngressoEmpresa().mes << endl;
            buffer << vendedor.getIngressoEmpresa().dia << endl;
        }

        std::cout << buffer.str();

        arquivo << buffer.str();
        arquivo.close();

        buffer.clear();
    }
    catch (const exception &ex)
    {
        // Tratamento de erro
        cerr << "Erro: " << ex.what() << endl;
    }
}

void Empresa::salvarGerentes()
{
    try
    {

        fstream arquivo = abrirArquivo("gerente.txt", ios_base::out);

        stringstream buffer;

        std::cout << ">>> Salvando gerentes..." << endl;

        int i = 0;
        for (const Gerente &gerente : gerentes)
        {
            buffer << "#########################################################" << endl;
            buffer << "GERENTE Nº: " << i++ << endl;
            buffer << "##### DADOS PESSOAIS #####" << endl;
            buffer << gerente.getNome() << endl;
            buffer << gerente.getCpf() << endl;
            buffer << gerente.getQtdFilhos() << endl;
            buffer << gerente.getEstadoCivil() << endl;

            buffer << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            buffer << gerente.getEnderecoPessoal().cidade << endl;
            buffer << gerente.getEnderecoPessoal().cep << endl;
            buffer << gerente.getEnderecoPessoal().bairro << endl;
            buffer << gerente.getEnderecoPessoal().rua << endl;
            buffer << gerente.getEnderecoPessoal().numero << endl;

            buffer << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            buffer << gerente.getDataNascimento().ano << endl;
            buffer << gerente.getDataNascimento().mes << endl;
            buffer << gerente.getDataNascimento().dia << endl;

            buffer << "##### DADOS FUNCIONAIS #####" << endl;
            buffer << gerente.getMatricula() << endl;
            buffer << gerente.getSalario() << endl;
            buffer << gerente.getParticipacaoLucros() << endl;
            buffer << 0 << endl;

            buffer << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            buffer << gerente.getIngressoEmpresa().ano << endl;
            buffer << gerente.getIngressoEmpresa().mes << endl;
            buffer << gerente.getIngressoEmpresa().dia << endl;
        }

        std::cout << buffer.str();

        arquivo << buffer.str();
        arquivo.close();
        
        buffer.clear();
    }
    catch (const exception &ex)
    {
        // Tratamento de erro
        cerr << "Erro: " << ex.what() << endl;
    }
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

    std::cout << "Funcionário não encontrado no sistema" << endl;
    return nullptr;
}

void Empresa::calculaSalarioFuncionario(string matricula)
{
    // NOTE: O cálculo do salário é feito com base no número de dias de faltas,
    // mas as faltas não foi usada em outro lugar do sistema.

    Funcionario *funcionario = buscaFuncionario(matricula);

    if (funcionario != nullptr)
    {
        std::cout << "Salário: " << funcionario->calcularSalario(0) << endl
                  << endl;
    }
}

void Empresa::calculaTodoOsSalarios()
{
    fstream arquivo = abrirArquivo("out/relatorioFinanceiro.txt", ios_base::out | ios_base::trunc);
    stringstream buffer;

    float totalSalarios = 0.0;
    float faturamentoMensal = 20957.15; // Valor fictício para o faturamento mensal

    buffer << "######### Relatório Financeiro ########\n\n";

    // Cálculos para cada ASG
    buffer << "Cargo: ASG\n";
    float totalSalariosASG = 0.0;
    for (auto &asg : asgs)
    {
        float salario = asg.calcularSalario(0);
        totalSalariosASG += salario;
        buffer << asg.getMatricula() << " - " << asg.getNome() << " - R$ " << salario << "\n";
    }
    buffer << "Total ASG: " << totalSalariosASG << "\n\n";
    totalSalarios += totalSalariosASG;

    // Cálculos para cada Vendedor
    buffer << "Cargo: Vendedor\n";
    float totalSalariosVendedores = 0.0;
    for (auto &vendedor : vendedores)
    {
        float salario = vendedor.calcularSalario(0);
        totalSalariosVendedores += salario;
        buffer << vendedor.getMatricula() << " - " << vendedor.getNome() << " - R$ " << salario << "\n";
    }
    buffer << "Total Vendedor: " << totalSalariosVendedores << "\n\n";
    totalSalarios += totalSalariosVendedores;

    // Cálculos para cada Gerente
    buffer << "Cargo: Gerente\n";
    float totalSalariosGerentes = 0.0;
    for (auto &gerente : gerentes)
    {
        float salario = gerente.calcularSalario(0);
        totalSalariosGerentes += salario;
        buffer << gerente.getMatricula() << " - " << gerente.getNome() << " - R$ " << salario << "\n";
    }
    buffer << "Total Gerente: " << totalSalariosGerentes << "\n\n";
    totalSalarios += totalSalariosGerentes;

    buffer << "CUSTO TOTAL: R$ " << totalSalarios << "\n\n";
    buffer << "FATURAMENTO MENSAL: R$ " << faturamentoMensal << "\n\n";

    // Cálculo das porcentagens
    float porcentagemASG = (totalSalariosASG / totalSalarios) * 100.0;
    float porcentagemVendedores = (totalSalariosVendedores / totalSalarios) * 100.0;
    float porcentagemGerentes = (totalSalariosGerentes / totalSalarios) * 100.0;
    buffer << "Custo ASG(%): " << porcentagemASG << "%\n";
    buffer << "Custo Vendedor(%): " << porcentagemVendedores << "%\n";
    buffer << "Custo Gerente(%): " << porcentagemGerentes << "%\n\n";

    // Cálculo do lucro
    float lucro = faturamentoMensal - totalSalarios;
    buffer << "LUCRO DA EMPRESA: R$ " << lucro << "\n\n";
    if (lucro >= 0)
    {
        buffer << "SITUAÇÃO: Lucro\n";
    }
    else
    {
        buffer << "SITUAÇÃO: Prejuízo\n";
    }

    std::cout << buffer.str();

    arquivo << buffer.str();
    arquivo.close();

    buffer.clear();
}

void Empresa::calcularRescisao(string matricula, Data desligamento)
{
    Funcionario *funcionario = buscaFuncionario(matricula);

    if (funcionario != nullptr)
    {
        std::cout << "Recisão do Funcionário: " << funcionario->calcularRescisao(desligamento) << endl
                  << endl;
    }
}

void Empresa::demitirFuncionario(string matricula, Data desligamento)
{
    fstream arquivo = abrirArquivo("out/relatorioDemissional.txt");

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

    if (funcionario != nullptr)
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
        std::cout << "Funcionário não encontrado no sistema" << endl;
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

void Empresa::contratarFuncionario()
{
    fstream arquivo = abrirArquivo("novoFuncionario.txt");

    string tipoFuncionario;
    string linha;
    getline(arquivo, tipoFuncionario);

    getline(arquivo, linha); // Ignorar linha "##### DADOS PESSOAIS #####"
    getline(arquivo, linha);
    string nome = linha;
    getline(arquivo, linha);
    string cpf = linha;
    getline(arquivo, linha);
    int qtdFilhos = stoi(linha);
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
    Endereco enderecoPessoal{cidade, bairro, rua, cep, numero};

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
    string matricula = linha;
    getline(arquivo, linha);
    float salarioBase = stof(linha);
    getline(arquivo, linha);
    string salarioVariante = linha;
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

    if (tipoFuncionario == "ASG")
    {
        cout << "Salário Variante: " << salarioVariante << endl;
        asgs.push_back(Asg(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salarioBase, matricula, dataIngresso, stof(salarioVariante)));
        salvarAsgs();
    }
    else if (tipoFuncionario == "Vendedor")
    {
        vendedores.push_back(Vendedor(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salarioBase, matricula, dataIngresso, salarioVariante[0]));
        salvarVendedores();
    }
    else if (tipoFuncionario == "Gerente")
    {
        gerentes.push_back(Gerente(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos, salarioBase, matricula, dataIngresso, stof(salarioVariante)));
        salvarGerentes();
    }

    std::cout << tipoFuncionario << " contratado com sucesso!" << endl;

    arquivo.close();
}
