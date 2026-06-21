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
concept 숫자만 = is_integral_v<T> || is_floating_point_v<T>;

template<숫자만 T>
T add(const T& a, const T& b)
{
	return a + b;
}

template <class T>
concept 몬스터 = is_integral_v<T> || is_floating_point_v<T>;

auto add(const 몬스터 auto& a, const 몬스터 auto& b)
{
	return a + b;
}

class Dog {
public:
	Dog() = default;
	Dog(int num) : n{ num } {}

	Dog operator+(const Dog& rhs) const {
		return Dog{ n + rhs.n };          // RVO
	}
private:
	int n;
	friend ostream& operator<<(ostream& os, const Dog& d) {
		return os << d.n;
	}
};

// ----------
int main()
// ----------
{
	// [문제] add 함수를 작성하라.
	cout << add(1, 2) << endl;
}