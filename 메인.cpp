//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		4월 27일													(8주 2일)
// 중간고사 4월 21일 (8주 1일) - 85 / 120 (33명 중 10등)
//------------------------------------------------------------------------------------------------------- 
// STL 컨테이너 - Containers are objects that store ohter objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - dynamic (size) array - free-store에 data 관리
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

// ----------
int main()
// ----------
{
	// save("메인.cpp");

	std::list<ZString> v{ "1", "22", "4444", "55555" };
	// [문제] "22" 다음에 "333"을 추가하라.
	관찰 = true; 
	for (int i = 0; i < 10; ++i)
		v.emplace(v.begin() + 2, "333");	// 여기에서 다음 주
	// 벡터에서 중간에 값 끼워넣기는 O(n) -> 쥐약임.
	// 그럼 잘하는 애는 누구냐?? -> list O(1)
	관찰 = false;

	for (const ZString& zs : v)
		std::cout << zs << std::endl;

	// [문제] 키보드에서 입력한 모든 정수의 합계를 출력하라. (중간고사 끝나고?)
	std::cout << std::accumulate(std::istream_iterator<int>{std::cin}, {}, 0LL) << std::endl;
}