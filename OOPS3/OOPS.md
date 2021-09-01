# Encapsulation  - To combine / to club  
Apni kisi bhi entity ke data aur function ko club kar de usse hum encapsulation bolte hai. 
we can achieve it with the help of class.  
eg. student class  
data member : name , roll , age , age , address  
func : setroll ,changeAddress.  
We have combined the properties of studnets in a single unit . That is called encapsulation. 

# Abstraction - hiding
hiding the unnecessary details from the world  
eg . we operate tv with remote.But we do not know what happens internally when we press the volume buttom. these details are unnecessary for us.  
eg . We use a inbuilt sort function. We just know it will sort for us but internally we do not know how and which sorting algorithm is used.  
eg. We use STL(Standard template library) We have many data structes aleady implemented here like : stacks , queues , hashmaps.   

Now if we want to implement abstraction in our class : 
eg . student class :  
data members : name , roll num , address  
If we wantb the property of roll number shoul dnot be accesssible to the outside world , then I just need to make this property private.  

**why do we need abstraction ?**  
1. updation/ changes : koi bhi changes se end user ke output mai effect nai aana chaiye  
eg. sort - suppose internally we were using bubble sort but later we realize quick sort was better but what changes we are making internally should not afftect the use case of the user.  
2. To avoid errors :  
eg. if the sort func is acceesible to everyone , the user can introduce some errors. 


# Inheritance - to inherit from parents
To inherit the properties from our parents or ancestor.  
eg . we have 2 classes car , bicycle . here are the properties of both :   
car - color , speed , numgears  
bicycle - color , speed , isfoldable  
truck - color , speed  
2 properties are common in all bcz they have one common property that they are vehicals. apart from the common properties thhey have their own unique properties as well.  
if we want to make these 3 classes car , bicycle , truck the prob is the 2 properties are repeated. One option is to create like this. If we want to avoid this we can make a parent class  VEHILCE and and put in them only the specific unique properties of their own.  
PARENT : Vehicle  
CHILD : car , bicycle , truck.  

eg2 .  
Parent : Name , age , address , contact  
Teacher : qualification , subject  
student : roll num , batch  

Using this we are able to reuse our code.   

## Access Modifiers  
- private : only for class members  
- public : for everyone.  
- **protected : This property is only accessible to it's child classes**  
If we want to make a property only accessible for some people .  

# Inheritance syntax 

1. Parent / Base class : vehical
2. Child / derived class : car

```C++ 
class vehicle{
    private : 
    int maxSpeed;

    protected: 
    int numTyres;

    public: 
    string color;
};

class car : public vehicle{
    // we have the inherited props numtyres , color
    public :
    int numGears ;

    void print(){
        cout << "Numtyres : " << numTyres << endl;
        cout << "color : " << color << endl;
        cout << "numGears : " << numGears << endl;
        cout << "maxSpeed : " << maxSpeed << endl;
    }
};

int main(){
    vehicle v;

    v.color = "blue";
    // v.maxSpeed = 100;  we cannot use this
    // v.numTyres = 4; protected 

    car c;

    c.color = "black";
    c.numGears = 5;
    // c.numTyres = 4; protected

}
```

syntax 
### ***class car : access_specifier(public/priv/protect) vehical*.** 

**Access specifiers** -   
DEFAULT : PRIVATE
1. public : 
    - private props -> not accesible to the car class  
    - protected props-> car class under protected modifier.  
    - public props-> car class ki public props.

2. protected :
    - private props -> not accesible 
    - protected props-> protected modifier.  
    - public props-> protected props.

3. private :
    - private props -> not accesible 
    - protected props-> private modifier.  
    - public props-> private props.

# Inheritance - order of Constructor / Destructor 

car class is a child class . so whiile initializing I have to initialize the property of vehical class as well.  
order of inheritance  
b inherited A , C inherited B.  
A -> B -> C  

Making objects of the class and seeing the order of consructors :  
A a ; A() Constructor  
B b ; A() Constructor -> B() Constructor  
C c ; A() Constructor -> B() Constructor -> C() Constructor .  
these constructors are called implicitly no need to calll them.  

