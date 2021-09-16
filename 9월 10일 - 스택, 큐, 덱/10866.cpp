#include <iostream>
#include <queue>
using namespace std;

int main(){
    deque<int> dq;
    int n, input;
    string cmd;

    cin >> n;
    while (n--){
        cin >> cmd;
        if (cmd=="push_front"){
            cin >> input;
            dq.push_front(input);
        }else if (cmd=="push_back"){
            cin >> input;
            dq.push_back(input);
        }else if (cmd=="pop_front"){
            if (!dq.empty()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }else cout << "-1\n";
        }else if (cmd=="pop_back"){
            if (!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            } else cout << "-1\n";
        }else if (cmd=="size"){
            cout << dq.size() << "\n";
        }else if (cmd=="empty"){
            cout << dq.empty() << "\n";
        }else if (cmd=="front") {
            if (!dq.empty())
                cout << dq.front() << "\n";
            else cout << "-1\n";
        }else if (cmd=="back"){
            if (!dq.empty())
                cout << dq.back() << "\n";
            else cout << "-1\n";
        }
    }

    return 0;
}
