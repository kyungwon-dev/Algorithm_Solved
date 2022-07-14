#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <queue>

using namespace std;

string menu = "";
vector<string> answer;
int alpha[100] = {0};
int mx_cnt = 2;

void make_menu(int course, string select, vector<string> orders, int idx){
    if(select.length() == course){
        int cnt = orders.size();
        vector<bool> isOk(orders.size(),true);
        
        for(auto s : select){
            for(int i=0;i<orders.size();i++){
                if(isOk[i] == false)
                    continue;
                if(orders[i].find(s) == string::npos){
                    isOk[i] = false;
                    cnt--;
                }
            }
        }
        
        
        if(cnt >= mx_cnt){
            if(cnt > mx_cnt)
                answer.clear();   
            sort(select.begin(),select.end());
            answer.push_back(select);
            mx_cnt = cnt;
        }
            
        return;
    }
    
    for(int i=idx;i<menu.length();i++){
        select.push_back(menu[i]);
        make_menu(course, select, orders, i+1);
        select.pop_back();
    }
}
struct cook{
    char c;
    int cnt;
    cook(char a, int b){
        c = a;cnt = b;
    }
    bool operator< (const cook &ck) const{
        if(ck.cnt == cnt)
            return ck.c < c;
        return ck.cnt > cnt;
    }
};

vector<string> solution(vector<string> orders, vector<int> courses) {
    vector<string> rs;
    // 알파벳 카운팅
    for(auto &order : orders){
        for(auto o : order)
            alpha[(int)o]++;
        sort(order.begin(),order.end());
    }
    
    priority_queue<cook> pq;
    // 알파벳 순 삽입
    for(int i=0;i<100;i++){
        if(alpha[i]>=2){
            pq.push(cook(char(i),alpha[i]));
        }
    }
    
    // 가장 많이 나온 순으로 menu 문자열 생성
    while(!pq.empty()){
        menu += pq.top().c;
        pq.pop();
    }
    
    for(auto course : courses){
        if(course > menu.length())
            continue;
        make_menu(course, "", orders,0);        
        mx_cnt = 2;
        for(auto a : answer)
            rs.push_back(a);
        answer.clear();
    }
    sort(rs.begin(),rs.end());
    return rs;
}