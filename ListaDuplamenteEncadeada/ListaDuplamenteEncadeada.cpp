// ListaDuplamenteEncadeada.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Exercicio Aula 4 -> Lista encadeada/duplamente encadeada */

int main()
{
	setlocale(LC_ALL, "");													// Inclui acentuação XD
	Documento * primeiro = (Documento*) malloc(sizeof(Documento));			// Primeiro item da lista
	Documento * ultimo = (Documento*)malloc(sizeof(Documento));				// Último item da lista	

	bool loop = true;
	while (loop)
	{
		Documento * novoDoc;
		switch (menuPrincipal())
		{
		case '1': // Novo Documento
			novoDoc = novoDocumento();
			adicionaDocumento(primeiro, novoDoc);
			break;

		case '2': // Alterar Documento
			alteraDocumento(primeiro);
			break;

		case '3': // Mostrar Documento
			imprimeDocumento(primeiro);
			break;

		case '4': // Deleta Documento
			deletaDocumento(primeiro);
			break;

		case '5': // Listar Documentos
			listaDocumentos(primeiro);
			while (!_kbhit())
			{
				continue;
			}
			break;

		case '0': // Sair
			loop = false;
			break;

		default: // Default. Porque sempre tem um FDP pra teclar uma opção inválida...
			break;
		}
	}

	return 0;
}