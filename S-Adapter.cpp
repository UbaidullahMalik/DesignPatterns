#include <iostream>
using namespace std;

class USBTypeA {
public:
    virtual void connectTypeA() = 0;
};

class USBTypeC {
public:
    virtual void connectTypeC() = 0;
};

class HardDisk : public USBTypeC {
public:
    void connectTypeC() override {
        cout << "Connected to a Type-C device" << endl;
    }
};

class Adapter : public USBTypeA {
private:
    USBTypeC* typeCDevice;

public:
    Adapter(USBTypeC* device) : typeCDevice(device) {}
    void connectTypeA() override {
        cout << "Connecting Type-C device to a Type-A laptop using Adapter" << endl;
        typeCDevice->connectTypeC();
    }
};

class Laptop : public USBTypeA {
public:
    void connectTypeA() override {
        cout << "Connected to a Type-A laptop" << endl;
    }
    void connectToHardDisk(HardDisk& harddisk) {
        Adapter adapter(&harddisk);
        USBTypeA* connector = &adapter;
        connector->connectTypeA();
    }
};

int main() {
    HardDisk harddisk;
    Laptop laptop;

    laptop.connectToHardDisk(harddisk);

    return 0;
}
