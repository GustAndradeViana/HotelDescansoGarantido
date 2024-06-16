#include <iostream>
#include <string>
#include "hotel.h"

int main() {
    switch (request) {
    case 1:
        cadastrar_cliente(nome, idade);
        break;

    case 2:
        //cadastrar_funcionario(nome, salario);
        break;

    case 3:
        //cadastrar_quarto(andar, numero);
        break;

    case 4:
        //cadastrar_estadia(nome, andar, numero);
        break;

    default:
        break;
    }
    return 0;
}
