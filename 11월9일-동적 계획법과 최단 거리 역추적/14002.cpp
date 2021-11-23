//
// Created by BaeSuA on 2021-11-09.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<int> back(int x, vector<int>& path) {
    vector<int> result(0); //Lis의 마지막 원소 인덱스부터 들어감
    while (x != -1) {//경로가 없을 때까지
        result.push_back(x);//현재 정점 넣어주기
        x = path[x]; //다음 경로
    }
    return result;//수열 
}

//시간 복잡도 O(n^2) Lis
ci lis(int n, vector<int>& arr, vector<int>& path) {
    vector<int> dp(n, 1);//순서
    ci ans = { 1, 0 }; //최장 길이, 마지막 원소 인덱스

    for (int i = 1; i < n; i++) {
        int index = -1; //경로 저장할 변수
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { //증가하는 관계, 가장 큰 dp[j] + 1
                dp[i] = dp[j] + 1;//dp[j] 다음으로 와야하니까
                index = j;//증가하는 수열에서 그 전 숫자 저장
            }
        }
        path[i] = index;//나중에 역추적 해야하니까 path[i]에 j저장
        if (ans.first < dp[i]) //최장 길이 + 마지막 원소 인덱스 갱신
            ans = { dp[i], i };//최장길이 , 마지막 원소 인덱스
    }
    return ans;//최장 길이 , 마지막 원소 인덱스
}

/**
 * 동적계획법 역추적
 * - 기본 문제: 가장 긴 증가하는 부분 수열
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n); //수열
    vector<int> path(n, -1); //경로 저장 배열
    for (int i = 0; i < n; i++)
        cin >> arr[i];//수열 입력 받기

    //연산
    ci ans = lis(n, arr, path); //first: 최장 길이, second: 최장 길이의 마지막 원소 인덱스
    vector<int> result = back(ans.second, path);//최장 길이의 마지막 원소 인덱스랑 경로 받아서 역추적

    //출력
    cout << ans.first << '\n';//최장 길이 출력
    for (int i = result.size() - 1; i >= 0; i--)//경로 출력
        cout << arr[result[i]] << ' ';
    return 0;//종료
}