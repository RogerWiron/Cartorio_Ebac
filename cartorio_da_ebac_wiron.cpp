#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  // biblioteca de aloca��es de texto por regi�o
#include <string.h>  // biblioteca respons�vel por cuidas das strings  

int registro() //fun��o respons�vel por cadastras os uru�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//in�cio de cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF � ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se � string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file;  // cria o arquivo
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);  // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //adiciona os dados ao arquivo principal (no caso utilizamos sempre o cpf para evitar duplicidade)
	fprintf(file,","); //virgula para melhor orgniza��o no momento de leitura
	fclose(file);
	
	printf("Digite o nome � ser cadastrado: ");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome � ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo � ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa a tela e aguarda comando
		
}

int consulta() //fun��o respon�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF � ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //caso o cpf escrito n�o exista na base de dados
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); //mensagem ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquando o cpf escrito existir na base de dados
	{
		printf("\nEssas s�o aas informa��es do usu�rio: "); //mensagem ao usu�rio
		printf("%s", conteudo); //o sistema ir� mostrar os dados solicitados
		printf("\n\n"); //para melhor organiza��o e est�tica
	}
	
	system("pause"); //pausa a tela e aguarda comando

}

int deletar() //fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40]; //nesse caso iremos utilizar apenas a vari�vel/string cpf, pois � nosso dado refer�ncia, cada usu�rio ter� um cpf diferente
	
	printf("Digite o CPF do usu�rio � ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //fun��o de remo��o de dados
	
	FILE *file;
	file = fopen(cpf,"r"); //solicita��o ao sistema para buscar os dados
	
	if(file == NULL) //caso n�o existe no sistema
	{
		printf("O usu�rio n�o se encontra no sistema!. \n"); //mensagem ao usu�rio
		system("pause"); //pausa o sistema e aguarda comando
	}
	
}


int main() //fun��o/tela principal, o sistema sempre retornar� � ela
{
	int opcao=0; // definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) // Definindo la�o
	{
		
		system("cls");
	
         setlocale(LC_ALL, "Portuguese"); // definindo a linguagem

     	printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    printf("\t4 - Sair do sistema\n\n");
    	printf("Op��o:"); // FIm do menu
    
	  
    	scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
    
    	system("cls"); //respos�vel por limpar a tela
    	
    	switch(opcao) // In�cio da sele��o do menu
    	{
    		case 1:
    		registro(); //chamada de fun��o
		    break;
		    
		    case 2:
		    consulta(); //chamada de fun��o
 	        break;
 	        
 	        case 3:
 	        deletar(); //chamada de fun��o
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
		    return 0;
		    break;
		    
		    default:
		    printf("Essa op��o n�o est� dispon�vel!\n"); //mensagem ao usu�rio
		    system("pause"); //pausa a tela a aguarda comando 
		    break;
		    
		
		} // Fim da sele��o
	
	    
    
    	}


     

}




