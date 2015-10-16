#pragma once
#include "stdafx.h"
#define CHAR_SUPERIOR_INFERIOR "-"
#define CHAR_LATERAIS "|"
#define CHAR_JUNCAO "+"
typedef struct documento
{
	int id = -1;							// Id do documento
	char nome_doc[51];						// Nome do documento
	char data_reg[11];						// Data de registo (ex. 11/11/1111)
	char nome_resp[51];						// Nome do responsável pelo cadastro
	int num_orig;							// Número de folhas originais
	char tipo_doc[2];						// tipo de Documento (A)ntigo / (C)ontemporâneo
	struct documento *proximo = NULL;		// Ponteiro para próxmo registro da lista
	struct documento *anterior = NULL;		// Ponteiro para registro anterior da lista
}Documento;

void printSeparador(short linha, bool juncao);

void printMenu();

char menuPrincipal();

Documento * novoDocumento();

bool existeDoumento(int id, Documento * primeiro);

void adicionaDocumento(Documento * primeiro, Documento * doc);

void imprimeDocumento(Documento * primeiro);

void alteraDocumento(Documento * primeiro);

Documento * deletaDocumento(Documento * primeiro);

void listaDocumentos(Documento * primeiro);
