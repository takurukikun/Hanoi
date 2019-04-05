#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Pilha.h"

int main() {
	int op = 0;
	int qtde = 0;
	int i = 1;
	char jogada1;
	char jogada2;
	Pilha * pa = criar();
	Pilha * pb = criar();
	Pilha * pc = criar();
	
	setlocale(LC_ALL, "Portuguese");
	printf("1 - Iniciar\n");
	printf("2 - Voltar jogada\n");
	printf("3 - Voltar ao menu principal\n");
	printf("4 - Sair do jogo\n");
	
	do{
		
		scanf("%d", &op);
		if(op == 1){
			
			printf("Quantidade de peças (mínimo 3)\n");
			scanf("%d", &qtde);
			while(qtde < 3){
				printf("A quantidade de pelas não pode ser menor que 3\n");
				scanf("%d", &qtde);
			}
			while(tamanho(pa) < qtde){
				empilhar(pa, i++);
			}
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
			printf("Digite uma jogada (exemplo a c)\n");
			jogada1 = getchar();
			jogada2 = getchar();
			if(jogada1 == 'a'){
				printf("Deu, vetin\n");
			}
		}
		
	}while(op!=4);
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
