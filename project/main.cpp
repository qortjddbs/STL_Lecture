#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <print>
#include <memory>
#include <numeric>
#include <chrono>
#include <unordered_map>
#include <execution>

class Player {
	std::string name;				// 이름, 길이[3, 15], ['a', 'z']로만 구성
	int score;						// 점수, 정규분포
	size_t id;						// 아이디, 겹치는 아이디 있을 수 있음
	size_t num;						// free store에 확보한 바이트 수
	std::unique_ptr<char[]> p;		// free store에 확보한 메모리

public:
	std::istream& read(std::istream& in) {
		in.read((char*)this, sizeof(Player));

		if (in) {
			p.release();
			p = std::make_unique<char[]>(num);
			in.read(p.get(), num);
		}
		return in;
	}

	const std::string& get_name() const { return name; }
	int get_score() const { return score; }
	size_t get_id() const { return id; }

	void show() const {
		std::println("이름:{:15}, 아이디:{}, 점수:{}, 자원수:{}", name, id, score, num);
		std::print("저장된 글자:");
		for (size_t i = 0; i < num; ++i) {
			std::print("{}", p[i]);
		}
		std::println("");
	}

	void sort_chars() {
		std::sort(p.get(), p.get() + num);
	}

	bool has_all_digits() const {
		std::string digits = "0123456789";
		return std::includes(p.get(), p.get() + num, digits.begin(), digits.end());
	}
};

