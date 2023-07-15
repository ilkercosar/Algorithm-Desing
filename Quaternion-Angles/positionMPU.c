#include "positionMPU.h"
#include <math.h>

/* İvmeden gelen roll, pitch açıları ilk önce alçak geçiren filtreye tabii tutuldu. */

/*

float roll(imuOut *imu, float gX, float dT, float aZ, float aY){

    aRoll = .8 * aRoll + .2 * (atan2(aY,aZ);

    imu->roll = .9 * (gX * dT) + .1 *aRoll * 57.2957795;
    return imu->roll;
}

float pitch(imuOut * imu, float gY, float dT, float aX, float aY, float aZ){

   aPitch = .8 * aPitch + .2 * (atan2(-aX, sqrt(aY*aY+aZ*aZ));

   imu->pitch = .9 * (gY * dT) + .1 * aPitch * 57.2957795;
   return imu->pitch;
}

float yaw(imuOut *imu, float mX, float mY, float mZ){

    imu->Mx = imu->mX * cos(imu->pitch) + imu->mZ * sin(imu->pitch);
    imu->My = imu->mX * sin(imu->roll) * sin(imu->pitch) + imu->mY * cos(imu->roll) - imu->mZ * sin(imu->roll) * cos(imu->pitch);
    imu->yaw = atan2(-imu->My, imu->Mx) * 57.2957795;
    return imu->yaw;
}

*/

imuOut getAngles(float mX, float mY, float mZ, 
                float gX, float gY, float gZ,
                float aX, float aY, float aZ, float dT){
    
    imuOut imu;

    aRoll = .8 * aRoll + .2 * (atan2(aY,aZ);
    aPitch = .8 * aPitch + .2 * (atan2(-aX, sqrt(aY*aY+aZ*aZ));
   
    imu.Mx = imu.mX * cos(imu.pitch) + imu.mZ * sin(imu.pitch);
    imu.My = imu.mX * sin(imu.roll) * sin(imu.pitch) + imu.mY * cos(imu.roll) - imu.mZ * sin(imu.roll) * cos(imu.pitch);
    
    imu.roll = .9 * (gX * dT) + .1 *aRoll * 57.2957795;   
    imu.pitch = .9 * (gY * dT) + .1 * aPitch * 57.2957795; 
    imu.yaw = atan2(-imu.My, imu.Mx) * 57.2957795;         

    return imu;
    
}

quaternation toQuaternation(float yaw, float pitch, float roll){

    quaternation q;

    float cy = cos(yaw * 0.5);
    float sy = sin(yaw * 0.5);
    float cp = cos(pitch * 0.5);
    float sp = sin(pitch * 0.5);
    float cr = cos(roll * 0.5);
    float sr = sin(roll * 0.5);

    q.w = cr * cp * cy + sr * sp * sy;
    q.x = sr * cp * cy - cr * sp * sy;
    q.y = cr * sp * cy + sr * cp * sy;
    q.z = cr * cp * sy - sr * sp * cy;

    return q;
}

