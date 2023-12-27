#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int regitro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%srefere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copia os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever	
	fprintf(file,"CPF: "); //nomeando a variavel
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", \nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", \nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", \nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file,".\n\n");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Denindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n");
	printf("\t");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("n�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\t");
		printf("%s", conteudo);
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado!.\n");
	printf("\t");
	scanf("%s", cpf);
	
	{
	remove(cpf); //deletar
	printf("O usu�rio foi deletado!.\n\n");
	system("pause");
	}
	
	FILE *file; //acessar fun��o, encontrar arquivo
	file = fopen(cpf,"r"); //abrir a pasta e abrir o arquivo, "ler"
	
	if(file == NULL);
	{
		printf("O usu�rio n�o encontrado no sistema!.\n\n");
		system("pause");
	}
}


int main()
	{
	int opcao=0; //defini��o vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Denindo a linguagem
	
		printf("\t### Cart�rio da EBAC ###\n\n"); //Inic�o do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); // Fim do menu
	
		scanf("%d", &	opcao); //Armezenamento a escolha do usu�rio
	
		system ("cls"); //Respnsavel por limpar a tela
		
		
		switch(opcao) // In�cio da sele��o do menu
		{
			case 1:
			regitro(); //Chama de fun��es
			break;

			case 2:
			consulta(); //Chama de fun��es
			break;
 
			case 3:
			deletar(); //Chama de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	

			default:
			printf("Essa op�o n�o est� dispon�vel!\n"); 
			system("pause");
			break;	
		} //Fim da sele��o
	}
}
