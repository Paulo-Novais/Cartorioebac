#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar usuários
{
	//Inicio da criação de variáveis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis / string
	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s" , cpf); //refere-se as string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); //Abrir o arquivo | "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file, " | "); //Salvo o valor da variavel
	fclose(file); //fechar o arquivo
	
	printf("Digite o Nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s" ,nome); //refere-se as string
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file,nome); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file, " "); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s" ,sobrenome); //refere-se as string
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file,sobrenome); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file, " | "); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo a ser cadastrado: "); //coletando informações do usuário
	scanf("%s" ,cargo); //refere-se as string
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo | "a" significa modificar
	fprintf(file,cargo); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //Pause o sistema
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio da criação de variáveis / string
	char cpf[40];
	char conteudo[200];
	//Final da criação de variáveis / string
	
	printf("Digite o CPF a ser consultado: "); //coletando informações do usuário
	scanf("%s" ,cpf); //refere-se as string
	
	FILE *file; //Programa abrir o "file" (arquivo)
	file = fopen(cpf, "r"); //abrir o arquivo "cpf" | "r" Significa ler o arquivo
	
	if(file == NULL) //se o arquivo for diferente (não localizado)
	{
		printf("CPF não localizado! \n"); //informação para usuário
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s" ,conteudo);
		printf("\n\n");
		
	}
       system("pause"); //Pause o sistema
}

int deletar()
{
	//Inicio da criação de variáveis / string
	char cpf[40];
	//Final da criação de variáveis / string
	
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informações do usuário
	scanf("%s", cpf); //refere-se as string
   	
	printf("\n Usuário localizado, deseja deletar? \n\n"); //Informar o usuário
	system("pause"); //Pause o sistema
		
	system("cls"); //Limpar tela
		
	remove(cpf); //Remover arquivo "cpf"
	
	FILE *file; //Criar o arquivo
	file = fopen(cpf, "r"); //Abrir o arquivo | "r" significa
	
	if(file == NULL) //Arquivo inexistente | Não encontrado
	{
		printf("\n O usuário deletado! \n\n"); //Informar o usuário
		system("pause"); //Pause o sistema
	}
		
}


int main()
{
	int opcao=0; //Definindo Variáveis
	int laco=1; //dafinindo valor
	
	for(laco=1;laco=1;) //definindo valor inicial e final
	{
	
        system("cls"); //Limpar tela
        
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("\t### Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu: \n\n");
    	printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");;
	    printf("\t3 - Deletar nomes\n\n\n");
	    printf("Opção: "); //Fim do menu 
        
		printf("\n\n\n Esse Software esta sendo desenvolvido por Paulo Novais.");	
	    
		
		scanf("%d" , &opcao); //Armazenando a escolha do usuário
	
        system("cls");
        
        switch(opcao)//Inicio da seleção
        {
        	
        	case 1:
        	registro(); //Chamada de função
	    	break;
	    	
	    	case 2:
	    	consulta(); //Chamada de função
            break;
            
            case 3:
            deletar(); //Chamada de função
        	break;
        	
        	default:
        	printf("Essa opção não está disponivel!\n");
        	system("pause");
        	break;
		}//fim da seleção
	

}
}
