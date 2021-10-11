#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n , k;
	cin >> n >> k;//롤케이크 개수랑 자르는 수 제한
	vector <int> roll (n);//롤케이크들 집어넣을 벡터
	for (int i = 0; i < n; i++) {
		cin >> roll[i];
	}
	int cnt = 0;//길이가 10인 케이크 개수
	for (int i = 0; i < n; i++) {
			    if (roll[i] == 10) {//만약 케이크 길이가 10이라면
					cnt += 1;//개수에 1을 더하고
					roll[i] = 0;//해당 인덱스 배열을 0으로 초기화
				}
				else if ((roll[i] % 10) == 0 && k >= ((roll[i] / 10) - 1)){//롤케이크 길이를 10으로 나눈 게 0이거나 만약 해당 롤케이크를 자른다면 자른 횟수가 제한 횟수를 넘지 않는지 확인하기
					    cnt += (roll[i] / 10);//길이가 10인 롤케이크 개수 더하기
						k = k - ((roll[i] / 10) - 1);//제한 횟수에서 자른 횟수 빼기
						roll[i] = 0;//0으로 초가화
			    }
				else {//이제 남은 경우는 롤케이크 길이가 10단위가 아닌 경우
				while (roll[i] > 10 && k > 0) {//10보다 작은 건 잘라봤자 의미가 없고 자르는 횟수가 k번을 넘으면 안되니까
					cnt += 1;//만약 위의 조건 만족하면 자른 횟수 더하고
					k -= 1;//k에서 1 빼기
					roll[i] -= 10;//한번 잘랐으니까 10 빼기
					
				}
			}
			}
        
        cout << cnt;
		return 0;

}