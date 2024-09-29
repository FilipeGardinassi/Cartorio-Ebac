#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaços em memória
#include <locale.h> //Biblioteca de alocação de textos por região
#include <string.h> //Biblioteca responsável pelas strings

int registro()
{
	setlocale(LC_ALL, "Portuguese");

	char arquivo[40]; //Início da criação de variáveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //Final da criação de variáveis/string
		
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s refere-se à string
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); //Cria o arquivo e escreve na memória
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo,"a"); //Comando que atualiza o arquivo gravado na memória
	fprintf(file,", "); //Separa os dados com uma vírgula
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
	fprintf(file,". "); //Inseri um ponto final no final das 4 informações para ficar melhor
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
		printf("CPF não encontrado. Não foi possível abrir o arquivo\n");
	}
	
	while (fgets(conteudo,200,file) != NULL) //fgets é o comando que busca a informação no arquivo, enquanto ele for diferente de nulo
	{
		printf("Estas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	}

	printf("Você escolheu deletar o CPF cadastrado: ");
	system ("pause");
}

int main()
{
	int opcao=0; //Define as variávies
	int x=1;
	
	for (x=1;x=1;)
	{
		system ("cls"); //Responsável por limpar a tela
		setlocale(LC_ALL, "Portuguese");
		printf("\n\tCartório da EBAC\n\n");
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1. Registrar nomes\n");
		printf("\t2. Consultar nomes\n");
		printf("\t3. Excluir nomes\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); //Armazena a escolha do usuário
	
		system("cls"); //Limpa a tela de saída do programa
	
	switch(opcao) //Início da seleção do menu
	{
		case 1:
		registro(); //Chamada de funções
		break;
			
		case 2:
		consulta(); //Chamada de funções
		break;
		
		case 3:
		deletar(); //Chamada de funções
		break;
			
		default:
			printf("Esta opção não está disponível\n");
			system("pause");
			break;
		}
	}
}


