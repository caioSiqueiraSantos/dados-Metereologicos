#include <stdio.h>

struct dados {
    int mes;
    int dia;
    float tempMax;
    float tempMin;
    char choveu; 
};

typedef struct dados dadosMet;

void mostrarInformacoes(dadosMet dados[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Dia: %d/%d\n", dados[i].dia, dados[i].mes);
        printf("Temperatura Maxima: %.2f\n", dados[i].tempMax);
        printf("Temperatura Minima: %.2f\n", dados[i].tempMin);
        printf("Choveu? %c\n\n", dados[i].choveu);
    }
}

int contarDiasChuvosos(dadosMet dados[], int tamanho) {
    int diasChuvosos = 0;
    for (int i = 0; i < tamanho; i++) {
        if (dados[i].choveu == 's' || dados[i].choveu == 'S') {
            diasChuvosos++;
        }
    }
    return diasChuvosos;
}

void calculaMediaTemperaturas(dadosMet dados[], int tamanho) {
    float somaTempMax = 0, somaTempMin = 0;

    for (int i = 0; i < tamanho; i++) {
        somaTempMax += dados[i].tempMax;
        somaTempMin += dados[i].tempMin;
    }

    float mediaTempMax = somaTempMax / tamanho;
    float mediaTempMin = somaTempMin / tamanho;

    printf("A temperatura maxima media do periodo eh: %.2f\n", mediaTempMax);
    printf("A temperatura minima media do periodo eh: %.2f\n", mediaTempMin);
}

void ordenarTemperaturas(dadosMet dados[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (dados[j].tempMin > dados[j + 1].tempMin) {
                dadosMet temp = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = temp;
            }
        }
    }
}

int main() {
    int diasChuvosos = 0;
    int tamanho = 2;
    dadosMet dadosMet[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Dia e mes para o dia %d: ", i + 1);
        scanf("%d %d", &dadosMet[i].dia, &dadosMet[i].mes);

        printf("Temperatura maxima e minima do dia: ");
        scanf("%f %f", &dadosMet[i].tempMax, &dadosMet[i].tempMin);
        
        getchar(); 
        printf("Choveu no dia? (s/n): ");
        scanf("%c", &dadosMet[i].choveu);
        getchar(); 
    }

    diasChuvosos = contarDiasChuvosos(dadosMet, tamanho);

    calculaMediaTemperaturas(dadosMet, tamanho);

    ordenarTemperaturas(dadosMet, tamanho);

    mostrarInformacoes(dadosMet, tamanho);

    printf("Choveu por %d %s.\n", diasChuvosos, (diasChuvosos == 1) ? "dia" : "dias");

    return 0;
}
