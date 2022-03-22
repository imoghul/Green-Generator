#include "pid.h"
#include "unit.h"
#include "main.h"
#include <stdio.h>

extern int phbValve, feedValve, feedMotor, algaeValve, algaeMotor, proccessingMotor, proccessingValve;
extern Sensor* photoBioReactor[];
extern Sensor* feedStockInfusion[];
extern Sensor* algaeTransport[];
extern Sensor* processing[];


int main(void) {
    for(int i = 0;i<023;++i) {
        printf("phbValve: %d\nfeedValve: %d\nfeedMotor: %d\nalgaeValve: %d\nalgaeMotor: %d\nproccessingValve: %d\nproccessingMotor: %d\n\n", phbValve, feedValve, feedMotor, algaeValve, algaeMotor, proccessingValve, proccessingMotor);
        ControlUnit(photoBioReactor);
        ControlUnit(feedStockInfusion);
        ControlUnit(algaeTransport);
        ControlUnit(processing);
    }

    return 0;
}