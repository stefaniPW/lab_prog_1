#include <stdio.h>
#include <stdlib.h>
//#include "clientes.h"//colocar sempre em aspas biblioteca criada

#define QTD_CLIENTE 100
#define QTD_PRODUTOS 100

typedef struct {
    char nome [100];
} Cliente;

typedef struct {
    char nome [100];
}Produto;

Cliente clientes [QTD_CLIENTE];
Produto produtos [QTD_PRODUTOS];

int index_cliente = 0;
int index_cliente2 = 0;

void insere_produto();
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
            insere_produto();
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
        printf("insira o cliente: \t");
        scanf("%s", clientes[index_cliente].nome);
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
        printf("Cliente %d: %s\n\n", (i+1), clientes[i]);
    }
   
}

void insere_produto(){
    int opcao;
    if (index_cliente2 >= QTD_PRODUTOS){
        printf ("Limite de produtos atingido!\n\n");
    }else{
        printf ("insira o produto: \t");
        scanf("%s", produtos[index_cliente2].nome);
        index_cliente2++;


        printf("Deseja inserir mais produtos?\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &opcao);

        if (opcao == 1){
            insere_produtos();
        }
    }
}

void listar_produtos(){ //listas = imprimi-r
    int j;
    for (j = 0; j < index_cliente2; j++){
        printf("produtos %d: %s\n\n", (j+1), produtos[j]);
        
    }
}