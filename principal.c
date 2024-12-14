#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void titulo_formatado();
int menu_opecoes();
void opcoes_inicio();
void menu_cadastro_produto();
void menu_produto();
void cadastrar_produto();
void listar_produto();

int main() {
	titulo_formatado("Bem vindo ao sistema de comércio!");
	char *opcoes[] = {"1 - PRODUTO", "2 - FUNCIONARIOS"};
	int opcao_escolhida;
	opcao_escolhida = menu_opecoes(2, opcoes);
	opcoes_inicio(opcao_escolhida);
	
	printf("\n"); 
	return 0;
}

void titulo_formatado (char mensagem[]) {
	system("clear");
	printf("###########################################");
	printf("\n");
	printf("%s", mensagem);
	printf("\n");
	printf("###########################################");
	printf("\n");
}

void opcoes_inicio(int opcao_escolhida) {
	switch(opcao_escolhida) {
	case 1:
		menu_produto();
		break; 
	case 2: 
		printf("Acessando cadastro de funcionário");
		break;
	}
}


int menu_opecoes(int maximo_opcoes, char *opcoes[]) {
	int opcao_escolhida;
	
	printf("\n");
	for(int i = 0; i < maximo_opcoes; i++) {
		printf("%s", opcoes[i]);
		printf("\n");
	}

	printf("Digite o número da opção: ");
	scanf("%d", &opcao_escolhida);
	
	while(opcao_escolhida < 1 || opcao_escolhida > maximo_opcoes) {
		system("clear");
		printf("Opção incorreta, tente novamente");

		printf("\n");
		for(int i = 0; i < maximo_opcoes; i++) {
			printf("%s", opcoes[i]);
			printf("\n");
		}

		printf("Digite o número da opção: ");
		scanf("%d", &opcao_escolhida);

	}

	return opcao_escolhida;
	
}


void menu_produto() {
	titulo_formatado("Menu de cadastro de produtos!");

	char *opcoes[] = {"1 - CADASTRAR", "2 - LISTAR"};
	int opcao_escolhida;
	opcao_escolhida = menu_opecoes(2, opcoes);

	switch(opcao_escolhida) {
		case 1:
			cadastrar_produto();
			break; 
		case 2: 
			listar_produto();
		break;
	}


}


void cadastrar_produto() {
		titulo_formatado("Menu de cadastro de produtos!");

		char nome_produto[100];

		//buscando linhas para quantidade total
		int qtd_produto = 0;
		FILE *getProduto;
		getProduto = fopen("tbl_produtos.txt", "r");
		char total_linhas[500];

		if(getProduto != NULL) {
			while(fgets(total_linhas, 500, getProduto)) {
				qtd_produto++;
			}

			fclose(getProduto);
		}

		memset(total_linhas, '\0', sizeof(total_linhas));
		qtd_produto++;


		//Cadastrando nova linha
		while(getchar() != '\n');
		printf("Digite o nome do produto: ");
		fgets(nome_produto, sizeof(nome_produto), stdin);

		FILE *setProduto;
		setProduto = fopen("tbl_produtos.txt", "a");
		fprintf(setProduto, "%d,%s", qtd_produto, nome_produto);
		fclose(setProduto);

		printf("\n");



		menu_produto();

}


void listar_produto() {
		titulo_formatado("Menu de cadastro de produtos!");

		printf("Produtos cadastrados: ");
		printf("\n");

		FILE *getProduto;
		char lista_produtos[500];
		char tecla_enter[500];

		getProduto = fopen("tbl_produtos.txt", "r");
		while(fgets(lista_produtos, 500, getProduto)) {
			printf("%s", lista_produtos);
		}

		printf("\n");
		printf("Tecle enter para voltar ...");
		while(getchar() != '\n');
		fgets(tecla_enter, sizeof(tecla_enter), stdin);

		memset(tecla_enter, '\0', sizeof(tecla_enter));


		menu_produto();

}
