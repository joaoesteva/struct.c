#include <stdio.h>
#include <string.h>

void cadastrarCategoria(struct Categoria v[], int *qtd) {
    if (*qtd >= TAM) {
        printf("Erro: Capacidade maxima do vetor atingida (%d).\n", TAM);
        return;
    }

    int codigoProposto;
    int codigoExiste;
    
    do {
        codigoExiste = 0;
        printf("Digite o codigo da nova categoria: ");
        scanf("%d", &codigoProposto);
        getchar(); 

        for (int i = 0; i < *qtd; i++) {
            if (v[i].codigo == codigoProposto) {
                printf("Erro: Ja existe uma categoria com o codigo %d. Tente outro.\n", codigoProposto);
                codigoExiste = 1;
                break;
            }
        }
    } while (codigoExiste);

    v[*qtd].codigo = codigoProposto;

    printf("Digite o nome da categoria: ");
    fgets(v[*qtd].nome, 50, stdin);
    v[*qtd].nome[strcspn(v[*qtd].nome, "\n")] = '\0';

    (*qtd)++;
    printf("Categoria cadastrada com sucesso!\n");
}

void imprimirCategorias(struct Categoria v[], int qtd) {
    if (qtd == 0) {
        printf("Nenhuma categoria cadastrada.\n");
        return;
    }

    printf("\n--- LISTA DE CATEGORIAS ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Codigo: %d | Nome: %s\n", v[i].codigo, v[i].nome);
    }
    printf("---------------------------\n");
}

void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias) {
    if (qtdProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE PRODUTOS ---\n");
    for (int i = 0; i < qtdProdutos; i++) {
        char nomeCategoria[50] = "Categoria nao encontrada";
        for (int j = 0; j < qtdCategorias; j++) {
            if (vc[j].codigo == vp[i].categoria) {
                strcpy(nomeCategoria, vc[j].nome);
                break;
            }
        }
        
        double precoReal = vp[i].preco / 100.0;

        printf("Codigo: %d\n", vp[i].codigo);
        printf("Titulo: %s\n", vp[i].titulo);
        printf("Descricao: %s\n", vp[i].descricao);
        printf("Categoria: %s\n", nomeCategoria);
        printf("Preco: R$ %.2f\n", precoReal);
        printf("-------------------------\n");
    }
}

void selectionSortPorDescricao(struct Produto v[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        int min_idx = i;
        
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(v[j].descricao, v[min_idx].descricao) < 0) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            struct Produto temp = v[i];
            v[i] = v[min_idx];
            v[min_idx] = temp;
        }
    }
    printf("Produtos ordenados por descricao com sucesso!\n");
}

void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x) {
    int inicio = 0;
    int fim = qtd - 1;
    int encontrado = 0;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        int comp = strcmp(x, v[meio].descricao);

        if (comp == 0) {
            printf("\nProduto Encontrado:\n");
            printf("Codigo: %d | Titulo: %s | Preco: R$ %.2f\n", 
                   v[meio].codigo, v[meio].titulo, v[meio].preco / 100.0);
            encontrado = 1;
            break;
        } 
        else if (comp > 0) {
            inicio = meio + 1;
        } /
        else {
            fim = meio - 1;
        }
    }

    if (!encontrado) {
        printf("Produto com a descricao \"%s\" nao foi encontrado.\n", x);
    }
}
