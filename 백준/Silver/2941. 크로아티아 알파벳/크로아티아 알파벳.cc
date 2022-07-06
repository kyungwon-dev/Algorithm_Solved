#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string str;
    cin >> str;
    string croatia[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    for(int i=0;i<8;i++){
        while(str.find(croatia[i]) != string::npos){
            str.replace(str.find(croatia[i]),croatia[i].size(),to_string(i));
        }
    }
    cout << str.length() << "\n";
    return 0;
}