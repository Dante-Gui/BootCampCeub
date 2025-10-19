#include <stdio.h>
#define TAM 3 

// Declaração das funções
void imprimirTab(char tab[TAM][TAM]);
int verificar_win(char tab[TAM][TAM], char simbolo);
int tabuleiro_velha(char tab[TAM][TAM]);

int main() {
    char jogarNovamente;

    do {
        char tabuleiro[TAM][TAM];
        char simboloAtual = 'X';
        int vencedor = 0;

      
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                tabuleiro[i][j] = ' ';
            }
        }

        printf("Jogo da Velha!\n");
        printf("Jogador 1: X\n");
        printf("Jogador 2: O\n");

        while (!vencedor && !tabuleiro_velha(tabuleiro)) {
            imprimirTab(tabuleiro);

            int linha, coluna;
            printf("Jogador %c, digite linha e coluna [0, 1, 2]: ", simboloAtual);
            scanf("%d %d", &linha, &coluna);

            if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM || tabuleiro[linha][coluna] != ' ') {
                printf("Posição inválida! Tente novamente.\n");
                continue;
            }

            tabuleiro[linha][coluna] = simboloAtual;

            if (verificar_win(tabuleiro, simboloAtual)) {
                imprimirTab(tabuleiro);
                printf("Jogador %c venceu!\n", simboloAtual);
                vencedor = 1;
                break;
            }

            // Troca de jogador
            simboloAtual = (simboloAtual == 'X') ? 'O' : 'X';
        }

        if (!vencedor) {
            imprimirTab(tabuleiro);
            printf("Deu velha!\n");
        }

        // Pergunta se o usuário quer jogar novamente
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente); 

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar!\n");
    return 0;
}


void imprimirTab(char tab[TAM][TAM]) {
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tab[i][j]);
            if (j < TAM - 1) printf("|");
        }
        printf("\n");
        if (i < TAM - 1) printf("---+---+---\n");
    }
    printf("\n");
}


int verificar_win(char tab[TAM][TAM], char simbolo) {
    
    for (int i = 0; i < TAM; i++) {
        if (tab[i][0] == simbolo && tab[i][1] == simbolo && tab[i][2] == simbolo)
            return 1;
    }

    for (int j = 0; j < TAM; j++) {
        if (tab[0][j] == simbolo && tab[1][j] == simbolo && tab[2][j] == simbolo)
            return 1;
    }
   
    if (tab[0][0] == simbolo && tab[1][1] == simbolo && tab[2][2] == simbolo)
        return 1;

    if (tab[0][2] == simbolo && tab[1][1] == simbolo && tab[2][0] == simbolo)
        return 1;

    return 0;
}

// Função que verifica se deu velha
int tabuleiro_velha(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tab[i][j] == ' ')
                return 0; 
        }
    }
    return 1; 
}