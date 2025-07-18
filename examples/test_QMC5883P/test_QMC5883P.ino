/*
 * QMC5883P Test Sketch
 * 
 * Basic test for the QMC5883P 3-axis magnetometer
 */

#include <Adafruit_QMC5883P.h>

Adafruit_QMC5883P qmc;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  
  Serial.println("QMC5883P Test");
  
  if (!qmc.begin()) {
    Serial.println("Failed to find QMC5883P chip");
    while (1) delay(10);
  }
  
  Serial.println("QMC5883P Found!");
}

void loop() {
  delay(1000);
}