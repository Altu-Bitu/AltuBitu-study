//
// Created by 이은우 on 2021-09-09.
//

#include <iostream>

using namespace std;

bool isGroup(string str){
    //알파벳 개수 크기의 배열로 이미 등장한 알파벳 check
    bool alphabet[26] = {false};

    alphabet[str[0]-'a'] = true;
    for (int i=1; i<str.length(); i++){
        //전 자리 문자와 같은 경우 continue
        if (str[i]==str[i-1]) continue;
        else{ //새로운 문자 등장
            if (alphabet[str[i]-'a'])
                return false;
            else {
                alphabet[str[i]-'a'] = true;
            }
        }
    }
    return true;
}

int main(){
    int n, cnt=0;
    cin >> n;
    string str;

    while (n--){
        cin >> str;

        if (isGroup(str)) cnt++;
    }

    cout << cnt;
}
