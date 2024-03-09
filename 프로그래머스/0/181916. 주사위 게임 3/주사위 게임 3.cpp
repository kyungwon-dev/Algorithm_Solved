#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int a, int b, int c, int d) {
    int dice[7] = {0,};
    dice[a]++;dice[b]++;dice[c]++;dice[d]++;
    
    int diff = 0;
    int minValue = 7;
    
    for(int i=1;i<sizeof(dice) / sizeof(int); i++){
        if(dice[i] >= 1){
            diff++;
            minValue = min(minValue, i);
        }
    }
    
    if(diff == 2){
        int p=0;
        int q=0;
        int P=0;
        for(int i=1;i<sizeof(dice) / sizeof(int); i++){
            
            if(dice[i] >= 1){
                if(p==0){
                    p=i;
                } else{
                    q=i;
                }
            }
            if(dice[i] == 3) P=i;
        }

        if(P == 0)
            return (p+q) * (abs(p-q));
        if(P==q){
            q = p;
        }        
        return (10 * P + q) * (10 * P + q);
    }
    if(diff == 3){
        int p=0;
        int q=0;
        int r=0;
        int P = 0;
        for(int i=1;i<sizeof(dice) / sizeof(int); i++){
            if(dice[i] >= 1){
                if(p==0){
                    p=i;    
                } else if(q==0){
                    q=i;
                } else{
                    r=i;break;
                }
            }
            if(dice[i] >= 2) P = i;
        }
        if(P==p) return q * r;
        if(P==q) return p * r;
        return p* q;
    }
    if(diff == 4) return minValue;
    
    return a * 1111;
}