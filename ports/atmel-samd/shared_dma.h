/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_ATMEL_SAMD_SHARED_DMA_H
#define MICROPY_INCLUDED_ATMEL_SAMD_SHARED_DMA_H

#include <stdbool.h>
#include <stdint.h>

#include "include/sam.h"

volatile bool audio_dma_in_use;

void init_shared_dma(void);

#ifdef SAMD51
int32_t qspi_dma_write(uint32_t address, const uint8_t* buffer, uint32_t length);
int32_t qspi_dma_read(uint32_t address, uint8_t* buffer, uint32_t length);
#endif

int32_t sercom_dma_write(Sercom* sercom, const uint8_t* buffer, uint32_t length);
int32_t sercom_dma_read(Sercom* sercom, uint8_t* buffer, uint32_t length, uint8_t tx);
int32_t sercom_dma_transfer(Sercom* sercom, const uint8_t* buffer_out, uint8_t* buffer_in, uint32_t length);

// Allocate a counter to track how far along we are in a DMA double buffer.
bool allocate_block_counter(void);
void switch_audiodma_trigger(uint8_t trigger_dmac_id);

#endif  // MICROPY_INCLUDED_ATMEL_SAMD_SHARED_DMA_H
