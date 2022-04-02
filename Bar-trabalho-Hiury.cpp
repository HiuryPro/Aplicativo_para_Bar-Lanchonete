#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MARGEM 135
#define DESENHO 60
#define DESENHOS 71

void margens(){
	int i , j;
		for(i=0; i<120; i++){
	        printf("%c", MARGEM);
	    }
		for(j=0; j<28; j++)
		{
			printf("%c%c", MARGEM,MARGEM);
			printf("\x1B[116C");
			printf("%c%c\n", MARGEM,MARGEM);	
		}
		
		printf("\x1B[19B");
		for(i=0; i<120; i++)
		{
        	printf("%c", MARGEM);
    	}
	
}

main(){
	setlocale(LC_ALL,"Portuguese");
	system("color 60");
	
	int indice, c;
	int  quantidade, cliente, totais[12];
	int i,j, count, num, tipo, iniciacao, contador, aumenta;
	int pergunta,pergunta2,pergunta3, pergunta4;
	int valida, valida1;
	int desenho, desenho1, desenho2;
	
	float preco[12], total, total1, troco , pago, deve;
	char produto[12][25], nomebar[20];
	
	cliente=1;
	contador = 0;
	troco=0;
	indice=0;
	count =-1;
	pergunta=3;
	pergunta2=1;
	pergunta3 =1;
	pergunta4 =1;
	num= 1;
	total=0;
	total1=0;
		
		for(iniciacao = 0 ; iniciacao < 12; iniciacao++){
			totais[iniciacao] = 0;
			
		}
		margens();
		system("cls");
	
    	printf("\x1B[30A");
    	printf("\t\t\t\tBem vindo ao nosso Software!!\n");
		printf("\t\t\tInforme o nome do bar  "); 
		gets(nomebar);/* Para o funcionaro/patrão escolher o nome do bar*/
		fflush(stdin);
		system("cls");
			
		
		
		do{
			
			margens();
    		printf("\x1B[30A");
			printf("\t\t\t\t\t\t\t %s\n",nomebar);
			printf("\t\t\t\t\t\t    MENU\n");
			printf("\n");
			for(desenho1=0; desenho1<=12; desenho1++)
			{
			for(desenho= 0; desenho<=23; desenho++)
			{
				if(desenho == 0){
					printf("\t\t\t\t\t");
				}
				if((desenho1 == 4 || desenho1 == 5) || (desenho1 == 10 || desenho1 == 11))
				{
					if(desenho == 0 || desenho ==2 || desenho == 4 || desenho == 6 ||desenho == 8 || desenho ==10 || desenho == 12 || desenho == 14 ||desenho == 16 || desenho == 18 ||desenho == 20 || desenho ==22){
					printf("]");	
					}
					else
					printf("[");
				}else if(desenho1 == 0 || desenho1 == 1){
				printf("*");
					
				}else if(desenho1 != -1){
					printf("|");
				}
				
			}
			printf("\n");
			}
	
			printf("\x1B[9A");
			for(desenho1=0; desenho1<=1; desenho1++){
				printf("\x1B[%iC",DESENHO);
				for(desenho= 0; desenho<=14; desenho++)
				{
						if(desenho == 0 || desenho ==2 || desenho == 4 || desenho == 6 ||desenho == 8 || desenho ==10 || desenho == 12 || desenho == 14){
						printf("]");	
						}
						else
						printf("[");
					
				}
				printf("\n");
			}
			printf("\x1B[4B");
			for(desenho1=0; desenho1<=1; desenho1++){
				
				printf("\x1B[%iC",DESENHO);
				for(desenho= 0; desenho<=14; desenho++)
				{
						if(desenho == 0 || desenho ==2 || desenho == 4 || desenho == 6 ||desenho == 8 || desenho ==10 || desenho == 12 || desenho == 14){
						printf("]");	
						}
						else
						printf("[");
					
				}
				printf("\n");
			}
				printf("\x1B[6A");
			for(desenho1 = 0; desenho1 < 4; desenho1++)
			{
				printf("\x1B[%iC",DESENHOS);
			for(desenho2 = 0; desenho2<2; desenho2++)
			{
				printf("[]");
			}
			printf("\n");	
			}
			printf("\x1B[4B");
			printf("\t\t\t1- Cadastro de produtos e preços\n");/* Para o funcionario/patrão cadastrar os produtos e preços*/
			printf("\t\t\t2- Cacha\n");						   /* Para o funcionario/patrão usar o cacha */
			printf("\t\t\t3- Relatório\n");					   /* Para o funcionario/patrão ver o relatorio das vendas */
			printf("\t\t\t4- Sair\n");                         /* Para o funcionario/patrão Sair do sistema */
			printf("\t\t\tEscolha sua opção.");                /* Para ofuncionario/patrão escolher a opção que deseja*/
			scanf("%i", &pergunta);
			if(pergunta == 2 && valida != 2 ){   /*Condição para poder acessar o relatorio*/
				printf("\n\tVocê não fez o cadastro de produtos!\n");
				printf("\tAcesso ao cacha permitido apenas após o cadastro!\n");
				printf("\tDeseja ir ao Cadastro?(1 para SIM 0 para NÃO)");/* Acesso para o cadastro ou sair do sistema, fora do menu principal */
				scanf("%i", &pergunta);
				if(pergunta != 1){ /* Condição para Sair do sistema*/
					pergunta = 4;	
				}
				
				system("cls");
				
			}
			if(pergunta == 3 && valida1 != 3 && valida != 2 ){   /*Condição para poder acessar o relatorio*/
				printf("\n\tVocê não fez o cadastro de produtos nem usou o cacha!\n");
				printf("\tAcesso ao relátorio permitido apenas após o cadastro e o uso do cacha!\n");
				printf("\tDeseja ir ao Cadastro?(1 para SIM 0 para NÃO)");/* Acesso para o cadastro ou sair do sistema, fora do menu principal */
				scanf("%i", &pergunta);
				if(pergunta != 1){ /* Condição para Sair do sistema*/
					pergunta = 4;	
				}
				
				system("cls");
				
			}else
			if(pergunta == 3 && valida == 2 && valida1 != 3 ){   /*Condição para poder acessar o relatorio*/
				printf("\n\tVocê não usou o cacha!\n");
				printf("\tAcesso ao relátorio permitido apenas após o uso do cacha!\n");
				printf("\tDeseja ir ao Cacha?(1 para SIM 0 para NÃO)");/* Acesso para o cadastro ou sair do sistema, fora do menu principal */
				scanf("%i", &pergunta);
				if(pergunta == 1){ /* Condição para Sair do sistema*/
					pergunta = 2;	
				}else
				pergunta = 4;
				
				system("cls");
				
			}	
				
			
			fflush(stdin);
			system("cls");
			
			switch(pergunta){
				
				case 1:
					margens();
    				printf("\x1B[30A");
					printf("\t\t\t\t\t       Cadastro de produtos\n");
					printf("\t\t\t\t\tMaximo 12 produtos\n");
						while(pergunta2 == 1)
						{
							
							count++;
							if(count == 4 || count == 8 || count == 11)
							{
								system("cls");
								margens();
    							printf("\x1B[30A");
								printf("\t\t\t\t\t       Cadastro de produtos\n");
								printf("\t\t\t\t\tMaximo 12 produtos\n");	
							}
							printf ("\n\tDigite o nome do %i produto  ", num);
							gets (produto[count]);
							num++;
							fflush(stdin);
							printf("\n\tInforme o preço desse produto  ");
							scanf("%f", &preco[count]);
							fflush(stdin);
							
							
							printf("\n\tDeseja Informar outro produto?(1 para SIM 0 para NÃO)  ");
							scanf("%i", &pergunta2);
							fflush(stdin);
							if(count == 11)
							{
								valida=2;
								printf("\n\tMaximo de produtos cadastrados alcançado!\n");
								printf("\tCadastros feitos com sucesso!\n");
								printf("\tRetornar ao menu? (1 para SIM 0 para NÃO)");
								scanf("%i",&pergunta2);
								fflush(stdin);	
								if(pergunta2 == 1)
								{   
									pergunta2 = pergunta2 + 5;
									pergunta = 5;
									system("cls");	
								}
								if(pergunta2 == 0){
									system("cls");
									pergunta = 4;
								}
									
						
							}
													
					    }
					    if(count < 11)
						{
					    	
							system("cls");
							margens();
					    	printf("\x1B[30A");
							printf("\t\tCadastros feitos com sucesso!\n");
							printf("\tRetornar ao menu? (1 para SIM 0 para NÃO)");
							scanf("%i",&pergunta);
							valida=2;
							if(pergunta == 1){
								pergunta = pergunta + 5;
								system("cls");	
							}else{
								system("cls");
								pergunta = 4;	
							}
								
						}
						break;
				case 2:
					while(pergunta3 == 1)
					{
						indice=0;
						contador = 0;
							margens();
						    printf("\x1B[30A");
							printf("\t\t\tCacha\n");
							contador++;
							printf("\t\tTabela de produtos e preços\n");
							contador++;
						
							for(c=0; c<=count; c++)
							{
								indice++;
								printf("\t%i- %s  Preço: R$ %.2f\n",indice,produto[c],preco[c]);
								contador++;	
							}
						while(pergunta4 == 1)
						{
							printf("\n\tInforme o número do produto e a quantidade comprada pelo %iº Cliente.",cliente);
							scanf("%i%i",&tipo,&quantidade);
							fflush(stdin);
							contador++;
							contador++;
							
							for(aumenta = 0; aumenta < 12)
							switch(tipo){
								
								case 1:
									totais[0]= totais[0] + quantidade;	
								break;
								
								case 2:
									totais[1]= totais[1] + quantidade;	
								break;
								
								case 3:
									totais[2]= totais[2] + quantidade;
								break;
								
								case 4:
									totais[3]= totais[3] + quantidade;
								break;
										
								case 5:
									totais[4]= totais[4] + quantidade;
								break;
								
								case 6:
									totais[5]= totais[5] + quantidade;
								break;
								
								case 7:
									totais[6]= totais[6] + quantidade;
								break;
								
								case 8:
									totais[7]= totais[7] + quantidade;
								break;
								
								case 9:
									totais[8]= totais[8] + quantidade;
								break;
								
								case 10:
									totais[9]= totais[9] + quantidade;
								break;
								
								case 11:
									totais[10]= totais[10] + quantidade;
								break;
								
								case 12:
									totais[11]= totais[11] + quantidade;
								break;
											
							}
							
							tipo = tipo - 1;
							total = total + (preco[tipo] * quantidade);
							printf("\n\tO %iº Cliente comprou mais alguma coisa?(1 para SIM  0 para NÃO)", cliente);
							scanf("%i",&pergunta4);
							
							contador++;
							contador++;
							
							if(contador >= 20)
							{
								indice=0;
								contador = 0;
								system("cls");
								margens();
							    printf("\x1B[30A");
								printf("\t\t\tCacha\n");
								contador++;
								printf("\t\tTabela de produtos e preços\n");
								contador++;
							
								for(c=0; c<=count; c++)
								{
									indice++;
									printf("\t%i- %s  Preço: R$ %.2f\n",indice,produto[c],preco[c]);
									contador++;	
								}
							}
							
						}
						system("cls");
						margens();
					    printf("\x1B[30A");
						total1 = total1 + total;
						fflush(stdin);			
						printf("\t\tO total que o %iº Cliente deve paga é R$ %.2f\n",cliente, total);
						printf("\tQuanto o Cliente pagou?");
						scanf("%f",&pago);
						fflush(stdin);
					
						troco = pago - total;
						fflush(stdin);
						
						if(pago < total){
							deve = total - pago;
							printf("\tO %iº Cliente está devendo R$ %.2f\n", cliente, deve);
							
					
						}else
						printf("\tO troco do %iº Cliente é R$ %.2f\n",cliente, troco);
					
						
						troco = 0;
						total=0;
						pergunta4=1;
						valida1 = 3;
						printf("\tOutro cliente?(1 para SIM 0 para NÃO)");
						scanf("%i", &pergunta3);
						fflush(stdin);
						if(pergunta3 != 1){
							printf("\tRetornar ao menu? (1 para SIM 0 para NÃO)");
							scanf("%i", &pergunta);
							fflush(stdin);
							if(pergunta == 1){
								pergunta = 5;
								system("cls");
							}else{
								pergunta = 4;
								system("cls");		
							}
							
						}
						if(pergunta3 == 1){
							cliente++;		
						}
						system("cls");
					}
					break;	
					case 3:
							margens();
						    printf("\x1B[30A");
							printf("\t\t\t\t\t Relátorio\n");
							printf("\tNesse dia houve %i clientes\n",cliente);
							
							for(c=0; c<=count; c++)
							{
								printf("\tForam vendidos %i %s\n",totais[c], produto[c] );	
							}
							
							printf("\tNesse dia foi faturado R$ %.2f\n", total1);
							
							printf("\tRetornar ao menu?(1 para SIM 0 para NÃO)");
							scanf("%i",&c);
							if(c == 1){
								pergunta = 5;
								system("cls");
							}else{
								pergunta = 4;
								system("cls");
							}
							
						
					break;
						
				
				
			}
			
		}while(pergunta != 4);
		
		margens();
		printf("\x1B[30A");
		printf("\t\tObrigado por usar nosso Software.\n");
		printf("\n");
		for(desenho1=0; desenho1<=12; desenho1++){
		for(desenho= 0; desenho<=23; desenho++)
		{
			if(desenho == 0){
				printf("\t\t\t\t\t");
			}
			if((desenho1 == 4 || desenho1 == 5) || (desenho1 == 10 || desenho1 == 11))
			{
				if(desenho == 0 || desenho ==2 || desenho == 4 || desenho == 6 ||desenho == 8 || desenho ==10 || desenho == 12 || desenho == 14 ||desenho == 16 || desenho == 18 ||desenho == 20 || desenho ==22){
				printf("]");	
				}
				else
				printf("[");
			}else if(desenho1 == 0 || desenho1 == 1){
			printf("*");
				
			}else if(desenho1 != -1){
				printf("|");
			}
			
		}
		printf("\n");
	}
	
		printf("\x1B[9A");
		for(desenho1=0; desenho1<=1; desenho1++)
		{
			printf("\x1B[%iC",DESENHO);
			for(desenho= 0; desenho<=14; desenho++)
			{
					if(desenho == 0 || desenho ==2 || desenho == 4 || desenho == 6 ||desenho == 8 || desenho ==10 || desenho == 12 || desenho == 14){
					printf("]");	
					}
					else
					printf("[");
				
			}
			printf("\n");
		}
		printf("\x1B[4B");
		for(desenho1=0; desenho1<=1; desenho1++)
		{
			printf("\x1B[%iC",DESENHO);
			for(desenho= 0; desenho<=14; desenho++)
			{
				if(desenho == 0 || desenho ==2 || desenho == 4 || desenho == 6 ||desenho == 8 || desenho ==10 || desenho == 12 || desenho == 14){
				printf("]");	
				}
				else
				printf("[");
				
			}
			printf("\n");
		}
		printf("\x1B[6A");
		for(desenho1 = 0; desenho1 < 4; desenho1++)
		{
			printf("\x1B[%iC",DESENHOS);
		for(desenho2 = 0; desenho2<2; desenho2++)
		{
			printf("[]");
		}
		printf("\n");	
		}
		printf("\x1B[10B");
		printf("\x1B[10C");
		printf("Sair (Digite qualquer valor)");
		scanf("%i", &c);
		system("cls");
}



