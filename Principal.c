#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Pilha.h"
#include <string.h>

int main() {
	int op = 0;
	int qtde = 0;
	int ja_qtde = 0;
	int k;
	char jogada[3];

	Pilha * pa = criar();
	Pilha * pb = criar();
	Pilha * pc = criar();
	
	setlocale(LC_ALL, "Portuguese");
	
	do{
		while(op == 0){
			printf("0 - Voltar ao menu principal\n");
			printf("1 - Iniciar\n");
			printf("2 - Sair do jogo\n\n");
			printf("Selecione uma opção: ");
			scanf("%d", &op);
			fflush(stdin);
			while(tamanho(pa) > 0){
				desempilhar(pa);
			}
			while(tamanho(pb) > 0){
				desempilhar(pb);
			}
			while(tamanho(pc) > 0){
				desempilhar(pc);
			}
			ja_qtde = 0;
		}
		while(op != 0 && op != 1){
			printf("\nOpção inválida!\n");
			scanf("%d", &op);
			fflush(stdin);
		}

		while(op == 1){
			if(ja_qtde == 0){
				printf("Quantidade de peças (mínimo 3): ");
				scanf("%d", &qtde);
				printf("\n");
				fflush(stdin);
				while(qtde < 3){
					printf("A quantidade de peças não pode ser menor que 3\n");
					scanf("%d", &qtde);
					fflush(stdin);
				}
				k = qtde;
				while(0 < qtde){
					empilhar(pa, qtde--);
				}
			}
			if(tamanho(pc) == k){
				printf("Jogo concluído!\n");
				op = 0;
			} else{
				ja_qtde = 1;
				printf("Possíveis jogadas: \n");
				if(possivel(pa, pb) == 1){
					printf("A -> B\n");
				}
				if(possivel(pa, pc) == 1){
					printf("A -> C\n");
				}
				if(possivel(pb, pc) == 1){
					printf("B -> C\n");
				}
				if(possivel(pb, pa) == 1){
					printf("B -> A\n");
				}
				if(possivel(pc, pa) == 1){
					printf("C -> A\n");
				}
				if(possivel(pc, pb) == 1){
					printf("C -> B\n");
				}
				imprimir(pa);
				imprimir(pb);
				imprimir(pc);
				printf("Digite uma jogada (exemplo 'a-c')\n");
				scanf("%s", jogada);
				fflush(stdin);
				while(jogadaInvalida(jogada) == 0 && (jogada[0] != '1' && jogada[0] != '2' && jogada[0] != '0')){
					printf("Jogada inválida!\n");
					printf("Jogue novamente\n");
					scanf("%s", jogada);
					fflush(stdin);
				}
				if(jogada[0] == '0'){
					op = 0;
				}
				if(jogada[0] == '2'){
					op = 2;
				}
				if(jogada[0] == 'a'){
					if(jogada[2] == 'b'){
						if(possivel(pa, pb) == 1){
							empilhar(pb, desempilhar(pa));
						} else{
							printf("Jogada inválida!\n");
							printf("Jogue novamente\n");
							scanf("%s", jogada);
							fflush(stdin);
						}
					} else{
						if(possivel(pa, pc) == 1){
							empilhar(pc, desempilhar(pa));
						} else{
							printf("Jogada inválida!\n");
							printf("Jogue novamente\n");
							scanf("%s", jogada);
							fflush(stdin);
						}
					}
				} else if(jogada[0] == 'b'){
					if(jogada[2] == 'a'){	
						if(possivel(pb, pa) == 1){
							empilhar(pa, desempilhar(pb));
						} else{
							printf("Jogada inválida!\n");
							printf("Jogue novamente\n");
							scanf("%s", jogada);
							fflush(stdin);
						}
					} else{
						if(possivel(pb, pc) == 1){
							empilhar(pc, desempilhar(pb));
						} else{
							printf("Jogada inválida!\n");
							printf("Jogue novamente\n");
							scanf("%s", jogada);
							fflush(stdin);
						}
					}
				} else if(jogada[0] == 'c'){
					if(jogada[2] == 'a'){	
						if(possivel(pc, pa) == 1){
							empilhar(pa, desempilhar(pc));
						} else{
							printf("Jogada inválida!\n");
							printf("Jogue novamente\n");
							scanf("%s", jogada);
							fflush(stdin);
						}
					} else{
						if(possivel(pc, pb) == 1){
							empilhar(pb, desempilhar(pc));
						} else{
							printf("Jogada inválida!\n");
							printf("Jogue novamente\n");
							scanf("%s", jogada);
							fflush(stdin);
						}
					}
				}
			}
		}		
	}while(op!=2);
	return 0;
}

int possivel(Pilha * a, Pilha * b){
	if(tamanho(a) > 0){
		if(topo(a) < topo(b) || tamanho(b) == 0){
			return 1;
		} else{
			return 0;
		}
	} else{
		return 0;
	}
}

int jogadaInvalida(char jogada[]){
	if(jogada[0] != 'a' && jogada[0] != 'b' && jogada[0] != 'c'){
		return 0;
	}
	if(jogada[1] != '-'){
		return 0;
	}
	if(jogada[2] != 'a' && jogada[2] != 'b' && jogada[2] != 'c'){
		return 0;
	}
	if(jogada[0] == 'a' && jogada[2] == 'a'){
		return 0;
	}
	if(jogada[0] == 'b' && jogada[2] == 'b'){
		return 0;
	}
	if(jogada[0] == 'c' && jogada[2] == 'c'){
		return 0;
	}
	return 1;
}
