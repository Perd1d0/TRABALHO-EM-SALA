#include <stdio.h>

// função da opção 1
void transformandoFC(double *resultado, double *t1) {
  (*resultado) = 1.8 * (*t1) + 32;
  printf("O resultato em Fahrenheit é: %.2lf\n", (*resultado));
}

// função da opção 2
void transformandoCF(double *resultado, double *t1) {
  (*resultado) = (*t1 - 32) / 1.8;
  printf("O resultato em Celsius é: %.2lf\n", (*resultado));
}

int main(void) {
  int opcao;
  double t1;

  printf("Escolha o tipo de conversão\n");
  printf("1 - F->.C\n");
  printf("2 - C->F\n");
  printf("3 - Sair\n");

  do {
    printf("Digite uma opção: \n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Transformando F -> C\n");
      printf("Digite o valor em Fahrenheit:");
      scanf("%lf", &t1);
      double resultado = 0;
      transformandoFC(&resultado, &t1);
      break;

    case 2:
      printf("Transformando C -> F\n");
      printf("Digite a temperatura: ");
      scanf("%lf", &t1);
      double resultado2 = 0;
      transformandoCF(&resultado2, &t1);
      break;
    case 3:
      printf("Saindo...\n");
      break;

    default:
      printf("Opção inválida\n");
    }
  } while (opcao != 3);
  return 0;
}