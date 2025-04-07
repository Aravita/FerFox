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

#ifndef INCLUDE_FILESYSTEM_H_
#define INCLUDE_FILESYSTEM_H_

#include <ffconf.h>
#include <ff.h>
#include <stdbool.h>
#include <stddef.h>
#include <pngle.h>
#include <tjpgdcnf.h>
#include <tjpgd.h>
#include <fmgl.h>


/**
 * Structure with information on JPEG decoding session
 */
typedef struct
{
	FIL* FilePtr; /* We read JPEG from this file */
}
JpegDecoderSessionStruct;

/**
 * Buffer size for PNG files load
 */
#define PNG_LOAD_BUFFER_SIZE 512

/**
 * Internal buffer size for JPEG decoder
 */
#define JPEG_WORKSPACE_SIZE 3092

extern FATFS* SDCardFsPtr;
extern pngle_t* PngleContext;
extern FMGL_API_DriverContext FmglContext;

/**
 * Attempt to mount SD-card filesystem
 * @return True if mount successful, false otherwise
 */
bool MountSDCardFS(void);

/**
 * Unmount previously-mounted SD-card filesystem. Do nothing in case if not mounted
 */
void UnmountSDCardFS(void);

/**
 * Load PNG file from given path
 * @param path File path on SD-card
 */
void LoadPngFromFile(const char* path);

/**
 * Function, reading JPEG-data from file
 * @param jdec JPEG decoder object
 * @param buff Buffer to store data here
 * @param ndata How much bytes we need to store
 * @return How much bytes were read
 */
size_t JpegInputFunction(JDEC* jdec, uint8_t* buff, size_t ndata);

/**
 * Function to write JPEG pixels to framebuffer
 * @param jdec JPEG decoder object
 * @param bitmap Pixels to write
 * @param rect Rectangle within image with bitmap
 * @return 1 to continue, 0 to abort
 */
int JpegOutputFunction (JDEC* jdec, void* bitmap, JRECT* rect);

/**
 * Load JPEG file from given path
 * @param path File path on SD-card
 */
void LoadJpegFromFile(const char* path);

#endif /* INCLUDE_FILESYSTEM_H_ */
