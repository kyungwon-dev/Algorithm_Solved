#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(vector<int> numbers, string hand) {
    /*
    1 2 3
    4 5 6
    7 8 9
    * 0 #
    */
    string answer = "";
    int hands[2][2];
    hands[0][0] = 3;
    hands[0][1] = 0;
    
    hands[1][0] = 3;
    hands[1][1] = 2;

    for(int num : numbers)
    {
        if(num == 1|| num == 4 || num == 7)
        {
            hands[0][0] = num / 3;
            hands[0][1] = 0;
            answer += "L";
        }
        else if(num == 3|| num == 6 || num == 9)
        {
            hands[1][0] = (num / 3) - 1;
            hands[1][1] = 2;
            answer += "R";
        }
        else
        {
            if(num == 0)
                num = 11;
            int l_len = abs((num/3)-hands[0][0]) + abs(1 - hands[0][1]);
            int r_len = abs((num/3)-hands[1][0]) + abs(1 - hands[1][1]);
                        
            
            if(l_len > r_len)
            {
                answer += "R";
                hands[1][0] = num/3;
                hands[1][1] = 1;
            }
            else if(l_len < r_len)
            {
                answer += "L";
                hands[0][0] = num/3;
                hands[0][1] = 1 ;
            }
            else
            {
                
                answer += (hand[0] == 'r' ? "R" : "L");
                int i = (hand[0] == 'r' ? 1 : 0 );
                hands[i][0] = num/3;
                hands[i][1] = 1;

            }
            
            
        }
        
    }
    
    
    return answer;
}