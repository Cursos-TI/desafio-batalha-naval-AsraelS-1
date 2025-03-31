#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10  // Tamanho do mapa
#define NAVIO 3      // Representação do navio
#define TAM_NAVIO 3  // Tamanho fixo dos navios

// Função para inicializar o mapa com água (valor 0)
void inicializarMapa(int mapa[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            mapa[i][j] = 0;  // Marca todas as posições como água
        }
    }
}

// Função para verificar se é possível posicionar um navio
int verificaEspaco(int mapa[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {  // Horizontal
        if (coluna + TAM_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (mapa[linha][coluna + i] != 0) return 0;
        }
    } else if (orientacao == 'V') {  // Vertical
        if (linha + TAM_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (mapa[linha + i][coluna] != 0) return 0;
        }
    } else if (orientacao == 'D') {  // Diagonal principal
        if (linha + TAM_NAVIO > TAMANHO || coluna + TAM_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (mapa[linha + i][coluna + i] != 0) return 0;
        }
    } else if (orientacao == 'd') {  // Diagonal secundária
        if (linha + TAM_NAVIO > TAMANHO || coluna - TAM_NAVIO < -1) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (mapa[linha + i][coluna - i] != 0) return 0;
        }
    }
    return 1;  // Espaço válido para posicionar o navio
}

// Função para posicionar o navio no mapa
void posicionarNavio(int mapa[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (orientacao == 'H') {
            mapa[linha][coluna + i] = NAVIO;
        } else if (orientacao == 'V') {
            mapa[linha + i][coluna] = NAVIO;
        } else if (orientacao == 'D') {
            mapa[linha + i][coluna + i] = NAVIO;
        } else if (orientacao == 'd') {
            mapa[linha + i][coluna - i] = NAVIO;
        }
    }
}

// Função para exibir o mapa no console
void exibirMapa(int mapa[TAMANHO][TAMANHO]) {
    printf("\n   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);  // Limpa o buffer e garante a saída correta no console
}

int main() {
    int mapa[TAMANHO][TAMANHO];
    inicializarMapa(mapa);

    // Coordenadas dos navios
    int linha1 = 2, coluna1 = 3;
    int linha2 = 6, coluna2 = 7;
    int linha3 = 1, coluna3 = 1;
    int linha4 = 4, coluna4 = 8;

    // Posicionamento dos navios
    if (verificaEspaco(mapa, linha1, coluna1, 'H')) {
        posicionarNavio(mapa, linha1, coluna1, 'H');
    }
    if (verificaEspaco(mapa, linha2, coluna2, 'V')) {
        posicionarNavio(mapa, linha2, coluna2, 'V');
    }
    if (verificaEspaco(mapa, linha3, coluna3, 'D')) {
        posicionarNavio(mapa, linha3, coluna3, 'D');
    }
    if (verificaEspaco(mapa, linha4, coluna4, 'd')) {
        posicionarNavio(mapa, linha4, coluna4, 'd');
    }

    // Exibe o mapa após o posicionamento
    exibirMapa(mapa);
    return 0;
}
