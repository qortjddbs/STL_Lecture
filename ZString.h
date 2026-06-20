//-------------------------------------------------------------------
// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026. 04. 13
// ------------------------------------------------------------------
#pragma once
#include <iostream>

// 2026년 5월 19일
class ZString_Iterator {
public:
	// 표준반복자가 되려면 다음 5가지 호출해야 한다.
	using iterator_category = std::random_access_iterator_tag;	// 2026. 05. 19 - 역방향 반복자는 양방향 반복자
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	

	ZString_Iterator() = default;

	ZString_Iterator(char* p) : p{ p } { }

	// void로 놓으면 안된다.
	ZString_Iterator& operator++() {
		++p;
		return *this;
	}

	ZString_Iterator& operator--() {
		--p;
		return *this;
	}

	ZString_Iterator operator+(difference_type n) const {
		return p + n;
	}

	char& operator*() const {
		return *p;
	}

	// 관계연산자는 6가지가 있다.
	// 그런데 우주선 연산자 한 개만 코딩해서 6개를 자동으로 만들 수 있다 - 만세!
	auto operator<=>(const ZString_Iterator& rhs) const = default;
	// 우주선 연산자의 반환형은 절대 bool이 아니다. struct 머시기라서 auto로 써준다.

	difference_type operator-(const ZString_Iterator& rhs) const {
		return p - rhs.p;
	}

	// 2026. 05. 26
	ZString_Iterator operator-(difference_type n) const {
		return p - n;
	}

private:
	char* p;
};

// 2026년 5월 19일
class ZString_Reverse_Iterator {
public:
	ZString_Reverse_Iterator() = default;
	ZString_Reverse_Iterator(char* p) : p{ p } {}

	void operator++() {
		--p;
	}

	char operator*() const {
		return *(p - 1);
	}

	auto operator<=>(const ZString_Reverse_Iterator& rhs) const = default;

private:
	char* p;
};

// ZString은 표준 컨테이너의 동작을 흉내내고 있다.
class ZString {
// 2026. 05. 26
// 표준 컨테이너라면 다음과 같은 타입을 제공해야한다.
public:
	using iterator = ZString_Iterator;
	using reverse_iterator = ZString_Reverse_Iterator;
	using value_type = char;

public:
	ZString();
	~ZString();

	ZString(const char* s);

	// 복사
	ZString(const ZString&);
	ZString& operator=(const ZString&);

	// 이동 - C++11부터 지원되는 move semantics
	// && - rvalue reference (오른값 참조자) - 이동 생성자
	ZString(ZString&&) noexcept;	// 2026. 04. 20 move에서 예외를 던지지 않는다.
	// 이동 할당 연산자
	ZString& operator=(ZString&&) noexcept;	

	// 연산자오버로딩
	// 2026. 04. 28
	bool operator==(const ZString& rhs) const; // rhs - right hand side (오른쪽 피연산자)

	// 2026. 06. 01
	// set의 기본정렬 연산자 <
	bool operator<(const ZString& rhs) const;

	// 2026. 05. 12 - 반복자 인터페이스
	// 2026. 05. 19 - begin이 되돌려줘야할 타입은 class이어야 한다.
	ZString_Iterator begin() const;
	ZString_Iterator end() const;

	// 2026. 05. 18 - 역방향 추가
	// 2026. 05. 19 - 역방향반복자는 반드시 class로 코딩해야 합니다.
	ZString_Reverse_Iterator rbegin() const;
	ZString_Reverse_Iterator rend() const;

	// 인터페이스 - 나중에 삭제 예정
	size_t getLen() const;

	// 2026. 06. 01
	size_t getId() const {
		return id;
	}

	// STL 컨테이너가 되려면 다음 함수정도는 제공해야 - 2026. 04. 20
	size_t size() const;
	char* data() const;		// 2026. 05. 11
	
	// 유니크 포인터 반환 함수 선언써줘
	char* get();

	void special(std::string) const;

	void show() const;			// 2026. 04. 20

	friend std::ostream& operator<<(std::ostream& os, const ZString& zs);

	// 파일에서 읽어오려고 만듦 - 2026. 04. 13
	friend std::istream& operator>>(std::istream& os, ZString& zs);

private:
	static size_t gid;				// 고유번호를 부여하기 위한 값
	size_t id;						// 객체 고유번호 - 생성 시 유일한 값
	size_t len{};					// 관리하는 글자 개수
	std::unique_ptr<char[]> p{};	// 글자가 저장된 free-store 메모리
};
