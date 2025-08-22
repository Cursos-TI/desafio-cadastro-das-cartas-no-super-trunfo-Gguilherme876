#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Estrutura de uma carta
typedef struct {
    char estado[30];
    char cidade[30];
    int populacao;
    float area;
    double pib;
    char pontosTuristicos[MAX_TURISMO][50];
} Carta;

// Limpar o buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler uma carta
void lerCarta(Carta *carta, int numero) {
    printf("\n--- Carta %d ---\n", numero + 1);

    printf("Estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0';

    printf("Cidade: ");
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de R$): ");
    scanf("%lf", &carta->pib);

    limparBuffer(); // limpar '\n' antes de fgets

    for (int i = 0; i < MAX_TURISMO; i++) {
        printf("Ponto turístico %d: ", i + 1);
        fgets(carta->pontosTuristicos[i], sizeof(carta->pontosTuristicos[i]), stdin);
        carta->pontosTuristicos[i][strcspn(carta->pontosTuristicos[i], "\n")] = '\0';
    }
}

int main() {
    int total;
    Carta cartas[MAX_CARTAS];

    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &total);
    limparBuffer();

    for (int i = 0; i < total; i++) {
        lerCarta(&cartas[i], i);
    }

    
    return 0;
}
