//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		06월 02일													(14주 1일)
// 6/22 기말시험 (16/2) - 제일 마지막 시험
//------------------------------------------------------------------------------------------------------- 
// 
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <map>
#include <random>
#include <print>

#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 10'000 };
std::normal_distribution nd{ 0.0, 0.09 };

// ----------
int main()
// ----------
{
	save("메인.cpp");

	// map 어디에 쓸 수 있나
	// 유니폼 분포는 유니폼한가?
	// 노멀분포를 화면에 출력

	std::map<size_t, size_t> 노멀;
	for (int i = 0; i < 1'0000'0000; ++i) {
		double num = nd(dre);		// nd로 뽑으면 double로 나옴
		num = num * 5000 + 5000;
		if (num < 0) num = 0;
		if (1'0000 < num) num = 1'0000;

		++노멀[static_cast<int>(num) / 200];
	}

	for (auto [구간, 개수] : 노멀)
		std::println("[{:2}] - {}", 구간, 개수);
}