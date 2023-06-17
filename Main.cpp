//Desenvolvido por
//Leonardo Gini Ferreira 

#include <iostream>

using namespace std;

//Funcao para mapear o terreno, dividindo as vagas em Carros, Camionetes e Esportivo
void MapearTerreno(string * TipoVeiculo, string * Disponibilidade)
{
	//La�o de divis�o das vagas
	//120
	for (int i = 0; i < 120; i++)
	{
		//Andar 1
		//if (i <= 19)
		if (i <= 19)
		{
			TipoVeiculo[i] = "Carro";
		}
		//i > 19 && i <= 49
		else if (i > 19 && i <= 49)
		{
			TipoVeiculo[i] = "Camionete";
		}
		//Andar 2
		//i > 49 && i <= 74
		else if (i > 49 && i <= 74)
		{
			TipoVeiculo[i] = "Carro";
		}
		//Andar 3
		//i > 74 && i <= 84
		else if (i > 74 && i <= 84)
		{
			TipoVeiculo[i] = "Camionete";
		}
		//Andar 4
		//i > 84 && i <= 99
		else if (i > 84 && i <= 99)
		{
			TipoVeiculo[i] = "Esportivo";
		}
		//Andar 5
		//i > 99 && i <= 119
		else if (i > 99 && i <= 119)
		{
			TipoVeiculo[i] = "Camionete";
		}
	}

	//La�o para inicializar as vagas como dispon�veis
	//120
	for (int j = 0; j < 120; j++)
	{
		Disponibilidade[j] = "Disponivel";
	}

}

//Funcao para verificar se h� vagas no estacionamento e coletar dados do usuario, incrementando algumas variaveis para o administrativo
void ChecarVaga(int & Codigo, int* DiaEntrada, int* MesEntrada, int* AnoEntrada, int* HoraEntrada, int* MinutoEntrada, int & AtendidosCarros,int & AtendidosCamionetes,int & NaoAtendidos,string & Modelo, string *TipoVeiculo,string *Disponibilidade)
{
	//Variavel para interromper a busca ap�s localizar uma vaga
	int Controle = 0;

	//La�o para verificar a vaga
	for (int i = 0; i < 120; i++)
	{
		//Caso o modelo de veiculo n�o seja atendido pelo estacionamento
		if (Modelo != "Carro" && Modelo != "Esportivo" && Modelo != "Camionete")
		{
			cout << "Nao temos vagas para este modelo" << endl;
			Codigo = 9999;
			break;
		}
		//Caso seja um dos modelos que o estacionamento comporte
		else if (Modelo == TipoVeiculo[i])
		{
			//Se a variavel for igual a zero entra para verificar 
			if (Controle == 0)
			{
				//Caso tenha vaga disponivel para aquele modelo entra no if, informa a vaga e a ocupa
				if (Disponibilidade[i] == "Disponivel")
				{
					//Demonstra a vaga em que o veiculo foi alocado
					cout << "Vaga " << i << " Disponivel" << endl;

					//Informa o codigo gerado para utilizar na saida
					cout << "Seu codigo e " << i << endl;
					Codigo = i;
					
					//Coleta os dados de entrada
					cout << "Digite o dia de entrada" << endl;
					cin >> DiaEntrada[i];

					cout << "Digite o mes de entrada" << endl;
					cin >> MesEntrada[i];

					cout << "Digite o ano de entrada" << endl;
					cin >> AnoEntrada[i];

					cout << "Digite a hora de entrada" << endl;
					cin >> HoraEntrada[i];

					cout << "Digite os minutos de entrada" << endl;
					cin >> MinutoEntrada[i];

					//Altera o status da vaga para Ocupado
					Disponibilidade[i] = "Ocupado";

					//Decisoes utilizadas para ter um controle de quantos veiculos foram atendidos
					if (Modelo == "Carro")
					{
						AtendidosCarros++;
					}
					else if (Modelo == "Esportivo")
					{
						AtendidosCarros++;
					}
					else if (Modelo == "Camionete")
					{
						AtendidosCamionetes++;
					}

					//Incrementa a variavel controle e interrompe a funcao ap�s ter o carro alocado
					Controle++;
					break;
				}
				//Condi��es para definir se ainda existem vagas para aquele modelo, definindo o i como maior ou igual a ultima vaga
				//Incrementa a variavel nao atendida para ter um controle dos que chegaram ao estacionamento mas nao conseguiram estacionar
				else if (i >= 74 && Modelo == "Carro")
				{
					cout << "Nao ha vagas para carro no momento" << endl;
					NaoAtendidos++;
				}
				else if (i >= 99 && Modelo == "Esportivo")
				{
					cout << "Nao ha vagas para esportivos no momento" << endl;
					NaoAtendidos++;
				}
				else if (i >= 119 && Modelo == "Camionete")
				{
					cout << "Nao ha vagas para camionete no momento" << endl;
					NaoAtendidos++;
				}
			}
		}
	}
}

