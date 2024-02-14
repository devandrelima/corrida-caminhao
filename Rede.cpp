#include "Pacote.h"
#include "Cores.h"
#include <iostream>

#define BRANCO 37
#define PRETO 30

using namespace std;	
unsigned int rede = 0;	//vari�vel global

//--------------------------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que transmite os dados do programa principal para o empacotamento e depois insere na rede.
// Entrada___: Cinco inteiros sem sinal: 
//			   passo -> passo atual do programa;
// 			   cor -> cor do caminh�o;
// 			   posicao -> posi��o atual do caminh�o;
// 			   velo -> velocidade sorteada;
// 			   pista -> estado da pista sorteado.
// Sa�da_____: Sem retorno.
//--------------------------------------------------------------------------------------------------------------
void transmitir(unsigned int passo, unsigned int cor, unsigned int posicao, unsigned int velo, unsigned int pista) {
	rede = empacotar(passo, cor, posicao, velo, pista); 
}

//----------------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que decop�e os dados recebidos, calcula e retorna a pr�xima posi��o do caminh�o.
// Entrada___: Um inteiro sem sinal: 
//			   pacoteRede -> dado ser� decomposto e utilizado na f�rmula para determinar a posi��o.
// Sa�da_____: Retorna um n�mero inteiro sem sinal.
//----------------------------------------------------------------------------------------------------
unsigned int processar(unsigned int pacoteRede) {
	return desenpacPosicao(pacoteRede) + desenpacVelocidade(pacoteRede) - desenpacPista(pacoteRede);
}

//----------------------------------------------------------------
// Descri��o_: Fun��o que exibe dados formatados e alinhados.
// Entrada___: Dois inteiros sem sinal: 
//			   funcaoDesempac -> dado desempacotado para exibi��o;
//			   cor -> cor que o dado ser� apresentado.
// Sa�da_____: Sem retorno.
//----------------------------------------------------------------
void exibirResultado(unsigned int funcaoDesempac, unsigned int cor) {
	ajustarCor(BRANCO, cor);						//Faz com que o pr�ximo cout exiba um nome branco e com o fundo da cor do caminh�o
	cout << left << " " << funcaoDesempac << " ";	//Alinha o texto
}

//--------------------------------------------------------------------------
// Descri��o_: Fun��o que exibe os dados do caminh�o e retorna o valor rede.
// Entrada___: Sem par�metros.
// Sa�da_____: Retorna um n�mero inteiro sem sinal.
//--------------------------------------------------------------------------
unsigned int receber() {
	unsigned int corCaminhao = desenpacCor(rede);		// Guarda a cor do caminh�o a ser usada para colorir as informa��es exibidas.

	exibirResultado(rede, corCaminhao);					// Exibe o valor da rede alinhado e colorido com a cor do caminh�o.

	//--------------------------------------------------------------------------------------------------------------------------------------------
	ajustarCor(corCaminhao, PRETO);						// Faz com que o cout da pr�xima linha exiba um nome da cor do caminh�o e com fundo preto.
	cout << "\nPasso ";									// Escreve o nome do dado que ser� exibido.
	exibirResultado(desenpacPasso(rede), corCaminhao);	// Exibe o resultado que � desempacotado da rede com a cor do caminh�o e alinhado.
	//--------------------------------------------------------------------------------------------------------------------------------------------
	
	//A l�gica da exibi��o dos dados abaixo se repete conforme o 'bloco' acima
	ajustarCor(corCaminhao, PRETO);
	cout << "\nPosi��o ";
	exibirResultado(desenpacPosicao(rede), corCaminhao);

	ajustarCor(corCaminhao, PRETO);
	cout << "\nVelocidade ";
	exibirResultado(desenpacVelocidade(rede), corCaminhao);

	ajustarCor(corCaminhao, PRETO);
	cout << "\n�leo ";
	exibirResultado(desenpacPista(rede), corCaminhao);

	ajustarCor(corCaminhao, PRETO);
	cout << "\nPr�xima Posi��o: ";
	exibirResultado(processar(rede), corCaminhao);		// Exibe o processamento da fun��o (pr�ximo passo do caminh�o) 
														// com a cor do caminh�o e alinhado.

	resetarCor();										// Retorna para as cores originais do prompt de comando.
	return rede;
}