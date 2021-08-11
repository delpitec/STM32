#include "7SegParallel_v1.2.h"

#if defined(DISPLAY1_LED_A_GPIO_Port) && defined(DISPLAY1_LED_B_GPIO_Port) && defined(DISPLAY1_LED_C_GPIO_Port) \
 && defined(DISPLAY1_LED_D_GPIO_Port) && defined(DISPLAY1_LED_E_GPIO_Port) && defined(DISPLAY1_LED_F_GPIO_Port) \
 && defined(DISPLAY1_LED_G_GPIO_Port) && defined(DISPLAY1_LED_A_Pin)       && defined(DISPLAY1_LED_B_Pin) \
 && defined(DISPLAY1_LED_C_Pin)       && defined(DISPLAY1_LED_D_Pin)       && defined(DISPLAY1_LED_E_Pin) \
 && defined(DISPLAY1_LED_F_Pin)       && defined(DISPLAY1_LED_G_Pin)
    #define Display1LedA(ValorDoLed) HAL_GPIO_WritePin(DISPLAY1_LED_A_GPIO_Port, DISPLAY1_LED_A_Pin, ValorDoLed)
    #define Display1LedB(ValorDoLed) HAL_GPIO_WritePin(DISPLAY1_LED_B_GPIO_Port, DISPLAY1_LED_B_Pin, ValorDoLed)
    #define Display1LedC(ValorDoLed) HAL_GPIO_WritePin(DISPLAY1_LED_C_GPIO_Port, DISPLAY1_LED_C_Pin, ValorDoLed)
    #define Display1LedD(ValorDoLed) HAL_GPIO_WritePin(DISPLAY1_LED_D_GPIO_Port, DISPLAY1_LED_D_Pin, ValorDoLed)
    #define Display1LedE(ValorDoLed) HAL_GPIO_WritePin(DISPLAY1_LED_E_GPIO_Port, DISPLAY1_LED_E_Pin, ValorDoLed)
    #define Display1LedF(ValorDoLed) HAL_GPIO_WritePin(DISPLAY1_LED_F_GPIO_Port, DISPLAY1_LED_F_Pin, ValorDoLed)
    #define Display1LedG(ValorDoLed) HAL_GPIO_WritePin(DISPLAY1_LED_G_GPIO_Port, DISPLAY1_LED_G_Pin, ValorDoLed)
#endif

#if defined(DISPLAY2_LED_A_GPIO_Port) && defined(DISPLAY2_LED_B_GPIO_Port) && defined(DISPLAY2_LED_C_GPIO_Port) \
 && defined(DISPLAY2_LED_D_GPIO_Port) && defined(DISPLAY2_LED_E_GPIO_Port) && defined(DISPLAY2_LED_F_GPIO_Port) \
 && defined(DISPLAY2_LED_G_GPIO_Port) && defined(DISPLAY2_LED_A_Pin)       && defined(DISPLAY2_LED_B_Pin) \
 && defined(DISPLAY2_LED_C_Pin)       && defined(DISPLAY2_LED_D_Pin)       && defined(DISPLAY2_LED_E_Pin) \
 && defined(DISPLAY2_LED_F_Pin)       && defined(DISPLAY2_LED_G_Pin)
    #define Display2LedA(ValorDoLed) HAL_GPIO_WritePin(DISPLAY2_LED_A_GPIO_Port, DISPLAY2_LED_A_Pin, ValorDoLed)
    #define Display2LedB(ValorDoLed) HAL_GPIO_WritePin(DISPLAY2_LED_B_GPIO_Port, DISPLAY2_LED_B_Pin, ValorDoLed)
    #define Display2LedC(ValorDoLed) HAL_GPIO_WritePin(DISPLAY2_LED_C_GPIO_Port, DISPLAY2_LED_C_Pin, ValorDoLed)
    #define Display2LedD(ValorDoLed) HAL_GPIO_WritePin(DISPLAY2_LED_D_GPIO_Port, DISPLAY2_LED_D_Pin, ValorDoLed)
    #define Display2LedE(ValorDoLed) HAL_GPIO_WritePin(DISPLAY2_LED_E_GPIO_Port, DISPLAY2_LED_E_Pin, ValorDoLed)
    #define Display2LedF(ValorDoLed) HAL_GPIO_WritePin(DISPLAY2_LED_F_GPIO_Port, DISPLAY2_LED_F_Pin, ValorDoLed)
    #define Display2LedG(ValorDoLed) HAL_GPIO_WritePin(DISPLAY2_LED_G_GPIO_Port, DISPLAY2_LED_G_Pin, ValorDoLed)
