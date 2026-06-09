//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		06월 09일													(15주 1일)
// 6/22 기말시험 (16/2) - 제일 마지막 시험
//------------------------------------------------------------------------------------------------------- 
// STL Algorithms
// - 정렬 관련 알고리즘 - 복잡도 순서대로
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

#include "save.h"
#include "ZString.h"

using namespace std;
extern bool 관찰;				// 관찰하려면 true

default_random_engine dre{ random_device{}() };		// random_device()() 해도 됨. 생성 호출한다는 의미로. 근데 촌스러움. 생성은 {}로 하자.

// ----------
int main()
// ----------
{
	save("메인.cpp");

	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 20260609;

	vector<ZString> v{ istream_iterator<ZString>{in}, {} };
	cout << "모두 " << v.size() << "개의 단어를 읽었다" << endl;

	sort(v.begin(), v.end());
	auto newEnd = unique(v.begin(), v.end());
	v.erase(newEnd, v.end());
	cout << "중복을 제거한 단어 개수 - " << v.size() << endl;

	shuffle(v.begin(), v.end(), dre);

	for (const ZString& zs : v)
		cout << zs << " ";
	cout << endl;

	// [문제] 길이가 홀수인것과 짝수인것으로 분리하라.
	// 앞에는 홀수 뒤에는 짝수
	// 홀수 앞에 짝수가 있으면 안된다.
	// 홀수와 짝수가 각각 몇 개인지 출력하라.
	// 파티션은 경계 위치를 반환한다.
	auto 짝수시작위치 = partition(v.begin(), v.end(), [](const ZString& a) {
		return *a.begin() == 'a';
		});

	cout << "길이가 홀수 - " << distance(v.begin(), 짝수시작위치) << endl;
	for (auto i = v.begin(); i != 짝수시작위치; ++i)
		cout << *i << " ";

	cout << endl;
	cout << endl;

	cout << "길이가 짝수 - " << distance(짝수시작위치, v.end()) << endl;
	for (auto i = 짝수시작위치; i != v.end(); ++i)
		cout << *i << " ";
	cout << endl;
}