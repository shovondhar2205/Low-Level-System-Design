#include<iostream>
#include<vector>
#include<string>
using namespace std;

class car{
protected:
    // characters
    string brand; 
    string model;
    bool isengineon;
    int currentspeed;
    int currentgear;
    // string tyre;

public:
    car(string b, string m){
        this->brand = b;
        this->model = m;
        isengineon = false;
        currentspeed = 0;
        currentgear = 0;
        // tyre = "MRF";
    }

    // getters and seetters
    int getcurrentspeed(){
        return this->currentspeed;
    }

    // behaviours -> methods
    void startengine(){
        isengineon = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void stopengine(){
        isengineon = false;
        currentgear = 0;
        currentspeed = 0;
        cout << brand << " " << model << " : Engine truned off!" << endl;
    }
    virtual void accelerate() = 0; // Abstract Method for dynamic polymorphism
    virtual void brake() = 0;   // Abstract Method for dynamic polymorphism
    virtual ~car() {}

};

class Manualcar : public car{
private:
    int currentgear;
public:
    Manualcar(string b, string m) : car(b, m){
        currentgear = 0;
    }

    // specialized method for manual car
    void shiftgear(int gear){
        currentgear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentgear << endl;
    }

    // Override accelerate - dynamic polymorphism
    void accelerate(){
        if(!isengineon){
            cout << brand << " " << model << " : Engine is off! cannot accelerate." << endl;
        }
        currentspeed += 20;
        cout << brand << " " << model << " : Accelerating to speed " << currentspeed << "km/h" << endl;
    }

    // Override brake - dynamic polymorphism
    void brake(){
        currentspeed -= 20;
        if(currentspeed < 0) currentspeed = 0;
        cout << brand << " " << model << " : Braking! current speed is " << currentspeed << "km/h" << endl;
    }

};

class Electriccar : public car{
private:
    int batteryLevel;
public:
    Electriccar(string b, string m) : car(b, m){
        batteryLevel = 100;
    }

    // specialized method for electric car 
    void chargebattery(){
        batteryLevel = 100;
        cout << brand << " " << model << " : Charged to " << batteryLevel << endl;
    }

    // Override accelerate - dynamic polymorphism
    void accelerate(){
        if(!isengineon){
            cout << brand << " " << model << " : Engine is off! cannot accelerate." << endl;
            return ;
        }
        if(batteryLevel <= 0){
            cout << brand << model << "Battery Dead! connect to the charger" << endl;
            return;
        }
        batteryLevel -= 10;
        currentspeed += 15;
        cout << brand << " " << model << " : Accelerating to speed " << currentspeed << " km/h and batterylevel is " << batteryLevel << endl;
    }

    // Override brake - dynamic polymorphism
    void brake(){
        currentspeed -= 15;
        if(currentspeed < 0) currentspeed = 0;
        cout << brand << " " << model << " : Braking! current speed is " << currentspeed << "km/h" << endl;
    }

};

int main(){

    Manualcar* mcar = new Manualcar("Nissan", "petrol");

    mcar->startengine();
    mcar->shiftgear(1);
    mcar->accelerate();
    mcar->accelerate();
    mcar->shiftgear(2);
    mcar->accelerate();
    mcar->accelerate();
    mcar->brake();
    mcar->brake();
    mcar->brake();
    mcar->brake();
    mcar->stopengine();

    cout << "--------------------------------------" << endl;

    Electriccar* Ecar = new Electriccar("Porsche", "Taycan");

    Ecar->chargebattery();
    Ecar->startengine();
    Ecar->accelerate();
    Ecar->accelerate();
    Ecar->brake();
    Ecar->brake();
    Ecar->stopengine();

    delete mcar;
    delete Ecar;
    
    return 0;
}