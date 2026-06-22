#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

#include "ZString.h" // 수업시간에 만든 YString

using namespace std;

int main()
{
    // ==========================================
    // [문제 1] 앨리스 텍스트 읽기 및 show 비교
    // ==========================================
    ifstream in1{ "이상한 나라의 앨리스.txt" };
    if (!in1) {
        cout << "앨리스 파일을 열 수 없습니다.\n";
        return -1;
    }

    // 1. List로 읽기 (주석 해제해서 1-2번 결과 확인할 때 사용)
    
    //list<ZString> Allice{ istream_iterator<ZString>{in1}, {} };
    //cout << "--- [1-2] list show() ---" << endl;
    //if(!Allice.empty()) Allice.back().show();
    //// [  26632] show     - 객체:0X01ED7900C550, 글자:0X01ED78FFA430, 개수:3      내용:END
    //cout << "-------------------------" << endl;
    

    // 파일 포인터를 다시 처음으로 되돌리기 (vector로 다시 읽기 위해)
    //in1.clear();
    //in1.seekg(0, ios::beg);

    //// 2. Vector로 읽기
    vector<ZString> Allice{ istream_iterator<ZString>{in1}, {} };
    cout << "--- [1-3] vector show() ---" << endl;
    if (!Allice.empty()) Allice.back().show();
    // [  81261] show     - 객체:0X016CA8E9C0B8, 글자:0X016CA8D1ACD0, 개수:3      내용:END
	cout << Allice.size() << " 개\n" << Allice.capacity() << " 개\n";
    cout << "---------------------------" << endl;


    //// ==========================================
    //// [문제 2] 단어들.txt 읽기
    //// ==========================================
    ifstream in2{ "단어들.txt" };
    if (!in2) {
        cout << "단어들 파일을 열 수 없습니다.\n";
        return -1;
    }
    
    vector<ZString> words{ istream_iterator<ZString>{in2}, {} };
    
    cout << "--- [2-1] 단어들.txt 개수 ---" << endl;
    cout << words.size() << " 개\n";
    cout << "-----------------------------" << endl;


    // ==========================================
    // [문제 3] 겹치는 단어들(교집합) 찾기
    // ==========================================
    // 1. Allice 복사, 정렬 및 중복 제거
    vector<ZString> unique_Allice = Allice;
    sort(unique_Allice.begin(), unique_Allice.end());
    unique_Allice.erase(unique(unique_Allice.begin(), unique_Allice.end()), unique_Allice.end());

    // 2. words 복사, 정렬 및 중복 제거
    vector<ZString> unique_words = words;
    sort(unique_words.begin(), unique_words.end());
    unique_words.erase(unique(unique_words.begin(), unique_words.end()), unique_words.end());

    // 3. 겹치는 단어를 담을 새로운 벡터
    vector<ZString> intersection_words;

    // 4. 교집합 알고리즘 실행
    set_intersection(unique_Allice.begin(), unique_Allice.end(),
        unique_words.begin(), unique_words.end(),
        back_inserter(intersection_words));

    // 5. 파일에 쓰기 (공백 한 칸 띄우기)
    ofstream out{ "겹치는 단어들(화56수34).txt" };
    for (const ZString& w : intersection_words) {
        out << w << " ";
    }

    cout << "--- [3-2] 겹치는 단어 개수 ---" << endl;
    cout << intersection_words.size() << " 개\n";
	cout << intersection_words.capacity() << " 개\n";
    cout << "------------------------------" << endl;
}