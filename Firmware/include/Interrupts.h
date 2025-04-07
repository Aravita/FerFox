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

#ifndef INCLUDE_INTERRUPTS_H_
#define INCLUDE_INTERRUPTS_H_

#include <l2hal.h>

/**
 * SysTick interrupt handler.
 */
volatile void SysTick_Handler(void);

/**
 * DMA transfer to SPI1 complete
 */
volatile void DMA1_Stream4_IRQHandler(void);

/**
 * DMA transfer from SPI1 complete
 */
volatile void DMA1_Stream3_IRQHandler(void);



#endif /* INCLUDE_INTERRUPTS_H_ */
