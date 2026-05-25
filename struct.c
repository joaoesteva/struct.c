#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria {
    int codigo;
    char nome[50];
};

void cadastrarCategoria(struct Categoria v[], int *qtd) {
    int i, codigo;
    int repetido;

    if (*qtd == TAM) {
        printf("Vetor cheio!\n");
        return;
    }

    do {
        repetido = 0;

        printf("Digite o codigo da categoria: ");
        scanf("%d", &codigo);

        for (i = 0; i < *qtd; i++) {
            if (v[i].codigo == codigo) {
                repetido = 1;
                printf("Codigo ja existente!\n");
            }
        }

    } while (repetido);

    v[*qtd].codigo = codigo;

    printf("Digite o nome da categoria: ");
    scanf(" %[^\n]", v[*qtd].nome);

    (*qtd)++;

    printf("Categoria cadastrada com sucesso!\n");
}