/*!
 * @file Adafruit_QMC5883P.h
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
 * Written by ladyada for Adafruit Industries.
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */

#ifndef _ADAFRUIT_QMC5883P_H_
#define _ADAFRUIT_QMC5883P_H_

#include "Arduino.h"
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>

/*=========================================================================
    I2C ADDRESS/BITS
    -----------------------------------------------------------------------*/
#define QMC5883P_DEFAULT_ADDR 0x2C ///< Default I2C address
/*=========================================================================*/

/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
#define QMC5883P_REG_CHIPID 0x00     ///< Chip ID register
#define QMC5883P_REG_XOUT_LSB 0x01   ///< X-axis output LSB register
#define QMC5883P_REG_XOUT_MSB 0x02   ///< X-axis output MSB register
#define QMC5883P_REG_YOUT_LSB 0x03   ///< Y-axis output LSB register
#define QMC5883P_REG_YOUT_MSB 0x04   ///< Y-axis output MSB register
#define QMC5883P_REG_ZOUT_LSB 0x05   ///< Z-axis output LSB register
#define QMC5883P_REG_ZOUT_MSB 0x06   ///< Z-axis output MSB register
#define QMC5883P_REG_STATUS 0x09     ///< Status register
#define QMC5883P_REG_CONTROL1 0x0A   ///< Control register 1
#define QMC5883P_REG_CONTROL2 0x0B   ///< Control register 2
/*=========================================================================*/

/*!
 * @brief Class for hardware interfacing with the QMC5883P 3-axis magnetometer
 */
class Adafruit_QMC5883P {
public:
  Adafruit_QMC5883P(void);
  ~Adafruit_QMC5883P(void);

  bool begin(uint8_t i2c_addr = QMC5883P_DEFAULT_ADDR, TwoWire *wire = &Wire);

private:
  Adafruit_I2CDevice *i2c_dev; ///< Pointer to I2C bus interface
};

#endif