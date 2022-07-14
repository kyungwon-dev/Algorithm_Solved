#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;
struct car{
    bool out;
    int tot_time;
    int sub_time;
};

vector<string> tknz(string str, char token){
    istringstream ss(str);
    vector<string> rs;
    string tmp;
    while(getline(ss,tmp,token)){
        rs.push_back(tmp);
    }
    return rs;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, car> parking_pee;
    map<string, car>::iterator it;
    
    for(auto record : records){
        vector<string> rs = tknz(record,' ');
        it = parking_pee.find(rs[1]);
        vector<string> time = tknz(rs[0],':');
        if(it == parking_pee.end())
            parking_pee[rs[1]];
        if(parking_pee[rs[1]].out){
            //cout << stoi(time[0]) * 60 + stoi(time[1]) << "\n";
            parking_pee[rs[1]].tot_time += stoi(time[0]) * 60 + stoi(time[1]) - parking_pee[rs[1]].sub_time;        
            parking_pee[rs[1]].sub_time = 0;        
            parking_pee[rs[1]].out = !parking_pee[rs[1]].out;
        }
        else{
            parking_pee[rs[1]].sub_time = stoi(time[0]) * 60 + stoi(time[1]);
            parking_pee[rs[1]].out = !parking_pee[rs[1]].out;
        }
        //cout << rs[1]<< " " << parking_pee[rs[1]].tot_time <<" " << parking_pee[rs[1]].sub_time << "\n";
    }
    for(it=parking_pee.begin();it!=parking_pee.end();it++){
        
        if(it->second.out == true){
            it->second.tot_time += 23*60 + 59 - it->second.sub_time;
            it->second.sub_time = 0;
        }
        
        if(it->second.tot_time < fees[0]){
            answer.push_back(fees[1]);
        }
        else{
            int plus = (it->second.tot_time - fees[0]) % fees[2] == 0? 0 : 1;
            answer.push_back(fees[1] + ((it->second.tot_time - fees[0]) / fees[2] + plus) * fees[3]);
        }
        //cout << it->first << " " << it->second.tot_time << " " << it->second.sub_time << "\n";
    }
    
    return answer;
}