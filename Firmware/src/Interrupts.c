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

#include <Interrupts.h>


void SysTick_Handler(void)
{
	HAL_IncTick();
	L2HAL_SysTick_Callback();
}

/* SPI2 DMA TX complete */
void DMA1_Stream4_IRQHandler(void)
{
	HAL_DMA_IRQHandler(SPI2Handle.hdmatx);

	L2HAL_PSRAMDmaCompleted(SPI2Handle.hdmatx);
	L2HAL_DisplayDmaCompleted(SPI2Handle.hdmatx);
}

/* SPI2 DMA RX complete */
void DMA1_Stream3_IRQHandler(void)
{
	HAL_DMA_IRQHandler(SPI2Handle.hdmarx);

	L2HAL_PSRAMDmaCompleted(SPI2Handle.hdmarx);
}

/* SPI1 DMA TX complete */
void DMA2_Stream3_IRQHandler(void)
{
	HAL_DMA_IRQHandler(SPI1Handle.hdmatx);

	L2HAL_SDCardDmaCompleted(SPI1Handle.hdmatx);
}

/* SPI1 DMA RX complete */
void DMA2_Stream2_IRQHandler(void)
{
	HAL_DMA_IRQHandler(SPI1Handle.hdmarx);

	L2HAL_SDCardDmaCompleted(SPI1Handle.hdmarx);
}

