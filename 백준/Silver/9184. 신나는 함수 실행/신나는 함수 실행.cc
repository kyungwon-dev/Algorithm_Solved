#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int table[21][21][21];
bool check[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        if(check[a][b][c] == false){
            table[a][b][c] = 1;
            check[a][b][c] = true;
        }        
        return table[a][b][c];
    }
    if(a > 20 || b > 20 || c > 20){
        if(check[20][20][20] == false){
            table[20][20][20] = w(20, 20, 20);
            check[20][20][20] = true;
        }
        return table[20][20][20];
    }
    if(a<b && b<c){
        if(check[a][b][c-1] == false){
            table[a][b][c-1] = w(a,b,c-1);
            check[a][b][c-1] = true;
        }
        if(check[a][b-1][c-1] == false){
            table[a][b-1][c-1] = w(a, b-1, c-1);
            check[a][b-1][c-1] = true;
        }
        if(check[a][b-1][c] == false){
            table[a][b-1][c] = w(a, b-1, c);
            check[a][b-1][c] = true;
        } 
        return table[a][b][c-1] + table[a][b-1][c-1] - table[a][b-1][c];
    }
    else{
        if(check[a-1][b][c] == false){
            table[a-1][b][c] = w(a-1,b,c);
            check[a-1][b][c] = true;
        }
        if(check[a-1][b-1][c] == false){
            table[a-1][b-1][c] = w(a-1, b-1, c);
            check[a-1][b-1][c] = true;
        }
        if(check[a-1][b][c-1] == false){
            table[a-1][b][c-1] = w(a-1, b, c-1);
            check[a-1][b][c-1] = true;
        } 
        if(check[a-1][b-1][c-1] == false){
           table[a-1][b-1][c-1] = w(a-1, b-1, c-1);
           check[a-1][b-1][c-1] = true;
        } 

        return table[a-1][b][c] + table[a-1][b-1][c] + table[a-1][b][c-1] - table[a-1][b-1][c-1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    table[0][0][0] = 1;
    check[0][0][0] = true;
    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1)
            return 0;
        cout << "w("  << a  << ", " << b << ", " << c << ") = ";
        if(a<=0 || b<=0 || c<=0)
            cout << w(0, 0, 0) << "\n";
        else
            cout << w(a, b, c) << "\n";
    } 
    return 0;
}