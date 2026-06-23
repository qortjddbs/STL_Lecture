#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include "ZString.h"

using namespace std;
extern bool 관찰;

// [문제 1 & 2] Test 클래스 설계
class Test {
private:
    size_t id;
    ZString name;
public:
    // set 컨테이너 삽입 시 항상 오름차순 정렬을 유지하기 위한 핵심 연산자 (문제 1-2)
    bool operator<(const Test& rhs) const {
        return id < rhs.id;
    }

    // 파일에서 istream_iterator로 읽어오기 위한 연산자 (문제 1-2)
    friend istream& operator>>(istream& is, Test& test) {
        is >> test.id >> test.name;
        return is;
    }

    // 문제에서 제공된 출력 연산자
    friend ostream& operator<<(ostream& os, const Test& test) {
        os << test.id << " " << test.name << " ";
        return os;
    }

    // 문제 5번을 위한 getter 함수
    const ZString& getName() const {
        return name;
    }
};

int main()
{
    // ==========================================
    // [문제 1] "시험.txt" 읽기 및 set에 저장
    // ==========================================
    ifstream in_test("시험.txt");
    if (!in_test) {
        cout << "시험.txt 파일을 열 수 없습니다.\n";
        return -1;
    }

    set<Test> tests{ istream_iterator<Test>{in_test}, {} };
    cout << "--- [1-3] Test 객체 개수 ---\n";
    cout << tests.size() << "개\n\n";
    // 20906개

    // ==========================================
    // [문제 3] 관찰 스위치 및 마지막 객체 복사
    // ==========================================
    cout << "--- [3-1] 화면 출력 내용 (관찰 = true) ---\n";
    관찰 = true;
    Test temp = *tests.rbegin();  // ZString의 복사생성자 호출 확인용
    관찰 = false;
    cout << "\n";

    // ==========================================
    // [문제 4] "비교.txt" 읽기 및 vector 저장
    // ==========================================
    ifstream in_compare("비교.txt");
    if (!in_compare) {
        cout << "비교.txt 파일을 열 수 없습니다.\n";
        return -1;
    }

    vector<ZString> compares{ istream_iterator<ZString>{in_compare}, {} };
    cout << "--- [4-1] vector 저장 개수 ---\n";
    cout << compares.size() << "개\n\n";

    cout << "--- [4-2] 마지막 객체 show() 결과 ---\n";
    if (!compares.empty()) compares.back().show();
    cout << "\n";

    // ==========================================
    // [문제 5] 동일한 ZString 찾기 (binary_search)
    // ==========================================
    // 빠른 이진 탐색을 위해 비교 대상(vector)을 먼저 정렬
    sort(compares.begin(), compares.end());

    cout << "--- [5-3] 동일한 ZString 목록 ---\n";
    // set을 순회하며 정렬된 vector를 대상으로 binary_search 수행
    for (const auto& t : tests) {
        if (binary_search(compares.begin(), compares.end(), t.getName())) {
            cout << t.getName() << "\n";
        }
    }

    return 0;
}