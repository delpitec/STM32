//Funções de inicialização
void lcd_20x4_4bits_Init(void);
void lcd_escreve_instrucao_Init(char opcode);
void lcd_escreve_instrucao_Init(char opcode);

// Funções de utilização
void lcd_posicao_do_cursor(char lin, char col); // posição do cursor na tela
void lcd_limpa_display(void);			// limpar o display + pos. l0 c0
void lcd_escreve_string(char *c); 		// escreve uma string de dados de caracteres até receber \r
