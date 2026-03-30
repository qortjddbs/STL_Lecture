//-------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56 화78		3월 30일																					(4주 2일)
//------------------------------------------------------------------------------------------------------- 
// CALLABLE TYPE -> 실습 -> STL
//-------------------------------------------------------------------------------------------------------
#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"

// [문제] "메인.CPP"의 소문자를 모두 대문자로 바꾼 "메인대문자.CPP"를 만들어라.
CHAR 소투대(CHAR C) {
	RETURN C = TOUPPER(C);
}

// ----------
INT MAIN()
// ----------
{
	STD::IFSTREAM IN{ "메인.CPP" };
	IF (NOT IN) {
		RETURN 20260330;
	}

	STD::OFSTREAM OUT{ "메인대문자.CPP" };

	TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {}, STD::OSTREAMBUF_ITERATOR<CHAR>{OUT}, 
		[](CHAR C) {
		RETURN C = TOUPPER(C);
		});

	SAVE("메인.CPP");
}