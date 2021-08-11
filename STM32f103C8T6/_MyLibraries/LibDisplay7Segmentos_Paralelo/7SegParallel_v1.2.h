/*
 * 7SegParallel_v1.2.h
 *
 *  Created on: Dec 24, 2020
 *      Author: Rafael
 */

#ifndef INC_7SEGPARALLEL_V1_2_H_
#define INC_7SEGPARALLEL_V1_2_H_

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>



struct Display{
    uint8_t   QuantidadedDeCaracteres;  // 0 ~ 9 = 1 caractere, 00 ~ 99 = 2 caracteres, 000 ~ 999 = 3 caracteres, 0000 ~ 1000 = 4 caracteres
    int8_t    Display[4];               // Informa quais displays exibirão os caracteres (Display 1, Display 2, Display 3, Display 4)
    uint16_t  ContadorDeCaractere;      // Contagem que informa qual o último display que teve seu valor exibido
    int8_t*   PonteiroParaTexto;        // Armazena o valor que deverá ser exibido no display (se houver)
};
typedef struct Display DisplaySeteSegmentos;



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
DisplaySeteSegmentos IniDisplay(const uint8_t QtdDeCaracteres, ...);



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
void EscreveNumero(DisplaySeteSegmentos* DisplayConfigurado , uint16_t Valor);



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Organiza o texto (@param2 uint_16) dentro de uma string de 4 posições (tam max permitido - limite da qtd de displays)
  *         para que seja passada para a função que irá definir qual o tipo de exibição que será feito (fixo ou com deslocamento)
  * @param1  :  Display inicializado e configurado pela função IniDisplay()
  * @param2  :  String que deverá ser escrito no display configurado
  *
  * @retval  :  Void
  */
void EscreveString(DisplaySeteSegmentos* DisplayConfigurado , int8_t* Texto);



#endif /* INC_7SEGPARALLEL_V1_2_H_ */
