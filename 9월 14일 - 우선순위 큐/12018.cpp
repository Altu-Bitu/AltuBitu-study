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
    }

    return 0;
}

