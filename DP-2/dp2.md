# Min Cost Path 

We will get a matrix m x n  
We have to go from (0,0) -> (m-1, n-1)  
We can move in 3 direction , right , down and diagonal  
A[i] = cost of crossing the cell  

## Brute Force  

int x = right to end  (i+1 , j)  
int y = down to end  (i , j + 1)  
int z = diagonal to end  (i+1 , j + 1)  
min(x,y,z) + inp[i][j]  

Implementatio :
cell 1 = 0,1 -> m-1,n-1  
cell 2 = 1,1 -> m-1,n-1  
cell 3 = 1,0 -> m-1,n-1  
toh yaha continously humare start points change hore so hume i and j ko 0 karna padega  
```C++ 
#include <climits>

int minCostPathHelper(int **input, int m, int n, int  i , int j)

{
	//base case
    // agar humare cell out of range jaara hai return karna hai , 0 likege toh min ka val will be 0
    if(i >= m || j >= n){
        return INT_MAX;
    }
    
    //humara start point he m-1 , n-1 hua toh
    else if(i == m-1 && j == n-1){
        return input[i][j];
    }
    
    //recursive call
    int x = minCostPathHelper(input,m , n, i + 1, j);
    int y = minCostPathHelper(input,m , n, i , j + 1);
    int z = minCostPathHelper(input,m , n, i + 1, j + 1);

    // small calc
    int ans = min(x , min(y,z)) + input[i][j];
    
    return ans  ;
}

int minCostPath(int **input, int m, int n){
	return minCostPathHelper(input , m ,n , 0 , 0);
}
```

<pre>
Input :
4 4
1 7 9 2
8 6 3 2
1 6 7 8
2 9 8 2 
Output :
16
</pre>
COMPLEXITY : 
<pre>
            0,1
           / | \
       0,1  1,0  1,1
</pre>
So basically at every setp we are doing 3 recursive calls .So our complecity is 3^n which is the worst.  

## Memoisation  
m = 4 , n =5  
Your last call will be on 3 , 4 (m-1, n-1)  
(0,0) -> (3,4)  
i = 0->3 (m-1) = m unique combinations  
j = 0->4 (n-1) = n unique combinations  
So unique calls can be m x n  
So we must use 2D array to save our answers.  
So at one particular cell we are saving :  
output[i][j] = min cost from (i,j) to (m-1, n-1)  
Final ans : output[0][0] to (m-1,n-1)  
```C++ 
int minCostPathHelper_Mem(int **input, int m, int n, int i, int j, int **output)
{

    //to check humare matrix se bahar chala gaya toh
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    //Check if ans already exists
    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    //recursive call
    int x = minCostPathHelper_Mem(input, m, n, i + 1, j, output);
    int y = minCostPathHelper_Mem(input, m, n, i, j + 1, output);
    int z = minCostPathHelper_Mem(input, m, n, i + 1, j + 1, output);

    // small calc
    int a = min(x, min(y, z)) + input[i][j];

    //save ans for future use
    output[i][j] = a;

    return a;
}

int minCostPath_Memoization(int **input, int m, int n)
{
    int **ans = new int *[m];
    for (int i = 0; i < m; i++)
    {
        ans[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = -1;
        }
    }
    return minCostPathHelper_Mem(input, m, n, 0, 0, ans);
}

```
COMPLEXITY : Tima and space - O(m*n)  

## Dynamic Programming

