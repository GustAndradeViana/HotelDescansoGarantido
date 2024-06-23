#include <iostream>
#include <string>
#include "hotel.h"
#include <locale>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int op;
    string nome, idade, cargo, telefone, endereco, status, dataEntrada, dataSaida, tipo_pessoa;
    float salario;
    int numero, qteHospedes, qteDiarias, id_pessoa;
    double valorDiaria;
    do
    {
        cout << "[MENU] HOTEL DESCANSO GARANTIDO" << endl;
        cout << "0 - SAIR DO SISTEMA" << endl;
        cout << "1 - CADASTRAR CLIENTE" << endl;
        cout << "2 - CADASTRAR FUNCIONARIO" << endl;
        cout << "3 - CADASTRAR QUARTO" << endl;
        cout << "4 - CADASTRAR ESTADIA" << endl;
        cout << "---------------------" << endl;
        cout << "5 - PESQUISAR PESSOA" << endl;
        cout << "6 - PESQUISAR ESTADIAS" << endl;
        cout << "7 - FINALIZAR ESTADIA" << endl;
        cout << "8 - PONTOS DE FIDELIDADE" << endl;
        cin >> op;
        cin.ignore();

        switch (op)
        {
        case 1:
            cout << "Digite o nome do cliente: " << endl;
            getline(cin, nome);
            cout << "Digite o endereço do cliente: " << endl;
            getline(cin, endereco);
            cout << "Digite o telefone do cliente: " << endl;
            getline(cin, telefone);
            cadastrar_cliente(nome, endereco, telefone);
            break;

        case 2:
            cout << "Digite o nome do funcionario: " << endl;
            cin >> nome;
            cout << "Digite o cargo do funcionario: " << endl;
            cin >> cargo;
            cout << "Digite o telefone do funcionario: " << endl;
            cin >> telefone;
            cout << "Digite o salario do funcionario: " << endl;
            cin >> salario;
            cadastrar_funcionario(nome, telefone, cargo, salario);
            break;

        case 3:
            cout << "Digite o numero do quarto: " << endl;
            cin >> numero;
            cout << "Digite a quantidade de hospedes no quarto: " << endl;
            cin >> qteHospedes;
            cout << "Digite o valor da diaria no quarto: " << endl;
            cin >> valorDiaria;
            cout << "Digite o status do quarto: " << endl;
            cin >> status;
            cadastrar_quarto(numero, qteHospedes, valorDiaria, status);
            break;

        case 4:
            cout << "Digire o nome do cliente: " << endl;
            cin >> nome;
            cout << "Digite o numero do quarto: " << endl;
            cin >> numero;
            cout << "Digite a quantidade de diarias: " << endl;
            cin >> qteDiarias;
            cout << "Digite a data de entrada: " << endl;
            cin >> dataEntrada;
            cout << "Digite a data de saida: " << endl;
            cin >> dataSaida;
            cadastrar_estadia(nome, numero, qteDiarias, dataSaida, dataEntrada);
            break;

        case 5:
            cout << "Digite o id da pessoa: " << endl;
            cin >> id_pessoa;
            cout << "Digite o tipo de pessoa (cliente ou funcionario): " << endl;
            cin >> tipo_pessoa;
            pesquisar_pessoa(id_pessoa, tipo_pessoa);
            break;

        case 6:
            cout << "Digite o nome do cliente: " << endl;
            cin >> nome;
            estadias_cliente(nome);
            break;
        case 7:
            cout << "Digite o numero do quarto: " << endl;
            cin >> numero;
            finalizar_estadia(numero);
            break;

        case 8:
            break;

        default:
            cout << "OPÇÃO INVÁLIDA." << endl;
            break;
        }

    }
    while (!op == 0);
    return 0;
}
