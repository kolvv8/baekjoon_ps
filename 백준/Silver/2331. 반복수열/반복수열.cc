#include <iostream>
#include <unordered_set>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

// 다음 A 값을 반환해주는 함수
int func(int x, int p) {
    int res = 0;
    while (x > 0) {
        int digit = x % 10;
        res += (int)pow(digit, p);
        x /= 10;
    }
    return res;
}


int main() {

    // map -> key: D[A] 값, value: 몇 번째로 나왔는지 기록
    map<int, long long> m;

    // A: 초기 A 입력값(나중에 A가 바뀔 때 마다 A 값 업데이트 할 예장), P: 몇 번 곱할 건지 입력값
    int A, P;
    cin >> A >> P;

    // 몇 번째 값인지 나타내는 변수, 시작은 0부터
    long long cnt = 0;

    while (true) {
        // 이전 값이 반복된 경우
        if (m.find(A) != m.end()) {

            cout << m[A] << "\n";
            return 0;

        }

        // key: A값, value: 몇 번째 인지 기록
        m[A] = cnt;

        // 다음 횟수
        cnt++;

        // 다음 A 값 지정
        A = func(A, P);


    }
}