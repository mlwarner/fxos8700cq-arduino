#include <Wire.h>
#include <FXOS8700CQ.h>

FXOS8700CQ sensor = FXOS8700CQ(0x1F);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Initialize the FXOS8700CQ
  sensor.init();
}

void loop() {
  // Query the sensor
  sensor.readAccelData();
  sensor.readMagData();

  // Print out the data
  // Accelerometer
  Serial.print("Accel ");
  Serial.print("X: ");
  Serial.print((int)sensor.accelData.x);
  Serial.print(" Y: ");
  Serial.print((int)sensor.accelData.y);
  Serial.print(" Z: ");
  Serial.println((int)sensor.accelData.z);
  
  // Magnometer
  Serial.print("Mag ");
  Serial.print("X: ");
  Serial.print((int)sensor.magData.x);
  Serial.print(" Y: ");
  Serial.print((int)sensor.magData.y);
  Serial.print(" Z: ");
  Serial.println((int)sensor.magData.z);

  delay(100);
}
