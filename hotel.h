#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#include <random>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

// Função para substituir espaços por "-" e vice-versa
string substituirEspacosPorTracos(const string& texto)
{
    string textoFormatado = texto;
    for (char& c : textoFormatado)
    {
        if (c == ' ')
        {
            c = '-';
        }
    }
    return textoFormatado;
}

string substituirTracosPorEspacos(const string& texto)
{
    string textoFormatado = texto;
    for (char& c : textoFormatado)
    {
        if (c == '-')
        {
            c = ' ';
        }
    }
    return textoFormatado;
}

// Função para calcular a diferença em dias entre duas datas no formato "YYYY-MM-DD"
int calcularDiferencaDias(const string& data_inicio, const string& data_fim)
{
    tm tm_inicio = {};
    tm tm_fim = {};
    istringstream ss_inicio(data_inicio);
    istringstream ss_fim(data_fim);
    ss_inicio >> get_time(&tm_inicio, "%Y-%m-%d");
    ss_fim >> get_time(&tm_fim, "%Y-%m-%d");

    time_t time_inicio = mktime(&tm_inicio);
    time_t time_fim = mktime(&tm_fim);

    double seconds = difftime(time_fim, time_inicio);
    int days = seconds / (60 * 60 * 24);

    return days;
}

// CLASSES
class Cliente
{
public:
    Cliente(int id, const string& nome, const string& endereco, const string& telefone)
        : id(id), nome(substituirEspacosPorTracos(nome)), endereco(substituirEspacosPorTracos(endereco)), telefone(substituirEspacosPorTracos(telefone)) {}

    // Getters
    int getId() const
    {
        return id;
    }
    string getNome() const
    {
        return substituirTracosPorEspacos(nome);
    }
    string getEndereco() const
    {
        return substituirTracosPorEspacos(endereco);
    }
    string getTelefone() const
    {
        return substituirTracosPorEspacos(telefone);
    }

    // Salvar cliente em um arquivo
    void salvar(ofstream& arquivo) const
    {
        arquivo << id << " " << nome << " " << endereco << " " << telefone << "\n";
    }

    // Carregar cliente de um arquivo
    static Cliente carregar(ifstream& arquivo)
    {
        int id;
        string nome;
        string endereco;
        string telefone;
        arquivo >> id >> nome >> endereco >> telefone;
        return Cliente(id, nome, endereco, telefone);
    }

private:
    int id;
    string nome;
    string endereco;
    string telefone;
};

class Funcionario
{
public:
    Funcionario(int id, const string& nome, const string& telefone, const string& cargo, double salario)
        : id(id), nome(substituirEspacosPorTracos(nome)), telefone(substituirEspacosPorTracos(telefone)), cargo(substituirEspacosPorTracos(cargo)), salario(salario) {}

    // Getters
    int getId() const
    {
        return id;
    }
    string getNome() const
    {
        return substituirTracosPorEspacos(nome);
    }
    string getTelefone() const
    {
        return substituirTracosPorEspacos(telefone);
    }
    string getCargo() const
    {
        return substituirTracosPorEspacos(cargo);
    }
    double getSalario() const
    {
        return salario;
    }

    // Método para salvar funcionário
    void salvar(ofstream& arquivo) const
    {
        arquivo << id << " " << nome << " " << telefone << " " << cargo << " " << salario << "\n";
    }

    // Método carregar funcionário
    static Funcionario carregar(ifstream& arquivo)
    {
        int id;
        string nome;
        string telefone;
        string cargo;
        double salario;
        arquivo >> id >> nome >> telefone >> cargo >> salario;
        return Funcionario(id, nome, telefone, cargo, salario);
    }

private:
    int id;
    string nome;
    string telefone;
    string cargo;
    double salario;
};

class Quarto
{
public:
    Quarto(int numero, int quantidade_hospedes, double valor_diaria, const string& status)
        : numero(numero), quantidade_hospedes(quantidade_hospedes), valor_diaria(valor_diaria), status(substituirEspacosPorTracos(status)) {}

    // Getters
    int getNumero() const
    {
        return numero;
    }
    int getQuantidadeHospedes() const
    {
        return quantidade_hospedes;
    }
    double getValorDiaria() const
    {
        return valor_diaria;
    }
    string getStatus() const
    {
        return substituirTracosPorEspacos(status);
    }

