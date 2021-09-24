#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

const int MAX = 1000000;
vector<bool> prime; // 소수 여부 저장하는 벡터

// 에라토스테네스의 체를 이용해 소수 판별
void isPrime(){
    //벡터 true로 초기화
    prime.assign(MAX+1, true);
    prime[0] = prime[1] = false; // 0과 1은 소수가 아니므로

    for (int i=2; i<=sqrt(MAX); i++){
        if (prime[i]){ // i가 소수라면
            for (int j=i*i; j<=MAX; j+=i){ // i의 배수 제거
                prime[j] = false;
            }
        }
    }
}

string goldbach(int n){

    for (int i=3; i<=n/2; i+=2){ // 홀수 소수인 i에 대해 반복문 실행, n의 절반을 넘어가면 반복되므로 n/2 까지만!
        if (prime[i] && prime[n-i]) // i가 소수일때 n-i도 소수가 되면 출력
            return to_string(n) + " = "+ to_string(i) + " + " + to_string(n-i);
    }
    return "Goldbach's conjecture is wrong.";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    isPrime(); // prime 벡터에 소수여부 저장

    while (true){
        cin >> n;
        if (n==0) break;
        cout << goldbach(n) << '\n';
    }
    return 0;
}



