/*!
 * @file Adafruit_QMC5883P.cpp
 *
 * @mainpage Adafruit QMC5883P 3-axis magnetometer library
 *
 * @section intro_sec Introduction
 *
 * This is a library for the QMC5883P 3-axis magnetometer
 *
 * These sensors use I2C to communicate, 2 pins (SCL+SDA) are required
 * to interface with the breakout.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * @section author Author
 *
 * Written by ladyada for Adafruit Industries.
 *
 * @section license License
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */

#include "Adafruit_QMC5883P.h"

/*!
 *  @brief  Instantiates a new QMC5883P class
 */
Adafruit_QMC5883P::Adafruit_QMC5883P(void) { i2c_dev = NULL; }

/*!
 *  @brief  Cleans up the QMC5883P
 */
Adafruit_QMC5883P::~Adafruit_QMC5883P(void) {
  if (i2c_dev) {
    delete i2c_dev;
  }
}

/*!
 *  @brief  Sets up the hardware and initializes I2C
 *  @param  i2c_addr
 *          The I2C address to be used.
 *  @param  wire
 *          The Wire object to be used for I2C connections.
 *  @return True if initialization was successful, otherwise false.
 */
bool Adafruit_QMC5883P::begin(uint8_t i2c_addr, TwoWire *wire) {
  if (i2c_dev) {
    delete i2c_dev;
  }

  i2c_dev = new Adafruit_I2CDevice(i2c_addr, wire);

  if (!i2c_dev->begin()) {
    return false;
  }

  // Check chip ID
  Adafruit_BusIO_Register chip_id_reg = Adafruit_BusIO_Register(i2c_dev, QMC5883P_REG_CHIPID);
  uint8_t chip_id = chip_id_reg.read();
  if (chip_id != 0x80) {
    return false;
  }

  return true;
}