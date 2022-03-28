struct PID {
    float kP, kD, kI;
    long error, lastError, lastIntegral;
    int* output;
};

typedef struct PID PIDController;

int Run(PIDController* pidController, int setPoint, int current);
void ClearController(PIDController* pidController);

int additionSafe(long val, long max, long min, long increment);
int multSafe(int a, int b);
long abs(long n);
long round(float num);