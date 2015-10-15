#pragma once
#include "stdafx.h"
#define CHAR_SUPERIOR_INFERIOR "-"
#define CHAR_LATERAIS "|"
#define CHAR_JUNCAO "+"
typedef struct documento
{
	int id;						// Id do documento
	char *nome_doc[50];			// Nome do documento
	char *data_reg[10];			// Data de registo (ex. 11/11/1111)
	char *nome_resp[50];		// Nome do respons�vel pelo cadastro
	int num_orig;				// N�mero de folhas originais
	char *tipo_doc[1];			// tipo de Documento (A)ntigo / (C)ontempor�neo
	struct documento *proximo;	// Ponteiro para pr�xmo registro da lista
	struct documento *anterior;	// Ponteiro para registro anterior da lista
}Documento;

void printSeparador(short linha, bool juncao);

void printMenu();

char menuPrincipal();

void adicionaDocumento(Documento * ultimo, Documento * doc);
