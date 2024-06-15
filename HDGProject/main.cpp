#include <windows.h>
#include <iostream>
#include <commctrl.h>
#include <string>
#include "resource.h"
#include "hotel.h"

using namespace std;

// Funções auxiliares
HFONT mudar_caracteristicas(LOGFONT lf, int tamanho_fonte, int negrito, string tipo_fonte, int corR, int corG, int corB);

// FUNÇÃO PRINCIPAL
int Main(int request, string nome, string idade, int salario, int andar, int numero) {
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

// INTERFACE GRÁFICA

HINSTANCE hInst;
HFONT hFont;
COLORREF crTextColor;
HWND hTitulo;
HWND hTexto_Cadastrar_Cliente;
HWND hCaixa_Nome_Cliente;
HWND hCaixa_Idade_Cliente;
HWND hBotao_Cadastrar_Cliente;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static LOGFONT lf;

    switch (uMsg) {
    case WM_INITDIALOG: // Quando a janela iniciar
    {
        // Definir o pincel de fundo preto para a caixa de diálogo
        SetClassLongPtr(hwndDlg, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(0, 0, 0)));

        // Forçar atualização da janela
        InvalidateRect(hwndDlg, NULL, TRUE);
        UpdateWindow(hwndDlg);

        // Pegar elementos de cadastrar cliente
        hTexto_Cadastrar_Cliente = GetDlgItem(hwndDlg, CADASTRAR_CLIENTE_TEXTO);
        hCaixa_Nome_Cliente = GetDlgItem(hwndDlg, NOME_CLIENTE_CAIXA);
        hCaixa_Idade_Cliente = GetDlgItem(hwndDlg, IDADE_CLIENTE_CAIXA);
        hBotao_Cadastrar_Cliente = GetDlgItem(hwndDlg, CADASTRAR_CLIENTE_BOTAO);

        // Pegar elemento referente ao titulo
        hTitulo = GetDlgItem(hwndDlg, TITULO_TEXTO); // Obter o controle estático pelo ID

        // Definir o pincel de fundo preto para a caixa de diálogo
        SetClassLongPtr(hwndDlg, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(0, 0, 0)));

        // MUDAR TEXTO //
        ZeroMemory(&lf, sizeof(LOGFONT)); // Inicializar a variável LOGFONT

        if (hTitulo != NULL) { // Conferir se existe o controle estático de tal ID
            hFont = mudar_caracteristicas(lf, 30, 1, "Arial", 255, 255, 255);
            SendMessage(hTitulo, WM_SETFONT, (WPARAM)hFont, TRUE); // Aplicar a fonte e cor ao controle estático inicialmente
            InvalidateRect(hTitulo, NULL, TRUE); // Forçar atualização do controle
        }
        if (hTexto_Cadastrar_Cliente != NULL) { // Conferir se existe o controle estático de tal ID
            hFont = mudar_caracteristicas(lf, 30, 1, "Arial", 255, 255, 255);
            SendMessage(hTexto_Cadastrar_Cliente, WM_SETFONT, (WPARAM)hFont, TRUE); // Aplicar a fonte e cor ao controle estático inicialmente
            InvalidateRect(hTexto_Cadastrar_Cliente, NULL, TRUE); // Forçar atualização do controle
        }

        return TRUE;
    }

    case WM_CLOSE: // Quando a janela fechar
    {
        salvar_clientes(clientes);
        DeleteObject(hFont);
        EndDialog(hwndDlg, 0);
        return TRUE;
    }

    case WM_COMMAND:
    {
        switch (LOWORD(wParam)) {
        case CADASTRAR_CLIENTE_BOTAO: // Usar o ID do botão de cadastro de cliente definido no arquivo de recursos
        {
            char entradaNome[60]; // Reservar memoria para entrada de dados do nome do cliente
            char entradaIdade[4]; // Reservar memoria para entrada de dados da idade do cliente
            GetWindowText(hCaixa_Nome_Cliente, entradaNome, 60); // Pegar o input da caixa de texto referente ao nome do cliente
            GetWindowText(hCaixa_Idade_Cliente, entradaIdade, 4); // Pegar o input da caixa de texto referente a idade do cliente
            if (strlen(entradaNome) > 0 && strlen(entradaIdade) > 0) { // Checar se há input
                // Chamar o método Main com pedido de cadastrar cliente
                Main(1, entradaNome, entradaIdade, 0, 0, 0);
            }
            return TRUE;
        }
        }
        break;
    }

    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetTextColor(hdcStatic, crTextColor);
        SetBkColor(hdcStatic, RGB(0, 0, 0)); // Configurar cor de fundo preto para textos estáticos
        return (INT_PTR)GetStockObject(NULL_BRUSH);
    }

    }
    return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    hInst = hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}

HFONT mudar_caracteristicas(LOGFONT lf, int tamanho_fonte, int negrito, string tipo_fonte, int corR, int corG, int corB) {
    lf.lfHeight = tamanho_fonte;
    lf.lfWeight = FW_NORMAL;
    if (negrito == 1) {
        lf.lfWeight = FW_BOLD;
    }
    if (tipo_fonte.size() < LF_FACESIZE) {
        strcpy(lf.lfFaceName, tipo_fonte.c_str());
    }
    crTextColor = RGB(corR, corG, corB);
    return CreateFontIndirect(&lf);
}
