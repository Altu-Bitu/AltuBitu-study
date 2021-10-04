#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    while (n--){
        int p,l;
        cin >> p >> l;

        vector<int> y(p);

        for (int i=0; i<p; i++){
            cin >> y[i];
        }

        // 신청인원이 수강가능인원보다 작을경우
        // 모든 신청자가 들을 수 있으므로 1마일리지 투자
        if (p<l){

        }
        // 오름차순으로 마일리지 정렬
        sort(y.begin(), y.end(), greater<int>());
        // 수강가능인원-1 번째 사람의 마일리지 만큼 투자
    }

    return 0;
}

