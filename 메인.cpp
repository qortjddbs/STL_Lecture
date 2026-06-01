//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		06월 01일													(13주 2일)
// 6/22 기말시험 (15/2) - 제일 마지막 시험
//------------------------------------------------------------------------------------------------------- 
// STL Associative Container
// - set/multiset - key-value, key==value
// - map/multimap - key-value, key값을 정렬기준으로 하여 O(log N) value를 찾는다
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <set>
#include <fstream>	// 파일 주고 ZString으로 읽어봐라 id값이 얼마냐?? 라는 문제 기말고사에 나올듯
#include <algorithm>
#include <vector>

#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

// ----------
int main()
// ----------
{
	// "이상한 나라의 앨리스.txt"의 단어를 set<ZString>에 저장하라.
	std::ifstream in{ "이상한 나라의 앨리스.txt" };

	if (not in) {
		std::cout << "파일을 살펴보세요" << std::endl;
		return 20260601;
	}

	std::multiset<ZString> s{ std::istream_iterator<ZString>{in}, {} };

	for (const ZString& zs : s)
		std::cout << zs << "  ";
	std::cout << std::endl;

	std::cout << "단어 개수 - " << s.size() << std::endl;
	
	save("메인.cpp");

	// 단어를 입력받아 있다면 몇 개인지
	// 없다면 없다고 출력하라.

	while (true) {
		std::cout << "찾을 단어? ";
		ZString word;
		std::cin >> word;

		auto [하한, 상한] = s.equal_range(word);
		// pair로 받아 코딩해 보세요
		if (하한 == 상한)
			std::cout << "없는 단어" << std::endl;
		else
			std::cout << std::distance(하한, 상한) << "개 있습니다" << std::endl;
	}
}

// 이퀄레인지 -> 정렬된 자료에 같은 값을 가진(Alice) 원소를 껴넣어도 정렬이 깨지지 않는다는 것?
// 장점 = distance를 재서 몇 개 있는지 셀 수 있음