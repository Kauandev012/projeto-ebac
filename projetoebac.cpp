#include <stdio.h> //biblioteca de comunic�o com o usuario
#include <stdlib.h> //bibliopteca de alocaca� de espaco em memoria 
#include<locale.h> //biblioteca de aloca��es de texto por regi�o
#include<string.h> //biblioteca responsavel pelas strings


int registro()//come�o da fun��o resgrito!
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	//come�o da variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da variavel
	
	printf("digite o cpf para cadastro: ");
	scanf("%s", cpf); 
	
	strcpy(arquivo, cpf);
	
	FILE * file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,"\n cpf : ");
	fprintf(file,cpf);
	fclose(file);//fecha o arquivo
	
	printf("digite o nome para cadastro: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n nome:");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("digite o sobrenome para cadastro: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n sobrenome:");
	fclose(file);
	
	file = fopen(arquivo, "a");	
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n cargo:");
	fclose(file);
	
	printf("digite o cargo para cadastro: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	//final da  fun��o!
}

int consulta()//come�o da fun��o consulta!
{
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf para consulta: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{	
	printf("arquivo n�o locaizado!.\n");
	}
	
	printf("\n");
	printf("\nEsses s�o as informa��es do usuario: ");
	
	while(fgets(conteudo,200,file)!= NULL)
	{
	printf("%s",conteudo);
	printf("\n");
	}
	
	system("pause");
	
	//final da fun��o consulta!//
	
}

int deletar()//funcao para deletar cpf do banco de dados
{
	char cpf[40];
	
	printf("Digite o CPF para deletar o usuario:");//pergunta o cpf pro usario deletar
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE * file;
	file= fopen(cpf,"r");
	fclose(file);

	
	if(file == NULL)//caso nao ache o cpf no sistema
	{
		printf("O usuario n�o se encontra no sistema! /n");//avisa que nao achou o osuario no sistema
		system("pause");
	}
	
	else
	{
    remove(cpf);
    printf("usuario deletado com sucesso!./n");
	}
	system("pause"); 
	
	}
	 
    

int main()
{
	int opcao=0;//definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
{

    system("cls");

	setlocale(LC_ALL, "portuguese");//definindo linguagem
	
	printf("### cart�rio da EBAC ### \n\n");// inicio menu	
	printf("escolha a op��o desejada do menu:\n\n");
	printf("\t1- registrar usuarios\n");
	printf("\t2- consultar usuaros\n");
	printf("\t3- deletar usuarios\n\n");
	printf("\t4-fechar sistema!\n\n");
	printf("op��o:");//final do menu

    scanf("%d", &opcao);//armazena escolha do usuario

    system("cls");
    
    
    switch(opcao)
    {
    	case 1:
        registro();
        break;
	
	    case 2:
		consulta();
	    break;

        case 3:
	    deletar();
	    break;
	    
	    case 4:
		printf("fechando o sitema obrigado por usar!\n");
		return 0;
		break;
			
	    default:
	   	printf("essa op��o n�o esta disponivel!\n");
        system("pause");
        break;
	
	}
    
  
 }
}
