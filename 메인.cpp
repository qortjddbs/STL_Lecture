//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		3월 30일																					(4주 2일)
//------------------------------------------------------------------------------------------------------- 
// callable type -> 실습 -> STL
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <print>
#include <array>
#include <ranges>
#include "save.h"

// [문제] 랜덤값을 갖는 int 1000만개를 메모리에 저장하라.
// qsort를 이용하여 오름차순 정렬하라.
// 정렬결과를 앞에서부터 1000개만 화면에 출력하라.

std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 999'9999 };

std::array<int, 1000'0000> a;

int 오름차순(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// ----------
int main()
// ----------
{
    save("메인.cpp");

    for (int& num : a) {
        num = uid(dre);
   }

    // 시간측정시작
    qsort(a.data(), a.size(), sizeof(std::array<int, 1000'0000>::value_type), 오름차순);
    // 측정 끝
	
    std::cout << "정렬 후 출력" << std::endl;

    for (int num : a | std::views::reverse
                                | std::views::take(1000)) {      // | : 버티컬 바 (짝대기) -> 필터 역할 (데이터를 원하는 대로 뽑아줄 수 있음!!)
        std::print("{:8}", num);
    }

    std::cout << std::endl;
}