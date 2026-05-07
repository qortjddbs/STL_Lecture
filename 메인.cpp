//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		05월 04일													(9주 2일)
//------------------------------------------------------------------------------------------------------- 
// STL 컨테이너 - Containers are objects that store ohter objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - 캐시 히트율이 높아 고속 데이터 처리에 유리
// - list<T> - 아무데서나 원소 추가/삭제 O(1)
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <fstream>
#include <ranges>
#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

// ----------
int main()
// ----------
{
	// [문제] 파일에 있는 단어를 list<ZString>에 저장하라.
	// 단어를 사전식 오름차순으로 정렬하라.

	std::ifstream in{ "2026년 1학기 STL 월56 화78.txt" };
	if (not in) {
		std::cout << "강의저장 파일이 없네요" << std::endl;
		return 20260504;
	}

	std::list<ZString> words{ std::istream_iterator<ZString>{in}, {} };
	words.sort([](const ZString& a, const ZString& b) {
		// 멤버함수가 없어서 미완. 다음시간에 -> 정렬시간비교
		lexicographical_compare();
		});

	save("메인.cpp");
}