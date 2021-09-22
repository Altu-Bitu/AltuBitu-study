#include <iostream>
using namespace std;

int factorial(int n){
    int result=1;
    if (n==1 || n==0){
        return result;
    }else{
        return n*factorial(n-1);
    }
}

int main(){
    int n, k, result;
    cin >> n >> k;
    result = factorial(n)/(factorial(k)*factorial(n-k));
    cout << result;

    return 0;
}