```C++ 
class vehicle{

    vehicle(){
        cout << "Vehical's default constructor " << endl;
    }
    
    ~vehicle(){
        cout << "Vehical's default destructor " << endl;
    }
};

class car : public vehicle{
    car(){
        cout << "car's default constructor " << endl;
    }
    
    ~car(){
        cout << "car's default destructor " << endl;
    }
};

int main(){
    vehicle v;

    car c;

}
```
<pre>
Vehical's default constructor   -> for object v
Vehical's default constructor   -> for object c
car's default constructor       -> for object c

car's default destructor        -> for object c
Vehical's default destructor    -> for object c
Vehical's default destructor    -> for object v
</pre>
**Order of constructor :**  
parent -> child  

**Order of destructor :**  
child -> parent  

### If we want to call a parameterized constructor because implicitly the default is called
```C++ 
class Vehicle{

private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    Vehicle()
    {
        cout << "Vehical's default constructor " << endl;
    }

    Vehicle (int z){
        cout << "Vehicle class parametrerized constructor" << endl;
        maxSpeed = z;
    }

    ~Vehicle()
    {
        cout << "Vehical's default destructor " << endl;
    }
};

class car : public Vehicle{

    // we have the inherited props numtyres , color
    public :
    int numGears ;

    // to call parametrized constructor
    car() : Vehicle(5) {
        cout << "car's default constructor " << endl;
    }
    
    ~car(){
        cout << "car's default destructor " << endl;
    }
};


int main(){
    Vehicle v;
    car c;
}

```

<pre>
Vehical's default constructor 
Vehicle class parametrerized constructor
car's default constructor
car's default destructor
Vehical's default destructor
Vehical's default destructor
</pre>

**if we dont have a default constructor in the vehical class , and in car class we do not mention parametrized constructor we will get an error.**  

WE CAN ALSO CALL BOTH PARAMETERIZED CONSTRUCTORS
```C++ 
class Vehicle{
        Vehicle (int z){
        cout << "Vehicle class parametrerized constructor" << endl;
        maxSpeed = z;
    }

};

class car{
    car(int x) : Vehicle(5) {
        cout << "car's default constructor " << endl;
    }
}

int main()
{
 car c(50);
}
```

### Another class Honda city  
```C++ 
class HondaCity : public car{
    public :

    HondaCity() : car(5){
        cout << "Honda city default constructor  " << endl;
    }
    ~HondaCity(){
        cout << "Honda city destructor  " << endl;
    }
};

int main(){
    HondaCity h;
}
```
<pre>
Vehicle class parametrerized constructor
car's default constructor 
Honda city default constructor          
Honda city destructor  
car's default destructor 
Vehical's default destructor
</pre>

### 2 parameterized constructor

```C++ 
class car {
    car(int x , int y) : Vehicle(5) {
        cout << "car's default constructor " << endl;
        numGears = y;  
    }
};

class HondaCity{
    HondaCity(int x , int y) : car(x , y){
        cout << "Honda city default constructor  " << endl;
    }
};
int main(){
    HondaCity h(4,5);

}
```

<pre>
Vehicle class parametrerized constructor
car's default constructor
Honda city default constructor
Honda city destructor
car's default destructor
Vehical's default destructor
</pre>

# Types of Inheritance 

## 1. Single Inheritance
<pre>
A       Vehical
|   or    |
v         V
B        car
</pre>
 
## 2. Multilevel Inheritance
A base class with it's own child class
<pre>
A       Vehical
|         |
v         V
B  or    car
|         |
v         V
C     hondacity
</pre>

## 3. Heirarchical Inheritance
A base class with many child class
<pre>
        A
      / | \
     B  C  D

     vehical
     /  |  \
  car cycle truck
</pre>

## 4. Multiple Inheritance
multiple base class having one child
<pre>
     A  B  C
      \ | /
        D

Teacher    Student
     \     /
     teaching assitance
</pre>
If both the base classes have 1 same function then we will get an error. So we have to use class name and scope resolution. 

```C++ 
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
    string name;
    void print(){
        cout << "student" << endl;
    }
};

class TA : public Teacher , public Student{

};

int main(){

    TA a;
    // a.print(); this will give us an error since both claases have [rint func]
    a.Student :: print();
    a.Teacher :: name = "abcd";
}
```
output :
<pre>
student
</pre>

First it will check khudka class and then base class. So this won't give an error.
```C++ 
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
    void print(){
        cout << "TA" << endl;
    }
};

int main(){

    TA a;
    a.print();
}
```
output :
<pre>
TA
</pre>

