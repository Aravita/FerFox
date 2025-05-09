/*
	This file is part of Aravita's FerFox.

	FerFox is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

	-------------------------------------------------------------------------

	Created by Aravita Cor

	Feel free to contact: aravita_cor@proton.me

	Repository: https://github.com/Aravita/FerFox

	-------------------------------------------------------------------------
 */

#ifndef INCLUDE_HAL_H_
#define INCLUDE_HAL_H_

#include <l2hal_mcu.h>
#include <stdbool.h>
#include <l2hal.h>
#include <Interrupts.h>

/***************
 * PORT C pins *
 ***************/

/**
 * LED pin
 */
#define HAL_LED_PIN GPIO_PIN_13
#define HAL_LED_PORT GPIOC


/**
 * Backlight
 */

/**
 * Use this timer for backlight control
 */
#define HAL_DISPLAY_BACKLIGHT_TIMER TIM2

/**
 * Call this for clocking backlight timer in
 */
#define HAL_DISPLAY_BACKLIGHT_TIMER_CLOCK_IN __HAL_RCC_TIM2_CLK_ENABLE

/**
 * Display backlight timer frequency
 */
#define HAL_DISPLAY_BACKLIGHT_TIMER_FREQ 16000000

/**
 * Display backlight timer period. PWM Frequency is HAL_DISPLAY_BACKLIGHT_TIMER_FREQ / HAL_DISPLAY_BACKLIGHT_TIMER_PERIOD,
 * in our case 16000000 / 500 = 32 kHz
 */
#define HAL_DISPLAY_BACKLIGHT_TIMER_PERIOD 500

/**
 * Generage backlight PWM on this channel
 */
#define HAL_DISPLAY_BACKLIGHT_TIMER_CHANNEL TIM_CHANNEL_2

/**
 * Backlight connected to this port (keep synchronized with timer and channel)
 */
#define HAL_DISPLAY_BACKLIGHT_TIMER_PORT GPIOB

/**
 * Backlight connected to this pin (keep synchronized with timer and channel)
 */
#define HAL_DISPLAY_BACKLIGHT_TIMER_PIN GPIO_PIN_3

/**
 * Alternative function for backlight pin  (keep synchronized with timer)
 */
#define HAL_DISPLAY_BACKLIGHT_TIMER_PIN_AF GPIO_AF1_TIM2


/**********************
 * DISPLAY - GC9A01 *
 *
 *  SPI 1
 *  PB0 - RESET (Active 0)
 *  PB1 - D/C (1 - data, 0 - command)
 *  PB2 - CS (Active 0)
 *  PB3 - Backlight (Active 1)
 *
 **********************/

#define HAL_DISPLAY_RESET_PIN GPIO_PIN_0
#define HAL_DISPLAY_RESET_PORT GPIOB

#define HAL_DISPLAY_DC_PIN GPIO_PIN_1
#define HAL_DISPLAY_DC_PORT GPIOB

#define HAL_DISPLAY_CS_PIN GPIO_PIN_2
#define HAL_DISPLAY_CS_PORT GPIOB


/**********************
 *  SD CARD *
 *
 *  SPI 1
 *  PB4 - CS (Active 0)
 *
 **********************/

#define HAL_SDCARD_CS_PIN GPIO_PIN_4
#define HAL_SDCARD_CS_PORT GPIOB


/**********************
 *  pSRAM - LY68L6400 *
 *
 *  SPI 2
 *  PB5 - CS (Active 0)
 *
 **********************/
#define HAL_PSRAM_CS_PIN GPIO_PIN_5
#define HAL_PSRAM_CS_PORT GPIOB


/**
 * Init project-specific hardware here
 */
void HAL_IntiHardware(void);

/**
 * Switch LED on of off
 */
void HAL_SwitchLed(bool isOn);

/**
 * Set backlight level [0-HAL_DISPLAY_BACKLIGHT_TIMER_PERIOD]
 */
void HAL_SetBacklightLevel(uint16_t level);


#endif /* INCLUDE_HAL_H_ */