#endif

#if defined(DISPLAY3_LED_A_GPIO_Port) && defined(DISPLAY3_LED_B_GPIO_Port) && defined(DISPLAY3_LED_C_GPIO_Port) \
 && defined(DISPLAY3_LED_D_GPIO_Port) && defined(DISPLAY3_LED_E_GPIO_Port) && defined(DISPLAY3_LED_F_GPIO_Port) \
 && defined(DISPLAY3_LED_G_GPIO_Port) && defined(DISPLAY3_LED_A_Pin)       && defined(DISPLAY3_LED_B_Pin) \
 && defined(DISPLAY3_LED_C_Pin)       && defined(DISPLAY3_LED_D_Pin)       && defined(DISPLAY3_LED_E_Pin) \
 && defined(DISPLAY3_LED_F_Pin)       && defined(DISPLAY3_LED_G_Pin)
    #define Display3LedA(ValorDoLed) HAL_GPIO_WritePin(DISPLAY3_LED_A_GPIO_Port, DISPLAY3_LED_A_Pin, ValorDoLed)
    #define Display3LedB(ValorDoLed) HAL_GPIO_WritePin(DISPLAY3_LED_B_GPIO_Port, DISPLAY3_LED_B_Pin, ValorDoLed)
    #define Display3LedC(ValorDoLed) HAL_GPIO_WritePin(DISPLAY3_LED_C_GPIO_Port, DISPLAY3_LED_C_Pin, ValorDoLed)
    #define Display3LedD(ValorDoLed) HAL_GPIO_WritePin(DISPLAY3_LED_D_GPIO_Port, DISPLAY3_LED_D_Pin, ValorDoLed)
    #define Display3LedE(ValorDoLed) HAL_GPIO_WritePin(DISPLAY3_LED_E_GPIO_Port, DISPLAY3_LED_E_Pin, ValorDoLed)
    #define Display3LedF(ValorDoLed) HAL_GPIO_WritePin(DISPLAY3_LED_F_GPIO_Port, DISPLAY3_LED_F_Pin, ValorDoLed)
    #define Display3LedG(ValorDoLed) HAL_GPIO_WritePin(DISPLAY3_LED_G_GPIO_Port, DISPLAY3_LED_G_Pin, ValorDoLed)
#endif

#if defined(DISPLAY4_LED_A_GPIO_Port) && defined(DISPLAY4_LED_B_GPIO_Port) && defined(DISPLAY4_LED_C_GPIO_Port) \
 && defined(DISPLAY4_LED_D_GPIO_Port) && defined(DISPLAY4_LED_E_GPIO_Port) && defined(DISPLAY4_LED_F_GPIO_Port) \
 && defined(DISPLAY4_LED_G_GPIO_Port) && defined(DISPLAY4_LED_A_Pin)       && defined(DISPLAY4_LED_B_Pin) \
 && defined(DISPLAY4_LED_C_Pin)       && defined(DISPLAY4_LED_D_Pin)       && defined(DISPLAY4_LED_E_Pin) \
 && defined(DISPLAY4_LED_F_Pin)       && defined(DISPLAY4_LED_G_Pin)
    #define Display4LedA(ValorDoLed) HAL_GPIO_WritePin(DISPLAY4_LED_A_GPIO_Port, DISPLAY4_LED_A_Pin, ValorDoLed)
    #define Display4LedB(ValorDoLed) HAL_GPIO_WritePin(DISPLAY4_LED_B_GPIO_Port, DISPLAY4_LED_B_Pin, ValorDoLed)
    #define Display4LedC(ValorDoLed) HAL_GPIO_WritePin(DISPLAY4_LED_C_GPIO_Port, DISPLAY4_LED_C_Pin, ValorDoLed)
    #define Display4LedD(ValorDoLed) HAL_GPIO_WritePin(DISPLAY4_LED_D_GPIO_Port, DISPLAY4_LED_D_Pin, ValorDoLed)
    #define Display4LedE(ValorDoLed) HAL_GPIO_WritePin(DISPLAY4_LED_E_GPIO_Port, DISPLAY4_LED_E_Pin, ValorDoLed)
    #define Display4LedF(ValorDoLed) HAL_GPIO_WritePin(DISPLAY4_LED_F_GPIO_Port, DISPLAY4_LED_F_Pin, ValorDoLed)
    #define Display4LedG(ValorDoLed) HAL_GPIO_WritePin(DISPLAY4_LED_G_GPIO_Port, DISPLAY4_LED_G_Pin, ValorDoLed)
