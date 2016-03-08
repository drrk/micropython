/*
 * Wrapper for Micro Python SPI functions for CC3100 Driver
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Kimball Johnson
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

 #include "cc_pal.h"

 #include <string.h>
 #include <stdarg.h>
 #include <errno.h>


 #include "py/nlr.h"
 #include "py/objtuple.h"
 #include "py/objlist.h"
 #include "py/stream.h"
 #include "py/runtime.h"
 #include "netutils.h"
 #include "modnetwork.h"
 #include "pin.h"
 #include "genhdr/pins.h"
 #include "spi.h"
 #include "pybioctl.h"
 #include "simplelink.h"

 Fd_t spi_Open(char* pIfName , unsigned long flags)
 {
   SPIHandle1.Init.Mode = SPI_MODE_MASTER;
   SPIHandle1.Init.CLKPolarity = SPI_POLARITY_HIGH;
   SPIHandle1.Init.CLKPhase = SPI_PHASE_2EDGE;
   SPIHandle1.Init.Direction = SPI_DIRECTION_2LINES;
   SPIHandle1.Init.DataSize = SPI_DATASIZE_8BIT;
   SPIHandle1.Init.NSS = SPI_NSS_SOFT;
   SPIHandle1.Init.FirstBit = SPI_FIRSTBIT_MSB;
   SPIHandle1.Init.TIMode = SPI_TIMODE_DISABLED;
   SPIHandle1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
   SPIHandle1.Init.CRCPolynomial = 0;
   // init the SPI bus
   spi_init(&SPIHandle1, true);
   return 1;
 }

 int spi_Close(Fd_t Fd)
 {
   spi_deinit(&SPIHandle1);
   return 0;
 }

 int spi_Read(Fd_t Fd , unsigned char* pBuff , int Len)
 {
   return 0;
 }

 int spi_Write(Fd_t Fd , unsigned char* pBuff , int Len){
   return 0;
 }

 void NwpPowerOnPreamble(void){}
 void NwpPowerOn(void){}
 void NwpPowerOff(void){}
 int NwpRegisterInterruptHandler(SL_P_EVENT_HANDLER InterruptHdl , void* pValue){return 0;}
 void NwpMaskInterrupt(){}
 void NwpUnMaskInterrupt(){}
