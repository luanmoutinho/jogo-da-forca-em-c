#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/* o programa jแ sorteia a palavra e descobre o seu tamanho e imprime o menu principal*/
int countA = 0;
int count = 0; // contador para indice de palavras erradas - usado no m้todo conferirLetra();
int erros = 0;
int acertos = 0;
char letra; 
char letrasAcertadas[15];
char letrasErradas[5];
char palavraNaTela[20];
char palavraSorteada[20];
int tamanhoPS;
int tamanhoUP;

char arrayPalavras[20][15] = {
			{'c','a','c','h','o','r','r','o'},
			{'c','a','v','a','l','o'},
			{'j','a','v','a','l','i'},
			{'z','e','b','r','a'},
			{'r','i','n','o','c','e','r','o','n','t','e'},
			{'c','o','e','l','h','o'},
			{'c','a','b','r','a'},
			{'c','o','b','r','a'},
			{'c','a','b','r','i','t','o'},
			{'e','l','e','f','a','n','t','e'},
			{'f','o','c','a'},
			{'b','e','z','e','r','r','o'},
			{'o','v','e','l','h','a'},
			{'o','n','i','n','t','o','r','r','i','n','c','o'},
			{'p','a','p','a','g','a','i','o'},
			{'g','a','t','o'},
			{'p','e','r','i','q','u','i','t','o'},
			{'r','a','t','o'},
			{'m','a','c','a','c','o'},
			{'p','e','i','x','e'}};	

//########################################################################## a็๕es							
int random(){ // gera um numero aleatorio para ser usado com indice no sorteio da palavra
	srand(time(NULL));
	int p = rand()%20;
	return p;
}


void sortearPalavra(){ //sorteia a palavra de acordo com indice gerado pelo random e isola a palavra em uma variแvel a parte / tamb้m calcula o tamanho da palavra pra exibir na tela a quantidade de * equivalentes a palavra soreteada
	int indice = random();
	for(int i = 0; i < 15; i++){
		palavraSorteada[i] = arrayPalavras[indice][i];		
	}
	tamanhoPS = strlen(palavraSorteada);
}
void zerarPalavraTela(){
	for(int i = 0; i < (tamanhoUP); i++){
		palavraNaTela[i]= NULL;		
	}
	
	
}


void palavraTela(){	
	tamanhoPS = strlen(palavraSorteada);
	tamanhoUP = tamanhoPS;
	for(int i = 0; i < (tamanhoPS); i++){
		palavraNaTela[i]= '*';		
	}
}

void conferirLetra(){ // verifica se se a letra digitada bate com alguma letra da palavra, compara indice por indice e acrescente um erro ou  um acerto dependendo do resultado 
	int contErro = 0;	
	for(int i = 0; i < strlen(palavraSorteada); i++){
		if(letra == palavraSorteada[i]){			
			palavraNaTela[i]= palavraSorteada[i];		
			contErro++;
			acertos++;
			letrasAcertadas[countA] = letra;
			countA++;
		}
	}
	if(contErro == 0){
		erros++;
		letrasErradas[count] = letra;
		count++;
	}	
}
 
 
 void zerarVariaveis(){ // reinicia contadores para uma nova partida
 	countA = 0;
	count = 0; // contador para indice de palavras erradas - usado no m้todo conferirLetra();
 	erros = 0;
 	acertos = 0;
 }
//########################################################################## FIM AวีES





//######################################################################### DISPLAYS


void encerrar(){ // encerra o programa
	system("cls");
	printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");			
	printf("\t\tบ\t     PROGRAMA FINALIZADO PELO USUARIO             บ\n");
	printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
	exit(1);
}

void displayContinuar(){  // pergunta se o usuแrio deseja iniciar um novo jogo ou se deseja sair 
	int continuar;
	printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");			
	printf("\t\tบPRESSIONE 1 PARA INICIAR NOVO JOGO 	                  บ\n");
	printf("\t\tบOU PRESSIONE 0 PARA SAIR DO JOGO 	                  บ\n");
	printf("\t\t >");
	scanf("%d", &continuar);
	getchar();
	if(continuar == 1){
		zerarVariaveis();
		zerarPalavraTela();
		sortearPalavra();
		palavraTela	();
		displayJogo();
	}else if( continuar == 0){
		encerrar();				
	}
}


