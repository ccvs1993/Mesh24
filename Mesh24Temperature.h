/*
This file is part of mesh24.
Copyright (C) 2014 Miklos Lengyel (j7only@gmail.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _MESH24_TEMPERATURE_
#define _MESH24_TEMPERATURE_

#include <Arduino.h>

class Mesh24TemperatureClass {
  public:
    word read() {
      ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
      ADCSRA |= _BV(ADEN);
      delay(1);
      ADCSRA |= _BV(ADSC);
      while (bit_is_set(ADCSRA, ADSC)) {
        // do nothing
      }
      return ADCW;
    }
};

Mesh24TemperatureClass Mesh24Temperature;

#endif
