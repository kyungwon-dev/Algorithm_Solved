#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member{
    int idx;
    int age;
    string name;
};

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const member a, const member b){
    if(a.age != b.age)
        return a.age < b.age;
    return a.idx < b.idx;
}

int main(){
    init();
    int n;
    cin >> n;
    vector<member> mem(n);
    for(int i=0;i<mem.size();i++){
        int age;
        string name;
        cin >> age >> name;
        mem[i].idx = i;
        mem[i].age = age;
        mem[i].name = name;
    }
    sort(mem.begin(),mem.end(),cmp);
    for(auto &m : mem)
        cout << m.age << " " << m.name << "\n";

    return 0;
}