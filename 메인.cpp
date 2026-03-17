//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		3월 10일																					(2주 1일)
//------------------------------------------------------------------------------------------------------- 
// 다음 주 - 많은 수의 자료를 다루기
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <print>		// C++ 23
#include <algorithm>
#include <array>		// C++ 11
#include "save.h"

std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 9999 };
// 다음 시간 멤버 설명부터 다시

template <class T, int N>
class myArray {
public:
	size_t size() const {
		return N;
	}

	int& operator[](int idx) {
		return a[idx];
	}

	T* begin() {
		return &a[0];
	}

	T* end() {
		return &a[N];
	}

private:
	T a[N];
};

// ----------
int main()
// ----------
{
	myArray<int, 1000> a;

	for (int i = 0; i < a.size(); ++i) {
		a[i] = uid(dre);
	}

	//for (int& num : a) {
	//	num = uid(dre);
	//}

	for (int num : a) {
		std::print("{:8}", num);
	}
	std::cout << std::endl;

	auto[minPos, maxPos] = std::minmax_element(a.begin(), a.end());
	std::cout << "가장 작은 값: " << *minPos << ", 가장 큰 값: " << *maxPos << std::endl;

	save("메인.cpp");
}