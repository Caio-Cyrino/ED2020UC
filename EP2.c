/*##############################
# Exercício Programa 2
# Autor: Caio de Oliveira Cyrino
# Data: 09/01/2021
# Cria um programa que pede ao usuário a entrada de um nome e faz a pesquisa
# no arquivo .csv, retornando alguns dados do registro
#################################*/

#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Cadastro.h"

int main()
{
	char nome[MAXSTR];
	char *p;

	printf("\n Entre com o nome: ");
	fgets( nome, MAXSTR, stdin);

	for (p = nome; *p != '\n' && *p != '\0'; p++);
	*p = '\0';

	busca(nome);
}

int busca( char *nome) 
{
	FILE *dados, *indice;
	IndiceCadastro registro;
	char nomebusca[MAXSTR], *p;
	char linha[MAXLIN];
	char dado[MAXSTR];

	IndiceCadastro *encontrados;
	IndiceCadastro *espacoExtra;

	int conta = 0;
	int limite = 100;

	encontrados = malloc( limite * sizeof(IndiceCadastro) );

	p = nomebusca;
	strcpy(nomebusca, nome);

	while (*p != '\0') 
	{
		*p = toupper(*p);
		p++;
	}

	indice = fopen( INDICE, "r");

	while ( 1 )
	{
		fread( &registro, sizeof(registro), 1, indice);
		if ( feof(indice) ) break;

		if ( strstr(registro.nome, nomebusca) ) 
		{
			strcpy(encontrados[conta].nome, registro.nome);
			encontrados[conta].localiza = registro.localiza;
			conta++;
			if ( conta >= limite ) {
				
				limite = conta + 100;
				espacoExtra = malloc( limite * sizeof(IndiceCadastro) );
				memcpy(espacoExtra, encontrados, conta * sizeof(IndiceCadastro));
				free(encontrados);
				encontrados = espacoExtra;

			}
		}
	}

	printf("\n%d registros encontrados!\n", conta);


	fclose(indice);
	dados = fopen( DADOS, "r");

	for(int i = 0; i < conta; i++) 
	{
		fseek ( dados, encontrados[i].localiza, 0 );
		fgets ( linha, MAXLIN, dados );


		printf( "Nome: %s\n", encontrados[i].nome );
		extrai ( linha, DESCRICAO_CARGO, dado );
		printf ( "Cargo: %s\n", dado );
		extrai ( linha, UORG_LOTACAO, dado );
		printf("UORG_LOTACAO: %s\n",dado );

	}

	return conta;
}