#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n, value;
    string str;
    cin >> n >> str;
    vector<double> val; // 알파벳에 해당하는 값 저장
    stack<double> s; // 후위표기법 계산을 위한 스택

    while (n--){
        cin >> value;
        val.push_back(value);
    }
    return 0;
}
