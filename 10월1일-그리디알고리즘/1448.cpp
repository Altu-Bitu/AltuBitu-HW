#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int makeTriangle(int n, vector<int>& straw) {//빨대 수, 빨대 길이들
    int ans = -1;//세 변 길이의 합 최솟값 초기화

    for (int i = 0; i < n - 2; i++) {//2개는 삼각형의 다른 변이어야해서
        if (straw[i] < straw[i + 1] + straw[i + 2]) { //삼각형이라면
            ans = straw[i] + straw[i + 1] + straw[i + 2];//길이 더해주기
            break;//나가기
        }
    }

    return ans;//최댓값 반환
}

/**
 * 세 변의 길이의 합이 최대가 되도록 삼각형을 만드는 문제
 * 주어지는 빨대의 길이를 내림차순 정렬한 후, 길이가 긴 빨대부터 그리디적으로 탐색
 * 현재 빨대 길이를 가장 긴 변의 길이라 가정하고 삼각형이 만들어지는지 확인하면 된다
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> straw(n, 0);//n개 숫자
    for (int i = 0; i < n; i++)
        cin >> straw[i];//벡터에 빨대 길이 집어넣기

    //연산
    sort(straw.begin(), straw.end(), greater<>());//오름차순

    //출력
    cout << makeTriangle(n, straw);//최댓값 구하기

    return 0;//종료
}