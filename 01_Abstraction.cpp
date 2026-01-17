#include<iostream>
#include<vector>
#include<string>
using namespace std;
// Abstraction
class car{
public:
    
    virtual void startengine() = 0;
    virtual void shiftgear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopengine() = 0;
    virtual ~car() {}

};

class sportscar : public car{
public:
    string brand;
    string model;
    bool isengineon;
    int currentspeed;
    int currentgear;

    sportscar(string b, string m){
        this->brand = b;
        this->model = m;
        isengineon = false;
        currentspeed = 0;
        currentgear = 0;
    }

    void startengine(){
        isengineon = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftgear(int gear){
        if(!isengineon){
            cout << brand << " " << model << " : Engine is off! cannot shift gear." << endl;
        }
        currentgear = gear;
        cout << brand << " " << model << " : shfted to gear " << currentgear << endl;
    }

    void accelerate(){
        if(!isengineon){
            cout << brand << " " << model << " : Engine is off! cannot accelerate." << endl;
        }
        currentspeed += 20;
        cout << brand << " " << model << " : Accelerating to speed " << currentspeed << "km/h" << endl;
    }

    void brake(){
        currentspeed -= 20;
        if(currentspeed < 0) currentspeed = 0;
        cout << brand << " " << model << " : Braking! current speed is " << currentspeed << "km/h" << endl;
    }

    void stopengine(){
        isengineon = false;
        currentgear = 0;
        currentspeed = 0;
        cout << model << " " << brand << " : Engine truned off!" << endl;
    }

};
using namespace std;
int main(){

    car* mycar = new sportscar("BMW", "M4");

    mycar->startengine();
    mycar->shiftgear(1);
    mycar->accelerate();
    mycar->accelerate();
    mycar->shiftgear(2);
    mycar->brake();
    mycar->brake();
    mycar->stopengine();

    delete mycar;

    return 0;
}