    // Setters
    void setStatus(const string& novo_status)
    {
        status = substituirEspacosPorTracos(novo_status);
    }

    // Método para salvar quarto
    void salvar(ofstream& arquivo) const
    {
        arquivo << numero << " " << quantidade_hospedes << " " << valor_diaria << " " << status << "\n";
    }

    // Método carregar quarto
    static Quarto carregar(ifstream& arquivo)
    {
        int numero;
        int quantidade_hospedes;
        double valor_diaria;
        string status;
        arquivo >> numero >> quantidade_hospedes >> valor_diaria >> status;
        return Quarto(numero, quantidade_hospedes, valor_diaria, status);
    }

private:
    int numero;
    int quantidade_hospedes;
    double valor_diaria;
    string status;
};

class Estadia
{
public:
    Estadia(int id_cliente, int numero_quarto, int codigo, const string& data_entrada, const string& data_saida, int qte_diarias)
        : id_cliente(id_cliente), numero_quarto(numero_quarto), codigo(codigo), data_entrada(data_entrada), data_saida(data_saida), qte_diarias(qte_diarias) {}

    // Getters
    string getNomeCliente() const
    {
        return substituirTracosPorEspacos(nome_cliente);
    }
    string getDataEntrada() const
    {
        return data_entrada;
    }
    string getDataSaida() const
    {
        return data_saida;
    }
    int getNumeroQuarto() const
    {
        return numero_quarto;
    }
    int getCodigo() const
    {
        return codigo;
    }
    int getQteDiarias() const
    {
        return qte_diarias;
    }
    int getIdCliente() const
    {
        return id_cliente;
    }

    // Método para salvar estadia em arquivo
    void salvar(ofstream& arquivo) const
    {
        arquivo << id_cliente << " " << numero_quarto << " " << codigo << " " << data_entrada << " " << data_saida << " " << qte_diarias << " " << "\n";
    }

    // Método estático para carregar estadia do arquivo
    static Estadia carregar(ifstream& arquivo)
    {
        string nome_cliente, data_entrada, data_saida;
        int numero_quarto, codigo, qte_diarias, id_cliente;
        arquivo >> id_cliente >> numero_quarto >> codigo >> data_entrada >> data_saida >> qte_diarias;
        return Estadia(id_cliente, numero_quarto, codigo, data_entrada, data_saida, qte_diarias);
    }

private:
    string nome_cliente;
    int numero_quarto;
    int codigo;
    string data_entrada;
    string data_saida;
    int qte_diarias;
    int id_cliente;
};

// CABEÇALHOS
void cadastrar_cliente(const string& nome, const string& endereco, const string& telefone);
void cadastrar_funcionario(const string& nome, const string& telefone, const string& cargo, double salario);
void cadastrar_quarto(int numero, int quantidade_hospedes, double valor_diaria, const string& status);
void cadastrar_estadia(int id_cliente, int numero_quarto, int quantidade_diarias, const string& data_saida, const string& data_entrada);

void finalizar_estadia(int numero_quarto);
void pesquisar_pessoa(int id, const string& tipo_pessoa);
void imprimir_estadias_cliente(int id_cliente);

void salvar_clientes(const vector<Cliente>& clientes);
void salvar_quartos(const vector<Quarto>& quartos);
void salvar_funcionarios(const vector<Funcionario>& funcionarios);
void salvar_estadias(const vector<Estadia>& estadias);
int gerar_id_cliente();
int gerar_id_funcionario();
int gerar_codigo_estadia();
int calcular_pontos_fidelidade(const string& nome_cliente, int id_cliente);
int buscar_id_cliente(const string& nome_cliente);

vector<Cliente> carregar_clientes();
vector<Funcionario> carregar_funcionarios();
vector<Quarto> carregar_quartos();
vector<Estadia> carregar_estadias();

// VETORES
vector<Cliente> clientes = carregar_clientes();
vector<Funcionario> funcionarios = carregar_funcionarios();
vector<Quarto> quartos = carregar_quartos();
vector<Estadia> estadias = carregar_estadias();


int buscar_id_cliente(const string& nome_cliente)
{
    string nome_formatado = substituirEspacosPorTracos(nome_cliente);
    for (const auto& cliente : clientes)
    {
        if (cliente.getNome() == nome_formatado)
        {
            return cliente.getId();
        }
    }
    return -1; // Retorna -1 se o cliente não for encontrado
}

