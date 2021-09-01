#include <iostream>
#include <string>
using namespace std;
// #include <string.h>
class Vehicle{

private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    // Vehicle()
    // {
    //     cout << "Vehical's default constructor " << endl;
    // }

    // Vehicle (int z){
    //     cout << "Vehicle class parametrerized constructor" << z << endl;
    //     maxSpeed = z;
    // }

    // virtual void print(){
    //     cout << "Vehical " << endl;
    // }
    virtual void print()  = 0;
    // ~Vehicle()
    // {
    //     cout << "Vehical's default destructor " << endl;
    // }
};

class car : /* virtual  */public Vehicle{

    // we have the inherited props numtyres , color
    public :
    int numGears ;

    car()  {
        cout << "car's default constructor " << endl;
        
    }
    // car(int x , int y) : Vehicle(5) {
    //     cout << "car's parameterized constructor " << endl;
    //     numGears = y;
        
    // }

    // car() : Vehicle(3) {
    //     cout << "car's default constructor " << endl;
        
    // }   

    void print(){
        cout << "Car" << endl;
    }
    ~car(){
        cout << "car's default destructor " << endl;
    }
};


/* class HondaCity : public car{
    public :

    HondaCity() {
        cout << "Honda city default constructor  " << endl;
    }
    // HondaCity(int x , int y) : car(x , y){
    //     cout << "Honda city default constructor  " << endl;
    // }
    ~HondaCity(){
        cout << "Honda city destructor  " << endl;
    }
};
 */
class Truck : virtual public Vehicle{
    public:
    //     Truck()  {
    //     cout << "Truck's default constructor " << endl;  
    // }
    //     Truck() : Vehicle(4) {
    //     cout << "Truck's default constructor " <<endl;  
    // }
};

class Bus : public car , public Truck{
    public:
    //     Bus()  {
    //     cout << "Bus's default constructor " << endl;  
    // }
    //     Bus() : Vehicle(5) {
    //     cout << "Bus's default constructor " << endl;  
    // }

        void print(){
        cout << "bus class print function" << endl;
    }
};

class Teacher{
    public :
    string name;
    string age;

    void print(){
        cout << "teacher" << endl;

    }
};

class Student{
    public:

    void print(){
        cout << "student" << endl;
    }
};

class TA : public Teacher , public Student{

};