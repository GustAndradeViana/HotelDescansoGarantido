#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#include <random>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// CABEÇALHOS DE FUNÇÕES
int cadastrar_cliente(string, string);
int cadastrar_funcionario(string, int);
int cadastrar_quarto(int, int);
int cadastrar_estadia(string, int, int);
int finalizar_estadia(int, int);
int pesquisar_pessoa(int, string);
int estadias_cliente(int, string);
int gerar_id();

// CLASSES
class Cliente {
public:
    Cliente(int id, const string& nome, const string& idade) : id(id), nome(nome), idade(idade) {}

    // Métodos getters
    int getId() const { return id; }
    string getNome() const { return nome; }
    string getIdade() const { return idade; }

    // Método para salvar cliente em um arquivo
    void salvar(ofstream& arquivo) const {
        arquivo << id << " " << nome << " " << idade << "\n";
    }

    // Método carregar cliente de um arquivo
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
private:
public:
};

class Quarto {
private:
public:
};

class Estadia {
private:
public:
};

// Vetores para armazenar os objetos das classes usando a biblioteca <vector>, vector.push_back() para adicionar ao final de um vetor
vector<Cliente> clientes;
vector<Funcionario> funcionarios;
vector<Quarto> quartos;
vector<Estadia> estadias;

// Função para gerar um ID aleatorio de 20 digitos
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
int cadastrar_cliente(string nome, string idade) {
    int id = gerar_id();
    Cliente novo_cliente(id, nome, idade);
    clientes.push_back(novo_cliente);
    return id;
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

#endif // HOTEL_H_INCLUDED
