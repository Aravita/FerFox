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

#ifndef INCLUDE_GLOBALVARIABLES_H_
#define INCLUDE_GLOBALVARIABLES_H_

#include <l2hal_systick.h>
#include <l2hal_gc9a01.h>
#include <l2hal_sdcard.h>
#include <l2hal_ly68l6400.h>
#include <l2hal_crc.h>
#include <fmgl.h>
#include <ffconf.h>
#include <ff.h>
#include <stddef.h>
#include <pngle.h>

/**
 * Number of drawing cycles before inverting font.
 */
#define FONT_BLINKING_INTERVAL 1U

/**
 * SysTick driver context.
 */
L2HAL_SysTick_ContextStruct L2HAL_SysTick_Context = { 0 };



/**
 * SPI1 bus handle.
 */
SPI_HandleTypeDef SPI1Handle = { 0 };

/**
 * SPI1 TX DMA handle.
 */
DMA_HandleTypeDef SPI1TxDmaHandle = { 0 };

/**
 * SPI1 RX DMA handle.
 */
DMA_HandleTypeDef SPI1RxDmaHandle = { 0 };



/**
 * SPI2 bus handle.
 */
SPI_HandleTypeDef SPI2Handle = { 0 };

/**
 * SPI2 TX DMA handle.
 */
DMA_HandleTypeDef SPI2TxDmaHandle = { 0 };

/**
 * SPI2 RX DMA handle.
 */
DMA_HandleTypeDef SPI2RxDmaHandle = { 0 };



/**
 * Backlight timer handler
 */
TIM_HandleTypeDef BacklightTimerHandle = { 0 };

/**
 * Display context
 */
L2HAL_GC9A01_ContextStruct DisplayContext;

/**
 * FMGL context.
 */
FMGL_API_DriverContext FmglContext;


/**
 * SD-card context
 */
L2HAL_SDCard_ContextStruct SDCardContext;


/**
 * pSRAM context
 */
L2HAL_LY68L6400_ContextStruct RamContext;

/**
 * CRC calculator context
 */
L2HAL_CRCContextStruct CRC_Context;

/**
 * SD card filesystem pointer
 */
FATFS* SDCardFsPtr = NULL;

/**
 * PNGLE library context
 */
pngle_t* PngleContext = NULL;


#endif /* INCLUDE_GLOBALVARIABLES_H_ */
