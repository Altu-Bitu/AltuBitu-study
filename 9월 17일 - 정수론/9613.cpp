#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) //b가 0이면 a가 최대공약수
        return a;
    //a%b구한 후 b와 자리 바꾸어서 호출
    return gcd(b, a % b);
}

int main(){
    int n, t, v;
    cin >> t;

    while (t--){
        long long sum = 0;

        cin >> n;
        vector<int> num(n);

        for (int i=0; i<n; i++){
            cin >> num[i];
        }

        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                sum += gcd(num[i], num[j]);
            }
        }
        cout << sum << "\n";
    }

    return 0;
}

