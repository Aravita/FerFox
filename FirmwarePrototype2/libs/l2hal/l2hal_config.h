/*
	This file is part of Aravita's STM32 level 2 HAL.

	STM32 level 2 HAL is free software: you can redistribute it and/or modify
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

	Repository: https://github.com/Aravita/stm32-l2hal

	-------------------------------------------------------------------------
 */

#ifndef L2HAL_L2HAL_CONFIG_H_
#define L2HAL_L2HAL_CONFIG_H_


/* Required */
#include "include/l2hal.h"
#include "include/l2hal_aux.h"

/* Drivers */
#include "drivers/input/buttons/include/l2hal_buttons_defaults.h"
#include "drivers/display/gc9a01_local_framebuffer/include/l2hal_gc9a01_lfb.h"
#include "drivers/internal/crc/include/l2hal_crc.h"
#include "drivers/ram/ly68l6400_qspi/include/l2hal_ly68l6400_qspi.h"


#endif /* L2HAL_L2HAL_CONFIG_H_ */
