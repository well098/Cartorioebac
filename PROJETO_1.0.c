#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocaçao de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() // função responsavel por cadastrar os usuarios no sistema
{
	// inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:  "); // coletando informações do usuario
	scanf("%s", cpf); //% refere-se a string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
    	
	FILE *file; // criar arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "w" significa escrever
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" significa atualizar
	fprintf(file,","); // "," significa pros dados coletados não sair tudo junto "wellington134TI"
	fclose(file); // fechar arquivo
	
    printf("Digite o nome a ser cadastrado:  "); // coletando informação do usuario
	scanf("%s",nome); //% refere-se a string
	
	
	file = fopen(arquivo, "a"); // atualizando arquivo
	fprintf(file,nome);// salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	
	file = fopen(arquivo, "a"); // atualizando arquivo novamente 
	fprintf(file,","); // salvando o valor da variavel novamente 
	fclose(file); // fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado:  "); // coletando informação do usuario
	scanf("%s",sobrenome); //% refere-se a string
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // pausar na opçao escolhida 
	
	
}

int consulta ()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" significa que vai ler o arquivo
	
	if(file == NULL) // " == " significa igual 
	{
	   printf("Não foi possivel abrir o arquivo,não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200,file)!= NULL) 
	{
		printf("\nEssas são as informações do usuário:  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausar na opçao escolhida 
}

int deletar()
{ 
    char cpf[40];
    
    printf("Digite o CPF a ser deletado:  ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); // "r" signifca que vai ler o arquivo em vez de criar ("w") ou atualizar ("a")
    
    if(file == NULL)
	{
	  
	  printf("O usuário não se encontra no sistema!.\n");
	  system("pause");
    	
	}
    


	
}

int main()
    {
    int opcao=0; // definindo variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	 
	  system("cls");
	  
      setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
    
    
      printf("### Cartório da EBAC ###\n\n"); //inicio do menu
      printf("Escolha a opçao desejada do menu\n\n");
      printf("\t1 - Registrar nomes\n");
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n\n");
      printf("\t4 - Sair do sistema\n\n");
      printf("Opção: "); // fim do menu
    
      scanf("%d", &opcao); // armazenamendo a escolha do usuario
	
	  system("cls"); // responsavel por limpar a tela
	   
      switch(opcao)
      {
      	  case 1:
      	  registro(); // chamadas de funções 
	      break;
      	  
      	  case 2:
      	  consulta();
      	  break;
      	  
      	  case 3:
      	  deletar();	
      	  break;
      	  
      	  case 4:
      	  printf("Obrigado por utilizar o sistema\n");
      	  return 0;
      	  break;
      	  
      	  default:
      	  printf("Essa opção não esta disponivel!\n");	
	      system("pause");
	      break;
	  }
	  


	
    }
}