void displayRespUsuario(){ // pede ao usuแrio que informe a letra para comparar com a palavra 
	printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");			
	printf("\t\tบDIGITE UMA LETRA: 				          บ\n");
	printf("\t\t >");
	scanf("%c", &letra);
	getchar();	
	if(letra == '0'){
		encerrar();
	}	
	conferirLetra();				
	displayJogo();
}


void displayVitoria(){  // exibe a mensagem de vit๓ria da partida
	printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("\t\tบ			 		  	          บ\n");
	printf("\t\tบ\t	    		  	                  บ\n");
	printf("\t\tบ\t\t  ***	 		  VOCE            บ\n");
	printf("\t\tบ\t\t *0_0 * 		  VENCEU!         บ\n");
	printf("\t\tบ\t\t *\\_/ *	 		                  บ\n");
	printf("\t\tบ\t\t  ***	 		  NINGUEM         บ\n");
	printf("\t\tบ\t\t   บ	 		  MORREU	  บ\n");
	printf("\t\tบ\t\tษออฮออป	 	          HOJE!       	  บ\n");
	printf("\t\tบ\t\tบ  บ  บ	  	          Ü Ü Ü           บ\n");
	printf("\t\tบ\t	  ษสป		     	  	  	  บ\n");
	printf("\t\tบ\t	  บ บ	 		  	          บ\n");
	printf("\t\tบ\t			 		  	  บ\n");
	printf("\t\tบ\t			 		  	  บ\n");
	printf("\t\tบ			 		  	          บ\n");
	printf("\t\tบ			 		  	          บ\n");
	printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");	
	displayContinuar();
	
}

void displayTopo(){  // enfeite
	printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");			
	printf("\t\tบ			JOGO DA FORCA		  	  บ\n");
	printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
	printf("\t\tTOTAL DE ACERTOS: %d", acertos);
}


void displayJogo(){ // controla o que ้ exibido na tela
	system("cls");
	displayTopo();
	if(acertos < tamanhoPS){	
		displayBoneco();
		printf("\t\t\t *PRESSIONE 0 A QUALQUER MOMENTO PARA SAIR*");
		displayPalavra();
		//printf("tamanho %d", tamanhoPS);
		//printf("\npalavra sorteada foi: %s\n", palavraSorteada); 
		if(erros < 6)
			displayRespUsuario();
			printf("");
	}else{
		displayVitoria();
		displayPalavra();		
	}	
}



void displayPalavra(){ //exibe a quantidade de caracteres referente a palavra  e uma dica padrใo
	printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");			
	printf("\t\tบ\t			 		  	  บ\n");
	printf("\t\tบ\t\tPALAVRA ออ> %s	                 \n", palavraNaTela);
	printf("\t\tบ\t			 		  	  บ\n");
	printf("\t\tบ\t\tDICA: ANIMAIS			  	  บ\n");
	printf("\t\tบ			 		  	          บ\n");		
	printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
}


