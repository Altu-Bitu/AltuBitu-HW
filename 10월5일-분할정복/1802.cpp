#include <iostream>
#include <algorithm>

using namespace std;

bool divide(string str) {//str을 매개변수로 받는 함수
    //Conquer : 문자열의 길이가 1
    if (str.size() == 1)//만약 str의 길이가 1이면 끝, 길이가 1이면 종이접기가 끝나기때문에
        return true;//true반환

    //Combine : 가운데 값을 기준으로 접었을 때, 만나게 되는 각 자릿수가 같다면 접을 수 없음
    int len = str.size();//str 길이 정수
    for (int i = 0; i < len / 2; i++) {//가운데 숫자를 중심으로 양쪽의 숫자가 같지 않은지 확인하기 위해서
        if (str[i] == str[len - i - 1])//만약 가운데를 기준으로 왼쪽과 오른쪽의 숫자가 같다면
            return false;//동호 방식으로 접지 못함
    }

    //Divide : 문자열을 절반으로 나누기
    return divide(str.substr(0, len / 2));//절반 잘라서 계속해서 확인
}

/**
 * 1. 가운데를 중심으로 접었을 때, 만나게 되는 각 자릿수가 다르다면 접을 수 있음
 * 2. 문자열의 길이가 1이 될 때까지 종이 접기
 *
 * (ex1)
 * 100 0 110
 * 0을 기준으로 접으면 100과 011이 겹쳐짐 -> 접을 수 있음
 *
 * 100에 대해 다시 가운데를 기준으로 나누면 1 0 0
 * 0을 기준으로 접으면 1과 0이 겹쳐짐 -> 접을 수 있음
 *
 * (ex2)
 * 0 0 0
 * 0을 기준으로 접으면 0과 0이 겹쳐짐 -> 접을 수 없음
 */
int main() {
    int t;//테스트 케이스 개수
    string str;//종이 접기 문자열

    cin >> t;
    while (t--) {
        //입력
        cin >> str;

        //연산
        bool ans = divide(str);//접을 수 있는지 없는지 확인

        //출력
        cout << ((ans) ? "YES" : "NO") << '\n';//true면 yes 아니면 no
    }
}