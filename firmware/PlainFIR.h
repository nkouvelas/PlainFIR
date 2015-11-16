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


/* Custom constants */

/* Windowing type */
#define FIR_WIN_TYP_BARLETT 0x00
#define FIR_WIN_TYP_BLACKMAN 0x01
#define FIR_WIN_TYP_RECTANGLE 0x02 /* rectangle (Box car) */
#define FIR_WIN_TYP_HAMMING 0x03 /* hamming */
#define FIR_WIN_TYP_HANN 0x04 /* hann */

/*bands of frequerncies*/
#define FIR_FIL_TYP_LOW_PASS 0x00
#define FIR_FIL_TYP_HIG_PASS 0x01
#define FIR_FIL_TYP_BAN_PASS 0x02
#define FIR_FIL_TYP_BAN_STOP 0x03


class PlainFIR {
	public:

	/* Constructor */
	PlainFIR(void);
	/* Destructor */
	~PlainFIR(void);
	/* Functions */
double SetFilter(uint8_t filterType, uint16_t order, uint16_t samplingFrequency, uint8_t windowType, uint16_t transition1, uint16_t transition2);
};////itan void

#endif
