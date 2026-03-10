//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		3월 9일																					(1주 2일)
//-------------------------------------------------------------------------------------------------------
// template 
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include "save.h"

// 사용하지 말아야 할 자료형 - 대체할 수 있다 -> zero-overhead (불이익이 하나도 없음)
// 1. char*		-> std::string
// 2. T*			-> smart pointer를 사용할 것
// 3. T[]		-> std::array를 사용할 것

void change(int *, int *);

// ----------
int main()
// ----------
{
	// 얘네는 코드 세그먼트
	//std::cout << "main - " << std::addressof(main) << std::endl;
	//std::cout << "save - " << std::addressof(save) << std::endl;
	{
		// [문제] 의도대로 실행되게 하자
		// Dog는 class로 작성하자.
		using Dog = int;		// #define Dog int 이건 사용하면 안된다
		Dog a{ 1 }, b{ 2 };

		// 얘네는 스택
		//std::cout << "a - " << std::addressof(a) << std::endl;		// 전역으로 옮기면 main, save의 윗동네로 변경
		//std::cout << "b - " << std::addressof(b) << std::endl;

		// 여기에서 change를 호출하였다.
		// change란? 호출할 수 있는 어떤 것. (호출할 만한게 무한대임) -> 호출 연산자는 ()
		// change(a, b); -> 이것도 맞지만 돌아가는 답임. 컴파일러가 알아서 주소로 변환해서 돌아가게 해줌. (항상 교수님이 알려준 코드처럼 코딩하자 포인터로)
		// 레퍼런스는 실제로 존재하지 않는다!!!!!! (찾아보기)
		change(&a, &b);

		std::cout << a << ", " << b << std::endl;		// 2, 1이라고 출력되어야 함
	}

	{
		// [문제] 의도대로 실행되게 하자
		int a{ 1 }, b{ 2 };

		// 얘네는 스택
		//std::cout << "a - " << std::addressof(a) << std::endl;		// 전역으로 옮기면 main, save의 윗동네로 변경
		//std::cout << "b - " << std::addressof(b) << std::endl;

		// 여기에서 change를 호출하였다.
		// change란? 호출할 수 있는 어떤 것. (호출할 만한게 무한대임) -> 호출 연산자는 ()
		// change(a, b); -> 이것도 맞지만 돌아가는 답임. 컴파일러가 알아서 주소로 변환해서 돌아가게 해줌. (항상 교수님이 알려준 코드처럼 코딩하자 포인터로)
		// 레퍼런스는 실제로 존재하지 않는다!!!!!! (찾아보기)
		change(&a, &b);

		std::cout << a << ", " << b << std::endl;		// 2, 1이라고 출력되어야 함
	}

	save("메인.cpp");
}

void change(int *p, int *q) {
	int temp{ *p };
	*p = *q;
	*q = temp;
}