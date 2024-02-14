//--------------------------------------------------------------------------
// Descrição_: Função empacota todos os valores recebidos em um único valor.
// Entrada___: Cinco inteiros sem sinal: 
//			   passo -> passo atual do programa;
// 			   cor -> cor do caminhão;
// 			   posicao -> posição atual do caminhão;
// 			   velo -> velocidade sorteada;
// 			   pista -> estado da pista sorteado;
// Saída_____: Retorna um inteiro sem sinal.
//--------------------------------------------------------------------------
unsigned int empacotar(unsigned int passo, unsigned int cor, unsigned int posicao, unsigned int velo, unsigned int pista) {
	unsigned int numero = 0;		// Número a ser moldado para empacotar todos os números recebidos.
	unsigned int padding = 0;		// Supre os bits que não serão preenchidos.

	numero = numero | passo;		// Insere os bits de 'passo' em numero. 
	numero = numero << 8 | cor;		// Move os bits de 'numero' 8 posições para a esquerda e preenche o espaço afastado com os 8 bits mais baixos de 'cor'.
	numero = numero << 7 | posicao;	// Move os bits de 'numero' 7 posições para a esquerda e preenche o espaço afastado com os 7 bits mais baixos de 'posicao'.
	numero = numero << 4 | velo;	// Move os bits de 'numero' 4 posições para a esquerda e preenche o espaço afastado com os 4 bits mais baixos de 'velo'.
	numero = numero << 1 | pista;	// Move os bits de 'numero' 1 posição para a esquerda e preenche o espaço afastado com o bit mais baixo de 'pista'.
	numero = numero << 4 | padding;	// Move os bits de 'numero' 4 posições para a esquerda e preenche o espaço afastado zeros.

	return numero;
}

//------------------------------------------------------------------------------------
// Descrição das Próximas 5 funções_: Funções que desempacotam seus respectivos dados.
// Entrada___: Recebem um inteiro sem sinal.
// Saída_____: Retornam um inteiro sem sinal.
//------------------------------------------------------------------------------------
unsigned int desenpacPasso(unsigned int pacote) {
	return pacote >> 24;		// Faz com que os 8 bits mais altos se tornem os 8 bits mais baixos e retorna o número resultante.
}

unsigned int desenpacCor(unsigned int pacote) {
	return pacote >> 16 & 255;	// Faz com que os 16 bits mais altos se tornem os 16 bits mais baixos,
								// concerva apenas os 8 bits mais baixos ao realizar a conjunção (255 = 11111111b)
								// e retorna o número resultante.
}

unsigned int desenpacPosicao(unsigned int pacote) {
	return pacote >> 9 & 127;	// Faz com que os 23 bits mais altos se tornem os 23 bits mais baixos,
								// concerva apenas os 7 bits mais baixos ao realizar a conjunção (127 = 01111111b)
								// e retorna o número resultante.
}

unsigned int desenpacVelocidade(unsigned int pacote) {
	return pacote >> 5 & 15;	// Faz com que os 27 bits mais altos se tornem os 27 bits mais baixos,
								// concerva apenas os 4 bits mais baixos ao realizar a conjunção (15 = 1111b)
								// e retorna o número resultante.
}

unsigned int desenpacPista(unsigned int pacote) {
	return pacote >> 4 & 1;		// Move os bits de 'pacote' 4 posições para a direita,
								// concerva apenas os bit mais baixo ao realizar a conjunção (1 = 0001b)
								// e retorna 0 ou 1.
}