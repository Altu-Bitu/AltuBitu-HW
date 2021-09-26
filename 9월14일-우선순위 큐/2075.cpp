#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
* 우선순위 큐(최소 힙)에는 가장 큰 수 부터 N번째 큰 수까지 총 N개의 숫자가 들어있음
* 가장 큰 수부터 N번째 큰수까지를 최소 힙에 넣었기때문에 root에 있는 값은 N번쩨 큰 수가 되는 것
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, input;
	priority_queue <int, vector<int>, greater<>> pq;//최소 힙, 정렬이랑 반대,

	cin >> n;
	int size = n * n;
	while (size--) {
		//입력
		cin >> input;

		//연산
		if (pq.size() < n)//우선순위의 큐가 N보다 작다면 그냥 투입
			pq.push(input);
		else if (pq.top() < input) {//우선순위 큐의 크기가 N이상이라면 root노드보다 input이 클 때만 갱신
			pq.pop();
			pq.push(input);
		}
	}
	//출력
	cout << pq.top();


}