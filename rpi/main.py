from pid import *

phbValve = 0
feedValve = 0
feedMotor = 0
algaeValve = 0
algaeMotor = 0
proccessingMotor = 0
proccessingValve = 0


def set_phbValve(val):
    global phbValve
    phbValve += val
    print(phbValve)


def set_feedValve(val):
    global feedValve
    feedValve += val


def set_feedMotor(val):
    global feedMotor
    feedMotor += val


def set_algaeValve(val):
    global algaeValve
    algaeValve += val


def set_proccessingMotor(val):
    global proccessingMotor
    proccessingMotor += val


def set_proccessingValve(val):
    global proccessingValve
    proccessingValve += val


phbValveTemp = PIDController(1, 0, 0, set_phbValve)
phbValveFlow = PIDController(1, 0.1, 0.3, set_phbValve)
phbTemp = Sensor([phbValveTemp], 10, 0)
phbFlow = Sensor([phbValveFlow], 10, 0)
phb = Unit([phbTemp,phbFlow])

for i in range(10):
    phb.run()