// ----------
int main()
// ----------
{
	std::ifstream in{ "2026 STL 과제 파일 - 2022180016", std::ios::binary };
	if (not in) {
		std::cout << "과제 파일이 존재하지 않습니다." << std::endl;
		return 2022180016;
	}

	// 1. 파일에 저장한 모든 Player 정보를 읽어 컨테이너에 저장하라.
	// 제일 마지막 Player의 정보를 다음과 같은 형식으로 화면에 출력하라.
	// - 어떤 방식으로 읽어 메모리에 저장했는지 보고서에 설명하라.\
	// -> array를 사용하지 않고 vector를 사용한 이유

	std::vector<Player> players;
	players.reserve(300'0000);

	Player temp;
	while (temp.read(in)) {
		players.push_back(std::move(temp));
	}

	//if(not players.empty()) {
	//	players.back().show();
	//}

	// 2. 점수가 가장 큰 Player를 찾아 화면에 출력하라.(동점 모두 출력)
	// 	Player의 평균 점수를 계산하여 화면에 출력하라.
	// 	- 어떻게 찾고 계산하였는지 보고서에 설명하라.
	// -> 
	
	/*auto max_it = std::max_element(players.begin(), players.end(), [](const Player& a, const Player& b) {
		return a.get_score() < b.get_score();
		});

	if (max_it != players.end()) {
		int max_score = max_it->get_score();
		std::println("최고 점수: {}", max_score);
		std::println("[최고 점수 플레이어 목록]");

		for (const Player& player : players) {
			if (player.get_score() == max_score) {
				player.show();
			}
		}
	}

	long long total_score = std::accumulate(players.begin(), players.end(), 0LL, [](long long sum, const Player& player) {
		return sum + player.get_score();
		});

	double avg_score = static_cast<double>(total_score) / players.size();

	std::println("전체 평균 점수: {:.1f}", avg_score);*/

	// 3. id가 서로 같은 객체를 찾아 "같은아이디.txt"에 기록하라.
	//	id가 같은 객체는 모두 몇 개인지 화면에 출력하라.
	//	파일에는 id가 같은 Player 객체의 이름과 아이디를 한 줄 씩 기록한다. 
	// - 어떻게 같은 id를 찾았는지 보고서에 설명하라.
	// -> 해시 (unordered_map)을 안쓰고 정렬 후 비교한 이유

	// std::println("\n--- [과제 3 속도 비교 테스트] ---");

	// 해시
	//auto start_hash = std::chrono::high_resolution_clock::now();

	//std::unordered_map<size_t, int> id_counts;
	//id_counts.reserve(players.size());

	//for (const Player& player : players) {
	//	++id_counts[player.get_id()];
	//}

	//int duplicate_count_hash = 0;

	//for (const auto& p : players) {
	//	if (id_counts[p.get_id()] > 1) {
	//		duplicate_count_hash++;
	//	}
	//}
	//auto end_hash = std::chrono::high_resolution_clock::now();
	//auto duration_hash = std::chrono::duration_cast<std::chrono::milliseconds>(end_hash - start_hash);

	// 정렬
	// auto start_sort = std::chrono::high_resolution_clock::now();
	std::sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
		return a.get_id() < b.get_id();
		});

	//int duplicate_count_sort = 0;
	//for (size_t i = 0; i < players.size(); ++i) {
	//	bool is_duplicate = false;
	//	if (i > 0 && players[i].get_id() == players[i - 1].get_id()) is_duplicate = true;
	//	else if (i < players.size() - 1 && players[i].get_id() == players[i + 1].get_id()) is_duplicate = true;

	//	if (is_duplicate) ++duplicate_count_sort;
	//}
	//auto end_sort = std::chrono::high_resolution_clock::now();
	//auto duration_sort = std::chrono::duration_cast<std::chrono::milliseconds>(end_sort - start_sort);

	// std::println("[해시 방식 결과] 중복: {}개, 소요 시간: {} ms", duplicate_count_hash, duration_hash.count());
	// std::println("[정렬 방식 결과] 중복: {}개, 소요 시간: {} ms", duplicate_count_sort, duration_sort.count());

	std::ofstream out{ "같은아이디.txt" };
	if (not out) {
		std::println("파일을 생성할 수 없습니다!");
		return 2022180016;
	}

	int duplicate_count_sort = 0;
	for (size_t i = 0; i < players.size(); ++i) {
		bool is_duplicate = false;
		if (i > 0 && players[i].get_id() == players[i - 1].get_id()) is_duplicate = true;
		else if (i < players.size() - 1 && players[i].get_id() == players[i + 1].get_id()) is_duplicate = true;

		if (is_duplicate) {
			out << players[i].get_name() << " " << players[i].get_id() << "\n";
			duplicate_count_sort++;
		}
	}

	std::println("id가 같은 객체 총 개수: {}개", duplicate_count_sort);

	// 4. Player의 멤버 p가 가리키는 메모리에는 파일에서 읽은 num개의 char가
	//	저장되어 있어야 한다
	//	메모리에 저장된 char를 오름차순으로 정렬하라.
	//	'0'부터 ‘9’까지 모든 숫자가 있는 Player를 찾아 모두 몇 객체인지 출력하라. 
	// - 어떻게 찾았는지 보고서에 설명하라.
	// -> 유니크 포인터로 할당한 메모리들은 free-store 여기저기에 흩어져 있어 300만번 포인터를 타고 free-store 메모리로 점프를 뛰어야 하니 cpu 캐시 미스로 인해 RAM에서 데이터를 계속 가져오느라 엄청난 overhead.
	// 따라서 C++ 17에 추가된 병렬 알고리즘 사용.

	std::println("\n--- [과제 4 실행 결과] ---");

	//auto start_task4 = std::chrono::high_resolution_clock::now();

	//for (Player& player : players) {
	//	player.sort_chars();
	//}

	//int all_digits_count = std::count_if(players.begin(), players.end(), [](const Player& player) {
	//	return player.has_all_digits();
	//	});

	//auto end_task4 = std::chrono::high_resolution_clock::now();
	//auto duration_task4 = std::chrono::duration_cast<std::chrono::milliseconds>(end_task4 - start_task4);

	//std::println("모든 숫자가 있는 Player 객체 수: {}개", all_digits_count);
	//std::println("과제 4 실행 시간: {} ms", duration_task4.count()); // -> 이 방식으로 하면 대략 17초

	auto start_task4 = std::chrono::high_resolution_clock::now();

	std::for_each(std::execution::par, players.begin(), players.end(), [](Player& player) {
		player.sort_chars();
		});

	int all_digits_count = std::count_if(std::execution::par, players.begin(), players.end(), [](const Player& player) {
		return player.has_all_digits();
		});

	auto end_task4 = std::chrono::high_resolution_clock::now();
	auto duration_task4 = std::chrono::duration_cast<std::chrono::milliseconds>(end_task4 - start_task4);

	std::println("'0'부터 '9'까지 모든 숫자가 있는 객체 수: {}개", all_digits_count); // 1558690
	std::println("과제 4 처리 소요 시간: {} ms", duration_task4.count()); // 대략 2초

	//5.[LOOP] id를 입력받아 존재하는 id라면 다음 내용을 한 번에 화면 출력하라. 
	// 
	// - 모든 Player가 id 기준 오름차순으로 정렬되어 있는 상태에서
	//	해당 id 포함 앞과 뒤 Player의 정보를 출력한다.
	
	//	id가 같은 Player가 둘 이상이면 이들의 정보를 모두 출력하여야 한다. 
	// - Player가 name 기준 오름차순으로 정렬되어 있는 상태에서
	//	해당 name 포함 앞과 뒤 Player의 정보를 출력한다.
	//	같은 name이 여럿일 경우 바로 앞뒤의 Player 정보만 출력하면 된다. 
	
	// - Player가 score 기준 오름차순으로 정렬되어 있는 상태에서
	//	해당 score 포함 앞과 뒤 Player의 정보를 출력한다.
	//	같은 score가 여럿일 경우 바로 앞뒤 한명의 Player 정보만 출력하면 된다. 
	// * 프로그램은 5번을 무한히 반복할 수 있어야 한다.
	//	- 5번 문제를 어떻게 해결하였는지 보고서에 설명하라.

	std::println("\n--- [과제 5 초기화 중: 데이터베이스 인덱스 생성] ---");

	std::vector<const Player*> id_index(players.size());
	for (size_t i = 0; i < players.size(); ++i) {
		id_index[i] = &players[i];
	}

	// 이래도 메모리 낭비 없음. 딱 300만개만 공간 할당
	std::vector<const Player*> name_index = id_index;
	std::vector<const Player*> score_index = id_index;

	std::sort(std::execution::par, id_index.begin(), id_index.end(), [](const Player* a, const Player* b) {
		return a->get_id() < b->get_id();
		});
	std::sort (std::execution::par, name_index.begin(), name_index.end(), [](const Player* a, const Player* b) {
		return a->get_name() < b->get_name();
		});
	std::sort (std::execution::par, score_index.begin(), score_index.end(), [](const Player* a, const Player* b) {
		return a->get_score() < b->get_score();
		});

	std::println("인덱스 생성 완료! 검색을 시작합니다.\n");

	while (true) {
		size_t target_id;
		std::print("검색할 ID를 입력하세요: ");
		std::cin >> target_id;

		// 1. id 기준 검색 (O(log n) 이진 탐색)
		// lower_bound는 target_id보다 크거나 같은 값 중 첫 번째 위치를 찾고, 
		// upper_bound는 target_id보다 큰 값 중 첫 위치를 찾음.
		// 못찾을 경우, 찾는 값이 주어진 데이터들 보다 크면 end() 반환,
		// 작으면 begin() 반환. 찾는 값이 데이터들 사이에 있으면 그 위치 반환.
		auto id_lower = std::lower_bound(id_index.begin(), id_index.end(), target_id, [](const Player* p, size_t id) {
			return p->get_id() < id;
			});
		auto id_upper = std::upper_bound(id_index.begin(), id_index.end(), target_id, [](size_t id, const Player* p) {
			return id < p->get_id();
			});

		if (id_lower == id_index.end() || (*id_lower)->get_id() != target_id) {
			std::println("존재하지 않는 ID입니다. 다시 입력해주세요.\n");
			continue;
		}

		std::string target_name = (*id_lower)->get_name();
		int target_score = (*id_lower)->get_score();

		std::println("\n[ 1. ID 기준 정렬 상태에서 앞뒤 출력 ]");
		// 입력한 id의 전 인덱스 출력
		if (id_lower != id_index.begin()) (*(id_lower - 1))->show();
		// 입력한 id와 동일한 인덱스 출력
		for (auto it = id_lower; it != id_upper; ++it) (*it)->show();
		// 입력한 id의 후 인덱스 출력
		if (id_upper != id_index.end()) (*id_upper)->show();

		// 2. name 기준 검색(O(log n) 이진 탐색)
		auto name_lower = std::lower_bound(name_index.begin(), name_index.end(), target_name, [](const Player* p, const std::string& name) {
			return p->get_name() < name;
			});
		auto name_upper = std::upper_bound(name_index.begin(), name_index.end(), target_name, [](const std::string& name, const Player* p) {
			return name < p->get_name();
			});

		std::println("\n[ 2. Name 기준 정렬 상태에서 앞뒤 출력 ]");
		if (name_lower != name_index.begin()) (*(name_lower - 1))->show();
		for (auto it = name_lower; it != name_upper; ++it) (*it)->show();
		if (name_upper != name_index.end()) (*name_upper)->show();

		// 3. score 기준 검색(O(log n) 이진 탐색)
		auto score_lower = std::lower_bound(score_index.begin(), score_index.end(), target_score, [](const Player* p, int score) {
			return p->get_score() < score;
			});
		auto score_upper = std::upper_bound(score_index.begin(), score_index.end(), target_score, [](int score, const Player* p) {
			return score < p->get_score();
			});

		std::println("\n[ 3. Score 기준 정렬 상태에서 앞뒤 출력 ]");
		if (score_lower != score_index.begin()) (*(score_lower - 1))->show();
		for (auto it = score_lower; it != score_upper; ++it) (*it)->show();
		if (score_upper != score_index.end()) (*score_upper)->show();

		std::println("\n--- 검색 완료 ---\n");
	}
}