#include <iostream>
using namespace std;

class Bus {
    public:
    void print();
};

void test();

class Truck{
    private:
    int x;

    protected:
    int y;

    public:
    int z;

    // puri class ko friend bana diya
    friend class Bus;

    friend void Bus :: print(); // :: is scope resolution
    friend void test();
};

// we will have to create a function outside the class
void Bus :: print(){
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;

}

// global function
void test(){
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

int main(){
    Bus b;
    b.print();

    test();
}