#include <iostream>
using namespace std;

//Name: Ubaid Ullah
//Roll no: 20i0541
//Question # 02

class InterfaceTemperatureSensor {
public:
    virtual void getTempStats() = 0;
};

class InterfacePressureSensor {
public:
    virtual void getPressureStats() = 0;
};

class InterfaceMotionSensor {
public:
    virtual void getMotionStats() = 0;
};

class TemperatureSensor : public InterfaceTemperatureSensor {
protected:
    string temp;
public:
    TemperatureSensor(string temp_) {
        temp = temp_;
    }
    void getTempStats() override {
        cout << "Temperature: " << temp << endl;
    }
};

class MotionSensor : public InterfaceMotionSensor {
protected:
    bool motionDetected;
public:
    MotionSensor(bool motionDetected_)
    {
        motionDetected = motionDetected_;
    }
    void getMotionStats() override {
        if (motionDetected)
        {
            cout << "Possible user activity detected" << endl;
        }
        else {
            cout << "No user activity detected" << endl;
        }
    }
};

class PressureSensor : public InterfacePressureSensor {
protected:
    double pressure;
public:
    PressureSensor(double pressure_)
    {
        pressure = pressure_;
    }
    void getPressureStats() override {
        cout << "System pressure meter reads " << pressure << " psi" << endl;
    }
};

class TemperatureSensorAdapter {
    InterfaceTemperatureSensor* temperatureConnector;
public:
    TemperatureSensorAdapter(TemperatureSensor *object)
    {
        temperatureConnector = object;
    }
    void callBack()
    {
        temperatureConnector->getTempStats();
    }

};

class PressureSensorAdapter {
    InterfacePressureSensor* pressureConnector;
public:
    PressureSensorAdapter(PressureSensor *object)
    {
        pressureConnector = object;
    }
    void callBack()
    {
        pressureConnector->getPressureStats();
    }
};

class MotionSensorAdapter {
    InterfaceMotionSensor* motionConnector;
public:
    MotionSensorAdapter(MotionSensor *object)
    {
        motionConnector = object;
    }
    void callBack()
    {
        motionConnector->getMotionStats();
    }
};

class AdvancedSoftwareSystem {
    TemperatureSensorAdapter* tsa;
    PressureSensorAdapter* psa;
    MotionSensorAdapter* msa;
public:
    AdvancedSoftwareSystem(TemperatureSensor *obj1, PressureSensor *obj2, MotionSensor *obj3)
    {
        tsa = new TemperatureSensorAdapter(obj1);
        msa = new MotionSensorAdapter(obj3);
        psa = new PressureSensorAdapter(obj2);
    }

    void callBack(string sensor) {
        if (sensor == "Temperature")
        {
            tsa->callBack();
        }
        else if (sensor == "Motion")
        {
            msa->callBack();
        }
        else if (sensor == "Pressure")
        {
            psa->callBack();
        }
        else
        {
            cout << "Invalid Sensor" << endl;
        }
    }

};
int main()
{
    TemperatureSensor* obj1 = new TemperatureSensor("35 Degree Celcius");
    PressureSensor* obj2 = new PressureSensor(43);
    MotionSensor* obj3 = new MotionSensor(false);

    AdvancedSoftwareSystem* AdvSftSys = new AdvancedSoftwareSystem(obj1, obj2, obj3);
    AdvSftSys->callBack("Pressure");
    return 0;
}

