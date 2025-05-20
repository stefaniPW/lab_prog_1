#include <stdio.h>
#include <stdlib.h>

#define QTD_CLIENTE 100
#define QTD_PRODUTOS 100

typedef struct {
    char nome [100];
    char email [100];
    
} Cliente;

typedef struct {
    char nome [100];
    double preco;

}Produto;

Cliente clientes [QTD_CLIENTE];
Produto produtos [QTD_PRODUTOS];

int index_cliente = 0;
int index_produto = 0;

void insere_produtos();
void insere_clientes();
void listar_clientes ();
void listar_produtos(); 

int main (){
    int opcao = 0;
    do{
        printf("Selecione uma opcao: \n"
        "0 = sair\n"
        "1 = Insere cliente\n"
        "2 = Insere produto\n"
        "3 = Insere venda\n"
        "4 = Listar clientes\n"
        "5 = Listar produtos\n");
    scanf ("%d", &opcao);
        
    switch (opcao) {
        case 1:
            insere_clientes();
            break;
        case 2:    
            insere_produtos();
            break;
        case 4:
            listar_clientes();
            break;
        case 5: 
            listar_produtos();
            break;
        case 0:
            printf ("Saindo do programo\n");
            break;
        default:
            printf ("Opção inválida\n");
        }
    } while (opcao != 0);

    return 0;
}

void insere_clientes(){
     int opcao;
    if (index_cliente >= QTD_CLIENTE){
        printf("Limite de clientes atingido!\n\n");
    }else{
        printf("insira o nome do cliente: \t");
        scanf("%s", clientes[index_cliente].nome);
        printf("insira o e-mail do cliente: \t");
        scanf("%s", clientes[index_cliente].email);

        index_cliente++;   //index_cliente = index_cliente + 1;

        printf("Deseja inserir mais clientes?\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &opcao);

        if (opcao == 1){
            insere_clientes();
        }
    }
}
   
void listar_clientes (){ //listas = imprimi-r
    int i;
    for (i = 0; i < index_cliente; i++){
        printf("Cliente %d - nome: %s\n\n", (i+1), clientes[i].nome);
        printf("Cliente %d - email: %s\n\n",(i+1), clientes[i].email);
    }
   
}

void insere_produtos(){
    int opcao;
    if (index_produto >= QTD_PRODUTOS){
        printf ("Limite de produtos atingido!\n\n");
    }else{
        printf ("insira o nome do produto: \t");
        scanf("%s", produtos[index_produto].nome);
        printf ("insira o preço do produto: \t");
        scanf("%s", produtos[index_produto].preco);
        index_produto++;

        printf("Deseja inserir mais produtos?\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &opcao);

        if (opcao == 1){
            insere_produtos();
        }
    }
}

void listar_produtos(){
    int j;
    for (j = 0; j < index_produto; j++){
        printf("Produtos %d - nome: %s\n\n", (j+1), produtos[j].nome);
        printf("Produtos %d - preço: %lf\n\n", (j+1), produtos[j].preco);

    }
}
