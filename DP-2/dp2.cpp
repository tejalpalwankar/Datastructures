#include <iostream>
using namespace std;
#include <climits>
#include <string>

int minCostPathHelper(int **input, int m, int n, int i, int j)

{
    //base case
    // agar humare cell out of range jaara hai return karna hai , 0 likege toh min ka val will be 0
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    //humara start point he m-1 , n-1  hua toh
    else if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    //recursive call
    int x = minCostPathHelper(input, m, n, i + 1, j);
    int y = minCostPathHelper(input, m, n, i, j + 1);
    int z = minCostPathHelper(input, m, n, i + 1, j + 1);

    // small calc
    int ans = min(x, min(y, z)) + input[i][j];

    return ans;
}

int minCostPath(int **input, int m, int n)
{
    return minCostPathHelper(input, m, n, 0, 0);
}

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

int lcs(string s , string t){
    // base case if any string is 0
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }

    // small calculation 
    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1) , t.substr(1));
    }

    // recursive calls
    else {
    int a = lcs(s.substr(1) , t);
    int b = lcs(s , t.substr(1));
    int c = lcs(s.substr(1) , t.substr(1));
    return max(a, max(b , c));
    }
}

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


int editDistance_DP(string s1, string s2 ) {
	// Write your code here
    int m = s1.size();
    int n = s2.size();
    int **output = new int*[m+1];
    
    for(int i = 0; i <= m; i++){
        output[i] = new int[n+1];
    }
    
	output[0][0] = 0;
    

    //fill 1st row
    for(int j = 1 ; j<= n ; j++){
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

int main()
{
    // int m, n;
    // cin >> m >> n;
    // int **input = new int *[m];
    // for (int i = 0; i < m; i++)
    // {
    //     input[i] = new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> input[i][j];
    //     }
    // }
    // cout << minCostPath(input, m, n) << endl;
    // cout << minCostPath_DP(input, m, n) << endl;
    // cout << lcs_DP("abcd" , "zxcd" ) << endl;
    // cout << editDistance("abcd" , "zxcd" ) << endl;

    int n;
    int weight[] = {5 , 1,8,9,2};
    int values[] = {4,10,2,3,1};
    int W = 15;
    cout < knapsack(weight , values, 5, W) << endl;
}