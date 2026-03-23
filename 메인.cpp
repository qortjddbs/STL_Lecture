//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		3월 23일																					(3주 2일)
//------------------------------------------------------------------------------------------------------- 
// 많은 수의 자료를 다루기 - FILE I/O - binary I/O - class 객체
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include "save.h"
#include <fstream>
#include <string>
#include <array>

class Dog {
private:
	std::string name;		// [10, 30] 사이의 소문자로 구성된 이름
	size_t id;						// [0, 9999]

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		std::print(os, "[{:>4}] - {}", dog.id, dog.name);
		return os;
	}
};

// [문제] 파일 "Dog천마리"에는 class Dog 객체 1000개가 저장되어있다.
// 파일은 binary mode이고 각 객체는 메모리 크기 그대로 stream의 write 함수로 기록하였다.
// 모든 객체를 한번의 write 함수를 사용하여 기록하였다. 
// Dog의 멤버는 위의 코드와 같다.
// 메모리에 모두 읽어 와라.
// 메모리에 읽은 모든 Dog를 화면 출력하라.

// ----------
int main()
// ----------
{
	std::ifstream in{ "Dog천마리", std::ios::binary };
	if (not in) {
		std::cout << "Dog 없음" << std::endl;
		return 20260323;
	};

	std::array<Dog, 1000> dogs;
	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs) {
		std::cout << dog << std::endl;
	}

	save("메인.cpp");
}