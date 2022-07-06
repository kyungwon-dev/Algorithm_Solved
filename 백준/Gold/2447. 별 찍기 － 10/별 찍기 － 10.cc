#include <iostream>

using namespace std;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}

void star(int i, int j, int N){
    if( (i/N) % 3 == 1 && (j/N)%3 == 1)
        cout << " ";
    else{
        if( N/3 == 0)
            cout << "*";
        else
            star(i, j, N/3);
    }
}

int main(){
    setup();
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            star(i, j, N);
        cout << "\n";
    }

    return 0;
}