// FUNÇÕES E PROCEDIMENTOS PARA CADASTRAR CLIENTE, SALVAR E CARREGAR
int gerar_id_cliente()
{
    ifstream arquivo("clientes.txt");
    if (!arquivo.is_open())
    {
        return 0;
    }
    string linha;
    int maior_id = -1;
    while (getline(arquivo, linha))
    {
        istringstream iss(linha);
        int id;
        iss >> id;
        if (id > maior_id)
        {
            maior_id = id;
        }
    }
    arquivo.close();
    return maior_id + 1;
}

// Função para cadastrar cliente
void cadastrar_cliente(const string& nome, const string& endereco, const string& telefone)
{
    int id = gerar_id_cliente();
    Cliente novo_cliente(id, nome, endereco, telefone);

    ofstream arquivo("clientes.txt", ios::app);
    if (arquivo.is_open())
    {
        novo_cliente.salvar(arquivo);
        clientes.push_back(novo_cliente); // Adiciona o novo cliente ao vetor de clientes
        arquivo.close();
        cout << "Cliente cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo de clientes." << endl;
    }
}

void salvar_clientes(const vector<Cliente>& clientes)
{
    ofstream arquivo("clientes.txt");
    if (arquivo.is_open())
    {
        for (const auto& cliente : clientes)
        {
            cliente.salvar(arquivo);
        }
        arquivo.close();
    }
}

vector<Cliente> carregar_clientes()
{
    vector<Cliente> clientes_carregados;
    ifstream arquivo("clientes.txt");
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            istringstream iss(linha);
            int id;
            string nome, endereco, telefone;
            iss >> id >> nome >> endereco >> telefone;
            if (!iss.fail()) // Verifica se a leitura foi bem-sucedida
            {
                clientes_carregados.push_back(Cliente(id, substituirTracosPorEspacos(nome), substituirTracosPorEspacos(endereco), substituirTracosPorEspacos(telefone)));
            }
        }
        arquivo.close();
    }
    return clientes_carregados;
}


// FUNÇÕES E PROCEDIMENTOS PARA CADASTRAR FUNCIONARIO, SALVAR E CARREGAR
int gerar_id_funcionario()
{
    ifstream arquivo("funcionarios.txt");
    if (!arquivo.is_open())
    {
        return 0;
    }
    string linha;
    int maior_id = -1;
    while (getline(arquivo, linha))
    {
        istringstream iss(linha);
        int id;
        iss >> id;
        if (id > maior_id)
        {
            maior_id = id;
        }
    }
    arquivo.close();
    return maior_id + 1;
}

void cadastrar_funcionario(const string& nome, const string& telefone, const string& cargo, double salario)
{
    int id = gerar_id_funcionario();
    Funcionario novo_funcionario(id, nome, telefone, cargo, salario);

    ofstream arquivo("funcionarios.txt", ios::app);
    if (arquivo.is_open())
    {
        novo_funcionario.salvar(arquivo);
        arquivo.close();
        cout << "Funcionário cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo de funcionários." << endl;
    }
}

void salvar_funcionarios(const vector<Funcionario>& funcionarios)
{
    ofstream arquivo("funcionarios.txt");
    if (arquivo.is_open())
    {
        for (const auto& funcionario : funcionarios)
        {
            funcionario.salvar(arquivo);
        }
        arquivo.close();
    }
}

vector<Funcionario> carregar_funcionarios()
{
    vector<Funcionario> funcionarios_carregados;
    ifstream arquivo("funcionarios.txt");
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            istringstream iss(linha);
            int id;
            string nome, telefone, cargo;
            double salario;
            iss >> id >> nome >> telefone >> cargo >> salario;
            if (!iss.fail()) // Verifica se a leitura foi bem-sucedida
            {
                funcionarios_carregados.push_back(Funcionario(id, nome, telefone, cargo, salario));
            }
        }
        arquivo.close();
    }
    return funcionarios_carregados;
}


// FUNÇÕES E PROCEDIMENTOS PARA CADASTRAR QUARTO, SALVAR E CARREGAR
void cadastrar_quarto(int numero, int quantidade_hospedes, double valor_diaria, const string& status)
{
    Quarto novo_quarto(numero, quantidade_hospedes, valor_diaria, status);

    ofstream arquivo("quartos.txt", ios::app);
    if (arquivo.is_open())
    {
        novo_quarto.salvar(arquivo);
        arquivo.close();
        cout << "Quarto cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo de quartos." << endl;
    }
}

