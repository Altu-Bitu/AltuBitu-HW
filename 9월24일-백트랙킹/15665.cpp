#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7; //배열 크기

int n, m;
int num[SIZE], ans[SIZE];//num배열과 답 배열

void backtracking(int cnt) {
    if (cnt == m) { //길이 m이라면 (기저조건)
        for (int i = 0; i < m; i++)//출력
            cout << ans[i] << ' ';//m까지 출력
        cout << '\n';//한 줄에 하나씩
        return;
    }
    int value = -1; //이전에 선택한 값
    for (int i = 0; i < n; i++) {
        if (value != num[i]) { //이전에 탐색한 값이 아니라면(=해당 수 사용 가능하다면)
            value = num[i];//이미 정렬된 상태이므로 만약 중복된 수가 나온다면 바로 뒤에 나올 것이므로 num[i]값 value에 넣기
            ans[cnt] = num[i];//답 배열에 넣기
            backtracking(cnt + 1);//인덱스 증가 시켜서 호출
        }
    }
}

/**
 * [백트래킹 풀이] (184ms)
 * 해설 : https://myunji.tistory.com/309
 */
int main() {
    //입력
    cin >> n >> m;//n개의 숫자 중에서 m개의 수를 골라 수열 ,같은 수를 골라도 되나 중복되는 수열은 안됨
    for (int i = 0; i < n; i++)
        cin >> num[i];//n개의 숫자를 num수열에 입력

    //연산
    sort(num, num + n);//n개의 숫자 오름차순 정렬

    //연산 + 출력
    backtracking(0);//0부터 시작하는 함수 호출
}