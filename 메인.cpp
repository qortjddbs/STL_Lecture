//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 16일			(15주 1일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// universal reference - range for 에서 range factory를 이용할 때 사용
// 
// concept
// type traits
// 
// C++ Constrained Algothm ( Range + Concept )
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ranges>
#include <numeric>
#include <print>
#include <list>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

template<class T>
concept 숫자만 = std::is_integral_v<T> || std::is_floating_point_v<T>; // _v는 value임. 값을 꺼내와서 참/거짓 판단.
// 컴파일 단계에 참 거짓을 판단할 수 있음.

template<숫자만 T>	// 숫자만 온다는 개념을 장착하고 오면 좋겠어 -> concept를 사용
T add(const T& a, const T& b)
{
	return a + b;	// 자료형이 무관한 코딩. Generic Programming. 이 부분은 C++이 최고임.
}

class Dog {
public:
	Dog() = default;
	Dog(int num) : n{ num } {};

	Dog operator+(const Dog& rhs) const {
		return n + rhs.n;	// == Dog { n + rhs.n }; / 근데 이러면 임시객체가 너무 많이 생기기는거 아냐?
		// => RVO (Return Value Optimization)가 자동으로 작동함.
	}

private:
	int n;
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.n;
	}
};

//--------
int main()
//--------
{
	save("메인.cpp");

	// [문제] add 함수를 작성하라.
	std::cout << add(1, 2) << std::endl;
	std::cout << add(1.2, 3.5) << std::endl;

	// [질문] 내가 만든 class Dog가 내가 만든 concept 숫자만을 만족하도록 하고싶다.
	// std::cout << add(Dog{ 1 }, Dog{ 2 }) << std::endl; // 3이라고 출력되어야.
}