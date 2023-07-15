#include <stdio.h>
#include "pid.h"

float signal(void){
    return rand()%100;
}

void delay(void){
    for (int i = 0; i < 500000000; i++)
    {

    }
}

static pidController pid;

int main(){
    // init pid
    pid_init();

    // set pid gain
    pid.Kd = 0;
    pid.Ki = 200;
    pid.Kp = 400;

    // set target value
    pid.target = 20;
        

    while(1){

        printf("Data without PID:%.2f\n",signal());

        //pid out
        float out = StructOfPID(signal(),0,100,true);
        
        printf("Out Data: %.2f\n",out);
        delay();
    }

    return 1;
}
