#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
using namespace std;

struct info{
    int block;
    set<string> mail;
};


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string,info> rs;

    for(auto id : id_list) rs[id];
    for(auto rp : report){
		istringstream ss(rp);
        string user[2];
        string tmp;
        int idx=0;
        while(getline(ss,tmp, ' '))
            user[idx++] = tmp;
        int size = rs[user[0]].mail.size();
        rs[user[0]].mail.insert(user[1]);
        if(rs[user[0]].mail.size() != size)
        	rs[user[1]].block++;
    }
	for(auto id : id_list){
        int cnt = 0;
        set<string>::iterator iter;
        for(iter = rs[id].mail.begin();iter != rs[id].mail.end();iter++){
            if(rs[*iter].block >= k)
                cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}