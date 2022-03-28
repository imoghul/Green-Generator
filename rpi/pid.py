class PIDController:
    def __init__(self, kP, kI, kD, set=None):
        self.P = kP
        self.I = kI
        self.D = kD
        self.set = set
        self.error = 0
        self.lastError = 0
        self.lastIntegral = 0

    def run(self, setPoint, actual):
        self.error = setPoint - actual
        integral = self.lastIntegral + self.error
        derivative = self.error - self.lastError
        self.lastError = self.error
        self.lastIntegral = integral
        out = self.P * self.error + self.D * derivative + self.I * integral
        if self.set != None:
            self.set(out)
        return out


class Sensor:
    def __init__(self, controllers, desired, actual):
        self.controllers = controllers
        self.desired = desired
        self.actual = actual

    def run(self):
        for i in self.controllers:
            i.run(self.desired, self.actual)


class Unit:
    def __init__(self, sensors):
        self.sensors = sensors

    def run(self):
        for i in self.sensors:
            i.run()
