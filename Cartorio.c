#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar usu�rios
{
	//Inicio da cria��o de vari�veis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis / string
	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s" , cpf); //refere-se as string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); //Abrir o arquivo | "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file, " | "); //Salvo o valor da variavel
	fclose(file); //fechar o arquivo
	
	printf("Digite o Nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s" ,nome); //refere-se as string
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file,nome); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file, " "); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s" ,sobrenome); //refere-se as string
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file,sobrenome); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file, " | "); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s" ,cargo); //refere-se as string
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file,cargo); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //Pause o sistema
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio da cria��o de vari�veis / string
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de vari�veis / string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s" ,cpf); //refere-se as string
	
	FILE *file; //Programa abrir o "file" (arquivo)
	file = fopen(cpf, "r"); //abrir o arquivo "cpf" | "r" Significa ler o arquivo
	
	if(file == NULL) //se o arquivo for diferente (n�o localizado)
	{
		printf("CPF n�o localizado! \n"); //informa��o para usu�rio
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s" ,conteudo);
		printf("\n\n");
		
	}
       system("pause"); //Pause o sistema
}

int deletar()
{
	//Inicio da cria��o de vari�veis / string
	char cpf[40];
	//Final da cria��o de vari�veis / string
	
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //refere-se as string
   	
	printf("\n Usu�rio localizado, deseja deletar? \n\n"); //Informar o usu�rio
	system("pause"); //Pause o sistema
		
	system("cls"); //Limpar tela
		
	remove(cpf); //Remover arquivo "cpf"
	
	FILE *file; //Criar o arquivo
	file = fopen(cpf, "r"); //Abrir o arquivo | "r" significa
	
	if(file == NULL) //Arquivo inexistente | N�o encontrado
	{
		printf("\n O usu�rio deletado! \n\n"); //Informar o usu�rio
		system("pause"); //Pause o sistema
	}
		
}


int main()
{
	int opcao=0; //Definindo Vari�veis
	int laco=1; //dafinindo valor
	
	for(laco=1;laco=1;) //definindo valor inicial e final
	{
	
        system("cls"); //Limpar tela
        
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("\t### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu: \n\n");
    	printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");;
	    printf("\t3 - Deletar nomes\n\n\n");
	    printf("Op��o: "); //Fim do menu 
        
		printf("\n\n\n Esse Software esta sendo desenvolvido por Paulo Novais.");	
	    
		
		scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
	
        system("cls");
        
        switch(opcao)//Inicio da sele��o
        {
        	
        	case 1:
        	registro(); //Chamada de fun��o
	    	break;
	    	
	    	case 2:
	    	consulta(); //Chamada de fun��o
            break;
            
            case 3:
            deletar(); //Chamada de fun��o
        	break;
        	
        	default:
        	printf("Essa op��o n�o est� disponivel!\n");
        	system("pause");
        	break;
		}//fim da sele��o
	

}
}
