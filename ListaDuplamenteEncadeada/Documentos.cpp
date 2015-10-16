#pragma once
#include "stdafx.h"

void printSeparador(short linha, bool juncao) {
	/* Print de uma linha separadora, com opcional para incluir char de junção ou não */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 1,linha });
	for (short i = 1; i < WIDTH; i++)
	{
		printf("%s", CHAR_SUPERIOR_INFERIOR);
	}

	if (juncao)
	{
		/* Adiciona Junção nas bordas da janela */
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,linha });
		printf("%s", CHAR_JUNCAO);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { WIDTH,linha });
		printf("%s", CHAR_JUNCAO);
	}
}

void printMenu() {
	/* Print de uma tela default, pode ser usado em todas as telas :) */

	system("cls");
	for (short i = 0; i < HEIGHT; i++)
	{
		/* Print das Laterais */
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,i });
		printf("%s", CHAR_LATERAIS);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { WIDTH,i });
		printf("%s", CHAR_LATERAIS);
	}

	for (short i = 0; i < WIDTH; i++)
	{
		/* Print Superior e Inferior */
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { i,0 });
		printf("%s", CHAR_SUPERIOR_INFERIOR);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { i,HEIGHT });
		printf("%s", CHAR_SUPERIOR_INFERIOR);
	}

	/* Print dos cantos */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	printf("%s", CHAR_JUNCAO);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,HEIGHT });
	printf("%s", CHAR_JUNCAO);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { WIDTH,0 });
	printf("%s", CHAR_JUNCAO);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { WIDTH,HEIGHT });
	printf("%s", CHAR_JUNCAO);
}

char menuPrincipal() {
	
	printMenu();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 25, 1 });
	printf("%s", "Menu Principal");
	printSeparador(2, true);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 3 }) && printf("%s", "1. Adicionar Documento");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 4 }) && printf("%s", "2. Alterar Documento");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 5 }) && printf("%s", "3. Mostrar Documento");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 6 }) && printf("%s", "4. Deletar Documento");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 7 }) && printf("%s", "5. Listar Documentos");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 8 }) && printf("%s", "0. Sair");
	while (!_kbhit())
	{
		continue;
	}
	char opcao = _getch();
	return opcao;
	

}

Documento * novoDocumento() {
	/* Retorna o doc estruturado */


	Documento * doc = (Documento *)malloc(sizeof(Documento));
	if ((doc = (Documento *)malloc(sizeof(Documento))) == NULL) {
		/* Aviso amigável para o usuário, caso o malloc falhe */
		printf("Não há memória Suficiente. Compre uma máquina que preste!");
		exit(1);
	}

	/* Mostra a o menu como deve ser de verdade :P */
	printMenu();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 25, 1 });
	printf("%s", "Inclusão de Documentos");
	printSeparador(2, true);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 3 }) && printf("%s", "Nome do documento	:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 4 }) && printf("%s", "Data de registro	:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 5 }) && printf("%s", "Nome do responsável	:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 6 }) && printf("%s", "Número de originais	:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 7 }) && printf("%s", "Tipo de documento	:");

	/* Leitura dos campos */
	/* WARNING: Ler dados a partir da coluna 26 */
	// Adicionado o _countof para que o windows se sinta seguro, coitado dele :/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 3 }) && scanf_s("%s", doc->nome_doc, _countof(doc->nome_doc));
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 4 }) && scanf_s("%s", doc->data_reg, _countof(doc->data_reg));
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 5 }) && scanf_s("%s", doc->nome_resp, _countof(doc->nome_resp));
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 6 }) && scanf_s("%d", &doc->num_orig);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 7 }) && scanf_s("%s", doc->tipo_doc, _countof(doc->tipo_doc));

	/* Define Proximo e anterior */
	doc->anterior = NULL;
	doc->proximo = NULL;

	return doc;
}


int escolhaDocumento(Documento *primeiro) {
	listaDocumentos(primeiro);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, HEIGHT - 1 }) && printf("%s", "Id desejado: ");
	int opcaoID;
	scanf_s("%d", &opcaoID);
	return opcaoID;
}

bool existeDoumento(int id, Documento * primeiro) {
	Documento *atual = primeiro;
	bool loop = true;
	while (loop)
	{
		if (atual->id != id)
		{
			if (atual->proximo == NULL)
			{
				return false;
			}
			atual = atual->proximo;
		}
		return true;
	}
}

