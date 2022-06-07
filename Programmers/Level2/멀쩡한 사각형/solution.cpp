using namespace std;

long long gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

long long solution(int w,int h) {
    long long answer = (long long) w * (long long) h;
    if(w==h)
        return answer - w;
    long long gcf = gcd(w,h);
    
    w = (long long) w / gcf; h = (long long)h / (long long)gcf;
    answer = answer - (w + h -1) * gcf;
    
    return answer;
}