void displayBoneco(){// controla as partes do corpo que vใo aparecendo ao errar
	
	switch(erros){
		case 1:
			printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ	           LETRAS DIGITADAS -> %c	          บ\n", letrasErradas[0]);
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ\tÛ฿฿฿฿฿฿฿฿฿฿	    		  	          บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  ESSE            บ\n");
			printf("\t\tบ\tÛ\t *   * 		  	  FOI             บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  O SEU           บ\n");
			printf("\t\tบ\tÛ			 	  PRIMEIRO        บ\n");
			printf("\t\tบ\tÛ			 	  ERRO            บ\n");
			printf("\t\tบ\tÛ		 		  Ü Ü Ü	          บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");	
			break;
		case 2:
			printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ	           LETRAS DIGITADAS -> %c %c	          บ\n", letrasErradas[0], letrasErradas[1]);
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ\tÛ฿฿฿฿฿฿฿฿฿฿	    		  	          บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  ESSE            บ\n");
			printf("\t\tบ\tÛ\t *   * 		  	  FOI             บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  O SEU           บ\n");
			printf("\t\tบ\tÛ\t   บ	 		  SEGUNDO	  บ\n");
			printf("\t\tบ\tÛ\t   บ	 		  ERRO	          บ\n");
			printf("\t\tบ\tÛ\t   บ 		  	  Ü Ü Ü           บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");			
			break;
		case 3:
			printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ	           LETRAS DIGITADAS -> %c %c %c	          บ\n", letrasErradas[0], letrasErradas[1], letrasErradas[2]);
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ\tÛ฿฿฿฿฿฿฿฿฿฿	    		  	          บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  ESSE            บ\n");
			printf("\t\tบ\tÛ\t *   * 		  	  FOI             บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  O SEU           บ\n");
			printf("\t\tบ\tÛ\t   บ	 		  TERCEIRO	  บ\n");
			printf("\t\tบ\tÛ\tษออฮ	 		  ERRO	          บ\n");
			printf("\t\tบ\tÛ\t   บ 		  	  Ü Ü Ü           บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");			
			break;
		case 4:
			printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ	           LETRAS DIGITADAS -> %c %c %c	%c         บ\n", letrasErradas[0], letrasErradas[1], letrasErradas[2], letrasErradas[3] );
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ\tÛ฿฿฿฿฿฿฿฿฿฿	    		  	          บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  ESSE            บ\n");
			printf("\t\tบ\tÛ\t *   * 		  	  FOI             บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  O SEU           บ\n");
			printf("\t\tบ\tÛ\t   บ	 		  QUARTO	  บ\n");
			printf("\t\tบ\tÛ\tษออฮออป	 	          ERRO  	  บ\n");
			printf("\t\tบ\tÛ\t   บ  	  	          Ü Ü Ü           บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
			break;
		case 5:
			printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ	           LETRAS DIGITADAS -> %c %c %c	%c %c       บ\n", letrasErradas[0], letrasErradas[1], letrasErradas[2], letrasErradas[3], letrasErradas[4] );
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ\tÛ฿฿฿฿฿฿฿฿฿฿	    		  	          บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  ESSE            บ\n");
			printf("\t\tบ\tÛ\t *   * 		  	  FOI             บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  O SEU           บ\n");
			printf("\t\tบ\tÛ\t   บ	 		  QUINTO	  บ\n");
			printf("\t\tบ\tÛ\tษออฮออป	 	          ERRO	          บ\n");
			printf("\t\tบ\tÛ\tบ  บ  บ	  	          Ü Ü Ü           บ\n");
			printf("\t\tบ\tÛ	  ษส		 		  	  บ\n");
			printf("\t\tบ\tÛ	  บ 	 		  	          บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");			
			break;
		case 6:
			printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ\tÛ฿฿฿฿฿฿฿฿฿฿	    		  	          บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  VOCE            บ\n");
			printf("\t\tบ\tÛ\t *x x * 		  ERROU           บ\n");
			printf("\t\tบ\tÛ\t * ~ *	 		  DEMAIS,         บ\n");
			printf("\t\tบ\tÛ\t  ***	 		  DEIXE           บ\n");
			printf("\t\tบ\tÛ\t   บ	 		  OUTRO	          บ\n");
			printf("\t\tบ\tÛ\tษออฮออป	 	          JOGAR	  	  บ\n");
			printf("\t\tบ\tÛ\tบ  บ  บ	  	          Ü Ü Ü           บ\n");
			printf("\t\tบ\tÛ	  ษสป		     	  	  	  บ\n");
			printf("\t\tบ\tÛ	  บ บ	 		  	          บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");			
			displayContinuar();
			break;
		default:
			printf("\n\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ\tÛ฿฿฿฿฿฿฿฿฿฿	    		  	          บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ		 		  	          บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ\tÛ			 		  	  บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tบ			 		  	          บ\n");
			printf("\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
			break;						
	}
}
	
//############################################################################# FIM DISPLAYS

//############################################################################# MAIN


int main(int argc, char *argv[]) {
	sortearPalavra();
	palavraTela	();
	displayJogo();
	
	return 0;
}
