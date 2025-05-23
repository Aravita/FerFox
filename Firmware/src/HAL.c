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

#include <HAL.h>


void HAL_IntiHardware(void)
{
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct;

	/* LED */
	GPIO_InitStruct.Pin = HAL_LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(HAL_LED_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(HAL_LED_PORT, HAL_LED_PIN, GPIO_PIN_SET);

	/* Initializing display pins */
	/* Reset */
	L2HAL_MCU_ClockPortIn(HAL_DISPLAY_RESET_PORT);
	GPIO_InitStruct.Pin = HAL_DISPLAY_RESET_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(HAL_DISPLAY_RESET_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(HAL_DISPLAY_RESET_PORT, HAL_DISPLAY_RESET_PIN, GPIO_PIN_RESET); /* Keep display resetted till driver will take control */

	/* D/C */
	L2HAL_MCU_ClockPortIn(HAL_DISPLAY_DC_PORT);
	GPIO_InitStruct.Pin = HAL_DISPLAY_DC_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(HAL_DISPLAY_DC_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(HAL_DISPLAY_DC_PORT, HAL_DISPLAY_DC_PIN, GPIO_PIN_RESET); /* 0 - Command mode */

	/* C/S */
	L2HAL_MCU_ClockPortIn(HAL_DISPLAY_CS_PORT);
	GPIO_InitStruct.Pin = HAL_DISPLAY_CS_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(HAL_DISPLAY_CS_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(HAL_DISPLAY_CS_PORT, HAL_DISPLAY_CS_PIN, GPIO_PIN_SET); /* 1 - Not selected */

	/* Initializing SD-card pins */
	/* C/S */
	L2HAL_MCU_ClockPortIn(HAL_SDCARD_CS_PORT);
	GPIO_InitStruct.Pin = HAL_SDCARD_CS_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(HAL_SDCARD_CS_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(HAL_SDCARD_CS_PORT, HAL_SDCARD_CS_PIN, GPIO_PIN_SET); /* 1 - Not selected */

	/* Initializing pSRAM pins */
	/* C/S */
	L2HAL_MCU_ClockPortIn(HAL_PSRAM_CS_PORT);
	GPIO_InitStruct.Pin = HAL_PSRAM_CS_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(HAL_PSRAM_CS_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(HAL_PSRAM_CS_PORT, HAL_PSRAM_CS_PIN, GPIO_PIN_SET); /* 1 - Not selected */
}


void HAL_SwitchLed(bool isOn)
{
	if (isOn)
	{
		HAL_GPIO_WritePin(HAL_LED_PORT, HAL_LED_PIN, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(HAL_LED_PORT, HAL_LED_PIN, GPIO_PIN_SET);
	}
}

void HAL_SetBacklightLevel(uint16_t level)
{
	if (level > HAL_DISPLAY_BACKLIGHT_TIMER_PERIOD)
	{
		level = HAL_DISPLAY_BACKLIGHT_TIMER_PERIOD;
	}

	TIM_OC_InitTypeDef sConfig = { 0 };
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_DISABLE;
	sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfig.Pulse = level;

	if (HAL_OK != HAL_TIM_PWM_ConfigChannel(&BacklightTimerHandle, &sConfig, HAL_DISPLAY_BACKLIGHT_TIMER_CHANNEL))
	{
		L2HAL_Error(Generic);
	}

	/* Start channel 2 */
	if (HAL_OK != HAL_TIM_PWM_Start(&BacklightTimerHandle, HAL_DISPLAY_BACKLIGHT_TIMER_CHANNEL))
	{
		L2HAL_Error(Generic);
	}
}

