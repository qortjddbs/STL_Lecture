//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		05월 11일													(9주 2일)
//------------------------------------------------------------------------------------------------------- 
// STL 컨테이너 - Containers are objects that store ohter objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - 캐시 히트율이 높아 고속 데이터 처리에 유리
// - list<T> - 아무데서나 원소 추가/삭제 O(1)
// - deque<T> - vector와 list의 장점을 갖는 컨테이너
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "save.h"
#include "ZString.h"

extern bool 관찰;				// 관찰하려면 true

class Test {
	char c[1024 * 1024];		// 1MB짜리 배열
};

// ----------
int main()
// ----------
{
	save("메인.cpp");

	{
		std::vector<Test> v;

		size_t cnt{};
		while (true) {
			try {
				v.emplace_back();
			}
			catch (...) {		// ... 은 타원들(ellipses)라고 불리는 문법 용어. 모든 예외를 잡아내는 catch 블록.
				std::cout << std::endl;
				std::cout << "벡터 - " << v.size() << std::endl;	
				// 벡터 - 11782400442 (벡터는 전체 메모리의 50퍼센트만 쓰기 때문에 이런 수치가 나옴)
				// 반면 리스트나 덱은 메모리를 100퍼센트 다 쓰기 때문에 컴퓨터가 다운됨.
				// 벡터는 메모리의 50퍼센트는 남아있기 때문에 복구할 여력이 충분. 덱이나 리스트는 그럴 여력이 없음.
				// 그런 공간조차 메모리를 할당해 원소를 넣었기 때문.
				break;
			}

			if (not (++cnt % 1000))
				std::cout << ".";
		}

	}

	{
		std::list<Test> v;

		size_t cnt{};
		while (true) {
			try {
				v.emplace_back();
			}
			catch (...) {		// ... 은 타원들(ellipses)라고 불리는 문법 용어. 모든 예외를 잡아내는 catch 블록.
				std::cout << std::endl;
				std::cout << "리스트 - " << v.size() << std::endl;
				// 벡터 - 11782400442 (벡터는 전체 메모리의 50퍼센트만 쓰기 때문에 이런 수치가 나옴)
				// 반면 리스트나 덱은 메모리를 100퍼센트 다 쓰기 때문에 컴퓨터가 다운됨.
				// 벡터는 메모리의 50퍼센트는 남아있기 때문에 복구할 여력이 충분. 덱이나 리스트는 그럴 여력이 없음.
				// 그런 공간조차 메모리를 할당해 원소를 넣었기 때문.
				break;
			}

			if (not (++cnt % 1000))
				std::cout << ".";
		}

	}

	{
		std::deque<Test> v;

		size_t cnt{};
		while (true) {
			try {
				v.emplace_back();
			}
			catch (...) {		// ... 은 타원들(ellipses)라고 불리는 문법 용어. 모든 예외를 잡아내는 catch 블록.
				std::cout << std::endl;
				std::cout << "덱 - " << v.size() << std::endl;
				// 벡터 - 11782400442 (벡터는 전체 메모리의 50퍼센트만 쓰기 때문에 이런 수치가 나옴)
				// 반면 리스트나 덱은 메모리를 100퍼센트 다 쓰기 때문에 컴퓨터가 다운됨.
				// 벡터는 메모리의 50퍼센트는 남아있기 때문에 복구할 여력이 충분. 덱이나 리스트는 그럴 여력이 없음.
				// 그런 공간조차 메모리를 할당해 원소를 넣었기 때문.
				break;
			}

			if (not (++cnt % 1000))
				std::cout << ".";
		}

	}
	
	관찰 = false;
}