void salvar_quartos(const vector<Quarto>& quartos)
{
    ofstream arquivo("quartos.txt");
    if (arquivo.is_open())
    {
        for (const auto& quarto : quartos)
        {
            quarto.salvar(arquivo);
        }
        arquivo.close();
    }
}

vector<Quarto> carregar_quartos()
{
    vector<Quarto> quartos_carregados;
    ifstream arquivo("quartos.txt");
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            istringstream iss(linha);
            int numero, quantidade_hospedes;
            double valor_diaria;
            string status;
            iss >> numero >> quantidade_hospedes >> valor_diaria >> status;
            if (!iss.fail()) // Verifica se a leitura foi bem-sucedida
            {
                quartos_carregados.push_back(Quarto(numero, quantidade_hospedes, valor_diaria, status));
            }
        }
        arquivo.close();
    }
    return quartos_carregados;
}


// FUNÇÕES E PROCEDIMENTOS PARA CADASTRAR ESTADIA, SALVAR E CARREGAR
int gerar_codigo_estadia()
{
    ifstream arquivo("estadias.txt");
    if (!arquivo.is_open())
    {
        return 0;
    }

    string linha;
    int maior_id = -1;
    while (getline(arquivo, linha))
    {
        istringstream iss(linha);
        int id;
        iss >> id;
        if (id > maior_id)
        {
            maior_id = id;
        }
    }

    arquivo.close();
    return maior_id + 1;
}

void cadastrar_estadia(int id_cliente, int numero_quarto, int quantidade_diarias, const string& data_saida, const string& data_entrada)
{
    int codigo_estadia = gerar_codigo_estadia();
    if (id_cliente == -1)
    {
        cout << "Erro: Cliente não encontrado." << endl;
        return;
    }
    Estadia nova_estadia(id_cliente, numero_quarto, codigo_estadia, data_entrada, data_saida, quantidade_diarias);
    ofstream arquivo("estadias.txt", ios::app);
    if (arquivo.is_open())
    {
        nova_estadia.salvar(arquivo);
        estadias.push_back(nova_estadia); // Adiciona a nova estadia ao vetor de estadias
        arquivo.close();
        cout << "Estadia cadastrada com sucesso!" << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo de estadias." << endl;
    }
}

void salvar_estadias(const vector<Estadia>& estadias)
{
    ofstream arquivo("estadias.txt");
    if (arquivo.is_open())
    {
        for (const auto& estadia : estadias)
        {
            estadia.salvar(arquivo);
        }
        arquivo.close();
    }
}

vector<Estadia> carregar_estadias()
{
    vector<Estadia> estadias_carregadas;
    ifstream arquivo("estadias.txt");
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            istringstream iss(linha);
            string data_entrada, data_saida;
            int numero_quarto, codigo, qte_diarias, id_cliente;
            iss >> id_cliente >> numero_quarto >> codigo >> data_entrada >> data_saida >> qte_diarias;
            if (!iss.fail()) // Verifica se a leitura foi bem-sucedida
            {
                estadias_carregadas.push_back(Estadia(id_cliente, numero_quarto, codigo, data_entrada, data_saida, qte_diarias));
            }
        }
        arquivo.close();
    }
    return estadias_carregadas;
}

int calcular_pontos_fidelidade(const string& nome_cliente, int id_cliente)
{
    int pontos = 0;
    for (const auto& estadia : estadias)
    {
        if (estadia.getIdCliente() == id_cliente)
        {
            pontos += estadia.getQteDiarias();
        }
    }
    return pontos;
}

