#include "Arduino_LSM9DS1.h"
#include "SensorFusion.h"

SF fusion;

float gx, gy, gz, ax, ay, az, mx, my, mz;
float pitch, roll, yaw;
float deltat;

void setup() {
  Serial.begin(9600);
  Serial.println("Started");
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  IMU.setAccelFS(2);
  IMU.setAccelODR(5);
  IMU.setAccelOffset(-0.019423, -0.012760, -0.007454);
  IMU.setAccelSlope (1.002830, 0.999749, 1.008102);

  IMU.setGyroFS(3);
  IMU.setGyroODR(4);
  IMU.setGyroOffset (-1.489929, -0.464600, 0.043884);
  IMU.setGyroSlope (1.166259, 1.144730, 1.149710);

  IMU.setMagnetFS(0);
  IMU.setMagnetODR(8);
  IMU.setMagnetOffset(-4.042358, 41.287231, -16.781616);
  IMU.setMagnetSlope (1.886174, 1.278351, 1.254920);

}


void loop() {
  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable() && IMU.magneticFieldAvailable()) {
    IMU.readAcceleration(ax, ay, az);
    IMU.readGyro(gx, gy, gz);
    IMU.readMagneticField(mx, my, mz);

    gx *= DEG_TO_RAD;
    gy *= DEG_TO_RAD;
    gz *= DEG_TO_RAD;
    
    deltat = fusion.deltatUpdate();

    fusion.MadgwickUpdate(gx, gy, gz, ax, ay, az, mx, my, mz, deltat);

    roll = fusion.getRollRadians();
    pitch = fusion.getPitchRadians();
    yaw = fusion.getYawRadians();

    Serial.print(roll);
    Serial.print("\t");
    Serial.print(pitch);
    Serial.print("\t");
    Serial.println(yaw);
  }
}
