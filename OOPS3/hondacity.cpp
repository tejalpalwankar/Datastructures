#include <iostream>
using namespace std;

class HondaCity : public car{
    public :

    HondaCity(int x , int y) : car(x , y){
        cout << "Honda city default constructor  " << endl;
    }
    ~HondaCity(){
        cout << "Honda city destructor  " << endl;
    }
};