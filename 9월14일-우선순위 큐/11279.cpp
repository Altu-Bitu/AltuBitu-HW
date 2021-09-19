#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> heap_vec;

//empty
bool empty() {
	return heap_vec.size() == 1;
}

//push
void push(int num) {
	int idx = heap_vec.size();//이번에 push할 데이터의 인덱스
	heap_vec.push_back(num);

	//root=1에 도달하거나, 더 이상 상위노드보다 값이 크지 않다면 반복문 탈출
	while (idx !=1 && heap_vec[idx] > heap_vec[idx / 2]) {
		swap(heap_vec[idx], heap_vec[idx / 2]);//하위 노드와 상위노드의 값을 바꿈
		idx /= 2;//상위 노드로 이동
	}

}
//pop
int pop() {
	int item = heap_vec[1];
	swap(heap_vec[1], heap_vec[heap_vec.size() - 1]);//힙의 맨 마지막 값과 바꿈
	heap_vec.pop_back();//데이터 제거

		int parent = 1; 
	    int child = 2;
	while (child < heap_vec.size()) {
		//만약 오른쪽 하위노드가 존재하면 왼쪽 하위노드와 값을 비교하고,상위노드와 비교할 하위노드를 갱신
		if (child + 1 < heap_vec.size() && heap_vec[child] < heap_vec[child + 1])
			child++;
		if (heap_vec[parent] >= heap_vec[child])//나보다 큰 하위노드가 없다.
			break;
		swap(heap_vec[parent], heap_vec[child]);//상위노드와 하위노드의 값을 바꿈
		parent = child;
		child = parent * 2;//부모와 왼쪽 child는 2배 차이나서
	}
	return item;
}
int main() {
	//입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	priority_queue <int> pq;//우선순위 큐
	heap_vec.push_back(0);//인덱스가 1부터 시작하도록 0번에 0 넣어줌

	cin >> n;
	while (n--) {//n번 연산
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';//비어있지 않는 경우 최댓값을 꺼내라고 해서
				pq.pop();//그리고 최댓값 없애기
			}
		}
		else
			pq.push(x);//0이 아니면 자연수 queue에 넣기

		
	}
}