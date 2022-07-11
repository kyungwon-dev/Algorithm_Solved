#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    //char criteria;
    for(char &c : s){
        if(c==' ')
            continue;
        if( 'A' <= c && c <= 'Z'){
            if( c + n > 'Z')
                c = 'A' + ((c + n - 1) % 'Z');
            else
                c = c + n;
        }
        else{
            if( c + n > 'z')
                c = 'a' + ((c + n - 1) % 'z');
            else
                c = c + n;
        }         
    }
    
    
    return s;
}