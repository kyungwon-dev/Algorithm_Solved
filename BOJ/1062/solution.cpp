#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
}
vector<int> words;

int calc(int k, int idx, int selected,char current){
    int answer = 0;
    if(k<0)
        return 0;
    if(idx == k){
        for(int word : words){
            if( (word & ( (1<<26) -1 - selected) ) == 0)
                answer++;
        }
        return answer;
    }
    for(char c = current;c<='z';c++){
        if( (selected & (1<<(c - 'a'))) != 0)
            continue;
        else{
            selected |= (1<<(c - 'a'));
            answer = max(answer, calc(k,idx+1,selected,c));
            selected &= ~(1<<(c - 'a')); 
        }   
    }
    
    return answer;
}

int main(){
    init();
    int n, k, selected = 0;
    cin >> n >> k;
    words.resize(n,0);
    
    char c[5] = {'a','n','t','i','c'};
    for(int i=0;i<5;i++)
        selected |= ( 1<< (c[i] - 'a'));   
        for(int i=0;i<n;i++){
            string str;
            cin >> str;
            for(int j=0;j<str.length();j++)
                words[i] |= ( 1 << (str[j] - 'a'));
        }

        cout << calc(k-5,0,selected,'a') << "\n";
    
    return 0;
}
