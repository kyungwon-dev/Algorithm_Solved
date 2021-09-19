#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string new_id) {
    string answer = "";

    transform(new_id.begin(), new_id.end(),new_id.begin(), ::tolower);
    
    new_id = regex_replace(new_id,regex("[^a-z\.0-9\-\_]++"),"");  
    
    new_id = regex_replace(new_id,regex("[\.]+"),".");  
    
    new_id = regex_replace(new_id,regex("^[\.]|[\.]$"),"");  
    
    if(new_id.length() == 0)
        new_id = "a";
    if(new_id.length() > 15)
    {
        new_id = new_id.substr(0,15);
        new_id = regex_replace(new_id,regex("[\.]$"),"");  
    }
    if(new_id.length() < 3)
    {
        for(int i=0;i<2;i++)
        {
            new_id = new_id + new_id[new_id.length()-1];
            if(new_id.length()==3)
                break;
        }
    }
      //  new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());
    return new_id;
}