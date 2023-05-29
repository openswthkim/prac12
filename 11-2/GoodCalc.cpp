/***************************************************************/
/*             HW#9 : 가상함수와 추상클래스                    */
/*  작성자 : 김태형                    날짜 : 2023년 5월 30일  */
/*                                                             */
/* 문제 정의 : 순수 가상 함수 구현하고 동적 바인딩 활용        */
/*                - - - - - - -                                */
/***************************************************************/
#include <iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0; // 두 정수의 합 리턴 받는 가상 함수
	virtual int subtract(int a, int b) = 0; // 두 정수의 차 리턴 받는 가상 함수
	virtual double average(int a[], int size) = 0; // 배열 a의 평균 리턴 받는 가상 함수 
};
class GoodCalc : public Calculator { // 순수 가상 함수 구현
public:
	int add(int a, int b) { return a + b; } // 두 정수의 합을 리턴
	int subtract(int a, int b) { return a - b; } // 두 정수의 차를 리턴
	double average(int a[], int size) { // 배열 a의 평균을 계산하고 리턴
		double sum = 0; // 실수형 변수 선언
		for (int i = 0; i < size; i++) // 배열의 크기만큼 반복
			sum += a[i]; // 합계를 구함
		return sum / size; // 평균값 리턴
	}
};
int main() {
	int a[] = { 1,2,3,4,5 }; // 배열 a 초기화
	Calculator *p = new GoodCalc(); // GoodCalc 객체를 가리키는 Calculator 포인터 선언
	cout << p->add(2, 3) << endl; // GoodCalc의 add함수 호출
	cout << p->subtract(2, 3) << endl; // GoodCalc의 subtract함수 호출
	cout << p->average(a, 5) << endl; // GoodCalc의 average함수 호출
	delete p; // 동적 할당된 메모리 해제
}