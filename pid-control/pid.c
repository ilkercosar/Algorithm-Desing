#include "pid.h"

static pidController pid; 

void pid_init(void){
    pid.error = 0;
    pid.input = 0;
    pid.Kd = 0;
    pid.Ki = 0;
    pid.Kp = 0;
    pid.output = 0;
    pid.integral = 0;
    pid.derivative = 0;
    pid.lastError = 0;
}

float StructOfPID(float input, float minLimit, float maxLimit, bool limit){

   if(limit == 1) // If we want to declerate limit of output data
   {
        pid.error =  pid.target - input;
        pid.integral = pid.integral + pid.error;
        pid.derivative = pid.error - pid.lastError;
        pid.output = (pid.Kp * pid.error) + 
                     (pid.Ki * pid.integral) + 
                     (pid.Kd * pid.derivative);
        if(pid.output > maxLimit) pid.output = maxLimit;
        if(pid.output < minLimit) pid.output = minLimit;
   } 

    else // if we don't
    {
        pid.error =  pid.target - input;
        pid.integral = pid.integral + pid.error;
        pid.derivative = pid.error - pid.lastError;
        pid.output = (pid.Kp * pid.error) + 
                     (pid.Ki * pid.integral) + 
                     (pid.Kd * pid.derivative);
    }

    pid.lastError = pid.error;
    return pid.output;
}
