#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char descricao [100];
float valor;
int quantidade;
} Produto;

void cadastrarProduto(Produto c){
  printf("\nCadastrar Produto\n");
  printf("Descrição: ");
  fgets(c.descricao, sizeof(c.descricao), stdin);
  c.descricao[strcspn(c.descricao, "\n")] = 0;
  printf("Valor: ");
  scanf("%f", &c.valor);

  printf("Quantidade: ");
  scanf("%d", &c.quantidade);
  printf("\n");
}

void salvarProduto(Produto c) {
  FILE *arquivo = fopen("produtos.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  fprintf(arquivo, "Descrição: %s,\nValor: %.2f\nQuantidade: %d.\n\n", c.descricao, c.valor, c.quantidade);
  fclose(arquivo);
}

void listarProdutos() {
  FILE *arquivo = fopen("produtos.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  char linha[70];
  while (fgets(linha, sizeof(linha), arquivo)){
    printf("%s", linha);
  }
fclose(arquivo);
}
int main() {
Produto c;
int opcao;
  
  do{
    printf("1 - Menu de Opções\n");
    printf("1 - Cadastrar produto\n2. Listar produtos\n3. Sair\n4. Escolha uma opção\n");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
      
      case 1:
      cadastrarProduto(c);
        salvarProduto(c);
      break;

      case 2:
      printf("\nListando produtos\n");
        listarProdutos();
      break;
      case 3:
      printf("\nSaindo...\n");
      break;

      default:
      printf("\nOpção inválida\n");
      break;
    }
  } while (opcao != 3);
  
  
  return 0;
}