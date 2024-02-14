#include <iostream>
#include "Cores.h"	//biblioteca criada que cont�m as fun��es de mudan�a de cor
#include "Pacote.h"	//biblioteca criada que cont�m as fun��es de empacotamento e desempacotamento
#include "Rede.h"	//biblioteca criada que cont�m as fun��es de transmiss�o, recebimento e processamento da rede

//---------------------------------------------------------------------
// Defini��es das cores do programa fazem com que n�o precise memorizar 
// o n�mero da cor, basta apenas digitar o nome. 
#define VERMELHO 31
#define AZUL 34
#define BRANCO 37
#define PRETO 30
#define MAGENTA 35
//---------------------------------------------------------------------

using namespace std; 

//------------------------------------------------------
//Fun��es criadas para serem usadas na fun��o principal.
void desenharCaminhao(int, int);
void espacos(unsigned int);
void pistaCorrida(void);
void resultFinal(int, int, int, int);
//------------------------------------------------------

//-----------------------------------------------------------------------------------
// Descri��o_: Fun��o principal que re�ne toda a exibi��o e processamento do programa
// Entrada___: Sem par�metros aparentes.
// Sa�da_____: Retorna 0.
//-----------------------------------------------------------------------------------
int main() {
	// Vari�veis inicializadas.
	int corA = VERMELHO, corB = AZUL;	//Essas duas vari�veis definem as 2 cores principais do programa.
	unsigned int posA = 0, posB = 0;
	unsigned int veloA = 0, veloB = 0;
	unsigned int pistaA = 0, pistaB = 0;
	int passo = 0;
	srand(unsigned(time(NULL)));		//Cria uma semente inicial para a fun��o rand.

	do {								// Atualiza a tela principal em cada repeti��o. 
		system("cls");					// Limpa tela.

		desenharCaminhao(corA, posA);	// Desenha o caminh�o A.
		pistaCorrida();					// Desenha a pista que fica sob o caminh�o A.
		desenharCaminhao(corB, posB);	// Desenha o caminh�o B.
		pistaCorrida();					// Desenha a pista que fica sob o caminh�o B.

		system("chcp 1252 > nul");		// Formata os caracteres para acentua��o.

		// -----------------------------------------------------------------------------------------------------------------------------------
		// Dados do caminh�o A.
		resetarCor();									// Retorna para as cores originais do prompt de comando.
		veloA = 1 + rand() % (9 - 1 + 1);				// Define a velocidade como um n�mero aleat�rio entre 9 e 1, incluindo ambos extremos.
		pistaA = 0 + rand() % (1 - 0 + 1);				// Define o estado da pista como 0 ou 1, aleatoriamente.
		cout << "\nTransmitindo dados...";
		transmitir(passo, corA, posA, veloA, pistaA);	//Envia dos dados do caminh�o A para a rede.
		cout << "\nRecebendo dados...";		
		cout << "\nDados da Rede: ";
		posA = processar(receber());					//Processa e Exibe os dados do caminh�o A recebidos da rede.
		// ------------------------------------------------------------------------------------------------------------------------------------
		
		// ----------------------------------------------------------------------------------------
		// Dados do caminh�o B. L�gica igual ao bloco anterior, mas com as vari�veis do caminh�o B. 
		resetarCor();									
		veloB = 1 + rand() % (9 - 1 + 1);				
		pistaB = 0 + rand() % (1 - 0 + 1);				
		cout << "\n\nTransmitindo dados...";
		transmitir(passo, corB, posB, veloB, pistaB);	
		cout << "\nRecebendo dados...";
		cout << "\nDados da Rede: ";
		posB = processar(receber());					
		// ----------------------------------------------------------------------------------------

		passo = passo + 1;								//Soma a quantidade de passos necess�rios para encerrar o programa. 
		cout << "\n\n";
		resetarCor();									// Retorna para as cores originais do prompt de comando.
		system("pause");								// Pausa o programa at� que alguma tecla seja pressionada.

	} while (posA <= 100 && posB <= 100);				// Repete o programa at� um dos caminh�es passar a posi��o 100.

	// ------------------------------------------------------------------------------------
	// Formata os caracteres dos caminh�es, limpa a tela, desenha os caminh�es e as pistas.
	system("chcp 437 > nul");		
	system("cls");					
	desenharCaminhao(corA, posA);	
	pistaCorrida();
	desenharCaminhao(corB, posB);
	pistaCorrida();
	// -------------------------------------------------------------------------------------

	system("chcp 1252 > nul");				// Formata os caracteres para acentua��o.
	resetarCor();							// Retorna para as cores originais do prompt de comando.	
	cout << "Passos: " << passo << endl;	// Exibe a quantidade de passos que foram necess�rios para um dos caminh�es ganhar
	resultFinal(corA, corA, posA, passo);	// Exibe os dados finais do caminh�o A.
	resultFinal(corB, corB, posB, passo);	// Exibe os dados finais do caminh�o B.

	resetarCor();							// Antes do programa finalizar ela retorna para as cores originais do prompt de comando.	
	cout << endl;
	return 0;
}

