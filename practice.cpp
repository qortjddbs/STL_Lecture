//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		3월 9일																					(1주 2일)
//-------------------------------------------------------------------------------------------------------
// template 
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include "save.h"

class Dog;			// forward declaration

void change(int*, int*);

class Dog {		// 중괄호는 여기에 쓰자! (좋은 코드 습관)
private:
	int num;

public:
	Dog() = default;		// 디폴트 생성자 만들어주기!
	explicit Dog(int n) : num{ n } {}
	// ~Dog() 쓸데없이 소멸자 만들지말기 (0점짜리)

	// 이 코드는 사용하지 말자
	//operator int () {
	//	return num;
	//}


	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.num;
	}
};

void change(Dog& p, Dog& q) {
	Dog temp{ p };		// temp를 "복사 생성"하라	- 내가 안만들어도 돌아가는 이유 => 스페셜 함수이기 때문! 컴파일러가 알아서 만들어줌
	p = q;		// p.operator = (q); -> 스페셜 함수!! 자동으로 만들어서 돌아가게 해줌
	q = temp;
}

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
		// using Dog = int;		// #define Dog int 이건 사용하면 안된다
		Dog a{ 1 }, b{ 2 };		// Dog a = 1, b = 2; 이런식으로 쓰는 건 좀 "위험" 하다
		// Dog c = 1;		// 이렇게 사용하면 내가 원치않게 실행될 수 있음. 컴파일러가 알아서 형변환 실행 (그래서 explicit 붙이면 바로 오류)

		// 얘네는 스택
		//std::cout << "a - " << std::addressof(a) << std::endl;		// 전역으로 옮기면 main, save의 윗동네로 변경
		//std::cout << "b - " << std::addressof(b) << std::endl;

		// 여기에서 change를 호출하였다.
		// change란? 호출할 수 있는 어떤 것. (호출할 만한게 무한대임) -> 호출 연산자는 ()
		// change(a, b); -> 이것도 맞지만 돌아가는 답임. 컴파일러가 알아서 주소로 변환해서 돌아가게 해줌. (항상 교수님이 알려준 코드처럼 코딩하자 포인터로)
		// 레퍼런스는 실제로 존재하지 않는다!!!!!! (찾아보기)
		change(a, b);

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

void change(int* p, int* q) {
	int temp{ *p };
	*p = *q;
	*q = temp;
}