#include <iostream>
#include <vector>

using namespace std;

//cnt명이 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값
int jumpDist(vector<int>& stones, int cnt) {//돌 수
    int dist = 1, prev = -1; //건너뛴 칸, 이전에 밟은 디딤돌
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] >= cnt) { //밟을 수 있음,cnt명이 밟아도 0보다 크거나 같으니까
            dist = max(dist, i - prev);//이전에 밟은 거 빼주고 둘 중 한번에 최대로 뛸 수 있는 칸 갱신
            prev = i;//디딤돌 밟은 개수? (맞나요?)
        }
    }
    dist = max(dist, (int)stones.size() - prev); //개울의 오른쪽 건너편까지 이동
    return dist;//최댓값 반환
}

int upperSearch(vector<int>& stones, int left, int right, int target) {
    int ans = 0;//건널 수 있는 수의 최댓값
    while (left <= right) {
        //mid만큼의 친구들이 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값은 몇칸인가?
        int mid = (left + right) / 2;//mid 
        int jump = jumpDist(stones, mid);//mid명일때 건너뛰어야 하는 디딤돌 칸 수의 최댓값

        if (jump <= target) {//target보다 작을때는 
            ans = mid;//최댓값에 mid 넣어주고
            left = mid + 1;//left값 바꿔주기
        }
        else if (jump > target)//target보다 클 때에는
            right = mid - 1;//수를 줄여야 하므로 right값 바꿔주기
    }
    return ans;//최댓값 반환
}

/**
 * 징검다리를 건널 수 있는 니니즈 친구들의 최댓값
 * -> 니니즈 친구들 n명이 징검다리를 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값이 k보다 작은가?
 *
 * left : 배열의 원소가 1이상이기 때문에 최소한 1명은 건널 수 있음
 * right : 아무리 많이 건너도 배열 원소의 최댓값보다 많은 인원이 건널 수는 없음
 */
int solution(vector<int> stones, int k) {
    int right = 0; //배열 원소의 최댓값
    for (int i = 0; i < stones.size(); i++)
        right = max(right, stones[i]);//각 돌이 가지고 있는 수 중에 최댓값 찾아내기

    return upperSearch(stones, 1, right, k);//함수 호출
}

int main() {
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };//각 돌의 수
    int k = 3;//최대 3칸만 뛸 수 있음
    cout << solution(stones, k);//최댓값
}