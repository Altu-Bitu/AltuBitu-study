//
// Created by 이은우 on 2021-09-09.
//
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, B, C;
    vector<int> A;
    cin >> N;
    for (int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    cin >> B;
    cin >> C;

    int cnt=0;

    for (int i=0; i<N; i++){
        if (B>=A[i]) cnt++; // 총 감독만 필요한 경우
        else {
            A[i] -= B; // 보조감독이 감독해야 하는 학생 수
            if (A[i]%C==0) // 나누어 떨어지는 경우
                cnt += A[i]/C;
            else
                cnt += A[i]/C +1;
        }
    }
    cout << cnt;
    return 0;
}
