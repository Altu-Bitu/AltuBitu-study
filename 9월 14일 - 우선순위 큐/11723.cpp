#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m;
    cin >> m;
    bool a[21] = {0};

    while (m--){
        string s;
        int n;
        cin >> s;
        if (s=="add"){
            cin >> n;
            a[n] = true;
        }else if (s=="remove"){
            cin >> n;
            a[n] = false;
        }else if (s=="check"){
            cin >> n;
            cout << a[n] << "\n";
        }else if (s=="toggle"){
            cin >> n;
            a[n] =! a[n];
        }else if (s=="all"){
            fill_n(a,21,1);
        }else
            fill_n(a,21,0);
    }
    return 0;
}