//Menu para escolha do usuario
void Menu(int & operacao)
{
	//Controle de repeticao do menu
	bool Decisao = true;

	//Decisao para execucao do menu
	while (Decisao == true)
	{
		cout << "\nEstacionamento" << endl;
		cout << "Carro: R$ 5,00 hora" << endl;
		cout << "Camionete: R$ 7,00 hora\n" << endl;
		cout << "Qual operacao ira realizar?" << endl;
		cout << "1 - Entrada" << endl;
		cout << "2 - Saida" << endl;
		cin >> operacao;
		cout << "\n" << endl;

		//Condicao para retornar ao inicio do menu caso seja digitado opcao invalida
		if (operacao != 1 && operacao != 2 && operacao != 666)
		{
			cout << "Operacao invalida, digite a operacao correta" << endl;
		}

		//Caso seja uma operacao valida, troca a decisao para falso para seguir com o procedimento
		if (operacao == 1 || operacao == 2 || operacao == 666)
		{
			Decisao = false;
		}
	}
}

//Demonstra as op��es de modelo que temos vaga e executa a funcao ChecarVaga
int EscolhaEntrada(int& Codigo, int operacao, int* DiaEntrada, int* MesEntrada, int* AnoEntrada, int* HoraEntrada, int* MinutoEntrada, int& AtendidosCarros, int& AtendidosCamionetes, int& NaoAtendidos, string Modelo, string* TipoVeiculo, string* Disponibilidade)
{
	//Condicao para executar a entrada
	if (operacao == 1)
	{
		cout << "Vagas disponiveis para: " << endl;
		cout << "Carro" << endl;
		cout << "Camionete" << endl;
		cout << "Esportivo" << endl;
		cout << "Digite o Modelo do veiculo" << endl;
		cin >> Modelo;

		//Checa vaga e coleta dados do usuario
		ChecarVaga(Codigo, DiaEntrada, MesEntrada, AnoEntrada, HoraEntrada, MinutoEntrada,AtendidosCarros,AtendidosCamionetes, NaoAtendidos, Modelo, TipoVeiculo, Disponibilidade);
	}
	return operacao;

}