1st cell ke dependancy is on 3 cell : left , right , down  
last cell is the only cell with no dependancy  
last row ke baju wala cells  also we can fill wih last row.  
last column from top to bottom with 
```C++ 
int minCostPath_DP(int **input, int m, int n){
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // Fill the last cell i.e destination 
    output[m-1][n-1] = input[m-1][n-1];

    // fill last row (right to left)
    for (int j =  n-2; j >= 0; j--)
    {
        output[m-1][j] = output[m-1][j + 1] + input[m-1][j];
    }

    // fill last column (bottom to top)
    for (int i =  m-2; i >= 0; i--)
    {
        output[i][n-1] = output[i + 1][n-1] + input[i][n-1];
    }
    
    //fill remaining cells 
    for(int i = m-2 ; i >=0 ; i--){
        for(int j = n-2; j>= 0; j--){
            output[i][j] =  min(output[i][j+1],min (output[i+1][j+1],output[i+ 1 ][j])) + input[i][j];
        }
    }

    return output[0][0];
}
```
<pre>
2 3
3 4 5 
6 7 8

OUTPUT :15

</pre>
COMPLEXITY : time and space O(m*n)  

# Longest common subsequence LCS  
S -> a b c d 
T -> b a d e a b    
Order of chars need to be maintained  , need not to be continous  
ad , ab are the 2 subsequences possible  with len 2 so longest is 2  

S -> a b c d e  
T -> c a d b e   
cdee , abe, ade here longest is 3  

S -> x y z  
T -> z x y  
z , xy here longest is 2  

Approach :  
S -> x | y z  
T -> x | x a y  
Do it for 1st letter and baaki is for recursion  
compare the 1st letter if it is similar call recursion on the rest of the string return ( 1 + x )  
S -> x | y z  
T -> z | x a y  
if both chars are not same  
case 1 : x is not in ans = a    
case 2 : z is not in ans = b  
case 2 : x and z both not in ans = c  
max(a,b,c)  

## Brute force
```C++ 
int lcs(string s , string t){
    // base case if any string is 0
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }

    // recursive calls
    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1) , t.substr(1));
    }

    else {
    int a = lcs(s.substr(1) , t);
    int b = lcs(s , t.substr(1));
    int c = lcs(s.substr(1) , t.substr(1));
    return max(a, max(b , c));
    }
}
```
<pre>
xyz  zxay
2
</pre>
Complexity : Exponential  with 3 calls (3^n) , with 2 calls (2^n)  
third call **lcs(s.substr(1) , t.substr(1))** can be redundant as we have already calculated this in the last 2 calls so this is unecessary . we can simplify using memoization  

## Memoization  
Suppose we have this  
S = abcd = 4 (m)  
T = xyzw = 4 (n)  
Here using brute force we will mai a really large num of calls  
max call : m, n  
min call : 0,0  
S => possible len 0 to m ,  (m + 1) unique calls  
T => possible len 0 to n ,  (n + 1) unique calls  
Total unique calls (m + 1 ) * (n + 1)  
ans[i][j] = lcs of S (len = i)  & T (len =j)  

```C++ 
int lcs_mem(string s , string t , int **output){
    int m = s.size();
    int n = t.size();

    // base case if any string is 0
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }

    // check if ans already exits 
    if(output[m][n] != -1){
        return output[m][n];
    }

    int ans;
    // recursive calls
    if(s[0] == t[0]){
        return 1 + lcs_mem(s.substr(1) , t.substr(1), output);
    }

    else {
    int a = lcs_mem(s.substr(1) , t, output);
    int b = lcs_mem(s , t.substr(1), output);
    int c = lcs_mem(s.substr(1) , t.substr(1), output);
    ans =  max(a, max(b , c));
    }

    // save your calculation
    output[m][n] = ans;

    return ans;
    //or return output[m][n]
}

int lcs_mem(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = -1;
		}
	}

	return lcs_mem(s, t, output);
}

```

Complexity :  
Time : (m + 1) x (n + 1) unique calls so O(mn) 
space : (m + 1) x (n + 1) output array created so O(mn) 



## Dynamic Programming  

output = (m + 1) * (n + 1)  
Output[i][j] = lcs of s (len = i)  
Output[i][j] = lcs of T (len = j)  
ans = Output[m][n]  

