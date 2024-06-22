#include <iostream>
#include <string>
#include "hotel.h"

int main()
{
    int op;
    string nome, idade;
    float salario;
    int andar, numero;
    do
    {
        cout << "[MENU] HOTEL DESCANSO GARANTIDO" << endl;
        cout << "0 - SAIR DO SISTEMA" << endl;
        cout << "1 - CADASTRAR CLIENTE" << endl;
        cout << "2 - CADASTRAR FUNCIONARIO" << endl;
        cout << "3 - CADASTRAR QUARTO" << endl;
        cout << "4 - CADASTRAR ESTADIA" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Digite o nome do cliente: " << endl;
            cin >> nome;
            cout << "Digite a idade do cliente: " << endl;
            cin >> idade;
            cadastrar_cliente(nome, idade);
            break;

        case 2:
            cout << "Digite o nome do funcionario: " << endl;
            cin >> nome;
            cout << "Digite o salario do funcionario: " << endl;
            cin >> salario;
            cadastrar_funcionario(nome, salario);
            break;

        case 3:
            cout << "Digite o andar do quarto: " << endl;
            cin >> andar;
            cout << "Digite o numero do quarto: " << endl;
            cin >> numero;
            cadastrar_quarto(andar, numero);
            break;

        case 4:
            cout << "Digire o nome do cliente: " << endl;
            cin >> nome;
            cout << "Digite o andar do quarto: " << endl;
            cin >> andar;
            cout << "Digite o numero do quarto: " << endl;
            cin >> numero;
            cadastrar_estadia(nome, andar, numero);
            break;

        default:
            cout << "OPÇÃO INVÁLIDA." << endl;
            break;
        }

    }
    while (!op == 0);
    return 0;
}
