#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int source, dest, amount;//택배 올리는 곳,택배 내리는 곳, 택배량
};

int greedyBox(int n, int m, int c, vector<info>& box) {
    vector<int> truck(n, 0);
    int ans = 0; //싣게되는 박스의 총 개수

    for (int i = 0; i < m; i++) {
        int max_loaded = 0;
        //현재 박스의 이동 구간에서 가장 많이 실린 박스의 수
        for (int j = box[i].source; j < box[i].dest; j++)//택배 출발하는 마을부터 종착 마을까지
            max_loaded = max(max_loaded, truck[j]);//계속 싣게 되는 박수 수랑 비교해서 더 큰 것을 max_loaded에 넣기

        //이번에 실을 수 있는 박스의 수는 트럭의 용량에서 max_loaded를 뺀 값과, 이번 박스의 개수 중 최솟값
        int loaded = min(box[i].amount, c - max_loaded);
        ans += loaded;//이번에 싣는 박스 수 더하기

        //트럭에 박스 실음
        for (int j = box[i].source; j < box[i].dest; j++)
            truck[j] += loaded;//박스 수 더하기
    }
    return ans;//최댓값 반환
}

/**
 * 그리디 알고리즘인 이유
 * 조건 3: 박스들 중 '일부'만 배송할 수도 있다.
 *
 * 1. 트럭은 1번 마을부터 출발
 * 2. 트럭에 여유 공간이 많아야 박스를 많이 실을 수 있음
 * -> 도착지가 1번 마을에서 가까운 박스 먼저 싣는다
 * -> 도착지 기준 오름차순 정렬
 *
 * 도착지 기준 오름차순 정렬을 해야 하는 이유
 * 1. 시작지 기준 오름차순 정렬을 할 경우, 내리는 마을이 멀어지면 트럭이 오래 박스를 싣게 되어 비효율적
 * 2. 도착지 기준 오름차순 정렬을 할 경우, 박스를 빨리 내리게 되어 효율적
 * 3. 시작지-도착지의 거리를 기준으로 정렬을 할 경우, 사이 거리는 짧지만 도착지가 먼 경우를 처리하지 못함
 */
int main() {
    int n, c, m;

    //입력
    cin >> n >> c >> m;//마을 수, 트럭 용량 제한 ,보내는 택배표 행 
    vector<info> box(m);
    for (int i = 0; i < m; i++)//표 행이 m개임
        cin >> box[i].source >> box[i].dest >> box[i].amount;//입력

    //연산
    sort(box.begin(), box.end(),//오름차순 정렬
        [](const info& i1, const info& i2) { //익명 함수로 compare 정의
            return i1.dest < i2.dest;//더 먼 종착지를 벡터 뒤쪽에 있게
        });

    //연산 & 출력
    cout << greedyBox(n, m, c, box);//최대 박스 수
}