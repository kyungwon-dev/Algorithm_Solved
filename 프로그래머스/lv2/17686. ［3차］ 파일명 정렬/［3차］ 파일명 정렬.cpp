#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <algorithm>
using namespace std;

struct fileName{
    int index;
    string head;
    string number;
    string tail;
    
};

bool compare(struct fileName &a, struct fileName &b){
    string a_head;
    string b_head;
    for(char &ch : a.head){
        a_head.push_back(tolower(ch));
    }
    for(char &ch : b.head){
        b_head.push_back(tolower(ch));
    }
    
    if(a_head != b_head){
        return a_head<b_head;
    }
        
    if(stoi(a.number) != stoi(b.number)){

        return stoi(a.number) < stoi(b.number);
    }
        
    return a.index < b.index;
    
}
    

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fileName> sortList(files.size());
    regex isFile("^([a-zA-Z -.]+)([0-9]{1,5})([a-zA-Z -.0-9]+)*");
    smatch match;
    for(int i=0;i<files.size();i++){
        if(regex_match(files[i],match,isFile)){
            sortList[i].index = i;
            sortList[i].head = match[1].str();
            sortList[i].number = match[2].str();
            sortList[i].tail = match[3].str();
        }
    }
    
    sort(sortList.begin(),sortList.end(),compare);
    for(struct fileName &a : sortList){
        answer.push_back(a.head+a.number+a.tail);
        
    }
    
    return answer;
}