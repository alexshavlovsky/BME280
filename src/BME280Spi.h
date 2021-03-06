/*
BME280Spi.h
This code records data from the BME280 sensor and provides an API.
This file is part of the Arduino BME280 library.
Copyright (C) 2016  Tyler Glenn

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

Written: Dec 18 2016. - Happy Holidays!
Last Updated: Dec 18 2016. - Happy Holidays!

This code is licensed under the GNU LGPL and is open for ditrbution
and copying in accordance with the license.
This header must be included in any derived code or copies of the code.

Based on the data sheet provided by Bosch for the Bme280 environmental sensor.
 */

#ifndef TG_BME_280_SPI_H
#define TG_BME_280_SPI_H

#include "BME280.h"


class BME280Spi: public BME280
{
public:

  ////////////////////////////////////////////////////////////////
  /// Constructor used to create the class. All parameters have
  /// default values.
  BME280Spi(
    uint8_t spiCsPin, 
    uint8_t tosr = 0x1, 
    uint8_t hosr = 0x1, 
    uint8_t posr = 0x1, 
    uint8_t mode = 0x1,
    uint8_t st = 0x5, 
    uint8_t filter = 0x0);  // Oversampling = 1, mode = forced, standby time = 1000ms, filter = none.

protected:

  ////////////////////////////////////////////////////////////////
  /// Method used at start up to initialize the class. Starts the
  /// I2C interface.
  virtual bool Initialize();

private:

  static const uint8_t BME280_SPI_WRITE  = 0x7F;
  static const uint8_t BME280_SPI_READ   = 0x80;

  uint8_t csPin;

  ////////////////////////////////////////////////////////////////
  /// Read the data from the BME280 addr into an array and
  /// return true if successful.
  virtual bool ReadRegister(
    uint8_t addr,
    uint8_t array[],
    uint8_t len);

  ////////////////////////////////////////////////////////////////
  /// Write values to BME280 registers.
  virtual bool WriteRegister(
    uint8_t addr,
    uint8_t data);

};
#endif // TG_BME_280_SPI_H