recursive calls : 
case 1 
S = abc  
T = xyz  
1st char match nai hua toh 3 recursive call  
But last cell ki val is dependent on 3 cells baju , upar , diagonal  
so the only cell not dependent on anyone is 1st cell  
No since if size of any of the 1 string is 0 we go in the base case so the 1st row n col will be filled with 0  
Now we can simply figure out x as uska upar , left and diag hume mil gaya hai . this way we can fill our array in left - right order  
<pre>
     0 1 2 3
  0  0 0 0 0
  1  0 x
  2  0
  3  0
</pre>

case 2 :  
S = a|bc  
T = a|de  
1st char match hua toh ans will be on doono ki 3-1 = len 2,2 bachi hai toh (2,2) pe so ans = 1 + (2,2)  


if(s[] == t[])  
To figure out konse do index ki val same hogi  
lets take a ex  
<pre>
    0 1 2 3   4 5
s = a b c d | e f    m=6
t = x y | z          n=4
i = 2 , j = 1  
</pre>
abhi hume konse 2 index ko compare karna hai ?  
we cannot compare i and j OR m and n  
It is actually  
m-i = 6 - 2 = 4  
n-j = 4 - 1 = 3

```C++ 

int lcs_DP(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];

	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
    }

    // fill 1st row
    for(int j = 0 ; j<= n ; j++){
        output[0][j] = 0;
    }

    // fill 1st col
    for(int i = 1 ; i<= m ; i++){
        output[i][0] = 0;
    }

    // i = len of s , j = len of t
    for(int i = 1; i <= m ; i++){
        for(int j = 1; j <= n ; j++){
            // check if 1st char matches
            if(s[m-i] == t[n-j]){
                output[i][j]  = 1 + output[i -1][j -1];
            }
            else{
                int a = output[i -1][j];
                int b = output[i][j- 1];
                int c = output[i -1][j - 1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }

    return  output[m][n] ;
}
```
COMPLEXITY : O(mn)

# Edit Distance
Q. Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.  
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character


S -> a b c  
T -> a c  
I want to make these to strings same  
I want to know which will need min operations  
here we need only 1 operation : insert b  
S -> a b c  
T -> a b c  

ex2 :  
S -> a b c  
T -> d c b  
dcb -> replace each char -> abc = 3 operations    
dcb -> remove d b and insert c -> 4 operations  
dcb -> replace d with a and delete b and insert b between a c = 3 operation  
So MIN OPERATIONS = 3  
We just want the count and do not have to update the string  

## Brute Force  
S -> a b c d  
T -> a x d z e 
We have to match 1st char and tell recursion to figure out rest  

S -> a b c d  
T -> z x c d 
Now 1st char is not same so we have to perform 3 opearions and see which has min count  
- insert : T -> a z x c d  and now ask recursion to get the rest and we have to return y + 1 becase 1 operation  
- delete : T -> x c d and recurive call and return z + 1  
- replace : T -> a x c d , recursion , return r + 1  
ANS = min(x,y,z)  

**IMPLEMENTATION** :
1. INSERT   
initially : 
s -> a b c  
T -> b c d  
After inserting  
s -> a | b c  
T -> a | b c d   
So here basically 1st string chota karke pass karn hai.   
2. DELETE    
initially : 
s -> a b c  
T -> b c d  
After inserting  
s -> a b c  
T -> b | c d   
after deleting 2nd string chota hoga     
3. UDATING :   
initially : 
s -> a b c  
T -> b c d  
After inserting  
s -> a | b c  
T -> a | c d   
So here basically 1st string chota karke pass karn hai.   


BASE CASE :  
S -> abc  
T -> 
Toh hume s ka size return karna hoga kyuki either T mai sab insert karna hai ya S mai sab delete karna hai  
```C++ 
#include <string>


int editDistance(string s1, string s2) {
	// Write your code here
    int m = s1.size();
    int n = s2.size();
    
    if(n == 0 || m == 0){
        return max(m, n);
    }
    
    if(s1[0] == s2[0]){
        return editDistance(s1.substr(1) , s2.substr(1));
    }
    else{
        int x = editDistance(s1.substr(1) , s2) + 1; // insert
        int y = editDistance(s1 , s2.substr(1)) + 1; // delete 
        int z = editDistance(s1.substr(1) , s2.substr(1)) + 1 ; // update
        return min(x , min (y, z));
    }

}
```