//Coleta o codigo, informacoes de data e hora de saida, compara entrada e saida e realiza o calculo do valor
int EscolhaSaida(int operacao, int Codigo, int* DiaEntrada, int* MesEntrada, int* HoraEntrada, int* MinutoEntrada, int* DiaSaida, int* MesSaida, int* AnoSaida, int* HoraSaida, int* MinutoSaida, double & FaturamentoMedio, double & FaturamentoTotal,string* Disponibilidade)
{
	//Variaveis com valores por hora para calculo
	double ValorCarro = 5;
	double ValorCamionete = 7;
	//Variavel para comparar o codigo digitado e buscar as informacoes do codigo no vetor
	int ComparaCodigo;
	//Variaveis utilizadas para calculos
	int AuxiliarMinuto = 0;
	int AuxiliarHora = 0;
	int BaseCalculoHora;
	int BaseCalculoMinuto;
	int HorasAcumuladas = 0;
	int MinutosAcumulados = 0;
	//Variaveis para controle financeiro
	double Media;
	double ValorAPagar = 0;
	double ValorPago;
	double ValorAdicional;
	double Troco;

	//Decisao de saida
	if (operacao == 2)
	{
		cout << "Digite seu codigo" << endl;
		cin >> ComparaCodigo;

		//Inicia o vetor
		for(int i = 0; i < 120; i++)
		{
			//Caso o codigo digitado e o valor de i sejam iguais ira coletar dados de saida
			if (ComparaCodigo == i)
			{
				cout << "Digite o dia de saida" << endl;
				cin >> DiaSaida[i];

				cout << "Digite o mes de saida" << endl;
				cin >> MesSaida[i];

				cout << "Digite o ano de saida" << endl;
				cin >> AnoSaida[i];

				cout << "Digite a hora de saida" << endl;
				cin >> HoraSaida[i];

				cout << "Digite os minutos de saida" << endl;
				cin >> MinutoSaida[i];

				//Se o valor de i entrar dentro dos intervalos � realizado o calculo com valor da camionete
				if (i > 19 && i <= 49 || i > 74 && i <= 84 || i > 99 && i <= 119)
				{
					//Calculos de valores a pagar
					if (MinutoSaida[i] > MinutoEntrada[i] && HoraSaida[i]>HoraEntrada[i])
					{
						AuxiliarMinuto = MinutoSaida[i];
						AuxiliarMinuto += 60;
						AuxiliarHora--;

						BaseCalculoHora = AuxiliarHora - HoraEntrada[i];
						BaseCalculoMinuto = AuxiliarMinuto - MinutoEntrada[i];

						HorasAcumuladas += BaseCalculoHora;
						MinutosAcumulados += BaseCalculoMinuto;

						ValorAPagar += BaseCalculoHora * ValorCamionete;
					}
					else 
					{
						BaseCalculoHora = HoraSaida[i] - HoraEntrada[i];
						BaseCalculoMinuto = MinutoSaida[i] - MinutoEntrada[i];

						HorasAcumuladas += BaseCalculoHora;
						MinutosAcumulados += BaseCalculoMinuto;
						ValorAPagar += BaseCalculoHora * ValorCamionete;
					}
					
					//Calculo a pagar caso ocupe a vaga por mais de 30 minutos
					if (BaseCalculoMinuto > 30)
					{
						ValorAPagar += ValorCamionete/2;
					}

					//Gera o valor total faturado
					FaturamentoTotal = FaturamentoTotal + ValorAPagar;


					//Gera a media faturada
					MinutosAcumulados = MinutosAcumulados / 60;
					if (MinutosAcumulados > 1)
					{
						Media = FaturamentoTotal / (HorasAcumuladas + MinutosAcumulados);
					}
					else
						Media = FaturamentoTotal / HorasAcumuladas;

					FaturamentoMedio += Media;

					cout << "O valor a pagar e de R$: " << ValorAPagar << endl;
					cout << "Insira o valor de pagamento" << endl;
					cin >> ValorPago;

					//Controle de valor pago para que o mesmo chegue ate o valor a pagar
					while (ValorPago < ValorAPagar)
					{
						cout << "Insira o restante do valor" << endl;
						cin >> ValorAdicional;

						ValorPago = ValorPago + ValorAdicional;
					}

					// Caso o valor pago seja igual ao valor a pagar desocupa a vaga e agradece
					if (ValorPago == ValorAPagar)
					{
						cout << "Agradecemos a preferencia" << endl;
						Disponibilidade[i] = "Disponivel";
					}

					// Caso o valor pago seja maior que o valor a pagar, calcula troco, desocupa a vaga e agradece
					else if (ValorPago > ValorAPagar)
					{
						Troco = ValorPago - ValorAPagar;
						cout << "Seu troco e de R$" << Troco << endl;
						cout << "Agradecemos a preferencia" << endl;
						Disponibilidade[i] = "Disponivel";
					}
					
				}
				//Se o valor de i entrar dentro dos intervalos � realizado o calculo com valor do carro
				else if (i <= 19 || i > 49 && i <= 74 || i > 84 && i <= 99)
				{
					//Calculos de valores a pagar
					if (MinutoSaida[i] < MinutoEntrada[i] && HoraSaida[i]>HoraEntrada[i])
					{
						AuxiliarMinuto = MinutoSaida[i];
						AuxiliarMinuto += 60;
						AuxiliarHora--;

						BaseCalculoHora = AuxiliarHora - HoraEntrada[i];
						BaseCalculoMinuto = AuxiliarMinuto - MinutoEntrada[i];

						ValorAPagar += BaseCalculoHora * ValorCarro;
					}
					else 
					{
						BaseCalculoHora = HoraSaida[i] - HoraEntrada[i];
						BaseCalculoMinuto = MinutoSaida[i] - MinutoEntrada[i];

						ValorAPagar += BaseCalculoHora * ValorCarro;
					}

					//Calculo a pagar caso ocupe a vaga por mais de 30 minutos
					if (BaseCalculoMinuto > 30)
					{
						ValorAPagar += ValorCarro/2;
					}

					//Gera a media faturada
					if (HorasAcumuladas > 1)
					{
						Media = BaseCalculoHora * (AuxiliarHora * ValorCarro);
					}
					else
						Media = BaseCalculoHora * ValorCarro;

					//Gera o valor total faturado
					FaturamentoTotal = FaturamentoTotal + ValorAPagar;

					//Gera a media faturada
					MinutosAcumulados = MinutosAcumulados / 60;
					if (MinutosAcumulados > 1)
					{
						Media = FaturamentoTotal / (HorasAcumuladas + MinutosAcumulados);
					}
					else
						Media = FaturamentoTotal / HorasAcumuladas;

					FaturamentoMedio = FaturamentoMedio + Media;

					cout << "O valor a pagar e de R$: " << ValorAPagar << endl;
					cout << "Insira o valor de pagamento" << endl;
					cin >> ValorPago;

					//Controle de valor pago para que o mesmo chegue ate o valor a pagar
					while (ValorPago < ValorAPagar)
					{
						cout << "Insira o restante do valor" << endl;
						cin >> ValorAdicional;

						ValorPago = ValorPago + ValorAdicional;
					}

					// Caso o valor pago seja igual ao valor a pagar desocupa a vaga e agradece
					if (ValorPago == ValorAPagar)
					{
						cout << "Agradecemos a preferencia" << endl;
						Disponibilidade[i] = "Disponivel";
					}
					// Caso o valor pago seja maior que o valor a pagar, calcula troco, desocupa a vaga e agradece
					else if (ValorPago > ValorAPagar)
					{
						Troco = ValorPago - ValorAPagar;
						cout << "Seu troco e de R$" << Troco << endl;
						cout << "Agradecemos a preferencia" << endl;
						Disponibilidade[i] = "Disponivel";
					}
				}
				break;
			}
		}
		
	}
	return operacao;
}

