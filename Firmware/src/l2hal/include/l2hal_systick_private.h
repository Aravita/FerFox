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
 * @brief Level 2 HAL SysTick handler (private stuff).
 */

#ifndef L2HAL_INCLUDE_L2HAL_SYSTICK_PRIVATE_H_
#define L2HAL_INCLUDE_L2HAL_SYSTICK_PRIVATE_H_

#include <l2hal_errors.h>
#include <l2hal_systick.h>
#include <stdlib.h>

/**
 * Maximal possible count of SysTick handlers
 */
#define L2HAL_SYSTICK_MAX_HANDLERS 16U

/**
 * Call it to initialize SysTick driver. Place it into void L2HAL_Init(void) after clocks initialization.
 */
void L2HAL_SysTick_Init(void);

#endif /* L2HAL_INCLUDE_L2HAL_SYSTICK_PRIVATE_H_ */
