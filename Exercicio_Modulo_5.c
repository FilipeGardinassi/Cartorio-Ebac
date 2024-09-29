#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //Biblioteca de aloca��o de textos por regi�o
#include <string.h> //Biblioteca respons�vel pelas strings

int registro()
{
	setlocale(LC_ALL, "Portuguese");

	char arquivo[40]; //In�cio da cria��o de vari�veis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //Final da cria��o de vari�veis/string
		
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s refere-se � string
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); //Cria o arquivo e escreve na mem�ria
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a"); //Comando que atualiza o arquivo gravado na mem�ria
	fprintf(file,", "); //Separa os dados com uma v�rgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);

	file = fopen(arquivo,"a");
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome); 
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file = fopen(arquivo,"a");
	fprintf(file,cargo); 
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,". "); //Inseri um ponto final no final das 4 informa��es para ficar melhor
	fclose(file);
		
	system("pause");
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese");

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Comando que fala para o computador ler o arquivo armazenado
	
	if (file == NULL)
	{
		printf("CPF n�o encontrado. N�o foi poss�vel abrir o arquivo\n");
	}
	
	while (fgets(conteudo,200,file) != NULL) //fgets � o comando que busca a informa��o no arquivo, enquanto ele for diferente de nulo
	{
		printf("Estas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //Comando que exclui o arquivo no banco de dados
	
	FILE *file; 
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}

	printf("Voc� escolheu deletar o CPF cadastrado: ");
	system ("pause");
}

int main()
{
	int opcao=0; //Define as vari�vies
	int x=1;
	
	for (x=1;x=1;)
	{
		system ("cls"); //Respons�vel por limpar a tela
		setlocale(LC_ALL, "Portuguese");
		printf("\n\tCart�rio da EBAC\n\n");
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1. Registrar nomes\n");
		printf("\t2. Consultar nomes\n");
		printf("\t3. Excluir nomes\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //Armazena a escolha do usu�rio
	
		system("cls"); //Limpa a tela de sa�da do programa
	
	switch(opcao) //In�cio da sele��o do menu
	{
		case 1:
		registro(); //Chamada de fun��es
		break;
			
		case 2:
		consulta(); //Chamada de fun��es
		break;
		
		case 3:
		deletar(); //Chamada de fun��es
		break;
			
		default:
			printf("Esta op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		}
	}
}


