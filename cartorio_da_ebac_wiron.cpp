#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h>  // biblioteca de alocação de espaço em memória
#include <locale.h>  // biblioteca de alocações de texto por região
#include <string.h>  // biblioteca responsável por cuidas das strings  

int registro() //função responsável por cadastras os uruários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//início de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF à ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se à string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings
	
	FILE *file;  // cria o arquivo
	file = fopen(arquivo, "w");  // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);  // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //adiciona os dados ao arquivo principal (no caso utilizamos sempre o cpf para evitar duplicidade)
	fprintf(file,","); //virgula para melhor orgnização no momento de leitura
	fclose(file);
	
	printf("Digite o nome à ser cadastrado: ");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome à ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo à ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa a tela e aguarda comando
		
}

int consulta() //função responável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF à ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //caso o cpf escrito não exista na base de dados
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); //mensagem ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquando o cpf escrito existir na base de dados
	{
		printf("\nEssas são aas informações do usuário: "); //mensagem ao usuário
		printf("%s", conteudo); //o sistema irá mostrar os dados solicitados
		printf("\n\n"); //para melhor organização e estética
	}
	
	system("pause"); //pausa a tela e aguarda comando

}

int deletar() //função responsável por deletar os usuários no sistema
{
	char cpf[40]; //nesse caso iremos utilizar apenas a variável/string cpf, pois é nosso dado referência, cada usuário terá um cpf diferente
	
	printf("Digite o CPF do usuário à ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //função de remoção de dados
	
	FILE *file;
	file = fopen(cpf,"r"); //solicitação ao sistema para buscar os dados
	
	if(file == NULL) //caso não existe no sistema
	{
		printf("O usuário não se encontra no sistema!. \n"); //mensagem ao usuário
		system("pause"); //pausa o sistema e aguarda comando
	}
	
}


int main() //função/tela principal, o sistema sempre retornará à ela
{
	int opcao=0; // definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) // Definindo laço
	{
		
		system("cls");
	
         setlocale(LC_ALL, "Portuguese"); // definindo a linguagem

     	printf("### Cartório da EBAC ###\n\n"); // Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    printf("\t4 - Sair do sistema\n\n");
    	printf("Opção:"); // FIm do menu
    
	  
    	scanf("%d", &opcao); // Armazenando a escolha do usuário
	
    
    	system("cls"); //resposável por limpar a tela
    	
    	switch(opcao) // Início da seleção do menu
    	{
    		case 1:
    		registro(); //chamada de função
		    break;
		    
		    case 2:
		    consulta(); //chamada de função
 	        break;
 	        
 	        case 3:
 	        deletar(); //chamada de função
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
		    return 0;
		    break;
		    
		    default:
		    printf("Essa opção não está disponível!\n"); //mensagem ao usuário
		    system("pause"); //pausa a tela a aguarda comando 
		    break;
		    
		
		} // Fim da seleção
	
	    
    
    	}


     

}