## 5. Hybrid inheritance
Mixture of 2-3 types of inheritance

<pre>
1.   A    B
    \  /   -> Multiple inher
     C
     |     -> multilevel
     D  
    / \    -> heirarchical 
   E   F
</pre>


## Diamon Structure,.
<pre>   
    A
   / \ 
  B   C
   \ /
    D
</pre>
In example :  
A -> own props  
B -> A and B props  
C -> A and props 3  
D -> A And B , A and C . so humare A ke 2 copies ban gaye hai.

<pre>   
    vehicle
    / \ 
  car  truck
    \ /
    bus
</pre>

```C++ 
class Vehicle{

public:

    Vehicle()
    {
        cout << "Vehical's default constructor " << endl;
    }

    ~Vehicle()
    {
        cout << "Vehical's default destructor " << endl;
    }
};

class car : public Vehicle{

    public :
    car()  {
        cout << "car's default constructor " << endl;
        
    }
    
    ~car(){
        cout << "car's default destructor " << endl;
    }
};

class Truck : public Vehicle{
    public:
        Truck()  {
        cout << "Truck's default constructor " << endl;  
    }
};

class Bus : public car , public Truck{
    public:
        Bus()  {
        cout << "Bus's default constructor " << endl;  
    }
};

int main(){
    Bus b;
}
```
OUTPUT :
<pre>
Vehical's default constructor  - vehical called by car
car's default constructor      - car
Vehical's default constructor  - vehical called by truck
Truck's default constructor    - truck
Bus's default constructor      - bus
Vehical's default destructor
car's default destructor
Vehical's default destructor
</pre>

### Calling print function through the Bus class

```C++ 
class Vehicle{

public:

    Vehicle()
    {
        cout << "Vehical's default constructor " << endl;
    }

    void print(){
        cout << "Vehical class print function" << endl;
    }

    ~Vehicle()
    {
        cout << "Vehical's default destructor " << endl;
    }
};

class car : public Vehicle{

    public :
    car()  {
        cout << "car's default constructor " << endl;
        
    }
    
    ~car(){
        cout << "car's default destructor " << endl;
    }
};

class Truck : public Vehicle{
    public:
        Truck()  {
        cout << "Truck's default constructor " << endl;  
    }
};

class Bus : public car , public Truck{
    public:
        Bus()  {
        cout << "Bus's default constructor " << endl;  
    }
};

int  main(){
    Bus b;
    b.print();
}
```

- Vehical ka print function call kiya toh uske 2 copies banenge ek car and ek truck mai so we will get this error.

<pre>
vehicleUse.cpp: In function 'int main()':
vehicleUse.cpp:19:7: error: request for member 'print' is ambiguous
   19 |     b.print();
      |       ^~~~~
