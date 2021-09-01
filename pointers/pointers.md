# array and pointers

```C++
int a[] ;

// dono same hai
cout << a << endl;
cout << &a[0] << endl;

address of 1st elee 
cout << *a << endl;
cout << *(a + 1) << endl;

int* p = &a[0];

cout << a << end; 
cout << p << end; 

cout << &a << end; 
cout << &p << end; 

cout << sizeOf(p) << end;
cout << sizeOf(a) << end;

p = p + 1;
p = a + 1;

```
<pre>
0x7bfdf0
0x7bfdf0
10      
20      
0x7bfdf0
0x7bfdf0
0x7bfdf0
0x7bfde8
8
40
</pre>
3 ways :
- a[i] , i[a], *(a + i)

# double pointers 

int *p = &i;   
int**p2 = p ; double pointers are pointers storing address of pointers.  

```C++ 
int main(){
    int i = 10;
    int *p = &i;
    int **p2 = &p;
    
    cout << p2 << endl;
    cout << &p << endl;

    cout << p << endl;
    cout << *p2 << endl;
    cout << &i << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;

}
```
<pre>
0x7bfe08
0x7bfe08
0x7bfe14
0x7bfe14
0x7bfe14
10
10
10
</pre>

```C++ 
// ye bolra hai muje double pointer dedo mai tumahre double pointer ko increase karunga.But isme p mai uski copy ban gayi and uske copy mai changes hore hai toh apna pointer change nai hoga
void increment1(int **p){
    p = p + 1;
}

// abhi ye jaake pointer ka address change karega.
// ** = 730
// * = 900 -> 904 toh uska address change hoga
// toh changes reflect hojayege
void increment1(int **p){
    *p = *p + 1;
}

// changes reflect honge
void increment1(int **p){
    **p = **p + 1;
}

```