int EscolhaADM(int operacao, int AtendidosCarros, int AtendidosCamionetes, int NaoAtendidos, int* DiaEntrada,int FaturamentoMedio,int FaturamentoTotal)
{
	//Controle da repeticao do sistema ADM, codigo 666 repassado pessoalmente ao administrador, para que o usuario nao tenha acesso a essa opcao
	int OperaADM;
	bool DecisaoADM = true;

	if (operacao == 666)
	{
		while (DecisaoADM == true)
		{
			//Menu Administrativo
			cout << "Bem-vindo ao modo Administrativo" << endl;
			cout << "Escolha a opcao desejada" << endl;
			cout << "1 - Numero de carros atendidos" << endl;
			cout << "2 - Numero de camionetes atendidas" << endl;
			cout << "3 - Numero de veiculos nao atendidos" << endl;
			cout << "4 - Faturamento medio por hora" << endl;
			cout << "5 - Faturamento Total" << endl;
			cin >> OperaADM;

			//Demonstra quantidade de carros atendidos
			if (OperaADM == 1)
			{
				cout << "Atendemos "<< AtendidosCarros << " carros" << endl;
			}
			//Demonstra quantidade de Camionetes atendidas
			else if (OperaADM == 2)
			{
				cout << "Atendemos " << AtendidosCamionetes << " camionetes" << endl;
			}
			//Demonstra quantidade de veiculos nao atendidos
			else if (OperaADM == 3)
			{
				cout << "Deixamos de atender " << NaoAtendidos << " veiculos" << endl;
			}
			//Demostra a media faturada
			else if (OperaADM == 4)
			{
				cout << "A media faturada e de R$" << FaturamentoMedio << endl;
			}
			//Demonstra o total faturado
			else if (OperaADM == 5)
			{
				cout << "Faturamos ate o momento: " << FaturamentoTotal << endl;
			}
			
			//Demonstra opcao invalida e retorna ao inicio do menu
			if (OperaADM < 1 || OperaADM > 5)
			{
				cout << "Operacao invalida, digite a operacao correta\n" << endl;
			}
			else
				DecisaoADM = false;
		}
	}

	return operacao;
}

int main()
{
	int Codigo = 0;
	int operacao;
	bool inicio = true;

	//Variaveis de data e hora usuario
	int DiaEntrada[120];
	int MesEntrada[120];
	int AnoEntrada[120];
	int HoraEntrada[120];
	int MinutoEntrada[120];
	int DiaSaida[120];
	int MesSaida[120];
	int AnoSaida[120];
	int HoraSaida[120];
	int MinutoSaida[120];

	//Variaveis Administrativas
	int AtendidosCarros = 0;
	int AtendidosCamionetes = 0;
	int NaoAtendidos = 0;
	double FaturamentoMedio = 0;
	double FaturamentoTotal = 0;

	//Variaveis iniciais para mapaear o terreno e coletar o modelo do carro
	string Modelo;
	string TipoVeiculo[120];
	string Disponibilidade[120];

	//Inicia o programa definindo as vagas
	MapearTerreno(TipoVeiculo, Disponibilidade);

	//Executa as funcoes de acordo com as acoes do usuario
	while (inicio == true)
	{ 
		Menu(operacao);
		EscolhaEntrada(Codigo,operacao, DiaEntrada, MesEntrada, AnoEntrada, HoraEntrada, MinutoEntrada,AtendidosCarros,AtendidosCamionetes,NaoAtendidos, Modelo, TipoVeiculo, Disponibilidade);
		EscolhaSaida(operacao, Codigo, DiaEntrada, MesEntrada, HoraEntrada, MinutoEntrada, DiaSaida, MesSaida, AnoSaida, HoraSaida, MinutoSaida,FaturamentoMedio,FaturamentoTotal,Disponibilidade);
		EscolhaADM(operacao, AtendidosCarros, AtendidosCamionetes, NaoAtendidos, DiaEntrada,FaturamentoMedio,FaturamentoTotal);
	}
	
	system ("pause");
	return 0;
}