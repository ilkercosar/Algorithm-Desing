#ifndef __PID__
#define __PID__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef float PID;
typedef struct pidController{
    PID target;
    PID Ki,Kp,Kd;
    PID input;
    PID output;
    PID error;
    PID integral;
    PID derivative;
    PID lastError;
}pidController;

void pid_init(void);
float StructOfPID(float input, float minLimit, float maxLimit, bool limit);

#ifdef __cplusplus
}
#endif
#endif