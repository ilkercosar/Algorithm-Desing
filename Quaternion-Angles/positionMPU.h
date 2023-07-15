#ifndef positionMPU_
#define positionMPU_

/*

1- kalibrasyon yapılacak
2- roll pitch ve yaw değerleri çıkartılacak
3- filtre eklenecek
4- quaternation açıları hesaplanacak

- GYRO için Euler 
Roll = gX * dT
Pitch = gY * dT
Yaw = gZ * dT

" theta(0) is pitch, psi(y) is roll, and phi(0 ama baştan sona çizgi var) is yaw.
pitch = +- 90
roll = +-180
yaw = 0-360

- İvme Sensörü ve Magnometre için Euler
Roll = atan2(aY,aZ) * 57.2957795
Pitch = atan2(-aX,sqrt(aY*aY+aZ*aZ)) * 57.2957795

Mx = mX * cos(pitch) + mZ * sin(pitch)
My = mX * sin(roll) * sin(pitch) + mY * cos(roll) - mZ * sin(roll) * cos(pitch)

Yaw = atan2(-My,Mx) * 57.2957795

*/

typedef struct{

float roll;
float pitch;
float yaw;

float Mx;
float My;

float mX;
float mY;
float mZ;

}imuOut;

union imuout *aRoll = 0;
union imuout *aPitch = 0; 

typedef struct{
    float w;
    float x;
    float y;
    float z;
}quaternation;


/* Fonksiyonların Prototipi */

quaternation toQuaternation( float yaw, float pitch, float roll);
imuOut getAngles(float mX, float mY, float mZ, 
                float gX, float gY, float gZ,
                float aX, float aY, float aZ, float dT);
/*
float yaw(imuOut *imu, float mX, float mY, float mZ);
float pitch(imuOut * imu, float gY, float dT, float aX, float aY, float aZ);
float roll(imuOut *imu, float gX, float dT, float aZ, float aY);
*/
#endif