In file included from vehicleUse.cpp:2:
vehicle.cpp:26:10: note: candidates are: 'void Vehicle::print()'
   26 |     void print(){

</pre>

TO AVOID THIS :
1. We can add a print function in our bus class
2. Explicity mention which class print funtion I want to call
```C++ 
int main(){

    Bus b;
    b.car::print();
}
```

### - Now what if we have a print function in the car class as well

```C++ 
    b.car::print();  // car ka khudka call hoga
    b.Truck::print(); // vehical ka call hoga
```
### To avoid making 2 copies of Default constructor
**We cleared the ambiguity But still the D class will have copies of 2 classes (B ka A , C ka A).**  
TO AVOID THIS :  
WE USED THE KEYWORD (Virtual)

```C++ 
class car virtual : public Vehicle{

    public :
    car()  {
        cout << "car's default constructor " << endl;
        
    }
    
    ~car(){
        cout << "car's default destructor " << endl;
    }
};

class Truck virtual : public Vehicle{
    public:
        Truck()  {
        cout << "Truck's default constructor " << endl;  
    }
};
```
Ab yaha pe car ya truck dono vehical ka constructor call nai karre hai. Bus direct vehical ka consructor call karega. Bcz car and truck dono ki virtual base class hai vehical.  
**Virtual base class means car and truck ke paas Vehical ka actual class nai hai but pointer pada hai.**
<pre>
Vehical's default constructor - vehical called by Bus
car's default constructor     
Truck's default constructor
Bus's default constructor
car's default destructor
Vehical's default destructor
</pre>

### Vehical class has no default constructor 
Hume parameterized constructor explicitly call karna padega in car , truck and BUS class as well. as studied earlier base class sirf apne immediate parent ko call karti hai but yaha hume virtual base class call kiya hai toh bus direct call karri hai vehical ko. 
***SO THIS IS ALSO KNOWN AS VIRTUAL INHERITANCE***

```C++ 
class Vehicle{

private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    Vehicle (int z){
        cout << "Vehicle class parametrerized constructor" << z << endl;
        maxSpeed = z;
    }

    ~Vehicle()
    {
        cout << "Vehical's default destructor " << endl;
    }
};

class car : virtual public Vehicle{

    public :

    car() : Vehical(3) {
        cout << "car's default constructor " << endl;
        
    }   
    ~car(){
        cout << "car's default destructor " << endl;
    }
};



class Truck : virtual public Vehicle{
    public:

        Truck() : Vehicle(4) {
        cout << "Truck's default constructor " <<endl;  
    }
};

class Bus : public car , public Truck{
    public:

        Bus() : Vehicle(5) {
        cout << "Bus's default constructor " << endl;  
    }

};
```

<pre>
Vehicle class parametrerized constructor 5 - yaha the value proves bus class call karri hai
car's default constructor 
Truck's default constructor 
Bus's default constructor 
car's default destructor 
Vehical's default destructor 
</pre>

# Polymorphism -(many forms) : Compile Time
This means when same code behave differently in different situations. 
1. Compile Time : I will decide at compile time What i need to do. 
2. Run time : We will decide at run time how it should behave.

COMPILE TIME :  
1. Function Overloading - We have different functions with same name but their structure is different. 
```C++ 
int test(int a , int b){

}

int test(int a){
    
}

int test(){
    
}
/*  We cannot use this as the complier won't be able to diffrentiate on baisis of return type
void test(){
    
}
 */
```

2. Operator Overloading 
    - 2 + 3 = 5 ( adding 2 int values)
    - 3.4 + 1.6 = 5.0 ( adding 2 float values)
    - 'a' + 'b' = 97 + 90 ( adding 2 ascii values)
    - c1 + c2 (complex number class adding 2 complex numbers)

3. Method/Function Overriding 

<pre>
A -- base class print()
|
V
B -- derived class print()
</pre>
If both my base class and derived class have a print func, derived class is overriding the print().  

```C++ 
class  Vehicle{
    public :
    Vehicle()
    {
        cout << "Vehical's default constructor " << endl;
    }

    void print(){
        cout << "vehicle" << endl;
    }
}

class car : public Vehicle{
    public :
    car()  {
        cout << "car's default constructor " << endl;
        
    }

    void print(){
        cout << "Car" << endl;
    }
}

int main(){
    Vehicle v; 

    car c;

    v.print();
    c.print();
}
```
So yaha hum compile time pe dekh rahehai kis object ke throuh call karna hai. Agar car ke pass print nai hota toh vehicle ka print call hota.
<pre>
Vehical's default constructor -vehical
Vehical's default constructor - vehical called by car
car's default constructor
Vehical - vehical ka print
Car     - car ka print
</pre>


v2 ke through I can access only those properties jo humare vehicle class mai hai.   
but abhi dono classe mai print funtion hai toh konsa call hoga 
```C++ 
int main(){
    Vehicle v; 

    car c;

    Vehicle *v1 = new Vehicle; // object banaya hai

    Vehicle *v2;  // ponter banaya hai
    // v2 = &v ;  v2 is pointing to v object

    v2 = &c ; // base class object is pointing to derived class object but viceversa is not allowed
    v1->print();

    v2->print(); 
```
So v2 was actually pointing to car but object v1 ka banaya tha, toh v2 ne check he nai kiya point kisko karra hai n direct vehical ka call kiya. This is complile time polymorphism as complie time pe decision lere hai. 
<pre>
Vehical   - called by v1
Vehical   - called by v2
</pre>

# Polymorphism - Run time
It uses VIRTUAL FUNCTIONS
```C++ 
class Vehicle {
    public :
    void print(){
        cout << "Vehical " << endl;
    }
};

class car {
    public :
    void print(){
        cout << "car " << endl;
    }
};

int main(){
    car c;
    Vehicle *v2;  

    v2 = &c ; 

    v2->print();
}
```
Last time when we made the object v2 of and pointed it to c. but v2 ka print func call karte time v2 ka he print func call hora tha. But if we want ke v2 car class ka print call kare bcz v2 is pointing to car na , we will need to take help of virtual functions.  
**VIRTIAL FUNCTION : Virtaul functions are created in the base class and overriden the derived class.This means we are telling to the complier to take the decision at runtime ke hume konsa print call karna hai** So yaha v2 ko jaake hum dekhne bolre hai ke vo konse pointer ko point karra hai.


```C++ 
class Vehicle {
    public :
    virtual void print(){
        cout << "Vehical " << endl;
    }
};

class car {
    public :
    void print(){
        cout << "car " << endl;
    }
};

int main(){
    Vehicle v; 

    car c;

    Vehicle *v1 = new Vehicle; // object banaya hai

    Vehicle *v2;  // ponter banaya hai
    // v2 = &v ;  v2 is pointing to v object

    v2 = &c ; // base class object is pointing to derived class object but viceversa is not allowed
    v1->print();
    v2->print();

}
```
<pre>
Vehical
Car
</pre>

Agar car class mai print() hai he nai
```C++ 
class Vehicle {
    public :
    virtual void print(){
        cout << "Vehical " << endl;
    }
};

class car {

};

int main(){
    Vehicle v; 

    car c;

    Vehicle *v1 = new Vehicle; 

    Vehicle *v2; 

    v2 = &c ; 
    v1->print();
    v2->print();

}
```
<pre>
Vehical
Vehical
</pre>

WHERE IS IT USED ?  
suppose we have an orrganization and we want to calculate the salaary of the employees in diff sectors.
- Hr , 
- managers ,
- engineers , 
- others.  
sabka salaray calc ka formula alag hai. 
<pre>
        employee
      /  |   |  \
   HR  mana  eng  others
   1    3    20    4

28 employees
</pre>
1. calculate each sal individually. Every class has this common func **calculateSalary()**. So I will make an array of type employee  
Employee **e = new Employee*[28];  
ab ye array ke har index pe uss class ka object hoga. double pointer bcz we want to make an array of pointers. 
<pre>
array
0   1   2   3   4 ....
hr  m   m   m   eng
</pre>
for loop on emp array:  
    e[i] -> calculatesalary();  // calsal() ko virtual banaya hai  
Toh ab hum runtime pe decision lenge. So ith index pe jo object rakha hoga uska function he call hoga.  

# Virtual Functions and Abstract Classes.

**Pure Virtual Functions**  
These are those functions jinki koi definition nai hoti. 
```C++ 
// normal virtual function
virtual void print(){

}

virtual void print() = 0;

```
***Any class which uses pure virtual function becomes an abstract class. Abstract classes are incomplete.*** 
- we cannot create a object of this class.
<pre>
    vehical (abstract)
       |
       V
      Car       
</pre>
Now car class has 2 options :  
1. implement all the pure virtual functions
2. become an abstract class

```C++ 
class Vehicle {
    public :
    virtual void print() = 0;
};

class car {
    public :
    void print(){
        cout << "car " << endl;
    }
};
```

USE CASE :  
<pre>
        employee
      /  |   |  \
   HR  mana  eng  others
   1    3    20    4

28 employees
</pre>
In order to calc salary we were running a loop on the array and calc each ka salary. But hume toh employee class mai bhi calsal() func banana padd raha tha.But how can we define in employee ke sal kaise calc hoga. So ideally it should be a pure virtual function as hum uski definition nai de sakte hai. 


# Friend Functions and Classes
Access Modifiers : so that we can restrict the acccess of that class.  

lets say we have a class truck  
private : x  
protected : y  
public : z  

class Bus  
 print()  

I want to acces the x of truck in my bus . We can do that with the help of friend function. Hum print() ko friend bana denge truck ka. So now bus can access all the props of truck.  

Here we have created afunction globally as well which is not a part of any class. Bcz we are calling friend func in our truck class and we haven't defined it before we might get an error so to avoid that we have defined it before . 
- friend functions won't have access to **this**  keyword. 
- we can put it under any access modifiers(priv , ublic , protec) it doesn't matter . 
- friendship is one way.