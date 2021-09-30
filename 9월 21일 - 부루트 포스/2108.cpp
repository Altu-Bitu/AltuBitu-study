#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int cnt[8001] = {0, }; // 빈도수 저장할 배열. 절대값이 4000이라 size는 8001
vector<int> num;

// 최빈값
int mode(){
    int max=0, m, max_num=0;
    for (int i=0; i < 8001; i++){
        if (max < cnt[i]){
            max = cnt[i];
            max_num = 1;
            m = i-4000;
        }else if(max==cnt[i]) max_num++;

        if (max==cnt[i] && max_num==2)
            m = i-4000;
    }
    return m;
}

int main(){

    int n, val, sum=0, num_max, num_min;

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> val;
        sum += val;
        num.push_back(val);
        cnt[val+4000]++;
    }

    sort(num.begin(), num.end());
    num_max = num[n-1]; num_min = num[0];
  
    // 출력
    cout << round((double) sum/n ) << "\n"; // 산술평균
    cout << num[n/2] << "\n"; // 중앙값
    cout << mode() << "\n"; // 최빈값
    cout << num_max - num_min; // 범위

    return 0;
}

