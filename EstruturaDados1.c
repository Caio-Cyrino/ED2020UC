/*

# EstruturaDados1: Estrutura de Dados Programa 1
# Autor: Caio de Oliveira Cyrino
# Data: 11/12/2020
# Recebe como entrada três coeficientes de uma equação de 2° grau
# e retorna suas raízes.
# Termina a execução após retornar as raízes da equação.

*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <tgmath.h>

int main(int argc, char const *argv[])

{	
	
	double A, B, C; 															// Declaração de variáveis 'double' (A, B, C).
	double complex R1, R2, Delta;												// Declaração das variáveis complexas, utilizadas mais a frente para calcular raízes de números complexos.
	char Vetor[100];															// Declaração de um vetor com tamanho fixo para armazenar os caracteres inseridos pelo usuário.

	printf("Voce tem uma equacao no formato A*x^2 + B*x + C.\n");
	
	printf("Entre com o valor de A:\n");
	
	fgets(Vetor, sizeof(Vetor), stdin);											// Recebe um caractere.
	while(sscanf(Vetor, "%lf", &A) != 1)										// Loop implementado para converter o caractere inserido em double, armazenando-o na variável A.

	{
		printf("Por favor, insira um valor numerico valido para A:\n");			// Caso o caractere não seja um número, emite um erro e pede para inserir um caractere numérico.
		fgets(Vetor, sizeof(Vetor), stdin);
	}


	printf("Entre com o valor de B:\n");										// O mesmo processo ocorrido em "A" agora ocorre com a variável "B".
	
	fgets(Vetor, sizeof(Vetor), stdin);
	while(sscanf(Vetor, "%lf", &B) != 1)

	{
		printf("Por favor, insira um valor numerico valido para B:\n");
		fgets(Vetor, sizeof(Vetor), stdin);
	}

	printf("Entre com o valor de C:\n");										// Processo análogo às variáveis "A" e "B" na variável "C".
	
	fgets(Vetor, sizeof(Vetor), stdin);
	while(sscanf(Vetor, "%lf", &C) != 1)

	{
		printf("Por favor, insira um valor numerico valido para C:\n");
		fgets(Vetor, sizeof(Vetor), stdin);
	}

	Delta = pow(B,2) - (4*A*C);													// Cálculo do valor de Delta, utilizado na equação de Bhaskara.

	if (A != 0)
		if (creal(Delta) >= 0)													// Caso a parte 'Real' de Delta seja positiva (Delta > 0), temos que as raízes possuem somente parte real.

		{
			R1 = ( -B + sqrt(Delta) ) / (2*A);
			R2 = ( -B - sqrt(Delta) ) / (2*A);
			printf("As raizes da equacao sao:\n Raiz 1: %.2lf\n Raiz 2: %.2lf\n", creal(R1), creal(R2)); // Calculam-se as raízes reais e imprime as duas raízes encontradas.
		}

		else																	// Caso a parte 'Real' de Delta seja negativa (Delta < 0), significa que as raízes possuem parte real e complexa.

		{
			R1 = ( -B + sqrt(Delta) ) / (2*A);
			R2 = ( -B - sqrt(Delta) ) / (2*A);
			printf("As raizes da equacao sao:\n Raiz 1: %.2lf %+.2lfi\n Raiz 2: %.2lf %+.2lfi\n", creal(R1), cimag(R1), creal(R2), cimag(R2)); // Calculam-se as partes reais e imaginárias das raízes e as imprime.
		}

	else 
		printf("Coeficiente 'A' invalido, portanto nao e uma equacao de 2 grau.\n"); // Caso o coeficiente A seja igual a 0, significa que não possuímos uma equação de 2° grau.

	printf("Pressione 'Enter' para continuar\n");
	
	getchar();

	return 0;
}
