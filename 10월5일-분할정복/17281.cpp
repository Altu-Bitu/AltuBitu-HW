#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings;//각 선수가 각 이닝에서 얻는 결과
vector<int> order(10, 0); //타순
vector<bool> check(10, false);//각 선수들이 타순이 정해졌는지 확인하기 위해
int n, ans;

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) {//아웃 되기 전까지
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10)//타순은 9까지 밖에 없으므로
                idx = 1;//다시 1로 만들어주기
            switch (state) {//현재 선수의 공격 상태에 따라
            case 0://0인경우
                out++;//아웃 더해주고
                break;//루프 나가기
            case 1: //안타, 1루씩 진루
                score += baseman[3]; //3루에 있는 선수있다면 홈 도착
                for (int i = 3; i > 0; i--)//각 선수들
                    baseman[i] = baseman[i - 1];//옮겨주기
                baseman[1] = 1; //새로운 선수 1루에 도착
                break;//나가기
            case 2: //2루타, 2루씩 진루
                score += baseman[3] + baseman[2]; //3루, 2루에 선수 있다면 홈 도착
                baseman[3] = baseman[1]; //1루 -> 3루 이동
                baseman[2] = 1; //새로운 선수 2루에 도착
                baseman[1] = 0; //초기화
                break;
            case 3: //3루타, 3루씩 진루
                for (int i = 3; i > 0; i--) { //3루, 2루, 1루에 선수 있다면 홈 도착
                    score += baseman[i];
                    baseman[i] = 0;// 다 홈 도착하니까 0으로
                }
                baseman[3] = 1; //새로운 선수 3루에 도착
                break;
            case 4: //홈런
                for (int i = 3; i > 0; i--) { //3루, 2루, 1루에 선수 있다면 홈 도착
                    score += baseman[i];
                    baseman[i] = 0;// 다 홈 도착하니까 0으로
                }
                score++; //새로운 선수도 홈 바로 도착
                break;
            }
        }
    }

    return score;//점수 반환
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1);//5번 타자로 가능한 배치 , 재귀 호출
        return;
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score);//최댓값을 정답으로
        return;
    }
    for (int i = 2; i <= 9; i++) {
        if (!check[i]) {//만약 2번 선수부터 9번 선수까지 타순이 정해져 있지 않다면
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자
            check[i] = false;//가능한 배치를 다 해봐야해서
        }
    }
    
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    //입력
    cin >> n;//이닝 수
    innings.assign(n, vector<int>(10, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> innings[i][j];//각 선수가 각 이닝에서 얻는 결과 입력 받기
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    array(1);

    //출력
    cout << ans << '\n';//최대 점수 출력

    return 0;//종료
}