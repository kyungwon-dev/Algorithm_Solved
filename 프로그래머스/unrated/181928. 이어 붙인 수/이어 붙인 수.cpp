#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string even = "", odd = "";
    for(int i=0; i< num_list.size();i++){
        if(num_list[i]%2 == 0){
            even += ('0' + num_list[i]);
        }
        else{
            odd += ('0' + num_list[i]);
        }
        
    }
    
    return stoi(even) + stoi(odd);
}