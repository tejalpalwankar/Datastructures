# Fibonnaci1  
Using recursion 
## BRUTE FORCE
```C++ 
int fibo(int n){
    if( n<= 1){
        return n;
    }

    int a = fibo(n-1);
    int b = fibo(n-2);

    return a + b;
}
```
COMPLEXITY : 2^n

## MEMOIZATION (Recursive) TOP DOWN APPROACH

Complexity : K constant work in every recursive call. 2^(n-1)*k  , it is a gp series  
n2^n which is exponential , so it is worst complexity.  
At some point we are doing repetitive work. Like on both sides of recursion we will need the fibo num of 4.So lets try to save ans of 4 and when we use next time directly waha se uthao instead of recalc.  
**So there will be (n+1) unique ans for this**
So I will make a array ans with size n+1  
ans[i] = ith fibo num  
CHECK IF ANS EXISTS  
YES : return  
NO : calc , save for future use , return 

```C++
int fibo_helper(int n,int *ans){
    if(n<=1){
        return n;
    }

    // check if o/p already exists
    if(ans[n] != -1){
        return ans[n];
    }

    int a = fibo_helper(n-1, ans);
    int b = fibo_helper(n-2, ans);

    // Save the o/p in arr for future use
    ans[n] = a + b;

    //return the final op
    return ans[n];
}

int fibo_2(int n){
    int *ans = new int[n+1];

    // nai toh we won't know usme apna ans hai ya garbage value
    for(int i= 0 ; i<= n ; i++){
        ans[i] = -1;
    }
    return fibo_helper(n, ans);
}
```
COMPLEXITY : O(n)  
so the complexity has changed from O(n) to O(2^n)  
### This process is known as MEMOIZATION . It is a top down approach where we can save  our ans and improve complexity

# Fibonacci2 - DYNAMIC PROGRAMMING (Iterative) BOTTOM UP APPROACH
SPACE OMPLEXITY IS BETTER IN THIS  
In the prev prob we have a array :  
0 1 2 3 4 5 
and we are going from 5 to 0 for recursive calls and then 0-5 for filling the array.So why are we doing double work using recurion , we can fill the array iteratively also.  
So to calc 5th fibo num we will need 4th and 3rd.  
0 is not dependent on anyone so we know the ans of 0.so we know the ans of 0 , 1 so we can figure out others easily.  

```C++
int fibo_3(int n){
    int *ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;

    for(int i =2 ; i<= n ; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }

    return ans[n];
}
```
COMPLEXITY : O(n)

# Min steps to 1

Suppose we have a num n and we have to reduce it to 1.  
Operations allowed :  
1. Decrement the number by 1   , n-1
2. Divide by 2, n/2 if n%2 == 0  
3. Divide by 3, n/3 if n%3 == 0  
7 -> 6 -> 5 -> 4 -> 3, 1 ...  
     | -> 3 -> 1 , 1  
     | -> 2 -> 1, 1  
    Min no of steps : 3 (7,6,2,1)  

10 -> 5 -> 4 -> 2 -> 1 min count = 4  
10 -> 9 -> 3 -> 1      min count = 3  


## Brute Force 

Ask recursion to count min steps req by  
x = n-1  
y = n/2    
z = n/3     
and return the min(x,y,z) + 1 bcz ek step humne bhi cover kiya hai.  
CAUTION : Initialize y, z by INT_MAX other it will have garbage value , and if we put 0 it will come as the min val. 
```C++ 
#include <climits>;
int countMinStepsToOne(int n)
{

    if(n <= 1 ){
        return 0;
    }

    int x = countMinStepsToOne(n -1);
	int y = INT_MAX;
    int z = INT_MAX;
    if(n%2 == 0){
        y = countMinStepsToOne(n/2);
    }
    if(n%3 == 0){
        z = countMinStepsToOne(n/3);

    }

    return min(x , min(y,z)) + 1;  
}
```
<pre>
Input : 12   12 -> 6 -> 3 -> 1
Output : 3

Input : 10  10 -> 9 -> 3 -> 1
Output : 3

Input : 20  20 -> 10 -> 9 -> 3 -> 1
Output : 4
</pre>

