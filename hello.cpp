#include <iostream>
using namespace std;

void printCountHelper(int **edges , int n , int sv ,int* visited){
    visited[sv] = true;

    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && edges[sv][i] == 1){
            printCountHelper(edges , n , i , visited);
        }
    }
}

int printCount(int **edges, int n){

    int *visited = new int[n];

    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }

    int count = 0;
    for(int i =0 ;i < n ; ++i){
        if(!visited[i] ){
            printCountHelper(edges, n , i, visited);
            ++count;
        }
    }
    return count;

}

int main() {
    // Write your code here
    int n , e;
    cin >> n >> e;
    if(e == 0){
		cout << n << endl;
    }
	else{
    int** edges = new int*[n];

    for(int i =0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j =0 ; j < n ; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i <  e ; i++){
        int f , s;
        cin >> f >> s; 
        edges[s][f]  = 1;
        edges[f][s]  = 1;
    }

    // int  count = printCount(edges , n);
    cout << printCount(edges , n) << endl;
        
    // cout << count << endl;
    }  

}
