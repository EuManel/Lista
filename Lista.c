#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* criarLista() {
    return NULL;
}

Node* inserirLista(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

void exibirLista(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("A lista está vazia.\n");
    } else {
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int verificarVazia(Node* head) {
    return head == NULL;
}

Node* buscarLista(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* excluirLista(Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }

    return head;
}

void liberarLista(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void exibirMenu() {
    printf("\n--- MENU DE OPERACOES ---\n");
    printf("1. Inserir elemento na lista\n");
    printf("2. Exibir a lista\n");
    printf("3. Verificar se a lista está vazia\n");
    printf("4. Buscar elemento na lista\n");
    printf("5. Excluir elemento da lista\n");
    printf("6. Liberar a lista\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Node* lista = criarLista();
    int opcao, valor;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                lista = inserirLista(lista, valor);
                printf("Valor %d inserido.\n", valor);
                break;

            case 2:
                printf("Elementos da lista: ");
                exibirLista(lista);
                break;

            case 3:
                if (verificarVazia(lista)) {
                    printf("A lista está vazia.\n");
                } else {
                    printf("A lista não está vazia.\n");
                }
                break;

            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                if (buscarLista(lista, valor) != NULL) {
                    printf("Valor %d encontrado na lista.\n", valor);
                } else {
                    printf("Valor %d não encontrado na lista.\n", valor);
                }
                break;

            case 5:
                printf("Digite o valor a ser excluído: ");
                scanf("%d", &valor);
                lista = excluirLista(lista, valor);
                printf("Valor %d excluído da lista.\n", valor);
                break;

            case 6:
                liberarLista(lista);
                lista = NULL;
                printf("Lista liberada da memória.\n");
                break;

            case 7:
                printf("Saindo...\n");
                liberarLista(lista);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}

----------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* criarLista() {
    return NULL;
}

Node* inserirOrdenado(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL || head->data >= data) {
        newNode->next = head;
        return newNode;
    } else {
        Node* current = head;
        
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        return head;
    }
}

void exibirLista(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("A lista está vazia.\n");
    } else {
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int verificarVazia(Node* head) {
    return head == NULL;
}

Node* buscarLista(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* excluirLista(Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }
    
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }

    return head;
}

void liberarLista(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void exibirMenu() {
    printf("\n--- MENU DE OPERACOES ---\n");
    printf("1. Inserir elemento na lista em ordem\n");
    printf("2. Exibir a lista\n");
    printf("3. Verificar se a lista está vazia\n");
    printf("4. Buscar elemento na lista\n");
    printf("5. Excluir elemento da lista\n");
    printf("6. Liberar a lista\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Node* lista = criarLista();
    int opcao, valor;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido em ordem: ");
                scanf("%d", &valor);
                lista = inserirOrdenado(lista, valor);
                printf("Valor %d inserido em ordem.\n", valor);
                break;

            case 2:
                printf("Elementos da lista: ");
                exibirLista(lista);
                break;

            case 3:
                if (verificarVazia(lista)) {
                    printf("A lista está vazia.\n");
                } else {
                    printf("A lista não está vazia.\n");
                }
                break;

            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                if (buscarLista(lista, valor) != NULL) {
                    printf("Valor %d encontrado na lista.\n", valor);
                } else {
                    printf("Valor %d não encontrado na lista.\n", valor);
                }
                break;

            case 5:
                printf("Digite o valor a ser excluído: ");
                scanf("%d", &valor);
                lista = excluirLista(lista, valor);
                printf("Valor %d excluído da lista.\n", valor);
                break;

            case 6:
                liberarLista(lista);
                lista = NULL;
                printf("Lista liberada da memória.\n");
                break;

            case 7:
                printf("Saindo...\n");
                liberarLista(lista);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
