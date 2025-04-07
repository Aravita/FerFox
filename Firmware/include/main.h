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

#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

#include <stdbool.h>
#include <GlobalVariables.h>
#include <fmgl.h>
#include <pngle.h>
#include <Filesystem.h>
#include <stdio.h>

#define FRAMES_COUNT 16

uint16_t fpsCounter;
uint16_t fpsHandlerCounter;
uint16_t fps;
char fpsMessageBuffer[32];

FMGL_API_FontSettings font;

uint32_t framebuffersAddresses[FRAMES_COUNT];

/**
 * Called by PNGLE to draw next pixel
 */
void PngleOnDraw(pngle_t *pngle, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint8_t rgba[4]);

/**
 * FPS SysTick handler, used to calculate FPS
 */
void FpsHandler(void);

#endif /* INCLUDE_MAIN_H_ */
