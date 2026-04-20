//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		4월 20일													(7주 2일)
// 중간고사 4월 21일 (8주 1일)
//------------------------------------------------------------------------------------------------------- 
// STL 컨테이너 - Containers are objects that store ohter objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - dynamic (size) array - free-store에 data 관리
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

// ----------
int main()
// ----------
{
	// save("메인.cpp");

	// [문제] 키보드에서 입력한 모든 정수의 합계를 출력하라. (중간고사 끝나고?)
	std::cout << std::accumulate(std::istream_iterator<int>{std::cin}, {}, 0LL) << std::endl;
}