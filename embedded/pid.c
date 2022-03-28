#include "pid.h"

long round(float num) {
    return num < 0 ? num - 0.5 : num + 0.5;
}

int Run(PIDController* pidController, int setPoint, int current) {
    pidController->error = setPoint - current;
    //if(abs(pidController->error)<=1) pidController->error = 0;
    long integral = pidController->lastIntegral + pidController->error;
    long derivative = pidController->error - pidController->lastError;
    pidController->lastError = pidController->error;
    pidController->lastIntegral = integral;
    long errorTerm = round(pidController->error * pidController->kP);
    long derivTerm = round(derivative * pidController->kD);
    long intTerm = round(integral * pidController->kI);
    long val = errorTerm + derivTerm + intTerm;
    *(pidController->output) = additionSafe(*(pidController->output), 32767, -32768, val);
    return *(pidController->output);
}

void ClearController(PIDController* pidController) {
    pidController->error = 0;
    pidController->lastError = 0;
    pidController->lastIntegral = 0;
}

int additionSafe(long val, long max, long min, long increment) {
    long out = abs(increment);
    long speed = val;

    if (increment > 0) {
        speed = val + out;

        if(speed < val) speed = max;
    }

    if (increment < 0) {
        speed = val - out;

        if(speed > val) speed = min;
    }


    if(speed > max)speed = max;

    if(speed < min)speed = min;

    return speed;
}

int multSafe(int a, int b) {
    if(a == 0 || b == 0)return 0;

    int res = a * b;

    if(a == res / b)return res;
    else return 32767 * (a < 0 ? -1 : 1) * (b < 0 ? -1 : 1);
}

long abs(long n) {
    const long ret[2] = {n, -n};
    return (long)(ret [n < 0]);
}