#include <iostream>
#include "Cores.h"	//biblioteca criada que contém as funções de mudança de cor
#include "Pacote.h"	//biblioteca criada que contém as funções de empacotamento e desempacotamento
#include "Rede.h"	//biblioteca criada que contém as funções de transmissão, recebimento e processamento da rede

//---------------------------------------------------------------------
// Definições das cores do programa fazem com que não precise memorizar 
// o número da cor, basta apenas digitar o nome. 
#define VERMELHO 31
#define AZUL 34
#define BRANCO 37
#define PRETO 30
#define MAGENTA 35
//---------------------------------------------------------------------

using namespace std; 

//------------------------------------------------------
//Funções criadas para serem usadas na função principal.
void desenharCaminhao(int, int);
void espacos(unsigned int);
void pistaCorrida(void);
void resultFinal(int, int, int, int);
//------------------------------------------------------

//-----------------------------------------------------------------------------------
// Descrição_: Função principal que reúne toda a exibição e processamento do programa
// Entrada___: Sem parâmetros aparentes.
// Saída_____: Retorna 0.
//-----------------------------------------------------------------------------------
int main() {
	// Variáveis inicializadas.
	int corA = VERMELHO, corB = AZUL;	//Essas duas variáveis definem as 2 cores principais do programa.
	unsigned int posA = 0, posB = 0;
	unsigned int veloA = 0, veloB = 0;
	unsigned int pistaA = 0, pistaB = 0;
	int passo = 0;
	srand(unsigned(time(NULL)));		//Cria uma semente inicial para a função rand.

	do {								// Atualiza a tela principal em cada repetição. 
		system("cls");					// Limpa tela.

		desenharCaminhao(corA, posA);	// Desenha o caminhão A.
		pistaCorrida();					// Desenha a pista que fica sob o caminhão A.
		desenharCaminhao(corB, posB);	// Desenha o caminhão B.
		pistaCorrida();					// Desenha a pista que fica sob o caminhão B.

		system("chcp 1252 > nul");		// Formata os caracteres para acentuação.

		// -----------------------------------------------------------------------------------------------------------------------------------
		// Dados do caminhão A.
		resetarCor();									// Retorna para as cores originais do prompt de comando.
		veloA = 1 + rand() % (9 - 1 + 1);				// Define a velocidade como um número aleatório entre 9 e 1, incluindo ambos extremos.
		pistaA = 0 + rand() % (1 - 0 + 1);				// Define o estado da pista como 0 ou 1, aleatoriamente.
		cout << "\nTransmitindo dados...";
		transmitir(passo, corA, posA, veloA, pistaA);	//Envia dos dados do caminhão A para a rede.
		cout << "\nRecebendo dados...";		
		cout << "\nDados da Rede: ";
		posA = processar(receber());					//Processa e Exibe os dados do caminhão A recebidos da rede.
		// ------------------------------------------------------------------------------------------------------------------------------------
		
		// ----------------------------------------------------------------------------------------
		// Dados do caminhão B. Lógica igual ao bloco anterior, mas com as variáveis do caminhão B. 
		resetarCor();									
		veloB = 1 + rand() % (9 - 1 + 1);				
		pistaB = 0 + rand() % (1 - 0 + 1);				
		cout << "\n\nTransmitindo dados...";
		transmitir(passo, corB, posB, veloB, pistaB);	
		cout << "\nRecebendo dados...";
		cout << "\nDados da Rede: ";
		posB = processar(receber());					
		// ----------------------------------------------------------------------------------------

		passo = passo + 1;								//Soma a quantidade de passos necessários para encerrar o programa. 
		cout << "\n\n";
		resetarCor();									// Retorna para as cores originais do prompt de comando.
		system("pause");								// Pausa o programa até que alguma tecla seja pressionada.

	} while (posA <= 100 && posB <= 100);				// Repete o programa até um dos caminhões passar a posição 100.

	// ------------------------------------------------------------------------------------
	// Formata os caracteres dos caminhões, limpa a tela, desenha os caminhões e as pistas.
	system("chcp 437 > nul");		
	system("cls");					
	desenharCaminhao(corA, posA);	
	pistaCorrida();
	desenharCaminhao(corB, posB);
	pistaCorrida();
	// -------------------------------------------------------------------------------------

	system("chcp 1252 > nul");				// Formata os caracteres para acentuação.
	resetarCor();							// Retorna para as cores originais do prompt de comando.	
	cout << "Passos: " << passo << endl;	// Exibe a quantidade de passos que foram necessários para um dos caminhões ganhar
	resultFinal(corA, corA, posA, passo);	// Exibe os dados finais do caminhão A.
	resultFinal(corB, corB, posB, passo);	// Exibe os dados finais do caminhão B.

	resetarCor();							// Antes do programa finalizar ela retorna para as cores originais do prompt de comando.	
	cout << endl;
	return 0;
}

