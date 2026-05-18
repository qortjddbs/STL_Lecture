//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		05월 18일													(10주 2일)
//------------------------------------------------------------------------------------------------------- 
// STL 반복자 - Iterators are a generalization of pointers that allow 
//				a C++ program to work with different data structures in a uniform manner.
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <forward_list>
#include <ranges>
#include <list>
#include <deque>
#include <algorithm>
#include <array>
#include <vector>
#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

// 반복자의 종류를 구분한 이유
// ZString이 표준 반복자를 제공하려면?


// ----------
int main()
// ----------
{
	ZString zs{ "Sphinx of black quartz, judge my vow." };
	
	std::sort(zs.begin(), zs.end());
	
	// [문제] zs를 거꾸로 출력하라.
	for (auto i = zs.rbegin(); i != zs.rend(); ++i)
		std::cout << *i;
	std::cout << std::endl;

	save("메인.cpp");
}