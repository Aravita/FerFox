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

/**
 * @file
 * @biref File for custom hardware-related stuff.
 */

#ifndef L2HAL_INCLUDE_L2HAL_CUSTOM_H_
#define L2HAL_INCLUDE_L2HAL_CUSTOM_H_

#include <l2hal_mcu.h>
#include <l2hal_errors.h>
#include <l2hal_gc9a01.h>
#include <l2hal_sdcard.h>
#include <l2hal_ly68l6400.h>

extern SPI_HandleTypeDef SPI1Handle;
extern DMA_HandleTypeDef SPI1TxDmaHandle;
extern DMA_HandleTypeDef SPI1RxDmaHandle;
extern SPI_HandleTypeDef SPI2Handle;
extern DMA_HandleTypeDef SPI2TxDmaHandle;
extern DMA_HandleTypeDef SPI2RxDmaHandle;
extern L2HAL_GC9A01_ContextStruct DisplayContext;
extern L2HAL_SDCard_ContextStruct SDCardContext;
extern L2HAL_LY68L6400_ContextStruct RamContext;

extern TIM_HandleTypeDef BacklightTimerHandle;

/**
 * Put custom hardware initialization stuff here,
 */
void L2HAL_InitCustomHardware(void);

/**
 * SPI-related stuff
 */
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi);
void L2HAL_SetupSPI(void);
void L2HAL_DisplayDmaCompleted(DMA_HandleTypeDef *hdma); /* Called when transmission via Display SPI is completed */
void L2HAL_SDCardDmaCompleted(DMA_HandleTypeDef *hdma); /* Called when transmission via SDCard SPI is completed */
void L2HAL_PSRAMDmaCompleted(DMA_HandleTypeDef *hdma); /* Called when transmission via PSRAM SPI is completed */

/**
 * PWM timer-related stuff
 */
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim);
void L2HAL_SetupBacklighTimer(void);

/**
 * CRC calculator init and de-init
 */
volatile void HAL_CRC_MspInit(CRC_HandleTypeDef *hcrc);
volatile void HAL_CRC_MspDeInit(CRC_HandleTypeDef *hcrc);

#endif /* L2HAL_INCLUDE_L2HAL_CUSTOM_H_ */
