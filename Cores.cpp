#include <iostream>
using namespace std;

//-------------------------------------------------------
// Descrição_: Função que muda a cor do texto.
// Entrada___: Dois inteiros sem sinal: 
//			   text -> define a cor do texto;
//			   fundo -> define a cor do fundo.
// Saída_____: Sem retorno.
//-------------------------------------------------------
void ajustarCor(unsigned int text, unsigned int fundo) {
	cout << "\033[0;" << text << ";" << fundo + 10 << "m"; //Código que muda a cor do texto e do fundo conforme os números inseridos.
}

//-----------------------------------------------------------------------------------------------
// Descrição_: Função que retorna a cor do texto e do fundo para a original do prompt de comando.
// Entrada___: Sem parâmetros.
// Saída_____: Sem retorno.
//-----------------------------------------------------------------------------------------------
void resetarCor() {
	cout << "\033[m";	//Código que muda a cor do texto e do fundo para a original do prompt de comando.
}