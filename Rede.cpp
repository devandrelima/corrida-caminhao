#include "Pacote.h"
#include "Cores.h"
#include <iostream>

#define BRANCO 37
#define PRETO 30

using namespace std;	
unsigned int rede = 0;	//variável global

//--------------------------------------------------------------------------------------------------------------
// Descrição_: Função que transmite os dados do programa principal para o empacotamento e depois insere na rede.
// Entrada___: Cinco inteiros sem sinal: 
//			   passo -> passo atual do programa;
// 			   cor -> cor do caminhão;
// 			   posicao -> posição atual do caminhão;
// 			   velo -> velocidade sorteada;
// 			   pista -> estado da pista sorteado.
// Saída_____: Sem retorno.
//--------------------------------------------------------------------------------------------------------------
void transmitir(unsigned int passo, unsigned int cor, unsigned int posicao, unsigned int velo, unsigned int pista) {
	rede = empacotar(passo, cor, posicao, velo, pista); 
}

//----------------------------------------------------------------------------------------------------
// Descrição_: Função que decopõe os dados recebidos, calcula e retorna a próxima posição do caminhão.
// Entrada___: Um inteiro sem sinal: 
//			   pacoteRede -> dado será decomposto e utilizado na fórmula para determinar a posição.
// Saída_____: Retorna um número inteiro sem sinal.
//----------------------------------------------------------------------------------------------------
unsigned int processar(unsigned int pacoteRede) {
	return desenpacPosicao(pacoteRede) + desenpacVelocidade(pacoteRede) - desenpacPista(pacoteRede);
}

//----------------------------------------------------------------
// Descrição_: Função que exibe dados formatados e alinhados.
// Entrada___: Dois inteiros sem sinal: 
//			   funcaoDesempac -> dado desempacotado para exibição;
//			   cor -> cor que o dado será apresentado.
// Saída_____: Sem retorno.
//----------------------------------------------------------------
void exibirResultado(unsigned int funcaoDesempac, unsigned int cor) {
	ajustarCor(BRANCO, cor);						//Faz com que o próximo cout exiba um nome branco e com o fundo da cor do caminhão
	cout << left << " " << funcaoDesempac << " ";	//Alinha o texto
}

//--------------------------------------------------------------------------
// Descrição_: Função que exibe os dados do caminhão e retorna o valor rede.
// Entrada___: Sem parâmetros.
// Saída_____: Retorna um número inteiro sem sinal.
//--------------------------------------------------------------------------
unsigned int receber() {
	unsigned int corCaminhao = desenpacCor(rede);		// Guarda a cor do caminhão a ser usada para colorir as informações exibidas.

	exibirResultado(rede, corCaminhao);					// Exibe o valor da rede alinhado e colorido com a cor do caminhão.

	//--------------------------------------------------------------------------------------------------------------------------------------------
	ajustarCor(corCaminhao, PRETO);						// Faz com que o cout da próxima linha exiba um nome da cor do caminhão e com fundo preto.
	cout << "\nPasso ";									// Escreve o nome do dado que será exibido.
	exibirResultado(desenpacPasso(rede), corCaminhao);	// Exibe o resultado que é desempacotado da rede com a cor do caminhão e alinhado.
	//--------------------------------------------------------------------------------------------------------------------------------------------
	
	//A lógica da exibição dos dados abaixo se repete conforme o 'bloco' acima
	ajustarCor(corCaminhao, PRETO);
	cout << "\nPosição ";
	exibirResultado(desenpacPosicao(rede), corCaminhao);

	ajustarCor(corCaminhao, PRETO);
	cout << "\nVelocidade ";
	exibirResultado(desenpacVelocidade(rede), corCaminhao);

	ajustarCor(corCaminhao, PRETO);
	cout << "\nÓleo ";
	exibirResultado(desenpacPista(rede), corCaminhao);

	ajustarCor(corCaminhao, PRETO);
	cout << "\nPróxima Posição: ";
	exibirResultado(processar(rede), corCaminhao);		// Exibe o processamento da função (próximo passo do caminhão) 
														// com a cor do caminhão e alinhado.

	resetarCor();										// Retorna para as cores originais do prompt de comando.
	return rede;
}