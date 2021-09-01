# allocation 
jabhi hum statically allocate karte hai tabhi stack mai karte hai. jabhi humdynamically allocate karte hai toh heap mai karte hai. Toh heap mai kya store hota hai  
**new int** new int muje uss memory ka address laake de dega but isse toh koi naam he nai hai.so lets store it  
int *p = new int; 

# 2D array
What are basically 2 D aary.  
If aI want a array of size 10 , 20. 
TThat means I want to create 10 array of size 20. mtalb muje arrya banana padetga which is stirring the int pointers. So isiliye muje int double pointer chaitye hoga ais akarne.  
int **p = new int*[10];  
```C++
int main(){
int **p = new int*[10];  
for(int i =0 ; i < 10; i++){
    p[i] = new int[n];
    for(int j = 0 ; j < n ; j++){
        cin >> p[i][j];
}
}

// pehle sab arry ko individually dlt karna . baadme pura dlt karo
for(int i =0 ; i < 10; i++){
    delete [] p[i] ;
}
delete [] p;
}
```