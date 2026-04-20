// -------------------------------------------------------------------------------------------------
// 한 학기 강의를 저장하기 위한 함수
// 
// 2026. 03. 09 (월)																																					백성윤
// -------------------------------------------------------------------------------------------------
// fname부터 하자 -> naming convention
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
// 헤더파일은 맨 나중에 넣기. 오류날 수 있음 (찾기 힘듦)
#include "save.h"

void save(const std::string& fname)
{
	std::ifstream in{ fname };		// RAII - 찾아보고 공부해보기
	// in.close();		// 절대 코딩 할 필요가 없다. 이걸 쓰면 나는 RAII에 대해 잘 모르는 바보라고 알려주는 꼴 (다 자동화 됨)
	if (not in) {		// 느낌표 대신 not 쓰기
		std::cout << fname << " - 열 수 없습니다" << '\n';
		// return 20260309;		// return은 함수를 호출한 곳으로 빠져나가는 코드
		exit(20260309);
	}

	std::cout << "\"" << fname << "\"를 저장합니다" << '\n';

	std::ofstream out{ "2026년 1학기 STL 월56 화78.txt", std::ios::app };
	// if (not out)		이건 할 필요 없음. std::ios::app -> 옛날 파일 그대로 두고 덮어쓰는 모드

	// 시간정보를 얻는다
	auto now = std::chrono::system_clock::now();		// time epoch로부터 1초마다 증가한 tick 수
	// 데이터 타입은 컴파일러가 추측할 수 있기 때문에(마우스 갖다대면 알려줌) 직접 써줘도 되고 auto를 써서 컴파일러가 자동으로 써주게끔 할 수 있음.

	using namespace std::chrono_literals;
	// out << now + 9h << '\n';		// 여기서 now는 그리니치 천문대 기준 시간 (우리나라로 바꾸려면 +9시간 해줘야함)

	out << '\n' << '\n';
	out << "==========================================================================================" << '\n';
	out << "저장한 시간 - " << now + 9h << '\n';
	out << "==========================================================================================" << '\n';
	out << '\n';

	// std::copy( 어디부터, 어디까지를, 어디로 );
	// buf없으면 글자'만' 읽어옴. buf 붙이면 화면에 있는 내용 그대로 옮기라는 뜻.
	std::copy(std::istreambuf_iterator<char>{in}, {},		// iterator in파일로부터 char, {} -> EOF, 마지막 글자까지 (특별한 약속)
		std::ostream_iterator<char>{out});

	//char c;
	//in >> std::noskipws;		// 이렇게 쓰면 공백 포함
	//while(in >> c)		// operator>>(in, c); 이렇게 바뀜. (연산자 오버로딩)
	//	out << c;		// 파일에 직접 쓰기
}