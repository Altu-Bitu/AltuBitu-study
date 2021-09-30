#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n,m; // n개의 수 중 m개 고르기
int num[7];
set<int> s;

void backtracking(int cnt){ // cnt : num 배열의 인덱스
    if (cnt == m){ // 기저조건, 길이 m인 수열 만든 경우
        for (int i=0; i<cnt; i++){
            cout << num[i] << ' '; // 출력
        }
        cout << '\n';
        return;
    }
    for (auto iter=s.begin(); iter!=s.end(); iter++){
        num[cnt] = *iter;
        backtracking(cnt+1);
    }
}

int main(){

    // 입력
    cin >> n >> m;

    int val;
    for (int i=0; i<n; i++){
        cin >> val;
        s.insert(val);
    }

    // 연산 + 출력
    backtracking(0); // 인덱스 0 부터 수열 제작
    return 0;
}