//--------------------------------------------------
// Descrição_: Função que desenha uma pista na tela.
// Entrada___: Sem parâmetros.
// Saída_____: Sem retorno.
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
// Descrição_: Função que desenha um caminhão na tela.
// Entrada___: Dois inteiros: 
//			   cor -> define a cor dos caracteres;
//			   posicao -> quantidade de caracteres a serem impressos na tela.
// Saída_____: Sem retorno.
//---------------------------------------------------------------------------
void desenharCaminhao(int cor, int posicao) {
	system("chcp 437 > nul");					// Formata os caracteres na tela para desenho.
	ajustarCor(cor, PRETO);						// Define a cor do caminhão.
	espacos(posicao);							// Insere caracteres na tela.
	cout << "     \xDC\xDC\xDC\n";				// Desenha teto do caminhão.
	espacos(posicao);							
	cout << "\xDC\xDC\xDC\xDC \xDB\xDC\xDB\n";	// Desenha meio do caminhão.
	espacos(posicao);
	cout << "\xDFOO\xDF\xDF\xDFO\xDF\n";		// Desenha parte de baixo do caminhão
}

//---------------------------------------------------------------
// Descrição_: Função que insere caracteres 'espaço' na tela.
// Entrada___: Um inteiro sem sinal: 
//			   qtd -> quantidade de caracteres a serem inseridos;
// Saída_____: Sem retorno.
//---------------------------------------------------------------
void espacos(unsigned int qtd) {
	while (qtd > 0) {	// Loop que só encerra quando a variável 'qnt' é menor ou igual a zero.
		cout << ' ';
		qtd--;
	}
}

//----------------------------------------------------------------------------------------
// Descrição_: Função que exibe os argumentos recebidos com o texto alinhado.
// Entrada___: Quatro inteiros: 
//			   corTexto -> Cor do caminhão para definir a cor do texto;
//			   corFundo -> Cor do fundo do texto;
//			   posicao -> Número da posição final;
//			   passo -> quantidade de passos realizados pelo programa até seu encerramento.
// Saída_____: Sem retorno.
//-----------------------------------------------------------------------------------------
void resultFinal(int corTexto, int corFundo, int posicao, int passo) {

	ajustarCor(corTexto, PRETO);									// Define a cor do texto igual a cor do caminhão e deixa o fundo preto. 
	cout << "\nPosição: ";
	ajustarCor(BRANCO, corFundo);									// Define a cor do texto como branco e o fundo como a cor passada.
	cout << left << " " << posicao << " ";							// Alinha o número da posição para a esquerda e centraliza. 
	ajustarCor(corTexto, PRETO);									
	cout << "\nVelocidade Média: ";
	cout.precision(3);												// Permite que apenas 3 números sejam visualizados no próximo cout.
	ajustarCor(BRANCO, corFundo);	
	cout << left << " " << posicao / (float)passo << " " << endl;	// Alinha e exibe a velocidade 
																	// média do caminhão (Divide a posição pela quantidade de passos).
}