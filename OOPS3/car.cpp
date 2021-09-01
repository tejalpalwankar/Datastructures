#include <iostream>
using namespace std;
class car : public Vehicle{

    // we have the inherited props numtyres , color
    public :
    int numGears ;

    car(int x , int y) : Vehicle(5) {
        cout << "car's default constructor " << endl;
        numGears = y;
        
    }
    
    ~car(){
        cout << "car's default destructor " << endl;
    }
};