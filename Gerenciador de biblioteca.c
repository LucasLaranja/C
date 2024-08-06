#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    int id;
    char titulo[100];
    char autor[100];
    int ano;
    struct Livro* proximo;
} Livro;

Livro* criarLivro(int id, char* titulo, char* autor, int ano) {
    Livro* novoLivro = (Livro*)malloc(sizeof(Livro));
    novoLivro->id = id;
    strcpy(novoLivro->titulo, titulo);
    strcpy(novoLivro->autor, autor);
    novoLivro->ano = ano;
    novoLivro->proximo = NULL;
    return novoLivro;
}

void adicionarLivro(Livro** head, int id, char* titulo, char* autor, int ano) {
    Livro* novoLivro = criarLivro(id, titulo, autor, ano);
    novoLivro->proximo = *head;
    *head = novoLivro;
}

void removerLivro(Livro** head, int id) {
    Livro* temp = *head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        *head = temp->proximo;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) return;

    prev->proximo = temp->proximo;
    free(temp);
}

void atualizarLivro(Livro* head, int id, char* novoTitulo, char* novoAutor, int novoAno) {
    Livro* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            strcpy(temp->titulo, novoTitulo);
            strcpy(temp->autor, novoAutor);
            temp->ano = novoAno;
            return;
        }
        temp = temp->proximo;
    }
}

Livro* buscarLivroPorID(Livro* head, int id) {
    Livro* temp = head;
    while (temp != NULL) {
        if (temp->id == id) return temp;
        temp = temp->proximo;
    }
    return NULL;
}

void listarLivros(Livro* head) {
    Livro* temp = head;
    while (temp != NULL) {
        printf("ID: %d\n", temp->id);
        printf("Titulo: %s\n", temp->titulo);
        printf("Autor: %s\n", temp->autor);
        printf("Ano: %d\n\n", temp->ano);
        temp = temp->proximo;
    }
}

void salvarLivros(Livro* head) {
    FILE* file = fopen("biblioteca.txt", "w");
    Livro* temp = head;
    while (temp != NULL) {
        fprintf(file, "%d;%s;%s;%d\n", temp->id, temp->titulo, temp->autor, temp->ano);
        temp = temp->proximo;
    }
    fclose(file);
}

void carregarLivros(Livro** head) {
    FILE* file = fopen("biblioteca.txt", "r");
    if (file == NULL) return;

    int id, ano;
    char titulo[100], autor[100];
    while (fscanf(file, "%d;%99[^;];%99[^;];%d\n", &id, titulo, autor, &ano) != EOF) {
        adicionarLivro(head, id, titulo, autor, ano);
    }
    fclose(file);
}

int main() {
    Livro* biblioteca = NULL;
    carregarLivros(&biblioteca);

    int opcao, id, ano;
    char titulo[100], autor[100];

    do {
        printf("Menu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Remover Livro\n");
        printf("4. Atualizar Livro\n");
        printf("5. Buscar Livro por ID\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("ID: ");
                scanf("%d", &id);
                printf("Titulo: ");
                scanf(" %[^\n]s", titulo);
                printf("Autor: ");
                scanf(" %[^\n]s", autor);
                printf("Ano: ");
                scanf("%d", &ano);
                adicionarLivro(&biblioteca, id, titulo, autor, ano);
                salvarLivros(biblioteca);
                break;
            case 2:
                listarLivros(biblioteca);
                break;
            case 3:
                printf("ID do livro a remover: ");
                scanf("%d", &id);
                removerLivro(&biblioteca, id);
                salvarLivros(biblioteca);
                break;
            case 4:
                printf("ID do livro a atualizar: ");
                scanf("%d", &id);
                printf("Novo Titulo: ");
                scanf(" %[^\n]s", titulo);
                printf("Novo Autor: ");
                scanf(" %[^\n]s", autor);
                printf("Novo Ano: ");
                scanf("%d", &ano);
                atualizarLivro(biblioteca, id, titulo, autor, ano);
                salvarLivros(biblioteca);
                break;
            case 5:
                printf("ID do livro a buscar: ");
                scanf("%d", &id);
                Livro* livroEncontrado = buscarLivroPorID(biblioteca, id);
                if (livroEncontrado != NULL) {
                    printf("Livro encontrado:\n");
                    printf("ID: %d\n", livroEncontrado->id);
                    printf("Titulo: %s\n", livroEncontrado->titulo);
                    printf("Autor: %s\n", livroEncontrado->autor);
                    printf("Ano: %d\n", livroEncontrado->ano);
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    return 0;
}
