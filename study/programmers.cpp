

/* lv1.



*/


/* lv1.



*/


/* lv1.



*/


/* lv1.



*/


/* lv1. 평균 구하기

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    for(int i = 0; i < arr.size(); i++){
        answer += arr[i];
    }

    answer = answer / arr.size();

    return answer;
}


numeric의 accumulate를 사용

#include <string>
#include <vector>
#include <numeric>
using namespace std;

double solution(vector<int> arr) {
    double answer = accumulate(arr.begin(), arr.end(), 0);

    return answer / arr.size();
}

*/



/* lv1. 하샤드 수

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int temp = x;

    while(temp > 0){
        sum += temp%10;
        temp /= 10;
    }

    if (x % sum != 0) answer = false;

    return answer;
}

*/



/* lv1. 핸드폰 번호 가리기

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    for (int i = 0; i < phone_number.size() - 4; i++) {
        phone_number[i] = '*';
    }

    return phone_number;
}

문제 수정안하고 하면

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    answer = phone_number;

    for (int i = 0; i < phone_number.size() - 4; i++) {
        answer[i] = '*';
    }

    return answer;
}

*/



/* lv1. 행렬의 덧셈

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int i=0; i < arr1.size(); i++){
        vector<int> temp;

        for(int j=0; j < arr1[i].size(); j++){
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }

        answer.push_back(temp);
    }

    return answer;
}

*/



/* lv1. x만큼 간격이 있는 n개의 숫자

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    for (int i = 1; i<n+1; i++){
        answer.push_back(x*i);
    }

    return answer;
}



#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n, x);

    for (int i = 1; i < n; i++)
        answer[i] = answer[i - 1] + x;

    return answer;
}


*/



/* lv1. 직사각형 별찍기
* 
#include <iostream>

using namespace std;

int main(void) {

    int a;
    int b;

    cin >> a >> b;

    for (int i = 0; i < b; i++) {

        for (int j = 0; j < a; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}

문자열을 사용하여 for을 한 번만 사용.

#include <iostream>

using namespace std;

int main(void) {

    int a;
    int b;

    cin >> a >> b;

    string s = "";
    s.append(a, '*');

    for (int i = 0; i < b; i++) {
        cout << s << endl;
    }

    return 0;
}
*/



/* lv1. 신규 아이디 추천

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";


    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] = tolower(new_id[i]);
        }
    }

    for (int i = 0; i < new_id.length(); ) {
        if (isalpha(new_id[i]) || isdigit(new_id[i])
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            i++;
            continue;
        }

        new_id.erase(new_id.begin() + i);
    }

    for (int i = 1; i < new_id.length(); ) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i);
            continue;
        }
        else i++;
    }

    if (new_id.front() == '.') {
        new_id.erase(new_id.begin());
    }
    if (new_id.back() == '.') {
        new_id.erase(new_id.end() - 1);
    }

    if (new_id.empty()) {
        new_id = "a";
    }

    if (new_id.length() > 15) {
        new_id.erase(new_id.begin() + 15, new_id.end());
    }
    if (new_id.back() == '.') {
        new_id.erase(new_id.end() - 1);
    }

    while (new_id.length() < 3) {
        new_id += new_id.back();
    }

    answer = new_id;

    return answer;
}


실압근

#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;

    string ret;
    for (char& ch: new_id) {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) ret += ch;
    }

    new_id = ret;
    ret.clear();
    for (char& ch: new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();

    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();

    return ret;
}

*/



/* lv1. 신고결과 받기

#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>


using namespace std;



vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    map<string, int> id_count;
    map<string, set<string>> report_list;        // set : 중복 방지

    for (int i = 0; i < id_list.size(); ++i) {
        id_count[id_list[i]] = i;       // id 저장
    }

    for (auto rep : report) {
        stringstream ss(rep);
        string reporter, reported;
        ss >> reporter >> reported;

        report_list[reported].insert(reporter);      // reporter, reported 저장
    }

    for (auto list : report_list) {
        if (list.second.size() >= k) {      // second = reporter : 신고한 사람이 k 이상
            for (auto first : list.second) {
                answer[id_count[first]]++;
            }
        }
    }

    return answer;
}


other solution, use unique

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1.
    const int n = id_list.size();
    map<string, int> Conv;
    for (int i = 0; i < n; i++) Conv[id_list[i]] = i;

    // 2.
    vector<pair<int, int>> v;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (const auto& s : report) {
        stringstream in(s);
        string a, b; in >> a >> b;
        v.push_back({ Conv[a], Conv[b] });
    }

    // 3.
    vector<int> cnt(n), ret(n);
    for (const auto& [a, b] : v) cnt[b]++;
    for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
    return ret;
}

*/