//--------------------------------------------------
// Descri��o_: Fun��o que desenha uma pista na tela.
// Entrada___: Sem par�metros.
// Sa�da_____: Sem retorno.
//--------------------------------------------------
void pistaCorrida() { 
	cout << "--------------------------------------------------";
	cout << "--------------------------------------------------";
	cout << "|-------------------------";
	cout << endl;
	cout << "                                                   ";
	cout << "                                                100" << endl;
}

//---------------------------------------------------------------------------
// Descri��o_: Fun��o que desenha um caminh�o na tela.
// Entrada___: Dois inteiros: 
//			   cor -> define a cor dos caracteres;
//			   posicao -> quantidade de caracteres a serem impressos na tela.
// Sa�da_____: Sem retorno.
//---------------------------------------------------------------------------
void desenharCaminhao(int cor, int posicao) {
	system("chcp 437 > nul");					// Formata os caracteres na tela para desenho.
	ajustarCor(cor, PRETO);						// Define a cor do caminh�o.
	espacos(posicao);							// Insere caracteres na tela.
	cout << "     \xDC\xDC\xDC\n";				// Desenha teto do caminh�o.
	espacos(posicao);							
	cout << "\xDC\xDC\xDC\xDC \xDB\xDC\xDB\n";	// Desenha meio do caminh�o.
	espacos(posicao);
	cout << "\xDFOO\xDF\xDF\xDFO\xDF\n";		// Desenha parte de baixo do caminh�o
}

//---------------------------------------------------------------
// Descri��o_: Fun��o que insere caracteres 'espa�o' na tela.
// Entrada___: Um inteiro sem sinal: 
//			   qtd -> quantidade de caracteres a serem inseridos;
// Sa�da_____: Sem retorno.
//---------------------------------------------------------------
void espacos(unsigned int qtd) {
	while (qtd > 0) {	// Loop que s� encerra quando a vari�vel 'qnt' � menor ou igual a zero.
		cout << ' ';
		qtd--;
	}
}

//----------------------------------------------------------------------------------------
// Descri��o_: Fun��o que exibe os argumentos recebidos com o texto alinhado.
// Entrada___: Quatro inteiros: 
//			   corTexto -> Cor do caminh�o para definir a cor do texto;
//			   corFundo -> Cor do fundo do texto;
//			   posicao -> N�mero da posi��o final;
//			   passo -> quantidade de passos realizados pelo programa at� seu encerramento.
// Sa�da_____: Sem retorno.
//-----------------------------------------------------------------------------------------
void resultFinal(int corTexto, int corFundo, int posicao, int passo) {

	ajustarCor(corTexto, PRETO);									// Define a cor do texto igual a cor do caminh�o e deixa o fundo preto. 
	cout << "\nPosi��o: ";
	ajustarCor(BRANCO, corFundo);									// Define a cor do texto como branco e o fundo como a cor passada.
	cout << left << " " << posicao << " ";							// Alinha o n�mero da posi��o para a esquerda e centraliza. 
	ajustarCor(corTexto, PRETO);									
	cout << "\nVelocidade M�dia: ";
	cout.precision(3);												// Permite que apenas 3 n�meros sejam visualizados no pr�ximo cout.
	ajustarCor(BRANCO, corFundo);	
	cout << left << " " << posicao / (float)passo << " " << endl;	// Alinha e exibe a velocidade 
																	// m�dia do caminh�o (Divide a posi��o pela quantidade de passos).
}