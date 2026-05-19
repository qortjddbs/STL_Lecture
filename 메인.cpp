//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		05월 19일													(11주 1일)
//------------------------------------------------------------------------------------------------------- 
// STL 반복자 - Iterators are a generalization of pointers that allow 
//				a C++ program to work with different data structures in a uniform manner.
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <ranges>
#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

//template<class 반복자>
//void (f)(반복자 iter)
//{
//	std::cout << typeid(iterator_traits<반복자>::iterator_category).name() << std::endl;
//}

// ----------
int main()
// ----------
{
	save("메인.cpp");

	ZString zs{ "Sphinx of black quartz judge my vow" };

	// [문제] zs를 오름차순으로 정렬하세요.
	std::sort(zs.begin(), zs.end());

	std::cout << zs << std::endl;
}