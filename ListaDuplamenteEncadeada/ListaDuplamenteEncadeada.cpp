// ListaDuplamenteEncadeada.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Exercicio Aula 4 -> Lista encadeada/duplamente encadeada */

int main()
{
	setlocale(LC_ALL, ""); // Inclui acentua��o XD
	Documento * primeiro = NULL;	// Primeiro item da lista
	Documento * ultimo = NULL;		// �ltimo item da lista
	
	if (primeiro == NULL) {
		printf("ITS NULL");
		exit(1);
	}
	adicionaDocumento(ultimo);
	return 0;
}