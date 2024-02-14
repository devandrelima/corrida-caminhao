//--------------------------------------------------------------------------
// Descri��o_: Fun��o empacota todos os valores recebidos em um �nico valor.
// Entrada___: Cinco inteiros sem sinal: 
//			   passo -> passo atual do programa;
// 			   cor -> cor do caminh�o;
// 			   posicao -> posi��o atual do caminh�o;
// 			   velo -> velocidade sorteada;
// 			   pista -> estado da pista sorteado;
// Sa�da_____: Retorna um inteiro sem sinal.
//--------------------------------------------------------------------------
unsigned int empacotar(unsigned int passo, unsigned int cor, unsigned int posicao, unsigned int velo, unsigned int pista) {
	unsigned int numero = 0;		// N�mero a ser moldado para empacotar todos os n�meros recebidos.
	unsigned int padding = 0;		// Supre os bits que n�o ser�o preenchidos.

	numero = numero | passo;		// Insere os bits de 'passo' em numero. 
	numero = numero << 8 | cor;		// Move os bits de 'numero' 8 posi��es para a esquerda e preenche o espa�o afastado com os 8 bits mais baixos de 'cor'.
	numero = numero << 7 | posicao;	// Move os bits de 'numero' 7 posi��es para a esquerda e preenche o espa�o afastado com os 7 bits mais baixos de 'posicao'.
	numero = numero << 4 | velo;	// Move os bits de 'numero' 4 posi��es para a esquerda e preenche o espa�o afastado com os 4 bits mais baixos de 'velo'.
	numero = numero << 1 | pista;	// Move os bits de 'numero' 1 posi��o para a esquerda e preenche o espa�o afastado com o bit mais baixo de 'pista'.
	numero = numero << 4 | padding;	// Move os bits de 'numero' 4 posi��es para a esquerda e preenche o espa�o afastado zeros.

	return numero;
}

//------------------------------------------------------------------------------------
// Descri��o das Pr�ximas 5 fun��es_: Fun��es que desempacotam seus respectivos dados.
// Entrada___: Recebem um inteiro sem sinal.
// Sa�da_____: Retornam um inteiro sem sinal.
//------------------------------------------------------------------------------------
unsigned int desenpacPasso(unsigned int pacote) {
	return pacote >> 24;		// Faz com que os 8 bits mais altos se tornem os 8 bits mais baixos e retorna o n�mero resultante.
}

unsigned int desenpacCor(unsigned int pacote) {
	return pacote >> 16 & 255;	// Faz com que os 16 bits mais altos se tornem os 16 bits mais baixos,
								// concerva apenas os 8 bits mais baixos ao realizar a conjun��o (255 = 11111111b)
								// e retorna o n�mero resultante.
}

unsigned int desenpacPosicao(unsigned int pacote) {
	return pacote >> 9 & 127;	// Faz com que os 23 bits mais altos se tornem os 23 bits mais baixos,
								// concerva apenas os 7 bits mais baixos ao realizar a conjun��o (127 = 01111111b)
								// e retorna o n�mero resultante.
}

unsigned int desenpacVelocidade(unsigned int pacote) {
	return pacote >> 5 & 15;	// Faz com que os 27 bits mais altos se tornem os 27 bits mais baixos,
								// concerva apenas os 4 bits mais baixos ao realizar a conjun��o (15 = 1111b)
								// e retorna o n�mero resultante.
}

unsigned int desenpacPista(unsigned int pacote) {
	return pacote >> 4 & 1;		// Move os bits de 'pacote' 4 posi��es para a direita,
								// concerva apenas os bit mais baixo ao realizar a conjun��o (1 = 0001b)
								// e retorna 0 ou 1.
}