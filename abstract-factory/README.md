# Abstract Factory Design Pattern

- It is a creational design pattern
- It provides an interface for creating families of related or dependent objects without specifying their concrete class.
- It is also called as factory of factories.
- It encapsulates the creation of multiple related objects without exposing the instantiation logic to the client.

## ABstract Factory pattern solves following problems

**1) Encapsulation of Object Creation:** It encapsulates the object creation logiv within a separate class or set of classes, abstracting it away from the client code. This allows the client code to work with abstract interfaces rather than concrete implementations, promoting loose coupling and making the system more flexible and easy to maintian.

**2) Dependency Inversion:** It promotes dependency inversion by allowing clients to depend on abstractions ( e.g. interfaces or abstract classes) rather than concrete implementations.

## Implementation

```cpp
#include <iostream>

using namespace std;

struct IBattery
{
    virtual void chargeBattery() = 0;
    virtual int getChargedLevel() = 0;
    virtual ~IBattery() {}
};

class SamsungBattery : public IBattery
{
public:
    void chargeBattery()
    {
        cout << "Samsung Battery Charging..." << endl;
    }
    int getChargedLevel()
    {
        return 10;
    }
};

class iPhoneBattery :public IBattery
{
public:
    void chargeBattery()
    {
        cout << "iPhone Battery Charging..." << endl;
    }
    int getChargedLevel()
    {
        return 20;
    }
};

class MiBattery :public IBattery
{
public:
    void chargeBattery()
    {
        cout << "Mi Battery Charging..." << endl;
    }
    int getChargedLevel()
    {
        return 8;
    }
};

struct ICamera
{
    virtual void getFrontCamera() = 0;
    virtual void getBackCamera() = 0;
    virtual ~ICamera() {};
};

class SamsungCamera : public ICamera
{
public:
    void getFrontCamera()
    {
        cout<<"Samsung Front Camera..." << endl;
    }

    void getBackCamera()
    {
        cout << "Samsung Back Camera..." << endl;
    }
};

class iPhoneCamera : public ICamera
{
public:
    void getFrontCamera()
    {
        cout << "iPhone Front Camera..." << endl;
    }

    void getBackCamera()
    {
        cout << "iPhone Back Camera..." << endl;
    }
};

class MiCamera : public ICamera
{
public:
    void getFrontCamera()
    {
        cout << "Mi Front Camera..." << endl;
    }

    void getBackCamera()
    {
        cout << "Mi Back Camera..." << endl;
    }
};

struct IProcessor
{
    virtual void ProcessTasks() = 0;
    virtual ~IProcessor() {}
};

class SamsungProcessor : public IProcessor
{
public:
    void ProcessTasks()
    {
        cout << "Samsung Processor..." << endl;
    }
};

class iPhoneProcessor : public IProcessor
{
public:
    void ProcessTasks()
    {
        cout << "iPhone Processor..." << endl;
    }
};

class MiProcessor : public IProcessor
{
public:
    void ProcessTasks()
    {
        cout << "Mi Processor..." << endl;
    }
};

struct ISmartPhone
{
    virtual IBattery* CreateBattery() = 0;
    virtual ICamera* CreateCamera() = 0;
    virtual IProcessor* CreateProcessor() = 0;
};

class Samsung : public ISmartPhone
{
public:
    IBattery* CreateBattery()
    {
        return new SamsungBattery();
    }

    ICamera* CreateCamera()
    {
        return new SamsungCamera();
    }

    IProcessor* CreateProcessor()
    {
        return new SamsungProcessor();
    }
};

class iPhone : public ISmartPhone
{
public:
    IBattery* CreateBattery()
    {
        return new iPhoneBattery();
    }

    ICamera* CreateCamera()
    {
        return new iPhoneCamera();
    }

    IProcessor* CreateProcessor()
    {
        return new iPhoneProcessor();
    }
};

class Mi : public ISmartPhone
{
public:
    IBattery* CreateBattery()
    {
        return new MiBattery();
    }

    ICamera* CreateCamera()
    {
        return new MiCamera();
    }

    IProcessor* CreateProcessor()
    {
        return new MiProcessor();
    }
};

int main()
{
    ISmartPhone* pPhone = new Mi();
    pPhone->CreateBattery()->chargeBattery();
    pPhone->CreateCamera()->getBackCamera();
    pPhone->CreateProcessor()->ProcessTasks();

    delete pPhone;
}

```
