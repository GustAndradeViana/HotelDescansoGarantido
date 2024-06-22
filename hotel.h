#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#include <random>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// CLASSES
class Cliente {
public:
    Cliente(int id, const string& nome, const string& idade) : id(id), nome(nome), idade(idade) {}

    // Getters
    int getId() const { return id; }
    string getNome() const { return nome; }
    string getIdade() const { return idade; }

    // Salvar cliente em um arquivo
    void salvar(ofstream& arquivo) const {
        arquivo << id << " " << nome << " " << idade << "\n";
    }

    // Carregar cliente de um arquivo
    static Cliente carregar(ifstream& arquivo) {
        int id;
        string nome;
        string idade;
        arquivo >> id >> nome >> idade;
        return Cliente(id, nome, idade);
    }

private:
    int id;
    string nome;
    string idade;
};

class Funcionario {
public:
    Funcionario(int id, const string& nome, const string& telefone, const string& cargo, double salario)
        : id(id), nome(nome), telefone(telefone), cargo(cargo), salario(salario) {}

    // Métodos getters
    int getId() const { return id; }
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }
    string getCargo() const { return cargo; }
    double getSalario() const { return salario; }

    // Método para salvar funcionário
    void salvar(ofstream& arquivo) const {
        arquivo << id << " " << nome << " " << telefone << " " << cargo << " " << salario << "\n";
    }

    // Método carregar funcionário
    static Funcionario carregar(ifstream& arquivo) {
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

class Quarto {
public:
    Quarto(int numero, int quantidade_hospedes, double valor_diaria, const string& status)
        : numero(numero), quantidade_hospedes(quantidade_hospedes), valor_diaria(valor_diaria), status(status) {}

    // Métodos getters
    int getNumero() const { return numero; }
    int getQuantidadeHospedes() const { return quantidade_hospedes; }
    double getValorDiaria() const { return valor_diaria; }
    string getStatus() const { return status; }

    // Método para salvar quarto
    void salvar(ofstream& arquivo) const {
        arquivo << numero << " " << quantidade_hospedes << " " << valor_diaria << " " << status << "\n";
    }

    // Método carregar quarto
    static Quarto carregar(ifstream& arquivo) {
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

class Estadia {
public:
    Estadia(const string& nome_cliente, int andar_quarto, int numero_quarto)
        : nome_cliente(nome_cliente), andar_quarto(andar_quarto), numero_quarto(numero_quarto) {}

    // Métodos getters
    string getNomeCliente() const { return nome_cliente; }
    int getAndarQuarto() const { return andar_quarto; }
    int getNumeroQuarto() const { return numero_quarto; }

    // Método para salvar estadia em arquivo
    void salvar(ofstream& arquivo) const {
        arquivo << nome_cliente << " " << andar_quarto << " " << numero_quarto << "\n";
    }

    // Método estático para carregar estadia do arquivo
    static Estadia carregar(ifstream& arquivo) {
        string nome_cliente;
        int andar_quarto, numero_quarto;
        arquivo >> nome_cliente >> andar_quarto >> numero_quarto;
        return Estadia(nome_cliente, andar_quarto, numero_quarto);
    }

private:
    string nome_cliente;
    int andar_quarto;
    int numero_quarto;
};




// CABEÇALHOS
void cadastrar_cliente(string, string);
void cadastrar_funcionario(string, int);
void cadastrar_quarto(int, int);
void cadastrar_estadia(string, int, int);

void finalizar_estadia(int, int);
int pesquisar_pessoa(int, string);
int estadias_cliente(int, string);
int gerar_id();

void salvar_clientes(const vector<Cliente>& clientes);
void salvar_quartos(const vector<Quarto>& quartos);
void salvar_funcionarios(const vector<Funcionario>& funcionarios);
void salvar_estadias(const vector<Estadia>& estadias);


// VETORES
vector<Cliente> clientes;
vector<Funcionario> funcionarios;
vector<Quarto> quartos;
vector<Estadia> estadias;



// Função para gerar um ID aleatório de 20 dígitos
int gerar_id() {
    int digitos = 20;
    int random_number = 0;
    for (int i = 0; i < digitos; i++) {
        random_device rd;  // Obtém um seed aleatório da melhor fonte disponível
        mt19937 gen(rd()); // Usa o seed para inicializar o gerador mersenne_twister_engine
        uniform_int_distribution<> dis(0, 9);
        random_number = random_number * 10 + dis(gen);
    }
    return random_number;
}

// Função para cadastrar um novo cliente
void cadastrar_cliente(string nome, string idade) {
    int id = gerar_id();
    Cliente novo_cliente(id, nome, idade);
    clientes.push_back(novo_cliente);
}

void salvar_clientes(const vector<Cliente>& clientes) {
    ofstream arquivo("clientes.txt");
    if (arquivo.is_open()) {
        for (const auto& cliente : clientes) {
            cliente.salvar(arquivo);
        }
        arquivo.close();
    }
}

vector<Cliente> carregar_clientes() {
    vector<Cliente> clientes_carregados;
    ifstream arquivo("clientes.txt");
    if (arquivo.is_open()) {
        while (arquivo.peek() != EOF) {
            Cliente cliente = Cliente::carregar(arquivo);
            if (arquivo.good()) {
                clientes_carregados.push_back(cliente);
            }
        }
        arquivo.close();
    }
    return clientes_carregados;
}






// Função para cadastrar novos funcionários
void cadastrar_funcionario(string nome, int salario) {
    int id = gerar_id();
    string telefone = "default"; // Ajuste conforme necessário
    string cargo = "default"; // Ajuste conforme necessário
    Funcionario novo_funcionario(id, nome, telefone, cargo, salario);
    funcionarios.push_back(novo_funcionario);
}

void salvar_funcionarios(const vector<Funcionario>& funcionarios) {
    ofstream arquivo("funcionarios.txt");
    if (arquivo.is_open()) {
        for (const auto& funcionario : funcionarios) {
            funcionario.salvar(arquivo);
        }
        arquivo.close();
    }
}

vector<Funcionario> carregar_funcionarios() {
    vector<Funcionario> funcionarios_carregados;
    ifstream arquivo("funcionarios.txt");
    if (arquivo.is_open()) {
        while (arquivo.peek() != EOF) {
            Funcionario funcionario = Funcionario::carregar(arquivo);
            if (arquivo.good()) {
                funcionarios_carregados.push_back(funcionario);
            }
        }
        arquivo.close();
    }
    return funcionarios_carregados;
}





// Função para cadastrar novos quartos
void cadastrar_quarto(int numero, int quantidade_hospedes) {
    double valor_diaria = 0.0; // Defina o valor padrão ou ajuste conforme necessário
    string status = "desocupado"; // Defina o status padrão ou ajuste conforme necessário
    Quarto novo_quarto(numero, quantidade_hospedes, valor_diaria, status);
    quartos.push_back(novo_quarto);
}

void salvar_quartos(const vector<Quarto>& quartos) {
    ofstream arquivo("quartos.txt");
    if (arquivo.is_open()) {
        for (const auto& quarto : quartos) {
            quarto.salvar(arquivo);
        }
        arquivo.close();
    }
}

vector<Quarto> carregar_quartos() {
    vector<Quarto> quartos_carregados;
    ifstream arquivo("quartos.txt");
    if (arquivo.is_open()) {
        while (arquivo.peek() != EOF) {
            Quarto quarto = Quarto::carregar(arquivo);
            if (arquivo.good()) {
                quartos_carregados.push_back(quarto);
            }
        }
        arquivo.close();
    }
    return quartos_carregados;
}





// Função para cadastrar novas estadias
void cadastrar_estadia(const string& nome_cliente, int andar_quarto, int numero_quarto) {
    Estadia nova_estadia(nome_cliente, andar_quarto, numero_quarto);

    // Abre o arquivo em modo de append
    ofstream arquivo("estadias.txt", ios::app);
    if (arquivo.is_open()) {
        nova_estadia.salvar(arquivo);
        arquivo.close();
        cout << "Estadia cadastrada com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo de estadias." << endl;
    }
}

void salvar_estadias(const vector<Estadia>& estadias) {
    ofstream arquivo("estadias.txt");
    if (arquivo.is_open()) {
        for (const auto& estadia : estadias) {
            estadia.salvar(arquivo);
        }
        arquivo.close();
    }
}

// Função para carregar estadias do arquivo
vector<Estadia> carregar_estadias() {
    vector<Estadia> estadias_carregadas;
    ifstream arquivo("estadias.txt");
    if (arquivo.is_open()) {
        while (arquivo.peek() != EOF) {
            Estadia estadia = Estadia::carregar(arquivo);
            if (arquivo.good()) {
                estadias_carregadas.push_back(estadia);
            }
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo de estadias." << endl;
    }
    return estadias_carregadas;
}

#endif // HOTEL_H_INCLUDED
