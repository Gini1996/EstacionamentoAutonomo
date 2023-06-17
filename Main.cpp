#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#define BaseCripto 10;

using namespace std;

//Função para ler o arquivo gerado
void LerArquivo(char CaracterArq[])
{
	FILE* ArquivoUsuario;

	ArquivoUsuario = fopen("Base.txt", "r");

	//Condição para verificar erro no arquivo
	if (ArquivoUsuario == NULL)
	{
		cout << "Nao foi possivel abrir o arquivo" << endl;
	}

	//Armazena o arquivo na variavel
	for (int i = 0; !feof(ArquivoUsuario); i++)
	{
		CaracterArq[i] = fgetc(ArquivoUsuario);
	}

	//Exibe o texto no terminal
	cout << "\n" << CaracterArq << "\n" << endl;

	fclose(ArquivoUsuario);

}

//Função de criptografia
void Criptografar(char CaracterArq[], char ArqCripto[], bool* ControleCripto)
{
	//Condição para verificar se o arquivo já esta criptografado
	if (*ControleCripto == true)
	{
		//Captura tamanho
		int TamanhoCripto = strlen(CaracterArq);

		//Criptografa
		for (int i = 0; i < TamanhoCripto; i++)
		{
			ArqCripto[i] = CaracterArq[i] + BaseCripto;
		}

		//Escreve no arquivo
		FILE* ArquivoUsuario;
		ArquivoUsuario = fopen("Base.txt", "w");
		fprintf(ArquivoUsuario, "%s", ArqCripto);
		fclose(ArquivoUsuario);

		//Retorna a criptografia na tela, mensagem de conclusao e altera a variavel de controle
		cout << "Arquivo Criptografado" << endl;
		cout << "\n" << ArqCripto << "\n" << endl;
		*ControleCripto = false;
	}
	else
	{
		cout << "Este arquivo ja se encontra criptografado" << endl;
	}

}

//Funcao para descriptografar
void Descriptografar(char ArqCripto[], char ArqDescripto[], bool* ControleCripto)
{
	//Condição para verificar se o arquivo já esta descriptografado
	if (*ControleCripto == false)
	{
		//Captura tamanho
		int TamanhoDescripto = strlen(ArqCripto);

		//Descriptografa
		for (int i = 0; i < TamanhoDescripto - 1; i++)
		{
			ArqDescripto[i] = ArqCripto[i] - BaseCripto;
		}

		//Escreve no arquivo
		FILE* ArquivoUsuario;
		ArquivoUsuario = fopen("Base.txt", "w");
		fprintf(ArquivoUsuario, "%s", ArqDescripto);
		fclose(ArquivoUsuario);

		//Retorna a descriptografia na tela e mensagem de conclusao
		cout << "Arquivo Descriptografado" << endl;
		cout << "\n" << ArqDescripto << "\n" << endl;

		*ControleCripto = true;
	}
	else
	{
		cout << "Este arquivo ja se encontra descriptografado" << endl;
	}

}

int main()
{
	bool Controle = true;
	bool ControleCripto = true;
	int Decisao;
	char CaracterArq[250];
	char ArqCripto[250];
	char ArqDescripto[250];
	FILE* ArquivoInit;

	//Cria o arquivo
	ArquivoInit = fopen("Base.txt", "w");
	fprintf(ArquivoInit, "Arquivo de teste para a segunda avaliacao da disciplina: Linguagem de Programacao\nAluno: Leonardo Gini");
	fclose(ArquivoInit);

	//Faz a leitura do arquivo criado
	LerArquivo(CaracterArq);

	//Menu
	cout << "Criptografia" << endl;
	cout << "Opcoes: " << endl;
	cout << "1 - Ler Arquivo Texto " << endl;
	cout << "2 - Criptografar" << endl;
	cout << "3 - Descriptografar" << endl;
	cout << "9 - Sair" << endl;
	cin >> Decisao;

	//Estrutura de controle para somente parar com ordem do usuario
	while (Controle == true)
	{
		if (Decisao == 1)
		{
			//Executa a funcao de leitura e retorna mensagem para escolha do usuario
			LerArquivo(CaracterArq);
			cout << "Concluido, escolha uma opcao no menu " << endl;
			cin >> Decisao;
		}
		else if (Decisao == 2)
		{
			//Executa a funcao de criptografia e retorna mensagem para escolha do usuario
			Criptografar(CaracterArq, ArqCripto, &ControleCripto);
			cout << "Concluido, escolha uma opcao no menu " << endl;
			cin >> Decisao;
		}
		else if (Decisao == 3)
		{
			//Executa a funcao de descriptografia e retorna mensagem para escolha do usuario
			Descriptografar(ArqCripto, ArqDescripto, &ControleCripto);
			cout << "Concluido, escolha uma opcao no menu " << endl;
			cin >> Decisao;
		}
		else if (Decisao == 9)
		{
			//Encerra o programa
			Controle = false;
		}
		else
		{
			//Repetição ate o usuario digitar uma condição valida
			cout << "Comando invalido" << endl;
			cout << "Digite novamente a opcao" << endl;
			cin >> Decisao;
		}
	}

	system("pause");
	return 0;
}
