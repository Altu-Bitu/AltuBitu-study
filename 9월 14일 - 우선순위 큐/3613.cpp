//
// Created by 이은우 on 2021-09-17.
//
#include <iostream>

using namespace std;

bool isCpp(string s){
    // 1. 소문자만 사용
    for (int i=0; i<s.length(); i++){
        if ('A'<= s[i] && s[i]<='Z'){
            return false;
        }
    }
    // 2. 맨앞이나 뒤에 _ 사용X
    if (s.front()=='_' || s.back()=='_')
        return false;
    return true;
}

bool isJava(string s){
    // 1. 첫문자 소문자
    if (!islower(s[0])) return false;
    // 2. '_' 있다면 false
    if (s.find('_')!=string::npos) return false;
    return true;
}

string cToJava(string s){
    string result;
    for (int i=0; i<s.length(); i++){
        if (s[i]=='_'){
            result += s[i+1] - 'a' + 'A';
            i++;
        }else
            result += s[i];
    }
    return result;
}

string javaToC(string s){
    string result;
    for (int i=0; i<s.length(); i++){
        if ('A'<= s[i] && s[i]<='Z') {
            result += "_";
            result += s[i] - 'A' + 'a';
        }else
            result += s[i];
    }
    return result;
}

int main(){
    string input;
    cin >> input;

    if (isCpp(input) && isJava(input))
        cout << input;
    else if (isCpp(input)){
        cout << cToJava(input);
    }else if (isJava(input)){
        cout << javaToC(input);
    }else
        cout << "Error!";
    return 0;
}
