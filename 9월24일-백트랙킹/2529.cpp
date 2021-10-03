#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

int k;//부등호의 개수
bool is_find;//부등호 관계를 만족시키는지
vector<char> op(SIZE); //부등호
vector<int> arr(SIZE), num(SIZE);//최대, 최소값이며 부등호 관계를 알아내기 위한 배열, 
vector<bool> check(SIZE);//숫자를 사용했는지 표시하기 위한 배열

//수열을 문자열로 바꾸는 함수
string arrToString(vector<int>& arr) {
    string result;
    for (int i = 0; i <= k; i++)
        result += (arr[i] + '0');//수열을 문자열로 변환 , 0추가 해서 숫자로 표현
    return result;//문자열 반환
}

//과정에서의 답이 가능성 있는 답인지 체크하는 함수
bool promising(int idx) {
    if (op[idx] == '<' && arr[idx] > arr[idx + 1]) //부등호가 '<'인데 '>'관계일 때면 부등호 관계가 성립하는 것이 아니므로 false
        return false;
    if (op[idx] == '>' && arr[idx] < arr[idx + 1]) //부등호가 '>'인데 '<'관계일 때  부등호 관계가 성립하는 것이 아니므로 false
        return false;
    return true; //위의 관계가 아니라면 true
}

//최댓값 or 최솟값 구하는 백트래킹 함수 (num배열을 통해 구분)
void findValue(int cnt) {
    //수가 2개 이상이 배치됐다면, 주어진 부등호 만족하는지 검사, 만족하지 않으면 바로 리턴 (가지치기)
    if (cnt >= 2 && !promising(cnt - 2))
        return;
    if (cnt == k + 1) { //부등호 만족하는 수를 찾음 (기저조건)
        is_find = true;//부등호 관계 만족
        return;
    }
    for (int i = 0; i <= k; i++) { //num[i]: 최댓값이면 9 ~ (9-k), 최솟값이면 0 ~ k
        if (!check[num[i]]) {//num[i]가 이전에 쓰이지 않았다면 
            check[num[i]] = true;//check배열에 true표시
            arr[cnt] = num[i];//arr배열에 값 저장,최댓값,최솟값으로 내보낼 배열
            findValue(cnt + 1);//인덱스 하나 더해서 호출
            if (is_find)
                return;//만약 부등호 관계 만족하는 k+1개의 숫자를 찾았으면 함수 종료
            check[num[i]] = false;//다시 초기화
            arr[cnt] = 0;//다시 초기화
        }
    }
}

/**
 * [백트래킹 풀이] (0ms)
 * 수를 중복없이 배치함 (N과 M(1)과 동일)
 * 수를 배치할 때마다 해당 수가 그 전 수와 부등호 관계를 만족하는지 확인, 만족하지 않으면 back (가지치기)
 */

int main() {
    string max_num, min_num; //정답

    //입력
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> op[i];//부등호 저장
    }

    //최댓값 연산
    for (int i = 0; i <= k; i++) //num배열에 값 미리 저장
        num[i] = 9 - i; //최댓값은 9부터 (9-k)까지 숫자로 이루어짐
    findValue(0);//0번 인덱스부터 해서 최댓값 배열 찾기
    max_num = arrToString(arr);//arr배열 문자열로 변환

    //초기화 !주의! 전역변수 사용 시 초기화 빼먹기 쉬우니 잘 체크하자
    is_find = false;//초기화
    check.assign(SIZE, false);//초기화
    arr.assign(SIZE, 0);//초기화

    

    //최솟값 연산
    for (int i = 0; i <= k; i++)
        num[i] = i; //최솟값은 0부터 k까지 숫자로 이루어짐
    findValue(0);//0번 인덱스부터해서 최솟값 찾기
    min_num = arrToString(arr);//문자열로 변환

    //출력
    cout << max_num << '\n' << min_num;

    return 0;
}