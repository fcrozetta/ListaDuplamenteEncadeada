// ListaDuplamenteEncadeada.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Exercicio Aula 4 -> Lista encadeada/duplamente encadeada */

int main()
{
	setlocale(LC_ALL, ""); // Inclui acentuação XD
	Documento * primeiro = NULL;	// Primeiro item da lista
	Documento * ultimo = NULL;		// Último item da lista	
	
	
	bool loop = true;
	while (loop)
	{
		Documento * novoDoc = NULL;
		if (primeiro = NULL) {
			primeiro = novoDoc;
		}
		
		switch (menuPrincipal())
		{
		case '1':
			adicionaDocumento(ultimo, novoDoc);
			break;

		case '2':
			/* Alterar Documento */
			break;

		case '3':
			/* Mostrar Documento */
			break;

		case '4':
			/* Deletar Documento */
			break;

		case '5':
			/* Listar Documentos */
			break;

		case '0':
			loop = false;
			break;

		default:
			printf("opcao inválida!");
			break;
		}
	}

	return 0;
}