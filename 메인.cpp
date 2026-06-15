//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		06월 15일													(15주 2일)
// 6/22 기말시험 (16/2) - 제일 마지막 시험
//------------------------------------------------------------------------------------------------------- 
// range - 4가지로 확장
// range factory / range adaptor
// view - light-weight object
// filter - lazy evaluation ( <=> eager evaluation )
// 
// universal reference - range for에서 range factory를 이용할 때 사용
// 
// concept
// type traits
// 
// C++20 Constrained Algorithm ( Range + Concept )
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <ranges>
#include <print>
#include "save.h"
#include "ZString.h"

using namespace std;
extern bool 관찰;				// 관찰하려면 true

template <class T>
T add(const T& a, const T& b)		// 선언과 정의를 동시에
{
	return a + b;
}

class Dog {
public:
	Dog() = default;
	Dog(int num) : n{ num } {}

	Dog operator+(const Dog& rhs) const {
		return n + rhs.n;
	}

private:
	int n;
	friend ostream& operator<< (ostream& os, const Dog& dog) {
		return os << dog.n;
	}
};

// ----------
int main()
// ----------
{
	save("메인.cpp");

	// [문제] add 함수를 작성하라.
	cout << add(1, 2) << endl;
	cout << add("2026년"s, "6월 15일"s) << endl;


	cout << add(Dog{ 1 }, Dog{ 2 }) << endl;		// 3이라고 출력되어야
}