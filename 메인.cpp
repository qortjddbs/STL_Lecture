//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		06월 01일													(13주 2일)
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

template<class 반복자, class 출력반복자>
반복자 my_copy(반복자 begin, 반복자 end, 출력반복자 o) {
	while (begin != end) {
		*o = *begin;
		++o;
		++begin;
	}
	return o;
}


// ----------
int main()
// ----------
{
	ZString zs{ "sphinx of black quartz 3 judge my 6 vow" };

	//코드 설명은 다음주에
	//std::copy(zs.begin(),zs.end(),std::ostream_iterator<ZString::value_type>(std::cout," ### "));
	my_copy(zs.begin(), zs.end(), std::ostream_iterator<ZString::value_type>(std::cout, " ### "));
	//copy는 원본 ---> 복사본/복사본 원본을 손상하지 않는 알고리즘이다. modifying한 알고리즘이라는 것
	//copy(zs.begin(),zs.end(),zs.begin()+5); 이것 가능은하다 하지만 하지말자
	//std::cout << zs << std::endl;




	// save("메인.cpp");
}