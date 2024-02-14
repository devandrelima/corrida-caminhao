#include <iostream>
using namespace std;

//-------------------------------------------------------
// Descri��o_: Fun��o que muda a cor do texto.
// Entrada___: Dois inteiros sem sinal: 
//			   text -> define a cor do texto;
//			   fundo -> define a cor do fundo.
// Sa�da_____: Sem retorno.
//-------------------------------------------------------
void ajustarCor(unsigned int text, unsigned int fundo) {
	cout << "\033[0;" << text << ";" << fundo + 10 << "m"; //C�digo que muda a cor do texto e do fundo conforme os n�meros inseridos.
}

//-----------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que retorna a cor do texto e do fundo para a original do prompt de comando.
// Entrada___: Sem par�metros.
// Sa�da_____: Sem retorno.
//-----------------------------------------------------------------------------------------------
void resetarCor() {
	cout << "\033[m";	//C�digo que muda a cor do texto e do fundo para a original do prompt de comando.
}