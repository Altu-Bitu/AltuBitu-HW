#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {//스위치 개수,학생이 가지고 있는 수, 스위치배열
    for (int i = number; i <= n; i += number) //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i];//스위치 바꿔주기

    return switches;//스위치 반환
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {//스위치 개수,학생이 가지고 있는 수, 스위치배열
    switches[number] = !switches[number];//학생이 가지고 있는 수의 배열 스위치 바꿔주기
    for (int i = 1; i < number; i++) {
        if ((number + i > n) || (switches[number - i] != switches[number + i])) //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break;
        switches[number - i] = !switches[number - i];//아니면 양쪽 바꿔주기
        switches[number + i] = !switches[number + i];//아니면 양쪽 바꿔주기
    }

    return switches;
}

/**
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m;//스위치개수, 학생 수
    int student, number;//학생 , 학생이 받은 수

    //입력
    cin >> n;
    vector<int> switches(n + 1, 0);//1번부터 시작이니까 사이즈를 n + 1
    for (int i = 1; i <= n; i++)
        cin >> switches[i];//스위치 상태 입력

    //입력 & 연산
    cin >> m;//학생 수
    while (m--) {//학생 수 만큼 반복
        cin >> student >> number;//입력
        if (student == 1)//남자학생이면
            switches = changeSwitchBoy(n, number, switches);//바꿔주기
        else//아니면 여자학생
            switches = changeSwitchGirl(n, number, switches);//바꿔주기
    }

    //출력
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' ';//스위치 처음부터 끝까지 출력
        if (i % 20 == 0)//20개씩 줄 바꿔주기
            cout << '\n';
    }
    return 0;//종료
}