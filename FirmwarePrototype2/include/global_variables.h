#ifndef GLOBAL_VARIABLES_H_
#define GLOBAL_VARIABLES_H_

#include <l2hal_config.h>
#include <libhwjpeg.h>
#include <ff.h>

/**
 * SysTick driver context.
 */
L2HAL_SysTick_ContextStruct L2HAL_SysTick_Context = { 0 };

/**
 * QSPI bus handle.
 */
QSPI_HandleTypeDef QspiHandle = { 0 };

/**
 * QSPI DMA handle
 */
DMA_HandleTypeDef QspiDmaHandle = { 0 };

/**
 * pSRAM context
 */
L2HAL_LY68L6400_QSPI_ContextStruct RamContext = { 0 };

/**
 * Backlight timer handler
 */
TIM_HandleTypeDef BacklightTimerHandle = { 0 };

/**
 * SPI1 bus handle.
 */
SPI_HandleTypeDef Spi1Handle = { 0 };

/**
 * SPI1 TX DMA handle.
 */
DMA_HandleTypeDef Spi1TxDmaHandle = { 0 };

/**
 * SPI1 RX DMA handle.
 */
DMA_HandleTypeDef Spi1RxDmaHandle = { 0 };

/**
 * Display context
 */
L2HAL_GC9A01_LFB_ContextStruct DisplayContext;

/**
 * FMGL context.
 */
FMGL_API_DriverContext FmglContext;

/**
 * SDCARD context
 */
SD_HandleTypeDef SdcardHandle = { 0 };

/**
 * SD card filesystem pointer
 */
FATFS* SdFsPtr = NULL;

/**
 * JPEG codec handle
 */
JPEG_HandleTypeDef JpegCodecHandle = { 0 };

/**
 * JPEG codec DMA handle (in)
 */
DMA_HandleTypeDef JpegInDmaHandle = { 0 };

/**
 * JPEG codec DMA handle (out)
 */
DMA_HandleTypeDef JpegOutDmaHandle = { 0 };

#endif /* GLOBAL_VARIABLES_H_ */
