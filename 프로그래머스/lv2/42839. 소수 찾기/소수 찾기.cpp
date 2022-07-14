#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if(n <=1)
        return false;
    if(n <= 3)
        return true;
    for(int i=2;i<=(n/2+1);i++){
        if( (n%i) ==0)
            return false;
    }
    return true;
        
}

void makeStringtoNumber(vector<int> &candidate_numbers, string numbers, string number, int idx){
    if(idx >=numbers.length() ){
        if(number.length()>0){
            //cout<<idx<<"\n";
            sort(number.begin(),number.end());
            do{
                int num = stoi(number);
                if(isPrime(num))
                    candidate_numbers.push_back(num);

	    }while(next_permutation(number.begin(),number.end()));
        }
        
        return;
    }
    makeStringtoNumber(candidate_numbers, numbers,number,idx+1);
    makeStringtoNumber(candidate_numbers, numbers,number+numbers[idx],idx+1);    
        
}


int solution(string numbers) {
    int answer = 0;
    //vector<char> tokenNumbers;
    vector<int> candidate_numbers;
//     for(char c : numbers){
//         int num = c -'0';
//         if(isPrime(num))
//             candidate_numbers.push_back(num);
//     }
        
//     sort(numbers.begin(),numbers.end());   
//     do{
//         int num = stoi(numbers);
//         if(isPrime(num))
//             candidate_numbers.push_back(num);

// 	}while(next_permutation(numbers.begin(),numbers.end()));
    
    
     makeStringtoNumber(candidate_numbers, numbers,"",0);
//     reverse(numbers.begin(),numbers.end());
//     makeStringtoNumber(candidate_numbers,numbers ,"",0);
//     //makeStringtoNumber(candidate_numbers, numbers,"",0);
//     //cout << candidate_numbers.size() << "\n";
    sort(candidate_numbers.begin(),candidate_numbers.end());
    
    candidate_numbers.erase(unique(candidate_numbers.begin(),candidate_numbers.end()),candidate_numbers.end());
    //for(int i : candidate_numbers)
        //cout<<i<<"\n";
    return candidate_numbers.size();
}