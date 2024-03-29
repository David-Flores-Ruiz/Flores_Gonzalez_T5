/*
 * @file:			T02_InvertSequencesRGB_White_Layered.c
 * @company:		ITESO
 * @Engineer Team:	D.F.R. / R.G.P.
 */

#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"
#include <bits.h>		// se añadió  .h vClass
#include <GPIO.h>		// se añadió  .h vClass	-  tiene propio .c vClass + vMy
#include "RGB.h"		// hicimos un .h vMy - con su .c vMy

int main(void) {

	uint32_t arriba_sw2 = 0;	// Secuencia: Verde-Amarillo-Rojo-Morado-Azul...Verde
	uint32_t abajo_sw3  = 0;	// Secuencia: Verde-Azul-Morado-Rojo-Amarillo...Verde
	uint32_t contador   = 0;	// Ascendente
	uint32_t contador_2 = 0;	// Descendente

	GPIO_clock_gating( GPIO_A);	// sw3
	GPIO_clock_gating( GPIO_B);	// led azul y rojo
	GPIO_clock_gating( GPIO_C);	// sw2
	GPIO_clock_gating( GPIO_E);	// led verde

	gpio_pin_control_register_t led_config = GPIO_MUX1;						// 100
	gpio_pin_control_register_t sw_config  = GPIO_MUX1 |GPIO_PE | GPIO_PS;	// 103

	GPIO_pin_control_register( GPIO_A, bit_4,  &sw_config );  // sw3	  - pin  4
	GPIO_pin_control_register( GPIO_B, bit_21, &led_config);  // ledBlue  - pin 21
	GPIO_pin_control_register( GPIO_B, bit_22, &led_config);  // ledRed   - pin 22
	GPIO_pin_control_register( GPIO_C, bit_6,  &sw_config );  // sw2	  - pin  6
	GPIO_pin_control_register( GPIO_E, bit_26, &led_config);  // ledGreen - pin 26

	GPIO_set_pin( GPIO_B, bit_22);	// OFF - 1 RED
	GPIO_set_pin( GPIO_E, bit_26);	// OFF - 1 GREEN
	GPIO_set_pin( GPIO_B, bit_21);	// OFF - 1 BLUE

	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, bit_22); // OUTPUT - 1 RED
	GPIO_data_direction_pin(GPIO_E, GPIO_OUTPUT, bit_26); // OUTPUT - 1 GREEN
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT, bit_21); // OUTPUT - 1 BLUE

	while (1) {
		arriba_sw2 = GPIO_read_pin( GPIO_C, bit_6);	// lee el sw2
		abajo_sw3  = GPIO_read_pin( GPIO_A, bit_4);	// lee el sw3

		if ( (contador == 0) && (contador_2 == 0) ){	  // Estado inicial y cada vez que salga de una secuencia.
<<<<<<< HEAD
					apagar_LED(RED_OFF);
					apagar_LED(BLUE_OFF);
					encender_LED(GREEN_ON);
				}


		if ( (abajo_sw3 == 0) && (arriba_sw2 == 0) ){	  // Estado inicial y cada vez que salga de una secuencia.
			encender_LED(RED_ON);
			encender_LED(BLUE_ON);
			encender_LED(GREEN_ON);
			delay(1000);
			contador=0;
			contador_2=0;
		}
		if ( (arriba_sw2 != 0) && (abajo_sw3 == 0) ) { // Si solo está presionado el sw3...
							abajo_sw3 = GPIO_read_pin(GPIO_A, bit_4);	  // lee el sw3

							if (abajo_sw3 != 0) {
								contador_2++;
							}
							switch ( contador_2  ) {		// Obtengo valores del 1 - 5 (el 5to reinicia la secuencia)

									case 1:
										apagar_LED(GREEN_OFF);
										encender_LED(BLUE_ON);		// Azul   	  - on
										break;

									case 2:
										apagar_LED(BLUE_OFF);
										encender_LED(BLUE_ON);		// Azul + Rojo
										encender_LED(RED_ON);		// = Morado   - on
										break;

									case 3:
										apagar_LED(BLUE_OFF);
										apagar_LED(RED_OFF);
										encender_LED(RED_ON);		// Rojo   		- on
										break;

									case 4:
										apagar_LED(RED_OFF);
										encender_LED(RED_ON);		// Rojo + Verde
										encender_LED(GREEN_ON);		// = Amarillo	- on
										break;

									default:
										apagar_LED(RED_OFF);
										apagar_LED(GREEN_OFF);
										contador_2 = 0;				// */*/ Reinicio de secuencia DESCENDENTE */*/ //
										contador   = 0;
										break;
							} // end switch
						}else if( (arriba_sw2 == 0) && (abajo_sw3 != 0)){
							arriba_sw2 = GPIO_read_pin(GPIO_C, bit_6);	  // lee el sw2
														if (arriba_sw2 != 0) {
															contador++;
														}
														switch ( contador  ) {		// Obtengo valores del 1 - 5 (el 5to reinicia la secuencia)

														case 1:
															apagar_LED(GREEN_OFF);
															encender_LED(RED_ON);		// Rojo + Verde
															encender_LED(GREEN_ON);		// = Amarillo	- on
															break;

														case 2:
															apagar_LED(RED_OFF);
															apagar_LED(GREEN_OFF);
															encender_LED(RED_ON);		// Rojo   		- on
															break;

														case 3:
															apagar_LED(RED_OFF);
															encender_LED(BLUE_ON);		// Azul + Rojo
															encender_LED(RED_ON);		// = Morado  	- on
															break;

														case 4:
															apagar_LED(BLUE_OFF);
															apagar_LED(RED_OFF);
															encender_LED(BLUE_ON);		// Azul	  		- on
															break;

														default:/**If doesn't exist the option*/
															apagar_LED(BLUE_OFF);
															contador   = 0;				// */*/ Reinicio de secuencia ASCENDENTE */*/ //
															contador_2 = 0;
															break;
														} // end switch
						}

						};




	return 0 ;
}




 // end main
