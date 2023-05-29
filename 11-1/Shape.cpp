/***************************************************************/
/*             HW#9 : 가상함수와 추상클래스                    */
/*  작성자 : 김태형                    날짜 : 2023년 5월 30일  */
/*                                                             */
/* 문제 정의 : 가상 함수를 사용하여 각 도형에 맞는 공식 적용   */
/*                - - - - - - -                                */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string name; // 이름 문자열 변수 선언
    int width, height; // 너비와 높이 변수 선언
public:
    Shape(string n = "", int w = 0, int h = 0) {
        name = n; width = w; height = h;
    }
    virtual double getArea() = 0;  // 가상함수 선언
    string getName() { return name; } // 이름 리턴
};
class Oval : public Shape {
public:
    Oval(string n, int w, int h) : Shape(n, w, h) {} 
    // Shape 클래스를 상속받아 타원 함수를 표현함
    double getArea() { return 3.14 * width * height; }
    // 가상함수를 사용해 타원의 넓이를 구함
};
class Rect : public Shape {
public:
    Rect(string n, int w, int h) : Shape(n, w, h) {}
    // 사각형 클래스의 멤버 변수를 초기화
    double getArea() { return width * height; } // 사각형의 넓이 구함
};
class Triangular : public Shape {
public:
    Triangular(string n, int w, int h) : Shape(n, w, h) {}
    // 삼각형 클래스의 멤버 변수를 초기화
    double getArea() { return width * height / 2; } // 삼각형의 넓이 구함
};
int main() {
    Shape *p[3]; // 포인터 배열 생성
    p[0] = new Oval("빈대떡", 10, 20); // 배열 첫번째에 타원 객체 동적 할당
    p[1] = new Rect("찰떡", 30, 40); // 배열 두번째에 사각형 객체 동적 할당
    p[2] = new Triangular("토스트", 30, 40); // 배열 세번째에 삼각형 객체 동적 할당
    for (int i = 0; i < 3; i++)
        cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
    // 각 객체의 이름과 넓이 출력
    for (int i = 0; i < 3; i++) 
        delete p[i]; // 각 객체 메모리 해제
}