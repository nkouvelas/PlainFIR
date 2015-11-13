/*

	FFT libray
	Copyright (C) 2010 Didier Longueville

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
*/

#ifndef PlainFIR_h /* Prevent loading library twice */
#define PlainFIR_h
#include "application.h"
#include <math.h>

#define FIR_LIB_REV 0x02
/* Custom constants */
#define FIR_FORWARD 0x01
#define FIR_REVERSE 0x00
/* Windowing type */
#define FIR_WIN_TYP_RECTANGLE 0x00 /* rectangle (Box car) */
#define FIR_WIN_TYP_HAMMING 0x01 /* hamming */
#define FIR_WIN_TYP_HANN 0x02 /* hann */
#define FIR_WIN_TYP_TRIANGLE 0x03 /* triangle (Bartlett) */
#define FIR_WIN_TYP_BLACKMAN 0x04 /* blackmann */
#define FIR_WIN_TYP_FLT_TOP 0x05 /* flat top */
#define FIR_WIN_TYP_WELCH 0x06 /* welch */
/*bands of frequerncies*/
#define FIR_FIL_TYP_LOW_PASS
#define FIR_FIL_TYP_HIG_PASS
#define FIR_FIL_TYP_BAN_PASS
#define FIR_FIL_TYP_BAN_STOP


class PlainFIR {
	public:

	/* Constructor */
	PlainFIR(void);
	/* Destructor */
	~PlainFIR(void);
	/* Functions */
void SetFilter(uint8_t filterType, uint16_t order, uint16_t samplingFrequency, uint8_t windowType, uint16_t transition1, uint16_t transition2);
};

#endif