## Memoization 
```C++ 
#include <climits>;

int minSteps(int n, int *ans)
{
   
    if(n <= 1 ){
        return 0;
    }
	
    if(ans[n] != INT_MAX){
        return ans[n];
    }

    int x = minSteps(n -1, ans);
	int y=INT_MAX;
    int z = INT_MAX;
    if(n%2 == 0){
        y = minSteps(n/2, ans);
    }
    if(n%3 == 0){
        z = minSteps(n/3, ans);

    }
	ans[n] = min(x, min(y,z)) + 1;
    return ans[n];
    
}

int countMinStepsToOne(int n){
    int *ans = new int[n+1];

    // nai toh we won't know usme apna ans hai ya garbage value
    for(int i= 0 ; i<= n ; i++){
        ans[i] = INT_MAX;
    }
    return minSteps(n, ans);
}
```
COMPLEXITY : O(n)
## Dynamic Programming

```C++ 
int countStepsToOne(int n)
{
    int *ans = new int[n+1];
    ans[1] = 0;

    for(int i =2 ; i<= n ; i++){
        int x = ans[i-1];
        int y=INT_MAX;
        int z = INT_MAX; 
        if(i%2 == 0){
            y = ans[i/2];
        }
        if(i%3 == 0){
            z = ans[i/3];

        }

        ans[i] = min(x, min(y,z)) + 1;
    }

    int output = ans[n];
    delete [] ans;
    return output;

}
```
COMPLEXITY : O(n)

# Staircase 

## recursive - brute force
```C++ 
int staircase(int n ){
    if(n == 0 || n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }

        return staircase(n-1) + staircase(n-2) + staircase(n-3);
    
}
```
## Dynamic programming
if there are 0, 1 steps only 1 way is possible  
idf there are 2 steps 2 ways are possible  
else we will go from 0-n i.

```C++ 
long staircase(int n)
{
	//Write your code here
    int *ans = new int[n+1];
	ans[0] = 1;
	ans[1] = 1;
	ans[2] = 2;
    
    int x =0, y=0, z=0;
    for(int i = 2 ; i <= n ; i++){
        x = ans[i- 1] ;
        y = ans[i- 2] ;
        z = ans[i- 3] ;
        ans[i] = x + y + z;
        
    }
    
    int output = ans[n];
    delete [] ans;
    return output;
}
```

#  Minimum Count
Q. Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.  
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

n = 1  1^2   = 1  
n = 2  1^2 + 1^2  = 2  
n = 3  1^2 + 1^2 + 1^2  = 3  
n = 4  1^2 + 1^2 + 1^2 + 1^2 = 3  
    2^2 = 1  
n = 5  1^2 + 1^2 + 1^2 + 1^2 + 1^2  = 5  
     1^2 +  2^2 = 2  

Approach :
## recursive 
n = x^2  + y^2 + .....  
I just need to figure out the 1st value  
1st val x = 1^2 , 2^2 , 3^2 ....  
recursive call : (n - 1^2)  

If n =10 we assume x = 1^2 and call recursion on (n - 1^2) = 10-1 = 9  
return ans + 1;
in n=10 we will call recursion 3 times pn 1^2 ,2^2 , 3^2  
Not on 4 bcz 4^2 = 16 which is greater than 10

## Dynamic Programming

```C++ 
int minCount(int n)
{
    //Write your code here
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;


    for(int i = 4; i <= n ; i++){
        ans[i] = i;
        for(int j = 1; i - j*j >= 0 ; j++){
            ans[i] = min(ans[i] ,1 + ans[i - (j*j)]);      
        }
    }

    return ans[n];
}
```

## Memoization

```C++ 
int minCounthelper(int n , int *ans)
{
    //Write your code here
    if( sqrt (n) -floor(sqrt(n))==0)
    {   ans[n]=1;
        return ans[n];
    }
    if(n < 4){
        return n;
    }
	if(ans[n] != INT_MAX){
        return ans[n];
    }
	
    int arr = n;
        for(int i = 1; n - i*i >= 0 ; i++){
            ans[n] = arr = min(arr,1 + minCounthelper(n - (i*i), ans));      
        }

    return ans[n];
}
```

# No. of Balanced Trees  
h = 1  
1 possible
<pre>
    root
