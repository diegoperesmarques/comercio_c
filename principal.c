#include <stdio.h>
#include <stdlib.h>

void titulo_formatado();
int menu_opecoes();
void opcoes_inicio();
void menu_cadastro_produto();
void menu_produto();

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


}
