#include <Arduino_LSM9DS1.h>
#include "SensorFusion.h"

SF fusion;

float gx, gy, gz, ax, ay, az, mx, my, mz;
float pitch, roll, yaw;
float deltat;

void setup() {
  Serial.begin(9600);
//  while (!Serial);
//  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

}

void loop() {
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(ax, ay, az);
  }
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gx, gy, gz);
    float gyroScale = 0.097656f / 4.5;
    gx = gx * gyroScale;
    gy = gy * gyroScale;
    gz = gz * gyroScale;
  }
  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(mx, my, mz);
  }

  deltat = fusion.deltatUpdate();
//  fusion.MahonyUpdate(gx, gy, gz, ax, ay, az, deltat);
  fusion.MadgwickUpdate(gx, gy, gz, ax, ay, az, mx, my, mz, deltat);

  pitch = fusion.getPitchRadians();
  yaw = fusion.getYawRadians();
  roll = fusion.getRollRadians();

  yaw = -yaw;

  Serial.print(pitch);
  Serial.print('\t');
  Serial.print(yaw);
  Serial.print('\t');
  Serial.println(roll);
}
