#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <print>
#include <fstream>
#include "ZString.h"

// ----------
int main()
// ----------
{
	std::ifstream in{ "시험.dat" };
	if (not in) {
		std::cout << "파일을 열 수 없습니다." << std::endl;
		return 20260421;
	}

	// [문제 1-1] 어디에 저장하였는가? 
	// [문제 1-2] 그렇게 한 이유는 무엇인가?
	std::vector<ZString> zs;
	zs.reserve(11'0000);
	ZString temp;
	while (in >> temp) {
		zs.push_back(std::move(temp));
	}

	// [문제 1-3] 모두 몇 개의 ZString 객체를 저장하였는가?
	std::cout << zs.size() << std::endl;		// 101109개

	// [문제 1-4] 컨테이너에 저장한 마지막 객체의 정보를 ZString::show()를 호출하여 화면에 출력된 내용 그대로 적어라.
	zs.back().show();
	// [ 101110] show     - 객체:0X027F1C81D740, 글자:0X027F1FB8E980, 개수:993    내용:igEUHQybzb

	// [문제 1-5] 사용한 컨테이너와, 저장된 ZString 객체 중에서 첫 ZSting 객체를 그림으로 그려라.

	// [문제 2] 컨테이너에 저장한 ZString 단어의 평균 길이를 소숫점 한 자리까지 출력하라.
	// 2-1) 평균 길이를 계산하는 코드 (10)
	size_t total_len = std::accumulate(zs.begin(), zs.end(), 0LL, [](long long acc, const ZString& zs) {
		return acc + zs.size();
		});

	double average_len = static_cast<double>(total_len) / zs.size();
	// 2-2) 자릿수를 맞춰 평균길이를 자릿수에 맞게 출력하는 코드(10)
	std::println("{:.1f}", average_len);

	// [문제 3] 컨테이너를 ZString 단어 길이기준 오름차순으로 전체 정렬하라.
	// 3) 정렬하는데 필요한 예상 비교함수 호출 횟수와 실제 비교함수 호출 횟수를 적어라.
	// 예상 비교함수 호출 횟수 - 1,812,000회 (101109개 * log2(101109) ≈ 1,812,000회)
	int count = 0;

	std::sort(zs.begin(), zs.end(), [&](const ZString& a, const ZString& b) {
		count++;
		return a.getLen() < b.getLen();
		});

	std::cout << "실제 비교함수 호출 횟수 - " << count << std::endl;		// 실제 비교함수 호출 횟수 - 1,549,948회

	// [문제 4] [문제 3]에서 정렬한 컨테이너에 있는 각 ZString의 단어를 사전순서와 같이 오름차순으로 정렬하라.
	// 4-1) 정렬하기 위해 ZString에 추가한 멤버 (10)
	// char* ZString::begin() { return p.get(); }
	// char* ZString::end() { return p.get() + len; }
	
	// 4-2) 정렬하는 코드 (10)
	for (ZString& s : zs)
		std::sort(s.begin(), s.end());
	// 4-3) 정렬 후 마지막 ZString 객체의 show()를 호출한 화면 출력 결과 (10)
	zs.back().show();
}