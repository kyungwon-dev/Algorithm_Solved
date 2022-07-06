#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void candidate_password(vector<char> password, string candidate, 
                        int idx, int vowels, int consonant, int L){
    if(idx==password.size()){
        if(L == candidate.length()){
            if(vowels >= 1 && consonant >= 2){
                cout << candidate << "\n";
            }
        }
        return;
    }
   
    candidate.push_back(password[idx]);
    if(password[idx] == 'a' || password[idx] == 'e' || password[idx] == 'i' || 
       password[idx] == 'o' || password[idx] == 'u' )
        candidate_password(password,candidate,idx+1,vowels+1,consonant,L);
    else
        candidate_password(password,candidate,idx+1,vowels,consonant+1,L);
    candidate.pop_back();
    candidate_password(password,candidate,idx+1,vowels,consonant,L);
}


int main(){
    int L, C;
    cin >> L >> C;
    vector<char> password(C);
    for(int i=0; i<C; i++)
        cin >> password[i];
    sort(password.begin(),password.end());
    candidate_password(password, "", 0, 0, 0, L);
    return 0;
}