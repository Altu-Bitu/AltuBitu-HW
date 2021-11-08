#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> immigration;//각 심사대에서 심사하는데 걸리는 시간

//심사를 받는데 걸리는 시간이 tot_time일 때, 심사를 받을 수 있는 사람의 수
ll cntPeople(ll tot_time) {
    ll cnt = 0;//받을 수 있는 사람 수
    for (int i = 0; i < immigration.size(); i++)
        cnt += (tot_time / immigration[i]);//심사하는 데 걸리는 시간 안에 몇 명을 심사할 수 있는지
    return cnt;//심사할 수 있는 사람 수 반환
}

ll lowerSearch(ll left, ll right, int target) {
    ll ans = 0;//걸리는 시간의 최솟값
    while (left <= right) {//left와 right가 만나기 전까지 계속
        //심사를 받는데 걸리는 시간이 mid일 때, 몇 명의 친구들이 심사를 받을 수 있는가?
        ll mid = (left + right) / 2;//중간 값
        ll entrance = cntPeople(mid);//중간값을 cntPeople에 넣었을 경우 심사 받을 수 있는 사람 수

        if (entrance >= target) {//위에서 구한 사람 수가 상근이와 친구들의 수보다 크다면
            ans = mid;//최솟값은 mid로 두고 만약 아직 target과 같지 않다면 left보다 right값이 더 클 것이므로 계속 루프 
            right = mid - 1;//right값 옮겨주기
        }
        else if (entrance < target)//아직 상근이와 친구들의 수에 도달하지 못했다면
            left = mid + 1;//left값 옮기기
    }
    return ans;//최솟값 반환
}

/**
 * 상근이와 친구들이 심사를 받는데 걸리는 시간의 최솟값
 * -> 시간이 t만큼 주어질 때, m명 이상의 친구들이 입국 심사를 받을 수 있는가?
 *
 * left : 모든 심사대의 심사 시간이 k이고, 심사대가 친구들의 수만큼 주어진다면 걸리는 시간은 k
 * right : 심사가 가장 오래 걸리는 심사대 k에서 모든 친구들이 한명씩 입국심사를 받는다면, 걸리는 시간은 k*m
 *
 * !주의! right k*m의 최댓값은 심사 시간의 최댓값 10^9와 m의 최댓값 10^9를 곱한 10^18이다.
 * 그러므로 long long 범위를 써야 함.
 */
int main() {
    int n, m;//심사대 개수 , 상근이와 친구들 수
    ll max_time = 0, min_time = 1e9;//최댓값이랑 최솟값 초기화

    //입력
    cin >> n >> m;
    immigration.assign(n, 0);//심사대에서 걸리는 시간 초기화
    for (int i = 0; i < n; i++) {
        cin >> immigration[i];//심사대에서 걸리는 시간 입력 받기
        max_time = max(max_time, immigration[i]);//각 심사대에서 걸리는 시간과 max값 비교해서 max값 갱신
        min_time = min(min_time, immigration[i]);//각 심사대에서 걸리는 시간과 min값 비교해서 min값 갱신
    }

    //연산 & 출력
    cout << lowerSearch(min_time, max_time * m, m);
}