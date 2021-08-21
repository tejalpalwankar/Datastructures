#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "ourmap.h"
using namespace std;

vector<int> removeDuplicates(int* a, int size){
    vector<int> output;
    unordered_map<int , bool> seen;
    for (int i = 0; i < size; i++)
    {
        if(seen.count(a[i]) > 0){
            continue;
        }
        seen[a[i]] = true ;
        output.push_back(a[i]);
    }
    return output;

}




int main(){
/*     unordered_map<string , int> ourMap;

    // insert 1 way
    pair<string , int> p("abc", 1);
    ourMap.insert(p);

    // insert 2nd way
    ourMap["def"] = 2;

    //find or access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;

    // cout << ourMap.at("ghi") << endl; it will give an error key not found
    cout << ourMap["ghi"] << endl; // if it does not exist it will insert 0 and give 0 to you

    // check if key is present
    if(ourMap.count("ghi") > 0){
        cout << "ghi is present" << endl;
    }

    // size
    cout << "size : " << ourMap.size() << endl;

    // erase 
    ourMap.erase("ghi") ;

    cout << "size : " << ourMap.size() << endl;
    if(ourMap.count("ghi") > 0){
        cout << "ghi is present" << endl;
    }
    else{
        cout << "ghi is not present" << endl;

    }

 */

/* int a[] = {1,2,3,3,4,2,1,6,2,1,8,5,4,9};
vector<int> output = removeDuplicates(a,11);
for(int i=0 ; i<output.size() ; i++){
    cout << output[i] << endl;
} */

/* 
unordered_map<string, int> ourmap;
ourmap["abc"] = 1;
ourmap["abc1"] = 2;
ourmap["abc2"] = 3;
ourmap["abc3"] = 4;
ourmap["abc4"] = 5;
ourmap["abc5"] = 6;

unordered_map<string, int> :: iterator it = ourmap.begin();
while(it != ourmap.end()){
    cout << "key : " << it->first << " Value: " << it->second << endl;
    it++;
}

//find 
unordered_map<string, int>::iterator it2 = ourmap.find("abc");
ourmap.erase(it2, it2 + 4);// it will dlt all the ele from it2 , it2 + 1 , it2 + 2


vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);

vector<int>::iterator it1 = v.begin();
while(it1 != v.end()){
    cout << *it1 << endl;
    it1++;
}
 */

ourmap<int> map;
for (int i = 0; i < 10; i++)
{
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    int value = i+ 1;
    map.insert(key, value);
    cout << map.getLoadFactor() << endl;
}
cout <<"size :" << map.size() << endl;

map.remove("abc2");
map.remove("abc7");

for (int i = 0; i < 10; i++)
{
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    cout << key << " : " << map.getValue(key) << endl;
}

cout <<"size :" << map.size() << endl;
}
