#include <iostream>
#include <vector>

using namespace std;

//역추적
vector<int> back(int x, vector<int>& path) { //x = n부터 역추적 시작
    vector<int> result(0);//0으로 초기화
    while (x != 0) {//경로가 없을 때까지
        result.push_back(x);//연산 과정 결과 배열에 x넣어주기
        x = path[x];//그 전 연산값으로 교체
    }
    return result;//배열 반환
}

//1로 만드는 최소 연산 횟수 리턴
int makeOne(int n, vector<int>& path) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int min_value = dp[i - 1]; //우선 i - 1 연산 횟수 저장
        path[i] = i - 1;//일단 i경로에 i-1연산  저장
        if (!(i % 3) && min_value > dp[i / 3]) {//i가 3으로 나누어 지지 않고 3으로 나눴을 경우 몫을 연산하였을 경우 연산 횟수가 그 전 수보다 작을 경우
            min_value = dp[i / 3];//더 작은 값으로 min_value교체
            path[i] = i / 3;//i경로에 3으로 나눈 몫으로 저장
        }
        if (!(i % 2) && min_value > dp[i / 2]) {//i가 2으로 나누어 지지 않고 2으로 나눴을 경우 몫을 연산하였을 경우 연산 횟수가 그 전 수보다 작을 경우
            min_value = dp[i / 2];//더 작은 횟수로 min_value교체
            path[i] = i / 2;//경로에 2로 나눈 몫 저장
        }
        dp[i] = min_value + 1;//1로 만들어야 하니까
    }
    return dp[n];//횟수 반환
}

/**
 * 기본 문제: 1로 만들기
 *
 * [점화식]
 * dp[i] = (i에 가능한 연산을 적용한 수 중 최소 연산 횟수) + 1
 * dp[i] = min(dp[i / 3], dp[i / 2], dp[i - 1]) + 1
 *
 * [역추적]
 * path: 인덱스가 정수를 나타냄, 해당 수에서 연산을 적용한 다음 수를 저장
 * n부터 역추적 시작
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> path(n + 1, 0); //경로 저장

    //연산
    int ans = makeOne(n, path);//연산 횟수
    vector<int> result = back(n, path);//연산 경로

    //출력
    cout << ans << '\n';
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';//연산 경로 출력
    return 0;//종료
}