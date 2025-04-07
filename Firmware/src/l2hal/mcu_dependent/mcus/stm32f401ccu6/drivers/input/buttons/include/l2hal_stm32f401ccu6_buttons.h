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

#ifndef L2HAL_MCU_DEPENDENT_MCUS_STM32F401CCU6_DRIVERS_INPUT_BUTTONS_INCLUDE_L2HAL_STM32F401CCU6_BUTTONS_H_
#define L2HAL_MCU_DEPENDENT_MCUS_STM32F401CCU6_DRIVERS_INPUT_BUTTONS_INCLUDE_L2HAL_STM32F401CCU6_BUTTONS_H_


#include <l2hal_buttons_defaults.h>
#include <l2hal_errors.h>

/**
 * Default pin initializer for buttons driver. Clocking port in, setting pin as input and enabling pull-up for it.
 * @port port Pins belongs to this port.
 * @port pins Pins to initialize.
 */
void L2HAL_Buttons_DefaultPinInitializer(GPIO_TypeDef* port, uint32_t pins);


#endif /* L2HAL_MCU_DEPENDENT_MCUS_STM32F401CCU6_DRIVERS_INPUT_BUTTONS_INCLUDE_L2HAL_STM32F401CCU6_BUTTONS_H_ */
