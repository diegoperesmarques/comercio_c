#include <stdio.h>
#include <stdlib.h>

void menu_inicial_titulo();
void menu_inicial_opcoes();

int main() {
	menu_inicial_titulo();
	menu_inicial_opcoes();
	
	printf("\n");
	return 0;
}

void menu_inicial_titulo () {
	system("clear");
	printf("###########################################");
	printf("\n");
	printf("Bem vindo ao sistema de comércio!");
	printf("\n");
	printf("###########################################");
	printf("\n");
}


void menu_inicial_opcoes() {
	int opcao_escolhida;
	
	printf("\n");
	printf("1 - CADASTRO PRODUTOS \n");
	printf("2 - CADASTRO FUNCIONARIOS \n");
	printf("Digite o número da opção: ");
	scanf("%d", &opcao_escolhida);
	
	while(opcao_escolhida < 1 || opcao_escolhida > 2) {
		system("clear");
		printf("Opção incorreta, tente novamente");
		printf("\n");
		printf("1 - CADASTRO PRODUTOS \n");
		printf("2 - CADASTRO FUNCIONARIOS \n");
		printf("Digite o número da opção: ");
		scanf("%d", &opcao_escolhida);
	}
	
	switch(opcao_escolhida) {
		case 1:
			printf("Acessando cadastro de produto");
			break; 
		case 2: 
			printf("Acessando cadastro de funcionário");
			break;
	}
	
}