// PROCEDIMENTO PARA IMPRIMIT AS ESTADIAS DO CLIENTE
void imprimir_estadias_cliente(int id_cliente)
{
    vector<Estadia> estadias_cliente_encontradas;

    ifstream arquivo("estadias.txt");
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            istringstream iss(linha);
            int id_cliente_arquivo, numero_quarto, codigo, qte_diarias;
            string data_entrada, data_saida;
            iss >> id_cliente_arquivo >> numero_quarto >> codigo >> data_entrada >> data_saida >> qte_diarias;

            if (id_cliente_arquivo == id_cliente)
            {
                Estadia estadia(id_cliente, numero_quarto, codigo, data_entrada, data_saida, qte_diarias);
                estadias_cliente_encontradas.push_back(estadia);
            }
        }
        arquivo.close();

        // Imprime as estadias encontradas
        if (!estadias_cliente_encontradas.empty())
        {
            cout << "Estadias do cliente com ID " << id_cliente << ":" << endl;
            for (const auto& estadia : estadias_cliente_encontradas)
            {
                cout << "Código da estadia: " << estadia.getCodigo() << endl;
                cout << "Número do quarto: " << estadia.getNumeroQuarto() << endl;
                cout << "Data de entrada: " << estadia.getDataEntrada() << endl;
                cout << "Data de saída: " << estadia.getDataSaida() << endl;
                cout << "Quantidade de diárias: " << estadia.getQteDiarias() << endl;
                cout << "---------------------" << endl;
            }
        }
        else
        {
            cout << "Nenhuma estadia encontrada para o cliente com ID " << id_cliente << "." << endl;
        }
    }
    else
    {
        cout << "Não foi possível abrir o arquivo de estadias." << endl;
    }
}

bool verificar_disponibilidade_quarto(int numero_quarto, const string& data_entrada, const string& data_saida)
{
    for (const auto& estadia : estadias)
    {
        if (estadia.getNumeroQuarto() == numero_quarto)
        {
            // Verifica se as datas de entrada e saída não conflitam
            if ((data_entrada >= estadia.getDataEntrada() && data_entrada <= estadia.getDataSaida()) ||
                (data_saida >= estadia.getDataEntrada() && data_saida <= estadia.getDataSaida()) ||
                (data_entrada <= estadia.getDataEntrada() && data_saida >= estadia.getDataSaida()))
            {
                return false;
            }
        }
    }
    return true;
}


double calcular_valor_estadia(int numero_quarto, const string& data_entrada, const string& data_saida)
{
    for (const auto& quarto : quartos)
    {
        if (quarto.getNumero() == numero_quarto)
        {
            int dias = calcularDiferencaDias(data_entrada, data_saida);
            return dias * quarto.getValorDiaria();
        }
    }
    return 0.0; // Retorna 0.0 se o quarto não for encontrado
}

// FUNÇÃO PARA PESQUISAR PESSOA PELO ID E IMPRIMIR OS DADOS
void pesquisar_pessoa(int id, const string& tipo_pessoa)
{
    if (tipo_pessoa == "cliente")
    {
        for (const auto& cliente : clientes)
        {
            if (cliente.getId() == id)
            {
                cout << "ID: " << cliente.getId() << endl;
                cout << "Nome: " << cliente.getNome() << endl;
                cout << "Endereço: " << cliente.getEndereco() << endl;
                cout << "Telefone: " << cliente.getTelefone() << endl;
                return;
            }
        }
    }
    else if (tipo_pessoa == "funcionario")
    {
        for (const auto& funcionario : funcionarios)
        {
            if (funcionario.getId() == id)
            {
                cout << "ID: " << funcionario.getId() << endl;
                cout << "Nome: " << funcionario.getNome() << endl;
                cout << "Telefone: " << funcionario.getTelefone() << endl;
                cout << "Cargo: " << funcionario.getCargo() << endl;
                cout << "Salário: " << funcionario.getSalario() << endl;
                return;
            }
        }
    }
    cout << "Pessoa não encontrada." << endl;
}

// FUNÇÃO PARA FINALIZAR UMA ESTADIA
void finalizar_estadia(int numero_quarto)
{
    for (auto it = estadias.begin(); it != estadias.end(); ++it)
    {
        if (it->getNumeroQuarto() == numero_quarto)
        {
            // Calcular o valor da estadia
            double valor_estadia = calcular_valor_estadia(numero_quarto, it->getDataEntrada(), it->getDataSaida());

            // Remover a estadia do vetor
            estadias.erase(it);

            // Salvar as estadias atualizadas no arquivo
            salvar_estadias(estadias);

            cout << "Estadia finalizada com sucesso!" << endl;
            cout << "Valor da estadia: R$ " << fixed << setprecision(2) << valor_estadia << endl;
            return;
        }
    }
    cout << "Estadia não encontrada." << endl;
}


#endif // HOTEL_H_INCLUDED