Complexity :every step 3 calls so O(3^n) for worst case  

## Memoization 

```C++ 
#include <string>
#include <climits>

int editDistance(string s1, string s2 ,int **output) {
	// Write your code here
    int m = s1.size();
    int n = s2.size();
    
    if(n == 0 || m == 0){
        return max(m, n);
    }
    
    if(output[m][n] != INT_MAX){
        return output[m][n];
    }
    int ans;
    
    if(s1[0] == s2[0]){
        return editDistance(s1.substr(1) , s2.substr(1), output);
    }
    else{
        int x = editDistance(s1.substr(1) , s2 , output) + 1;
        int y = editDistance(s1 , s2.substr(1), output) + 1;
        int z = editDistance(s1.substr(1) , s2.substr(1), output) + 1 ;
        ans = min(x , min (y, z));
    }
    
    output[m][n] = ans;
    return ans;

}

int editDistance(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = INT_MAX;
		}
	}

	return editDistance(s, t, output);
}
```

## Dynamic Programming  
refer to lsc . same as that
```C++ 
int editDistance_DP(string s1, string s2 ) {
	// Write your code here
    int m = s1.size();
    int n = s2.size();
    int **output = new int*[m+1];
    
    for(int i = 0; i <= m; i++){
        output[i] = new int[n+1];
    }
    
    //fill 1st row
    for(int j = 0 ; j<= n ; j++){
        output[0][j] = j;
    }
    
    //fill 1st col
    for(int i = 1 ; i<= m ; i++){
        output[i][0] = i;
    }
    
    for(int i = 1; i <= m ; i++){
        for(int j = 1; j <= n ; j++){
            if(s1[m-i] == s2[n-j]){
                output[i][j]  = output[i -1][j -1];
            }
            else{
                int a = output[i -1][j] ;
                int b = output[i][j- 1] ;
                int c = output[i -1][j - 1];
                output[i][j] = min(a, min(b, c))  + 1;
            }
        }
    }
    
    return output[m][n];

}
```

# Knapsack  
Q. A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?  

We are given wieghts and values of n items and we want to put those values in  a knapsack  
n -> 5  
W -> 10 3 2 5 20  
V -> 5 7 1 0 8    
Weight the knapsack can hold -> 16  
if we put : 0,1,2  W= 15 V =15 we will choose this as I am getting max value  
if we put : 0,3    W= 15 V =15  
if we put : 1,2,3  W= 10 V =8  

Approach : 
n = 5  
weight = 5 | 8 7 1 4  
Values = 3 | 1 0 10 9  
capacity = 15  
w = 5 either we can put or not put  
<pre>
        15
       / \
     10  15
val: 3    0
</pre>
base case : arr ka len 0  or maxweight = 0 

<pre>
           0  1 2 3 4
Input : W  5  1 8 9 2
        V  4 10 2 3 1 
Output : 
            weight  values
 0, 1, 2     14        16
 1, 2, 4     13        13
 0, 1, 3     15        17

 Output : 17 
</pre>


```C++ 
int knapsack(int *weight , int *values , int n , int maxWeight){

    //base case
    if(n ==0 || maxWeight == 0){
        return 0;
    }

    if(weight[0] > maxWeight){
        return  knapsack(weight + 1 , values + 1 , n - 1 , maxWeight) + values[0];
    }

    int x = knapsack(weight + 1 , values + 1 , n - 1 , maxWeight - weight[0]) + values[0];
    int y = knapsack(weight + 1 , values + 1 , n - 1 , maxWeight) + values[0];

    return max(x,y);
}
```