#endif

struct Segmentos{
   uint8_t SegmentoA;
   uint8_t SegmentoB;
   uint8_t SegmentoC;
   uint8_t SegmentoD;
   uint8_t SegmentoE;
   uint8_t SegmentoF;
   uint8_t SegmentoG;
 };
 typedef struct Segmentos SegDoDisplay ;

 void EscreveCaractereComDeslocamento(DisplaySeteSegmentos* __DisplayConfigurado, int8_t* _DadoEmString);
 void EscreveCaractereFixo(DisplaySeteSegmentos __DisplayConfigurado, int8_t* _DadoEmString);
 SegDoDisplay ConverteDezenaParaSegmento(int8_t DadoQueSeraConvertido);
 void DefineTipoDeExibicao(DisplaySeteSegmentos* _DisplayConfigurado, int8_t* DadoEmString);

/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Inicializa o objeto que definirá as especificações do display de 7 segmentos.
  *
  * @param1  QtdDeCaracters:  Quantidade de caracteres que possui o dado (0~9=1 ; 00~99=2; 000~999=3 ; 0000~9999=4 )
  * @param2             ...:  ID do display do caractere mais significativo
  * @param3             ...:  ID do display do 2º caractere mais significativo
  * @param4             ...:  ID do display do 3º caractere mais significativo
  * @param5             ...:  ID do display do 4º caractere mais significativo
  *
  * @retval                :  Void
  */
  DisplaySeteSegmentos IniDisplay(const uint8_t QtdDeCaracteres, ...){

  DisplaySeteSegmentos ObjetoInicializado;

  ObjetoInicializado.QuantidadedDeCaracteres = QtdDeCaracteres;
  ObjetoInicializado.ContadorDeCaractere = 0;
  ObjetoInicializado.PonteiroParaTexto = 0;
  memset(ObjetoInicializado.Display, 0, sizeof(ObjetoInicializado.Display));

  va_list lista;

  va_start(lista,QtdDeCaracteres);

  for (uint8_t i = 0; i < QtdDeCaracteres; i++){
      ObjetoInicializado.Display[i] = va_arg(lista,int);
  }

  va_end(lista);

  return(ObjetoInicializado);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Organiza o número (@param2 uint_16) dentro de uma string de 4 posições (tam max permitido - limite da qtd de displays)
  *         para que seja passada para a função que irá definir qual o tipo de exibição que será feito (fixo ou com deslocamento)
  *
  * @OBS: Não é possível exibir números maiores que a quantidade de caracteres configurados no display.
  *       Caso um número maior seja inserido, os dígitos mais significativos serão descartados
  *
  * @param1  :  Display inicializado e configurado pela função IniDisplay()
  * @param2  :  valor numerico que deverá ser escrito no display configurado
  *
  * @retval  :  Void
  */
void EscreveNumero(DisplaySeteSegmentos* DisplayConfigurado , uint16_t Valor){
  int8_t ValorEmString[5] = {0};

  switch (DisplayConfigurado->QuantidadedDeCaracteres){
    case 1:
      Valor = Valor % 10;
      sprintf((char*)ValorEmString, "%01d" , Valor);
    break;
    case 2:
      Valor = Valor % 100;
      sprintf((char*)ValorEmString, "%02d", Valor);
    break;
    case 3:
      Valor = Valor % 1000;
      sprintf((char*)ValorEmString, "%03d", Valor);
    break;
    case 4:
      Valor = Valor % 10000;
      sprintf((char*)ValorEmString, "%04d", Valor);
    break;

    default:
    break;
  }
  DefineTipoDeExibicao(DisplayConfigurado,ValorEmString);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/



void ArmazenaTextoEmPonteiroParaTexto(DisplaySeteSegmentos* _DisplayConfigurado, int8_t* _Texto){
  uint16_t ComprimentoDoTexto = (strlen((char *)_Texto)*sizeof(int8_t)) + 1;
  _DisplayConfigurado->PonteiroParaTexto = (int8_t*)malloc(ComprimentoDoTexto);
   sprintf((char *)_DisplayConfigurado->PonteiroParaTexto,"%s",_Texto) ;
}

void DeletaTextoEmPonteiroParaTexto(DisplaySeteSegmentos* _DisplayConfigurado){
  free(_DisplayConfigurado->PonteiroParaTexto);
  _DisplayConfigurado->PonteiroParaTexto = 0;
}



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Organiza o texto (@param2 uint_16) dentro de uma string de 4 posições (tam max permitido - limite da qtd de displays)
  *         para que seja passada para a função que irá definir qual o tipo de exibição que será feito (fixo ou com deslocamento)
  * @param1  :  Display inicializado e configurado pela função IniDisplay()
  * @param2  :  String que deverá ser escrito no display configurado
  *
  * @retval  :  Void
  */
void EscreveString(DisplaySeteSegmentos* DisplayConfigurado , int8_t* Texto){

	  // Se for primeiro valor a ser escrito neste display
	  if(DisplayConfigurado->PonteiroParaTexto == 0){
	    ArmazenaTextoEmPonteiroParaTexto(DisplayConfigurado , Texto);
	  }
	  // Se algum valor já foi escrito no display, verifica se é o mesmo dado. Caso for diferente, armazena novo texto e zera contagem.
	  else{
	    if(strcmp((char *)Texto,(char *)DisplayConfigurado->PonteiroParaTexto) != 0){
	      DeletaTextoEmPonteiroParaTexto(DisplayConfigurado);
	      ArmazenaTextoEmPonteiroParaTexto(DisplayConfigurado , Texto);
	      DisplayConfigurado->ContadorDeCaractere = 0;
	    }
	  }

	  DefineTipoDeExibicao(DisplayConfigurado,Texto);

}
/*----------------------------------------------------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Verifica se a quantidade de caracteres é maior ou menor que a quantidade de caracteres do display configurado
  *         na função IniDisplay() para a struct DisplayConfigurado e define se a exibição será estática(fixa) ou com
  *         deslocamento para que todo o dado possa ser visualizado.
  *
  * @param1  :  Display inicializado e configurado pela função IniDisplay()
  * @param2  :  String que deverá ser escrito no display configurado
  *
  * @retval  :  Void
  */
void DefineTipoDeExibicao(DisplaySeteSegmentos* _DisplayConfigurado, int8_t* DadoEmString){

  // Exibe o caractere com deslocamento no display
  if(strlen((char *)DadoEmString) > _DisplayConfigurado->QuantidadedDeCaracteres){
    EscreveCaractereComDeslocamento(_DisplayConfigurado, DadoEmString);
  }
  // Exibe os caracteres de modo fixo no display
  else{
    EscreveCaractereFixo(*_DisplayConfigurado, DadoEmString);
  }
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

void EscreveNoDisplayConformeID(SegDoDisplay SegmentosDoDisplayFormatado, int8_t IDDoDisplay){

 switch(IDDoDisplay){

	#if defined(DISPLAY1_LED_A_GPIO_Port) && defined(DISPLAY1_LED_B_GPIO_Port) && defined(DISPLAY1_LED_C_GPIO_Port) \
	 && defined(DISPLAY1_LED_D_GPIO_Port) && defined(DISPLAY1_LED_E_GPIO_Port) && defined(DISPLAY1_LED_F_GPIO_Port) \
	 && defined(DISPLAY1_LED_G_GPIO_Port) && defined(DISPLAY1_LED_A_Pin)       && defined(DISPLAY1_LED_B_Pin) \
	 && defined(DISPLAY1_LED_C_Pin)       && defined(DISPLAY1_LED_D_Pin)       && defined(DISPLAY1_LED_E_Pin) \
	 && defined(DISPLAY1_LED_F_Pin)       && defined(DISPLAY1_LED_G_Pin)
 	case 1:
      Display1LedA(SegmentosDoDisplayFormatado.SegmentoA);
      Display1LedB(SegmentosDoDisplayFormatado.SegmentoB);
      Display1LedC(SegmentosDoDisplayFormatado.SegmentoC);
      Display1LedD(SegmentosDoDisplayFormatado.SegmentoD);
      Display1LedE(SegmentosDoDisplayFormatado.SegmentoE);
      Display1LedF(SegmentosDoDisplayFormatado.SegmentoF);
      Display1LedG(SegmentosDoDisplayFormatado.SegmentoG);
    break;
	#endif

    #if defined(DISPLAY2_LED_A_GPIO_Port) && defined(DISPLAY2_LED_B_GPIO_Port) && defined(DISPLAY2_LED_C_GPIO_Port) \
	 && defined(DISPLAY2_LED_D_GPIO_Port) && defined(DISPLAY2_LED_E_GPIO_Port) && defined(DISPLAY2_LED_F_GPIO_Port) \
	 && defined(DISPLAY2_LED_G_GPIO_Port) && defined(DISPLAY2_LED_A_Pin)       && defined(DISPLAY2_LED_B_Pin) \
	 && defined(DISPLAY2_LED_C_Pin)       && defined(DISPLAY2_LED_D_Pin)       && defined(DISPLAY2_LED_E_Pin) \
	 && defined(DISPLAY2_LED_F_Pin)       && defined(DISPLAY2_LED_G_Pin)
    case 2:
      Display2LedA(SegmentosDoDisplayFormatado.SegmentoA);
      Display2LedB(SegmentosDoDisplayFormatado.SegmentoB);
      Display2LedC(SegmentosDoDisplayFormatado.SegmentoC);
      Display2LedD(SegmentosDoDisplayFormatado.SegmentoD);
      Display2LedE(SegmentosDoDisplayFormatado.SegmentoE);
      Display2LedF(SegmentosDoDisplayFormatado.SegmentoF);
      Display2LedG(SegmentosDoDisplayFormatado.SegmentoG);
    break;
	#endif

    #if defined(DISPLAY3_LED_A_GPIO_Port) && defined(DISPLAY3_LED_B_GPIO_Port) && defined(DISPLAY3_LED_C_GPIO_Port) \
	 && defined(DISPLAY3_LED_D_GPIO_Port) && defined(DISPLAY3_LED_E_GPIO_Port) && defined(DISPLAY3_LED_F_GPIO_Port) \
	 && defined(DISPLAY3_LED_G_GPIO_Port) && defined(DISPLAY3_LED_A_Pin)       && defined(DISPLAY3_LED_B_Pin) \
	 && defined(DISPLAY3_LED_C_Pin)       && defined(DISPLAY3_LED_D_Pin)       && defined(DISPLAY3_LED_E_Pin) \
	 && defined(DISPLAY3_LED_F_Pin)       && defined(DISPLAY3_LED_G_Pin)
    case 3:
      Display3LedA(SegmentosDoDisplayFormatado.SegmentoA);
      Display3LedB(SegmentosDoDisplayFormatado.SegmentoB);
      Display3LedC(SegmentosDoDisplayFormatado.SegmentoC);
      Display3LedD(SegmentosDoDisplayFormatado.SegmentoD);
      Display3LedE(SegmentosDoDisplayFormatado.SegmentoE);
      Display3LedF(SegmentosDoDisplayFormatado.SegmentoF);
      Display3LedG(SegmentosDoDisplayFormatado.SegmentoG);
    break;
	#endif

    #if defined(DISPLAY4_LED_A_GPIO_Port) && defined(DISPLAY4_LED_B_GPIO_Port) && defined(DISPLAY4_LED_C_GPIO_Port) \
	 && defined(DISPLAY4_LED_D_GPIO_Port) && defined(DISPLAY4_LED_E_GPIO_Port) && defined(DISPLAY4_LED_F_GPIO_Port) \
	 && defined(DISPLAY4_LED_G_GPIO_Port) && defined(DISPLAY4_LED_A_Pin)       && defined(DISPLAY4_LED_B_Pin) \
	 && defined(DISPLAY4_LED_C_Pin)       && defined(DISPLAY4_LED_D_Pin)       && defined(DISPLAY4_LED_E_Pin) \
	 && defined(DISPLAY4_LED_F_Pin)       && defined(DISPLAY4_LED_G_Pin)
    case 4:
      Display4LedA(SegmentosDoDisplayFormatado.SegmentoA);
      Display4LedB(SegmentosDoDisplayFormatado.SegmentoB);
      Display4LedC(SegmentosDoDisplayFormatado.SegmentoC);
      Display4LedD(SegmentosDoDisplayFormatado.SegmentoD);
      Display4LedE(SegmentosDoDisplayFormatado.SegmentoE);
      Display4LedF(SegmentosDoDisplayFormatado.SegmentoF);
      Display4LedG(SegmentosDoDisplayFormatado.SegmentoG);
    break;
	#endif
  }
}

SegDoDisplay ConverteDezenaParaSegmento(int8_t DadoQueSeraConvertido){

  SegDoDisplay RetornarSegmentoDoDisplay;

  switch(DadoQueSeraConvertido){
    case '0':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case '1':
    case 'i':
    case 'I':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 0;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case '2':
    case 'z':
    case 'Z':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case '3':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 0;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case '4':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 0;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case '5':
    case 's':
    case 'S':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 0;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case '6':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case '7':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 0;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case '8':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case '9':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 0;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'a':
    case 'A':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;
    case 'b':
    case 'B':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'c':
    case 'C':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case 'd':
    case 'D':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'e':
    case 'E':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'f':
    case 'F':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'g':
    case 'G':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case 'h':
    case 'H':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'j':
    case 'J':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case 'l':
    case 'L':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case 'm':
    case 'M':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case 'n':
    case 'N':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'o':
    case 'O':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'p':
    case 'P':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'q':
    case 'Q':
      RetornarSegmentoDoDisplay.SegmentoA = 1;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 0;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'r':
    case 'R':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 't':
    case 'T':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    case 'u':
    case 'U':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case 'v':
    case 'V':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 1;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

    case 'x':
    case 'X':
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 1;
      RetornarSegmentoDoDisplay.SegmentoC = 1;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 1;
      RetornarSegmentoDoDisplay.SegmentoF = 1;
      RetornarSegmentoDoDisplay.SegmentoG = 1;
    break;

    default:
      RetornarSegmentoDoDisplay.SegmentoA = 0;
      RetornarSegmentoDoDisplay.SegmentoB = 0;
      RetornarSegmentoDoDisplay.SegmentoC = 0;
      RetornarSegmentoDoDisplay.SegmentoD = 0;
      RetornarSegmentoDoDisplay.SegmentoE = 0;
      RetornarSegmentoDoDisplay.SegmentoF = 0;
      RetornarSegmentoDoDisplay.SegmentoG = 0;
    break;

  }

  return(RetornarSegmentoDoDisplay);

}


void EscreveCaractereFixo(DisplaySeteSegmentos __DisplayConfigurado, int8_t* _DadoEmString){

  SegDoDisplay SegmentosDoDisplay = {0};

  for (int8_t i = 0; i < __DisplayConfigurado.QuantidadedDeCaracteres; i++){
    SegmentosDoDisplay = ConverteDezenaParaSegmento(_DadoEmString[i]);
    EscreveNoDisplayConformeID(SegmentosDoDisplay, __DisplayConfigurado.Display[i]);
  }
}

void EscreveCaractereComDeslocamento(DisplaySeteSegmentos* __DisplayConfigurado, int8_t* _DadoEmString){

  SegDoDisplay SegmentosDoDisplay = {0};

    for (int8_t i = 0; i < __DisplayConfigurado->QuantidadedDeCaracteres; i++){
        SegmentosDoDisplay = ConverteDezenaParaSegmento(_DadoEmString[__DisplayConfigurado->ContadorDeCaractere+i]);
        EscreveNoDisplayConformeID(SegmentosDoDisplay, __DisplayConfigurado->Display[i]);
        if(_DadoEmString[__DisplayConfigurado->ContadorDeCaractere+i] == 0){
          __DisplayConfigurado->ContadorDeCaractere = 0;
          return;
        }
    }
    __DisplayConfigurado->ContadorDeCaractere++;
}



