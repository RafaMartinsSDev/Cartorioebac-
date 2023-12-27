#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int regitro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informações do usuário
	scanf("%s", cpf); //%srefere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copia os valores das string
	
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
		printf("não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	printf("\nEssas são as informações do usuário: \n\n");
	
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
	
	printf("Digite o CPF do usuário a ser deletado!.\n");
	printf("\t");
	scanf("%s", cpf);
	
	{
	remove(cpf); //deletar
	printf("O usuário foi deletado!.\n\n");
	system("pause");
	}
	
	FILE *file; //acessar função, encontrar arquivo
	file = fopen(cpf,"r"); //abrir a pasta e abrir o arquivo, "ler"
	
	if(file == NULL);
	{
		printf("O usuário não encontrado no sistema!.\n\n");
		system("pause");
	}
}


int main()
	{
	int opcao=0; //definição variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Denindo a linguagem
	
		printf("\t### Cartório da EBAC ###\n\n"); //Inicío do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); // Fim do menu
	
		scanf("%d", &	opcao); //Armezenamento a escolha do usuário
	
		system ("cls"); //Respnsavel por limpar a tela
		
		
		switch(opcao) // Início da seleção do menu
		{
			case 1:
			regitro(); //Chama de funções
			break;

			case 2:
			consulta(); //Chama de funções
			break;
 
			case 3:
			deletar(); //Chama de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	

			default:
			printf("Essa opão não está disponível!\n"); 
			system("pause");
			break;	
		} //Fim da seleção
	}
}
