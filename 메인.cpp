//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		4월 7일														(6주 1일)
// 중간고사 4월 21일 (8주 1일)
//------------------------------------------------------------------------------------------------------- 
// STL 컨테이너 - std::string과 유사한 ZString을 만들어서 컨테이너 본질에 접근
//-------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <memory>		// 스마트 포인터 사용 - 1. 유니크 포인터 (많이 씀) / 2. 쉐어드 포인터 (거의 안씀)
#include "save.h"

class ZString {
public:
	ZString() {
		std::cout << "생성() 글자수: " << len << " 객체: " << this << " 글자주소: " << (void*)p.get() << std::endl;
	}

	ZString(const char* s) {
		len = std::strlen(s);
		p = std::make_unique<char[]>(len);	// 스마트 포인터는 원래 만들어짐과 동시에 초기화되어야 하지만 그게 아니라면 이렇게 초기화
		memcpy(p.get(), s, len);		// 이거보다 빠른 명령어는 없다. 제일 밑바닥 (어셈블리 수준)

		std::cout << "생성(char*) 글자수: " << len << " 객체: " << this << " 글자주소: " << (void*)p.get() << std::endl;
		// p.get()은 주소가 틀림없다. 근데 << 가 고급 그거라 char* 일 때는 이 주소로부터 적혀있는 걸 
		// 바이트단위로 읽어다가 아스키 코드로 찍어준다. 널 캐릭터를 만날때까지.
		// 객체는 스택(저주소), 글자는 free-store(고주소) 에 저장
	}

	friend std::ostream& operator<<(std::ostream& os, const ZString& zs) {
		for (int i = 0; i < zs.len; ++i)
			os << *(zs.p.get() + i);		// 유니크 포인터가 확보한 메모리는 p.get()으로 알 수 있음.
		return os;
	}

private:
	size_t len{};
	std::unique_ptr<char[]> p{};
};

// ----------
int main()
// ----------
{
	// 이 동작 다시 설명하고 ZString으로 바꾸면 안되는 이유부터 시작
	std::string s{ "2026년" };		// xvalue , t는 lvalue
	std::string t = move(s);		// -> t = static_cast<std::string&&>(s); -> t {static_cast<std::string&&>(s)}; -> t.string(string&&);
	// move라는 건 존재하지 않고 그냥 타입 캐스팅	( && -> r-value reference )

	std::cout << "s - " << s << std::endl;
	std::cout << "t - " << t << std::endl;

	save("메인.cpp");
}

// 질문
// std::string에서 15글자 이하일 땐 2칸에 메모리 낭비, 16글자 이상일 땐 3~4칸에 메모리 낭비되는지
// 그럼 만약 처음에 초기화할 땐 15글자 이하였다가 추가해서 16글자 이상이 되면 저장하는 위치도 달라지나?