=======
			apagar_LED(RED_OFF);
			apagar_LED(BLUE_OFF);
			encender_LED(GREEN_ON);
		}

		while ( (arriba_sw2 == 0) && (abajo_sw3 != 0) ) { // Si solo está presionado el sw2...
			arriba_sw2 = GPIO_read_pin(GPIO_C, bit_6);	  // lee el sw2
			if (arriba_sw2 != 0) {
				contador++;
			}
			switch ( contador ) {		// Obtengo valores del 1 - 5 (el 5to reinicia la secuencia)

			case 1:
				apagar_LED(GREEN_OFF);
				encender_LED(RED_ON);		// Rojo + Verde
				encender_LED(GREEN_ON);		// = Amarillo	- on
				break;

			case 2:
				apagar_LED(RED_OFF);
				apagar_LED(GREEN_OFF);
				encender_LED(RED_ON);		// Rojo   		- on
				break;

			case 3:
				apagar_LED(RED_OFF);
				encender_LED(BLUE_ON);		// Azul + Rojo
				encender_LED(RED_ON);		// = Morado  	- on
				break;

			case 4:
				apagar_LED(BLUE_OFF);
				apagar_LED(RED_OFF);
				encender_LED(BLUE_ON);		// Azul	  		- on
				break;

			default:/**If doesn't exist the option*/
				apagar_LED(BLUE_OFF);
				contador   = 0;				// */*/ Reinicio de secuencia ASCENDENTE */*/ //
				contador_2 = 0;
				break;
			} // end switch
		} // end while (sw2)

		while ( (arriba_sw2 != 0) && (abajo_sw3 == 0) ) { // Si solo está presionado el sw3...
			abajo_sw3 = GPIO_read_pin(GPIO_A, bit_4);	  // lee el sw3
			if (abajo_sw3 != 0) {
				contador_2++;
			}
			switch ( contador_2 ) {// Obtengo valores del 1 - 5 (el 5to reinicia la secuencia)

			case 1:
				apagar_LED(GREEN_OFF);
				encender_LED(BLUE_ON);		// Azul   	    - on
				break;

			case 2:
				apagar_LED(BLUE_OFF);
				encender_LED(BLUE_ON);		// Azul + Rojo
				encender_LED(RED_ON);		// = Morado     - on
				break;

			case 3:
				apagar_LED(BLUE_OFF);
				apagar_LED(RED_OFF);
				encender_LED(RED_ON);		// Rojo		    - on
				break;

			case 4:
				apagar_LED(RED_OFF);
				encender_LED(RED_ON);		// Rojo + Verde
				encender_LED(GREEN_ON);		// = Amarillo	- on
				break;

			default:
				apagar_LED(RED_OFF);
				apagar_LED(GREEN_OFF);
				contador_2 = 0;	// */*/ Reinicio de secuencia DESCENDENTE */*/ //
				contador = 0;
				break;
			} // end switch
		} // end while (sw3)

		while ( (arriba_sw2 == 0) && (abajo_sw3 == 0) ) { // Si se presionan el sw2 + el sw3...
			arriba_sw2 = GPIO_read_pin(GPIO_C, bit_6);	  // lee el sw2
			abajo_sw3  = GPIO_read_pin(GPIO_A, bit_4);	  // lee el sw3
			encender_LED(RED_ON);		// Rojo   		- on	|
			encender_LED(GREEN_ON);		// Green   		- on	 > = WHITE
			encender_LED(BLUE_ON);		// Blue   		- on	|
			delay(3000);
			contador   = 0;
			contador_2 = 0;
		} // end while (sw2 + sw3)

	} // end while (1)
    return 0 ;
} // end main
>>>>>>> fc8981d13db48f41244c9ad0fe35012ecc960fff