void adicionaDocumento(Documento *primeiro,Documento *doc) {
	/* Definições de ponteiros de localização na lista */

	Documento *ultimo = primeiro;
	if (ultimo->id > 0)
	{
		while (ultimo->proximo != NULL)
		{
			ultimo = ultimo->proximo;
		}

		doc->id = ((ultimo->id) + 1);

		doc->anterior = ultimo;
		doc->proximo = NULL;
		ultimo->proximo = doc;
	}
	else
	{
		primeiro->id = 1;
		strcpy_s(primeiro->nome_doc, doc->nome_doc);
		strcpy_s(primeiro->data_reg, doc->data_reg);
		strcpy_s(primeiro->nome_resp, doc->nome_resp);
		primeiro->num_orig = doc->num_orig;
		strcpy_s(primeiro->tipo_doc, doc->tipo_doc);
		primeiro->proximo = NULL;
		primeiro->anterior = NULL;
	}
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, HEIGHT-1 }) && printf("%s", "Documento adicionado!");
	while (! _kbhit())
	{
		continue;
	}
}

void imprimeDocumento(Documento * primeiro) { // Print do registro do documento
	
	/* Lista as opções possíveis e espera o id desejado */
	int opcaoId = escolhaDocumento(primeiro);

	/* Mostra o Registro do documento*/
	printMenu();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 25, 1 });
	printf("Registro do documento: %d ",opcaoId);
	printSeparador(2, true);
	documento * atual = primeiro;
	while ((atual->id != opcaoId) && (atual->proximo != NULL))
	{
		atual = atual->proximo;
	}
	if (atual->id == opcaoId)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 3 }) && printf("Nome do documento	: %s",atual->nome_doc);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 4 }) && printf("Data de registro	: %s",atual->data_reg);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 5 }) && printf("Nome do responsável	: %s",atual->nome_resp);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 6 }) && printf("Número de originais	: %d",atual->num_orig);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 7 }) && printf("Tipo de documento	: %s",atual->tipo_doc);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 8 });
	}
	else
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 3 }) && printf("Registro Não encontrado");
	}
	while (!_kbhit())
	{
		continue;
	}
	
}


void alteraDocumento(Documento * primeiro) {
	/* Altera o documento selecionado */
	int opcaoId = escolhaDocumento(primeiro);
	if (existeDoumento(opcaoId,primeiro))
	{
		Documento * novo = novoDocumento();
		Documento * atual = primeiro;
		while (atual->id != opcaoId)
		{
			atual = atual->proximo;
		}
		
		strcpy_s(atual->nome_doc, novo->nome_doc);
		strcpy_s(atual->data_reg, novo->data_reg);
		strcpy_s(atual->nome_resp, novo->nome_resp);
		atual->num_orig = novo->num_orig;
		strcpy_s(atual->tipo_doc, novo->tipo_doc);

	}
	
}

Documento * deletaDocumento(Documento *primeiro) {
	/* Deleta o documento */
	int opcaoId = escolhaDocumento(primeiro);
	if (existeDoumento(opcaoId,primeiro))
	{
		Documento * atual = primeiro;
		while (atual->id != opcaoId)
		{
			atual = atual->proximo;
		}
		
		if (atual->id != primeiro->id)
		{
			if (atual->proximo != NULL)
			{
				Documento * tmp = atual->proximo;
				tmp->anterior = atual->anterior;

			}

			if (atual->anterior != NULL)
			{
				Documento * tmp = atual->anterior;
				tmp->proximo = atual->proximo;

			}

			free(atual);
		}
		else
		{
			//TODO: Tratar quando for exclusão do primeiro da lista
			if (primeiro->proximo != NULL)
			{
				primeiro = primeiro->proximo;
				primeiro->anterior = NULL;
			}
			else
			{
				/* Isso é um XGH muito grande, é possível que eu não arruma .. esteja avisado */
				primeiro->id = -1;
			}
			
		}

		
	}

	return primeiro;
}

void listaDocumentos(Documento * primeiro) {
	/* Lista todos os documentos */
	printMenu();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 25, 1 });
	printf("%s", "Listagem de Documentos");
	printSeparador(2, true);
	
	Documento * atual = primeiro;
	short linha = 3; // Linha onde deve iniciar a printar os documentos
	bool loop = true;
	while (loop)
	{
		if (atual->id < 0)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, linha }) && printf("Nenhum Documento a listar");
			loop = false;

		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, linha }) && printf("Id: %d\tNome documento : %s", atual->id, atual->nome_doc);
			if (atual->proximo != NULL)
			{
				atual = atual->proximo;
				linha++;
			}
			else
			{
				loop = false;
			}
		}
		
	}
}