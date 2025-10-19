#include <stdio.h>

int main() {
   float num1, num2, resultado;
   char operador;

   printf("Digite o primeiro número: ");
   scanf("%f", &num1);

   printf("Digite o operador (+, -, , /): ");
   scanf(" %c", &operador); 

   printf("Digite o segundo número: ");
   scanf("%f", &num2);

   switch (operador) {
      case '+':
         resultado = num1 + num2;
         break;
      case '-':
         resultado = num1 - num2;
         break;
      case '*':
         resultado = num1 * num2;
         break;
      case '/':
         if (num2 == 0) {
            printf("Erro: divisão por zero");
            return 1; 
         } else {
            resultado = num1 / num2;
         }
         break;
      default:
         printf("Operador inválido");
         return 1; 
   }

   printf("O resultado é: %.2f", resultado);
   return 0;
}