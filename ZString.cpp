// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class - 중간고사 준비 잘 하기 (이걸로 나옴)
// 
// 2026. 04. 20
// ------------------------------------------------------------------
#include <print>				// 표준 헤더는 내가 만든 헤더 위에다 적기
#include <string>
#include <algorithm>			// equal 2026. 04. 28
#include "ZString.h"

size_t ZString::gid{};		// 외부에서 초기화
bool 관찰{ false };

ZString::ZString()
	: id{ ++gid }		// 객체가 생성될 때마다 고유번호를 부여
{
	if (관찰)
		special("생성");
}

ZString::~ZString()
{
	if (관찰) {
		special("소멸");
	}
}

ZString::ZString(const char* s)
	: id{ ++gid }
{
	len = std::strlen(s);
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);

	if (관찰)
		special("생성(*)");
}

// 복사생성과 복사할당연산자
ZString::ZString(const ZString& other)
	: id{ ++gid }
{
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);		// 제일 밑바닥 함수 (std함수 아님!)
	if (관찰)
		special("복사생성");
}

// ZString a = b;	// 복사 생성
// a = b; 	// 할당 (복사 생성과 전혀 다른 동작)

ZString& ZString::operator=(const ZString& other)
{
	if (this == &other)		// 자기 자신을 복사하는 경우는 아무 것도 하지 않음
		return *this;

	len = other.len;
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰)
		special("복사할당");

	return *this;
}

// 이동 - C++11부터 지원되는 move semantics
// 2026. 04. 20 move에서 예외를 던지지 않는다.
//ZString::ZString(ZString&& other) noexcept
//	: id{ ++gid }
//{
//	len = other.len;
//	p.reset(other.p.release());	// other의 p가 관리하는 메모리를 가져옴 - other는 자동으로 nullptr이 됨
//
//	other.len = 0;
//	// 자기 자원이 이동된 other는 xvalues가 되고 이것을 사용하면 undefined behavior
//	if (관찰)
//		special("이동생성");
//}
//
//ZString& ZString::operator=(ZString&& other) noexcept
//{
//	if (this == &other)
//		return *this;
//
//	len = other.len;
//	// 잘 한 건가? 내 메모리 반환했나?
//	p.reset(other.p.release());
//	other.len = 0;
//
//	if (관찰)
//		special("이동할당");
//
//	return *this;
//}

// 2026. 04. 28
bool ZString::operator==(const ZString& rhs) const  // rhs - right hand side (오른쪽 피연산자)
{
	// 동등성(equality)과 상등성(equivalence)의 차이
	// id, len, p가 있는데 ==> 내가 관리하는 글자가 같으면 같은거다.
	if (len != rhs.len)
		return false;

	return std::equal(p.get(), p.get() + len, rhs.p.get());	// 심지어 인라인 함수임. 속도도 빠르고 효율적, 가독성도 좋음

	// 오래된 구식 코드
	//for (int i = 0; i < len; ++i) {
	//	if (p[i] != rhs.p[i])
	//		return false;
	//}
	//return true;
}
// :: -> scope resolution operator (범위 해제 연산자) - 클래스의 멤버 함수를 정의할 때 사용

// 2026. 05. 12 - 반복자 인터페이스
ZString_Iterator ZString::begin() const 
{ 	
	return p.get(); 
}

ZString_Iterator ZString::end() const 
{	
	return p.get() + len;
}

// 2026. 05. 18 - 역방향 추가
// 2026. 05. 19 - 역방향반복자는 반드시 class로 코딩해야 합니다.
ZString_Iterator ZString::rbegin() const
{
	return p.get() + len;
}

ZString_Iterator ZString::rend() const
{
	return p.get();
}

size_t ZString::getLen() const { return len; }

// STL 컨테이너가 되려면 다음 함수정도는 제공해야
size_t ZString::size() const
{
	return len;
}

char* ZString::data() const		// 2026. 05. 11
{
	return p.get();
}

void ZString::special(std::string 동작) const
{
	// 글자수가 10개 이상이라도 10개 까지만 출력
	int num = 10;
	if (len < 10)
		num = len;
	std::string 글자{};
	for (int i = 0; i < num; ++i)
		글자 += p[i];

	std::println("[{:7}] {:8} - 객체:{:#014X}, 글자:{:#014X}, 개수:{:<6} 내용:{} ",
		id, 동작, (long long)this, (long long)p.get(), len, 글자);
}

void ZString::show() const		// 2026. 04. 20
{
	special("show");
}

std::ostream& operator<<(std::ostream& os, const ZString& zs)
{
	for (int i = 0; i < zs.len; ++i)
		os << *(zs.p.get() + i);
	return os;
}

std::istream& operator>>(std::istream& is, ZString& zs)
{
	std::string s;
	is >> s;
	zs.len = s.size();
	zs.p.reset();
	zs.p = std::make_unique<char[]>(s.size());
	memcpy(zs.p.get(), s.data(), zs.len);

	return is;
}