/*
Copyright (C) 2021 Franco Sauvisky
This file is part of CultiCon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#define ADMUX_DEFAULT 0

uint16_t
adc_get(uint8_t admux_chan)
{
  ADMUX = ADMUX_DEFAULT|admux_chan;
  ADCSRA |= _BV(ADSC); // start conversion
  loop_until_bit_is_set(ADCSRA, ADIF); // wait until complete
  ADCSRA |= _BV(ADIF); // clear adc interrupt flag
  return ADC;
}
