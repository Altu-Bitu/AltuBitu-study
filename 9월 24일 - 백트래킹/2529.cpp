#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10; // k가 최대 9

int k; // 부등호의 개수
bool is_find; // 찾음 여부 저장할 변수
vector<char> op(SIZE); //부등호
vector<int> arr(SIZE), num(SIZE); // arr:몇번째 자리에 어떤 숫자 오는지, num:사용할 숫자
vector<bool> check(SIZE); // 숫자의 사용 여부 저장할 벡터

//수열을 문자열로 바꾸는 함수
string arrToString(vector<int> &arr) {
    string result; // 문자열로 바뀔 수열 저장할 변수
    for (int i = 0; i <= k; i++)
        result += (arr[i] + '0');
    return result; // 문자열로 바뀐 수열 리턴
}

//과정에서의 답이 가능성 있는 답인지 체크하는 함수
bool promising(int idx) {
    if (op[idx] == '<' && arr[idx] > arr[idx + 1]) //부등호가 '<'인데 '>'관계일 때
        return false; // 가능성 없음
    if (op[idx] == '>' && arr[idx] < arr[idx + 1]) //부등호가 '>'인데 '<'관계일 때
        return false; // 가능성 없음
    return true; // 위 모든 조건을 통과하면 나머지는 true
}

//최댓값 or 최솟값 구하는 백트래킹 함수 (num배열을 통해 구분)
void findValue(int cnt) {
    //수가 2개 이상이 배치됐다면, 주어진 부등호 만족하는지 검사, 
    if (cnt >= 2 && !promising(cnt - 2))
        return; // 만족하지 않으면 바로 리턴 (가지치기)
    if (cnt == k + 1) { //부등호 만족하는 수를 찾음 (기저조건)
        is_find = true; // 찾음
        return; // 함수 종료
    }
    for (int i = 0; i <= k; i++) { //num[i]: 최댓값이면 9 ~ (9-k), 최솟값이면 0 ~ k
        if (!check[num[i]]) { // num[i]가 쓰이지 않은 경우
            check[num[i]] = true; // num[i] 쓰인것으로 표기
            arr[cnt] = num[i]; // cnt번째 자리에 num[i] 
            findValue(cnt + 1); // 재귀함수로 cnt+1 자리의 수
            if (is_find) // 문자열을 끝까지 다 찾았다면
                return; // 함수 종료
            check[num[i]] = false; // 재귀에서 다음 연산을 위해 check배열 다시 false로 되돌려주기
            arr[cnt] = 0; // 재귀에서 다음 연산을 위해 cnt번째 자리의 수를 0으로 초기화
        }
    }
}

/**
 * [백트래킹 풀이] (0ms)
 * 수를 중복없이 배치함 (N과 M(1)과 동일)
 * 수를 배치할 때마다 해당 수가 그 전 수와 부등호 관계를 만족하는지 확인, 만족하지 않으면 back (가지치기)
 */

int main() {
    string max_num, min_num; //정답

    //입력
    cin >> k; // 부등호 개수
    for (int i = 0; i < k; i++) { // k개만큼
        cin >> op[i]; // 부등호 입력
    }

    //최댓값 연산
    for (int i = 0; i <= k; i++) //num배열에 값 미리 저장
        num[i] = 9 - i; //최댓값은 9부터 (9-k)까지 숫자로 이루어짐
    findValue(0); // 최댓값 구하기
    max_num = arrToString(arr); // 최댓값 저장

    //초기화 !주의! 전역변수 사용 시 초기화 빼먹기 쉬우니 잘 체크하자
    is_find = false; // 못 찾은 것으로 초기화
    check.assign(SIZE, false); // 모든 숫자 사용X로 초기화
    arr.assign(SIZE, 0); // cnt번째 자리 수 0으로 초기화

    //최솟값 연산
    for (int i = 0; i <= k; i++)
        num[i] = i; //최솟값은 0부터 k까지 숫자로 이루어짐
    findValue(0); // 최솟값 구하기
    min_num = arrToString(arr); // 최솟값 저장

    //출력
    cout << max_num << '\n' << min_num; // 최댓값 최솟값 

    return 0;
}
