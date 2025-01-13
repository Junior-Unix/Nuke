#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_NOME 50
#define MAX_ENDERECO 100

typedef struct {
    char nome[MAX_NOME];
    char endereco[MAX_ENDERECO];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

void adicionarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }
    printf("Nome do cliente: ");
    fgets(clientes[totalClientes].nome, MAX_NOME, stdin);
    clientes[totalClientes].nome[strcspn(clientes[totalClientes].nome, "\n")] = 0; // Remove newline character

    printf("Endereco do cliente: ");
    fgets(clientes[totalClientes].endereco, MAX_ENDERECO, stdin);
    clientes[totalClientes].endereco[strcspn(clientes[totalClientes].endereco, "\n")] = 0; // Remove newline character

    totalClientes++;
    printf("Cliente adicionado com sucesso!\n");
}

void consultarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalClientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Endereco: %s\n", clientes[i].endereco);
    }
}

void menu() {
    int opcao;
    do {
        system("cls"); // Use "clear" if on Unix-based system
        printf("\033[0;32m"); // Set text color to green
        printf("1. Adicionar Cliente\n");
        printf("2. Consultar Clientes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Consume newline character left by scanf

        switch (opcao) {
            case 1:
                adicionarCliente();
                break;
            case 2:
                consultarClientes();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        printf("Pressione Enter para continuar...");
        getchar();
    } while (opcao != 3);
}

int main() {
    menu();
    return 0;
}