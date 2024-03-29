/*
 * RGB.h
 *
 *  Created on: 10 sep 2019
<<<<<<< HEAD
 *      Author: Ricardo Pacas
=======
 *      Author: pacas
>>>>>>> 45429a7189ceb0347e7331ffec247f81757327da
 */

#ifndef RGB_H_
#define RGB_H_

#include "stdint.h"

<<<<<<< HEAD
#define SET_RED_ON	  0x00400000;
#define SET_GREEN_ON  0x04000000;
#define SET_BLUE_ON   0x00200000;

#define SET_RED_OFF   0x00400000;
#define SET_GREEN_OFF 0x04000000;
#define SET_BLUE_OFF  0x00200000;

typedef enum {
	RED_ON,
	GREEN_ON,
	BLUE_ON,
} color_ON;

typedef enum {
	RED_OFF,
	GREEN_OFF,
	BLUE_OFF,
} color_OFF;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function clears all interrupts that were sensed by the GPIO.

 	 \param[in]  port_name Port to clear interrupts.
 	 \return void
 	 \todo Implement a mechanism to clear interrupts by a specific pin.
 */
uint8_t encender_LED(color_ON color_encendido);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function clears all interrupts that were sensed by the GPIO.

 	 \param[in]  port_name Port to clear interrupts.
 	 \return void
 	 \todo Implement a mechanism to clear interrupts by a specific pin.
 */
uint8_t apagar_LED(color_OFF color_apagar);


=======
/*Constante que representa la habilitacion del clock GPIOA*/
//#define SET_RED_ON 0x00400000;
//#define SET_GREEN_ON 0x4000000;
//#define SET_BLUE_ON 0x00200000;

//#define SET_RED_OFF 0x00400000;
//#define SET_GREEN_OFF 0x4000000;
//#define SET_BLUE_OFF 0x00200000;



typedef enum{RED_ON, /*!< Definition to select GPIO A */
			 GREEN_ON, /*!< Definition to select GPIO B */
			 BLUE_ON, /*!< Definition to select GPIO C */
			} color_ON;
typedef enum{RED_OFF, /*!< Definition to select GPIO A */
			 GREEN_OFF, /*!< Definition to select GPIO B */
			 BLUE_OFF, /*!< Definition to select GPIO C */
			} color_OFF;

			uint8_t encender_LED(color_ON color_encendido);
			uint8_t apagar_LED(color_OFF color_apagar);

>>>>>>> 45429a7189ceb0347e7331ffec247f81757327da
#endif /* RGB_H_ */
