// #include "pid.c"
#define CONTROLLERS_PER_SENSOR      (2)
#define DEVICES_PER_UNIT            (2)
#define SENSORS_PER_UNIT            (5)

typedef struct {
    int val, desired;
    PIDController * controllers [CONTROLLERS_PER_SENSOR];
} Sensor;

typedef struct {
    Sensor * sensors[SENSORS_PER_UNIT];
} Unit;

void ControlSensor(Sensor* sensor);
void ControlUnit(Sensor* unit[]);