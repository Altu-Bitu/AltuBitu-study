#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int main(){
    int n, m;
    string word;
    cin >> n >> m;
    map<string, int> mp;

    while (n--){
        cin >> word;
        // 입력받은 단어가 m 이하면 입력X
        if (word.size() < m) continue;
        // 입력받은 단어가 단어장에 없는 경우
        if (mp.find(word) == mp.end()){
            mp[word] = 0;
        }else mp[word]++;
    }
}
