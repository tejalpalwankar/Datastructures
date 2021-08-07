#include <iostream>
#include <cstddef>
using namespace std;
// #include "stackUsingLL.h"
#include <stack>
#include <string>

bool isBalanced(string expression) 
{
    stack<char> s;
    for(int i=0 ; i< expression.length() ; i++){
 
			if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{'){
				s.push(expression[i]);
            
        }
        
         else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}'){
             if(s.empty()){
				return false;
             }
             int ch = s.top();
             s.pop();
             
             if(expression[i] == ')' && ch =='('){
                 return true;
                 continue;
             }
             else if(expression[i] == ']' && ch =='['){
                 return true;
                 continue;
             }
             else if(expression[i] == '}' && ch =='{'){
                 return true;
                 
                 continue;
             }
             else{
                return false;
             }
            
            }
        }

    
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}

// int main()
// {   
    // Pair<Pair<int , int>, int> p2;
    // p2.setY(10);
    // Pair<int, int> p4;
    // p4.setX(5);
    // p4.setY(16);

    // p2.setX(p4);

    // cout << p2.getX().getX() << " " << p2.getX().getY() << p2.getY() << " "  ;

 /*    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(10.67);
    p2.setY(20.89);

    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<char> p3; */
/* 
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << " " << s.empty() << " " << s.size() << endl;

    s.pop();
    s.pop();
    s.pop();

    cout << s.top() << " " << s.empty() << " " << s.size() << endl;

    s.pop();
    s.pop();
    s.pop();


    cout << s.top() << " " << s.empty() << " " << s.size() << endl;  */

    
    
// }