#pragma once
#include "stdafx.h"

/* O programa deve conter tr�s fun��es :
- Adicionar Cadastro
- Alterar Cadastro
- Listar Cadastros
- (B�nus) remover Cadastro -> Utilizar� lista duplamente encadeada
*/

void printSeparador(short linha, bool juncao) {
	/* Print de uma linha separadora, com opcional para incluir char de jun��o ou n�o */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 1,linha });
	for (short i = 1; i < WIDTH; i++)
	{
		printf("%s", CHAR_SUPERIOR_INFERIOR);
	}

	if (juncao)
	{
		/* Adiciona Jun��o nas bordas da janela */
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,linha });
		printf("%s", CHAR_JUNCAO);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { WIDTH,linha });
		printf("%s", CHAR_JUNCAO);
	}
}

void printMenu() {
	/* Print de uma tela default, pode ser usado em todas as telas :) */

	/* Modo de preencher ap�s usar a fun��o:
	- Posicinar o cursor na linha desejada e depois realizar o print (para todos os campos da janela)
	- Para cada campo criado, posicionar o curso ao lado, permitindo que o usu�rio digite. (para cada campo da janela)
	*/

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

void adicionaDocumento(Documento *ultimo,Documento *doc) {
	/* Cria um novo documento, e registra no fim da fila */
	if ((doc = (Documento *)malloc(sizeof(Documento))) == NULL) {
		/* Aviso amig�vel para o usu�rio, caso o malloc falhe */
		printf("N�o h� mem�ria Suficiente. Compre uma m�quina que preste!");
		exit(1);
	}

	/* Inclus�o de dados */
	/* Ler na coluna 21 */
	printMenu();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 25, 1 });
	printf("%s", "Inclus�o de Documentos");
	printSeparador(2, true);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 3 }) && printf("%s", "Nome do documento	:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 4 }) && printf("%s", "Data de registro	:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 5 }) && printf("%s", "Nome do respons�vel	:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 6 }) && printf("%s", "N�mero de originais	:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, 7 }) && printf("%s", "Tipo de documento	:");

	/* Leitura dos campos */
	// Adicionado o _countof para que o windows se sinta seguro, coitado dele :/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 3 }) && scanf_s("%s", doc->nome_doc, _countof(doc->nome_doc));
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 4 }) && scanf_s("%s", doc->data_reg, _countof(doc->data_reg));
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 5 }) && scanf_s("%s", doc->nome_resp, _countof(doc->nome_resp));
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 6 }) && scanf_s("%d", &doc->num_orig);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 26, 7 }) && scanf_s("%s", doc->tipo_doc, _countof(doc->tipo_doc));

	/* Defini��es de ponteiros de localiza��o na lista */
	if (ultimo == NULL)
	{
		doc->id = 1;
		doc->anterior = NULL;
		
	}
	else
	{
		doc->id = (ultimo->id)+1;
		ultimo->proximo = doc;
		doc->anterior = ultimo;
	}
	doc->proximo = NULL; // Define como o �ltimo da lista ...
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2, HEIGHT-1 }) && printf("%s", "Documento adicionado");
	while (! _kbhit())
	{
		continue;
	}
}

void imprimeDocumento(Documento *) {
	/* Print do Registro passado */

}

void alteraDocumento(Documento *) {

}

void deletaDocumento(Documento *) {

}

void listaDocumentos(Documento * primeiro) {

}