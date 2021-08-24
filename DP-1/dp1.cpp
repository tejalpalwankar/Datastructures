#include <iostream>
#include <cmath>
using namespace std;

//Brute force
int fibo(int n){
    if( n<= 1){
        return n;
    }

    int a = fibo(n-1);
    int b = fibo(n-2);

    return a + b;
}


// memoization (top down approach)
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

// Dynamic Programming (Bottom up approach)
int fibo_3(int n){
    int *ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;

    for(int i =2 ; i<= n ; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }

    return ans[n];
}

int countMinStepsToOne(int n)
{
	//Write your code here

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

// int balancedBTsOutOfrange(int h){
//     if(h <= 1){
//         return 1;
//     }

//     int x = balancedBTs(h - 1);
//     int y = balancedBTs(h - 2);

//     int ans = x*x + 2*x*y;
//     return ans;
// }
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
    // x** bhi out of range ja sakta hai
    // int ans = x*x + 2*x*y;

    return ans;
}

int main(){
    int n;
    cin >> n;
    // cout << fibo(n) << endl;
    // cout << countMinStepsToOne(n) << endl;
    cout << balancedBTs(n) << endl;
}