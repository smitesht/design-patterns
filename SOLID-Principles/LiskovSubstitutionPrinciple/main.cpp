#include <iostream>
#include <string>

using namespace std;

/*class Vehicle
{
    public:
        virtual int numberOfWheels(){
            return 4;
        }

        virtual void hasEngine(){
            cout<<"Has 4 Cylinder Engine"<<endl;
        }

        virtual ~Vehicle(){
            cout<<"dtor..." <<endl;
        }
};

class Car : public Vehicle
{
    public:
        virtual int numberOfWheels() override {
            return 4;
        }

        virtual void hasEngine() override {
            cout<<"Has 4 Cylinder Engine"<<endl;
        }
};

class MotorCycle : public Vehicle
{
    public:
        virtual int numberOfWheels() override {
            return 2;
        }

        virtual void hasEngine() override {
            cout<<"Has 2 Cylinder Engine"<<endl;
        }
};

class Bicycle : public Vehicle
{
    public:
        virtual int numberOfWheels() override {
            return 2;
        }

        virtual void hasEngine() override {
            throw "No Engine";
        }

};
*/

class Vehicle
{
    public:
        virtual int numberOfWheels(){
            return 4;
        }

        virtual ~Vehicle(){
            cout<<"dtor..." <<endl;
        }
};

class EngineVehicle : public Vehicle
{
    public:
         virtual void hasEngine(){
            cout<<"Has 4 Cylinder Engine"<<endl;
        }
};


class Car : public EngineVehicle
{
   public:
        virtual int numberOfWheels() override {
            return 4;
        }

        virtual void hasEngine() override {
            cout<<"Has 4 Cylinder Engine"<<endl;
        }
};

class MotorCycle : public EngineVehicle
{
    public:
        virtual int numberOfWheels() override {
            return 2;
        }

        virtual void hasEngine() override {
            cout<<"Has 2 Cylinder Engine"<<endl;
        }
};

class Bicycle: public Vehicle
{
    public:
        virtual int numberOfWheels() override {
            return 2;
        }
};

int main()
{
    EngineVehicle *p = new Car();
    p->hasEngine();

    p = new MotorCycle();
    p->hasEngine();

    //p = new Bicycle();  Compilation Error
    //p->hasEngine();

    Vehicle *q = new Bicycle();
    q->numberOfWheels();

    return 0;
}