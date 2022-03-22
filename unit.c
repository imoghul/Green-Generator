#include "pid.h"
#include "unit.h"
#include <stdio.h>

int phbValve, feedValve, feedMotor, algaeValve, algaeMotor, proccessingMotor, proccessingValve;

PIDController phbValveTemp = {
    .kP = 1,
    .kD = 0,
    .kI = 0,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &phbValve
};
PIDController phbValveFlow = {
    .kP = 1,
    .kD = 0,
    .kI = 0,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &phbValve
};



PIDController feedValveFeedCap = {
    .kP = 1,
    .kD = 0,
    .kI = 0,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &feedValve
};
PIDController feedValvePressure = {
    .kP = 1,
    .kD = 0,
    .kI = 0,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &feedValve
};
PIDController feedValveTemp = {
    .kP = 1,
    .kD = 0,
    .kI = 0,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &feedValve
};
PIDController feedValveFeedMotor = {
    .kP = 1,
    .kD = 0,
    .kI = 0,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &feedValve
};

PIDController feedMotorFeedCap = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &feedMotor
};
PIDController feedMotorPressure = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &feedMotor
};
PIDController feedMotorTemp = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &feedMotor
};
PIDController feedMotorFeedMotor = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &feedMotor
};



PIDController algaeValveFlow = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &algaeValve
};

PIDController algaeMotorFlow = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &algaeMotor
};



PIDController processingValveFlow = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &proccessingValve
};
PIDController processingValvePressure = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &proccessingValve
};
PIDController processingValveTemp = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &proccessingValve
};
PIDController processingValveConcentration = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &proccessingValve
};

PIDController processingMotorFlow = {
    .kP = .6,
    .kD = 0,
    .kI = 2,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &proccessingMotor
};
PIDController processingMotorPressure = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &proccessingMotor
};
PIDController processingMotorTemp = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &proccessingMotor
};
PIDController processingMotorConcentration = {
    .kP = .3,
    .kD = 0,
    .kI = 1,
    .error = 0,
    .lastError = 0,
    .lastIntegral = 0,
    .output = &proccessingMotor
};



Sensor phbID = {
    .val = 0,
    .desired = 0,
    .controllers = {}
};
Sensor phbTemp = {
    .val = 10,
    .desired = 0,
    .controllers = {&phbValveTemp}
};
Sensor phbFlow = {
    .val = 0,
    .desired = 0,
    .controllers = {&phbValveFlow}
};

Sensor feedID = {
    .val = 0,
    .desired = 0,
    .controllers = {}
};
Sensor feedFeedCap = {
    .val = 0,
    .desired = 0,
    .controllers = {&feedValveFeedCap, &feedMotorFeedCap}
};
Sensor feedPressure = {
    .val = 0,
    .desired = 0,
    .controllers = {&feedValvePressure, &feedMotorPressure}
};
Sensor feedTemp = {
    .val = 0,
    .desired = 0,
    .controllers = {&feedValveTemp, &feedMotorTemp}
};
Sensor feedFeedMotor = {
    .val = 0,
    .desired = 0,
    .controllers = {&feedValveFeedMotor, &feedMotorFeedMotor}
};

Sensor algaeID = {
    .val = 0,
    .desired = 0,
    .controllers = {}
};
Sensor algaeFlow = {
    .val = 0,
    .desired = 0,
    .controllers = {&algaeValveFlow, &algaeMotorFlow}
};

Sensor processingID = {
    .val = 0,
    .desired = 0,
    .controllers = {}
};
Sensor processingFlow = {
    .val = 0,
    .desired = 10,
    .controllers = {&processingValveFlow, &processingMotorFlow}
};
Sensor processingPressure = {
    .val = 0,
    .desired = 0,
    .controllers = {&processingValvePressure, &processingMotorPressure}
};
Sensor processingTemp = {
    .val = 0,
    .desired = 0,
    .controllers = {&processingValveTemp, &processingMotorTemp}
};
Sensor processingConcentration = {
    .val = 2,
    .desired = -11,
    .controllers = {&processingValveConcentration, &processingMotorConcentration}
};

Sensor* photoBioReactor [] = {&phbTemp, &phbFlow};
Sensor* feedStockInfusion [] = {&feedFeedCap, &feedPressure, &feedTemp, &feedFeedMotor};
Sensor* algaeTransport [] = {&algaeFlow};
Sensor* processing [] = {&processingFlow, &processingPressure, &processingTemp, &processingConcentration};


void ControlSensor(Sensor* sensor) {
    for(int i = 0; sensor->controllers[i] && i < CONTROLLERS_PER_SENSOR; ++i) {
        Run(sensor->controllers[i], sensor->desired, sensor->val);
    }
}

void ControlUnit(Sensor* unit[]) {
    for(int i = 0; unit[i] && i < SENSORS_PER_UNIT; ++i) {
        ControlSensor(unit[i]);
    }
}