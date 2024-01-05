#include <iostream>
using namespace std;

bool jogador1 = false;

#define linhas_tab  3
#define colunas_tab 3

char jogador1char = 'X', jogador2char = 'O';

char tabuleiro[linhas_tab][colunas_tab];

void preencheTabuleiro(int linhas, int colunas) {
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            tabuleiro[l][c] = ' ';
        }
    }
}

void imprimeTabuleito(int linhas, int colunas) {
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            if (c == colunas_tab-1) {
                cout << "|" << tabuleiro[l][c] << endl;
            } else if (c == colunas_tab-2) {
                cout << tabuleiro[l][c];
            } else {
                cout << tabuleiro[l][c] << "|";
            }
        }
        if (l != linhas_tab-1) {
            for (int i = 0; i < colunas_tab*2 ; i++) {
                if (i == colunas_tab*2-1) {
                    cout << "-\n";
                } else {
                    cout << "-";
                }
            }
        }
    }
}

bool checarGanhador() {
    for (int l = 0; l < linhas_tab; l++) {
        if (tabuleiro[l][0] == tabuleiro[l][1] && tabuleiro[l][1] == tabuleiro[l][2] && tabuleiro[l][0] != ' ') {
            return true;
        }
    }
    for (int c = 0; c < colunas_tab; c++) {
        if (tabuleiro[0][c] == tabuleiro[1][c] && tabuleiro[1][c] == tabuleiro[2][c] && tabuleiro[0][c] != ' ') {
            return true;
        }
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return true;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return true;
    }

    return false;
}

int main() {
    bool in_game;
    int linha, coluna;

    in_game = true;

    preencheTabuleiro(linhas_tab, colunas_tab);

    while (in_game) {
        inicio:
        system("cls");
        cout << "Jogando Agora: " << (jogador1 ? jogador1char : jogador2char) << endl;
        imprimeTabuleito(linhas_tab, colunas_tab);

        cout << endl << "Onde jogar? [Linha]: ";
        cin >> linha;
        if (linha > linhas_tab || linha <= 0) {
            cout << endl << "Não tem essa linha!";
            continue;
        }
        cout << endl << "Onde jogar? [Coluna]: ";
        cin >> coluna;
        if (coluna > colunas_tab || coluna <= 0) {
            cout << endl << "Não tem essa coluna!";
            continue;
        }

        if (tabuleiro[linha-1][coluna-1] != jogador1char && tabuleiro[linha-1][coluna-1] != jogador2char) {
            tabuleiro[linha-1][coluna-1] = jogador1 ? jogador1char : jogador2char;
            jogador1 = !jogador1;
        } else {
            cout << endl << "Lugar já ocupado!!";
            continue;
        }
    
        if  (checarGanhador()) {
            system("cls");
            cout << (jogador1 ? "Jogador 1" : "Jogador 2") << " venceu" << endl;
            imprimeTabuleito(linhas_tab, colunas_tab);
            in_game = false;
        }
    }

    return 0;
}