#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#include <random>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;


// FALTA IMPLEMENTAR:

// O CALCULO DE PONTOS DE FIDELIDADE
// CHECAR A DISPONIBILIDADE DE QUARTO NA ESTADIA
// O CALCULO DE DATA DE ENTRADA E SAIDA PARA O VALOR DA ESTADIA


// CLASSES
class Cliente
{
public:
    Cliente(int id, const string& nome, const string& endereco, const string& telefone)
        : id(id), nome(nome), endereco(endereco), telefone(telefone) {}

    // Getters
    int getId() const
    {
        return id;
    }
    string getNome() const
    {
        return nome;
    }
    string getEndereco() const
    {
        return endereco;
    }
    string getTelefone() const
    {
        return telefone;
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
        : id(id), nome(nome), telefone(telefone), cargo(cargo), salario(salario) {}

    // Getters
    int getId() const
    {
        return id;
    }
    string getNome() const
    {
        return nome;
    }
    string getTelefone() const
    {
        return telefone;
    }
    string getCargo() const
    {
        return cargo;
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
        : numero(numero), quantidade_hospedes(quantidade_hospedes), valor_diaria(valor_diaria), status(status) {}

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
        return status;
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
    Estadia(const string& nome_cliente, int numero_quarto, int codigo, const string& data_entrada, const string& data_saida, int qte_diarias, int id_cliente)
        : nome_cliente(nome_cliente), numero_quarto(numero_quarto), codigo(codigo), data_entrada(data_entrada), data_saida(data_saida), qte_diarias(qte_diarias), id_cliente(id_cliente) {}

    // Getters
    string getNomeCliente() const
    {
        return nome_cliente;
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
        arquivo << nome_cliente << " " << numero_quarto << " " << codigo << " " << data_entrada << " " << data_saida << " " << qte_diarias << " " << id_cliente << "\n";
    }

    // Método estático para carregar estadia do arquivo
    static Estadia carregar(ifstream& arquivo)
    {
        string nome_cliente, data_entrada, data_saida;
        int numero_quarto, codigo, qte_diarias, id_cliente;
        arquivo >> nome_cliente >> numero_quarto >> codigo >> data_entrada >> data_saida >> qte_diarias >> id_cliente;
        return Estadia(nome_cliente, numero_quarto, codigo, data_entrada, data_saida, qte_diarias, id_cliente);
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
void cadastrar_estadia(const string& nome_cliente, int numero_quarto, int quantidade_diarias, const string& data_saida, const string& data_entrada);

void finalizar_estadia(int numero_quarto);
void pesquisar_pessoa(int id, const string& tipo_pessoa);
vector<Estadia> estadias_cliente(const string& nome_cliente);

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
    for (const auto& cliente : clientes)
    {
        if (cliente.getNome() == nome_cliente)
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

void cadastrar_cliente(const string& nome, const string& endereco, const string& telefone)
{
    int id = gerar_id_cliente();
    Cliente novo_cliente(id, nome, endereco, telefone);

    ofstream arquivo("clientes.txt", ios::app);
    if (arquivo.is_open())
    {
        novo_cliente.salvar(arquivo);
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
                clientes_carregados.push_back(Cliente(id, nome, endereco, telefone));
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

void cadastrar_estadia(const string& nome_cliente, int numero_quarto, int quantidade_diarias, const string& data_saida, const string& data_entrada)
{
    int codigo_estadia = gerar_codigo_estadia();
    int id_cliente = buscar_id_cliente(nome_cliente);
    if (id_cliente == -1)
    {
        cout << "Erro: Cliente não encontrado." << endl;
        return;
    }
    Estadia nova_estadia(nome_cliente, numero_quarto, codigo_estadia, data_entrada, data_saida, quantidade_diarias, id_cliente);
    ofstream arquivo("estadias.txt", ios::app);
    if (arquivo.is_open())
    {
        nova_estadia.salvar(arquivo);
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
            string nome_cliente, data_entrada, data_saida;
            int numero_quarto, codigo, qte_diarias, id_cliente;
            iss >> nome_cliente >> numero_quarto >> codigo >> data_entrada >> data_saida >> qte_diarias >> id_cliente;
            if (!iss.fail()) // Verifica se a leitura foi bem-sucedida
            {
                estadias_carregadas.push_back(Estadia(nome_cliente, numero_quarto, codigo, data_entrada, data_saida, qte_diarias, id_cliente));
            }
        }
        arquivo.close();
    }
    return estadias_carregadas;
}

int calcular_pontos_fidelidade(const string& nome_cliente, int id_cliente)
{
    // Implementar lógica de cálculo de pontos de fidelidade
    return 0;
}

// FUNÇÃO PARA PEGAR AS ESTADIAS DO CLIENTE
vector<Estadia> estadias_cliente(const string& nome_cliente)
{
    vector<Estadia> estadias_cliente;
    for (const auto& estadia : estadias)
    {
        if (estadia.getNomeCliente() == nome_cliente)
        {
            estadias_cliente.push_back(estadia);
        }
    }
    return estadias_cliente;
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
            estadias.erase(it);
            cout << "Estadia finalizada com sucesso!" << endl;
            return;
        }
    }
    cout << "Estadia não encontrada." << endl;
}


#endif // HOTEL_H_INCLUDED