</pre>

h = 2  
3 possible
<pre>
    root   root   root 
    /        \    /  \
</pre>

h = 3  
15 are possible
<pre>
        root
        /  \
       *    *
      / \  / \
     *   * *  *   level 3
</pre>
So level 3 pe total 4 nodes hai n iske har node ke 2 combination are possible ,either it is there or not .  
so 2^n = 2^4 = 16  
but there will be 1 case where no nodes at all  
**2^n - 1** = 16 - 1 = 15  
level = 4 : 2^8 - 1 = 256 - 1 = 255  
this is wrong ans should be 315  
THIS APPROACH  HAS SOMETHING MISSING  
we assumed till level 3 it is  a complete binary tree but level 3 can be half filled as well
<pre>
        root
        /  \
       *    *
      / \    \
     *   *    *   level 3
    /
  *
</pre>
This is also a Balanced binary tree  

## Recursive - brute force  
<pre>
        root
        /  \
       O    O -> O is a subtree
    h-1    h-1
    h-1    h-2
    h-2    h-1
</pre>
Count these 3 combinations and return
x = h-1  
y = h-2  
x*y  ,x*x , y*y
```C++ 
int balancedBTs(int h){
    if(h <= 1){
        return 1;
    }

    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    int ans = x*x + 2*x*y;
    return ans;
}
```
Output:
3 - 15  
4 - 315  
5 - 108675  
6 - -1006181013  
So the prob here is 6 ke liye the ans is negative , as the range of our int is -2^31 to 2^31  
we can take the return type as long , it will be out of range of long as well  
So generally when our ans is too long we :  
**ans% (10^9 + 7)**

Code :
isme bhi value out of range jaa sakti hai so iska individually mod lete hai
```C++ 
    int ans = x*x + 2*x*y;


    int temp1 = (x*x) % mod;
    int temp2 = (2*x*y) % mod;
    int ans = (temp1 + temp2) % mod;
```  
(x*x) now as both are int , int x int = int  
but x*x bhi out of range ja sakta hai so we have to save this ans in long , fir mod leke int hoga then we haive to typecast it.
So our final code is 
```C++ 
int balancedBTs(int h){
    if(h <= 1){
        return 1;
    }

    int mod = (int)(pow(10,9)) + 7 ;
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    int temp1 = (int)(((long long)(x)*x) % mod);
    int temp2 = (int)((2*(long long)(x)*y) % mod);
    int ans = (temp1 + temp2) % mod;

    return ans;
}
```
Now all are values are in range
<pre>
6 - 878720798
7 - 396813529
8 - 533723121
</pre>

COMPLEXITY : T(h) = T(h-1) + T(h-2)  -> 2^n

## Memoisation 

```C++ 
#include <cmath>

int balancedBTshelper(int h, int *ans){
    if(h == 1){
        return 1;
    }
    if(h == 2){
        return 3;
    }
    
    if(ans[h] != -1){
        return ans[h];
    }

    int mod = (int)(pow(10,9)) + 7 ;
    int x = balancedBTshelper(h - 1, ans);
    int y = balancedBTshelper(h - 2, ans);

    int temp1 = (int)(((long long)(x)*x) % mod);
    int temp2 = (int)((2*(long long)(x)*y) % mod);
	ans[h] = (temp1 + temp2) % mod;

    return ans[h];
}

int balancedBTs(int n){
    int *ans = new int[n+1];

    // nai toh we won't know usme apna ans hai ya garbage value
    for(int i= 0 ; i<= n ; i++){
        ans[i] = -1;
    }
    return balancedBTshelper(n, ans);
}

```

## Dynamic programming

```C++ 
#include <cmath>

int balancedBTs(int h){
	int *ans = new int[h+1];
	
    ans[1] = 1;
    ans[2] = 3;
    
    int mod = (int)(pow(10,9)) + 7 ;
    
    for(int i=3; i <= h ; i++){
        int x = ans[i-1];
        int y = ans[i-2];

        int temp1 = (int)(((long long)(x)*x) % mod);
        int temp2 = (int)((2*(long long)(x)*y) % mod);
        ans[i] = (temp1 + temp2) % mod;

  }
    return ans[h];
}
```