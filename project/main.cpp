#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <iterator>

class Player {
	std::string name; // 이름, 길이[3, 15], ['a', 'z']로만 구성
	int score; // 점수, 정규분포
	size_t id; // 아이디, 겹치는 아이디 있을 수 있음
	size_t num; // free store에 확보한 바이트 수
	std::unique_ptr<char[]> p; // free store에 확보한 메모리
};


// 1. 파일에 저장한 모든 Player 정보를 읽어 컨테이너에 저장하라. (array)
// 제일 마지막 Player의 정보를 다음과 같은 형식으로 화면에 출력하라.
// - 어떤 방식으로 읽어 메모리에 저장했는지 보고서에 설명하라

// ----------
int main()
// ----------
{
	std::ifstream in{ "2026 STL 과제 파일 - 2022180016" };
	if (not in) {
		std::cout << "과제 파일이 존재하지 않습니다." << std::endl;
		return 2022180016;
	}

	std::array<Player, 300'0000> players{ std::istream_iterator<Player>{in}, {} };
}