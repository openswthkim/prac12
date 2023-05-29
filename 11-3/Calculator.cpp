/***************************************************************/
/*             HW#9 : 가상함수와 추상클래스                    */
/*  작성자 : 김태형                    날짜 : 2023년 5월 30일  */
/*                                                             */
/* 문제 정의 : 순수 가상 함수 구현하고 상속 받은 클래스에      */
/*             따른 연산 수행- - - - -                         */
/***************************************************************/
#include <iostream>
using namespace std;

class Calculator {
	void input() { // 정수 입력 받는 함수 선언
		cout << "정수 2 개를 입력하세요>> ";
		cin >> a >> b;
	}
protected:
	int a, b; // 정수형 변수 a, b 선언
	virtual int calc(int a, int b) = 0; // 계산하는 순수 가상 함수
public:
	void run() { // 계산하는 함수 선언
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};

class Adder :public Calculator { // Calculator를 상속받은 Adder 클래스
protected:
	int calc(int a, int b){ // 가상 함수 구현
		return a + b; // 두 정수의 합을 리턴
	}
};

class Subtractor :public Calculator { // Calculator를 상속받은 Subtractor 클래스
protected:
	int calc(int a, int b) { // 가상 함수 구현
		return a - b; // 두 정수의 차를 리턴
	}
};

int main() {
	Adder adder; // Adder 클래스 객체 adder 생성
	Subtractor subtractor; // Subtractor 객체 subtractor 생성
	adder.run(); // Adder 객체의 run함수 호출, 두 정수 입력 받아 합 리턴
	subtractor.run(); // Subtractor 객체의 run함수 호출, 두 정수 입력 받아 차 리턴
}