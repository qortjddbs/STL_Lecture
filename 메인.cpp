//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		05월 12일													(10주 1일)
//------------------------------------------------------------------------------------------------------- 
// STL 컨테이너 - Containers are objects that store ohter objects.
// Sequence Container
// - array<T, N>			- 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T>				- 캐시 히트율이 높아 고속 데이터 처리에 유리
// - list<T>				- 아무데서나 원소 추가/삭제 O(1)
// - deque<T>				- vector와 list의 장점을 갖는 컨테이너
// - forword_list<T>		- 네가 아무리 잘 코딩해도 나보다 효율적인 코드 못만든다.
//							  It is intended that forward_list have zero space or 
//							  time overhead relative to a hand-written C-style singly linked list.
//							  Features that would conflict with that goal have been omitted.
// 
// 
// function pointer (function)
// lambda
// function object
// member function pointer
// pointer to member data -> int len; 할 때 len을 호출할 수 있다 (최신)
// => callable - types (부를 수 있는 애들)
// 
// 얘네가 너무 많아서(무한) 범용적으로 나온 게 function <T> wrap
// [] () {}; 랑 [] (int) {} 는 다른 것. (그래서 무한히 많은거다)
// 
// 
// T[N];
// array <T,N>
// vector <T>
// string
// ZString
// => contiguous memory
// 
// 범용적으로 나온 게 span <T> -> light-weight object = 경량 객체
// contiguous한 메모리는 숫자 두개면 끝남. 시작번지 끝번지
// 뭘 몇개 담을건지는 T로 결정이 되는거고 원격지에서 얼마든지 access가능
// string은 전용 경량객체가 따로 있는데 그게 바로 string_view이다.
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <ranges>
#include <span>
#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

// ----------
int main()
// ----------
{
	ZString zs{ "The quick brown fox jumps over the lazy dog" };

	for (char c : zs)
		std::cout << c << std::endl;

	// save("메인.cpp");
}

//char* begin() const;
//char* end() const; 네가 이 함수를 쓴다고 해도 내 멤버 데이터가 변경될 일은 없다는 것을 증명