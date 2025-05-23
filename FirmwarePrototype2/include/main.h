#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "diag/trace.h"

#include <hal.h>
#include <global_variables.h>

#include <l2hal_config.h>

#include <filesystem.h>
#include <jpeg_decoder.h>

#include <libhwjpeg.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240

#define FRAMES_COUNT 16

FMGL_API_FontSettings font;

uint32_t mainTickHandlerCounter;

uint32_t framebuffersAddresses[FRAMES_COUNT];

/*uint16_t fpsCounter;
char fpsMessage[32];*/

void MainTickHandler(void);

#endif /* INCLUDE_MAIN_H_ */
