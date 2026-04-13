//-------------------------------------------------------------------
// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026. 04. 13
// ------------------------------------------------------------------
#pragma once
#include <iostream>


class ZString {
public:
	ZString();
	~ZString();
	
	ZString(const char* s);

	// 복사
	ZString(const ZString&);
	ZString& operator=(const ZString&);

	// 이동 - C++11부터 지원되는 move semantics
	ZString(ZString&&);		// && - rvalue reference (오른값 참조자) - 이동 생성자
	ZString& operator=(ZString&&);	// 이동 할당 연산자

	// 연산자오버로딩
	
	// 인터페이스
	size_t getLen() const;

	void special(std::string) const;

	friend std::ostream& operator<<(std::ostream& os, const ZString& zs);

	// 파일에서 읽어오려고 만듦 - 2026. 04. 13
	friend std::istream& operator>>(std::istream& os, ZString& zs);
	
private:
	static size_t gid;				// 고유번호를 부여하기 위한 값
	size_t id;						// 객체 고유번호 - 생성 시 유일한 값
	size_t len{};					// 관리하는 글자 개수
	std::unique_ptr<char[]> p{};	// 글자가 저장된 free-store 메모리
};
