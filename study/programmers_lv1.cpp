/*
1珪 43/55
2珪 0/76
3珪 0/57
4珪 0/21
5珪 0/12
*/



/* lv1. 重壱 衣引 閤奄

#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    map<string, int> id_count;
    map<string, set<string>> report_list;        // set : 掻差 号走

    for (int i = 0; i < id_list.size(); ++i) {
        id_count[id_list[i]] = i;       // id 煽舌
    }

    for (auto rep : report) {
        stringstream ss(rep);
        string reporter, reported;
        ss >> reporter >> reported;

        report_list[reported].insert(reporter);      // reporter, reported 煽舌
    }

    for (auto list : report_list) {
        if (list.second.size() >= k) {      // second = reporter : 重壱廃 紫寓戚 k 戚雌
            for (auto first : list.second) {
                answer[id_count[first]]++;
            }
        }
    }

    return answer;
}


use unique @@

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


/* lv1. 稽暁税 置壱 授是人 置煽 授是

#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 0);

    int ok = 0, no = 0;

    for (int n : lottos)
    {
        for (int i = 0; i < 6; i++)
        {
            if (n == win_nums[i]) ok++;
        }

        if (n == 0) no++;
    }

    if(ok + no < 2) answer[0] = 6;
    else answer[0] = 7 - ok - no;

    if(ok < 2) answer[1] = 6;
    else answer[1] = 7 - ok;

    return answer;
}

*/


/* lv1. 重鋭 焼戚巨 蓄探

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

叔笑悦 @@

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


/* lv1. 収切 庚切伸引 慎舘嬢

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer = "";


    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            answer += s[i];
        }

        else
        {
            if(s.substr(i,4) == "zero"){
                answer += '0';
                i += 3;
            }
            else if(s.substr(i,3) == "one"){
                answer += '1';
                i += 2;
            }
            else if(s.substr(i,3) == "two"){
                answer += '2';
                i += 2;
            }
            else if(s.substr(i,5) == "three"){
                answer += '3';
                i += 4;
            }
            else if(s.substr(i,4) == "four"){
                answer += '4';
                i += 3;
            }
            else if(s.substr(i,4) == "five"){
                answer += '5';
                i += 3;
            }
            else if(s.substr(i,3) == "six"){
                answer += '6';
                i += 2;
            }
            else if(s.substr(i,5) == "seven"){
                answer += '7';
                i += 4;
            }
            else if(s.substr(i,5) == "eight"){
                answer += '8';
                i += 4;
            }
            else if(s.substr(i,4) == "nine"){
                answer += '9';
                i += 3;
            }
        }
    }

    return stoi(answer);
}

舛鋭妊薄縦, 舛鋭縦, regex 紫遂

#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string s) {
    int answer = 0;

    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");

    answer = stoi(s);

    return answer;
}

壕伸?

#include <string>
#include <vector>


using namespace std;

int solution(string s) {
    string answer = "";

    vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            answer += s[i];
        }

        else
        {
            for(int j = 0; j < 10; j++)
            {
                if(s[i] == v[j][0] && s[i+1] == v[j][1])
                {
                    char tmp = j + '0';
                    answer += tmp;
                    i += v[j].size() - 1;
                    break;
                }
            }
        }
    }

    return stoi(answer);
}

*/


/* lv1. 徹鳶球 刊牽奄

#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int left = 10, right = 12;
    int l_dis = 0, r_dis = 0;

    for (int n : numbers)
    {
        if (n == 1 || n == 4 || n == 7)
        {
            answer += "L";
            left = n;
        }
        else if (n == 3 || n == 6 || n == 9)
        {
            answer += "R";
            right = n;
        }
        else // 2,5,8,0
        {
            if (n == 0) n = 11;

            l_dis = (abs(n - left) / 3) + (abs(n - left) % 3);
            r_dis = (abs(n - right) / 3) + (abs(n - right) % 3);

            if (l_dis > r_dis)
            {
                answer += "R";
                right = n;
            }
            else if (l_dis < r_dis)
            {
                answer += "L";
                left = n;
            }
            else
            {
                if (hand == "left")
                {
                    answer += "L";
                    left = n;
                }
                else
                {
                    answer += "R";
                    right = n;
                }
            }
        }
    }

    return answer;
}

*/


/* lv1. 滴傾昔 昔莫嗣奄 惟績

#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<int> tmp;

    for (int i = 0; i < moves.size(); i++)
    {

        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][moves[i] - 1] != 0)
            {
                tmp.push_back(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;

                if (tmp.size() >= 2 && (tmp[tmp.size() - 1] == tmp[tmp.size() - 2]))
                {
                    tmp.pop_back();
                    tmp.pop_back();
                    answer += 2;
                }

                break;
            }
        }
    }

    return answer;
}

*/


/* lv1. 蒸澗 収切 希馬奄

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;

    for(int n : numbers) answer -= n;

    return answer;
}

*/


/* lv1. 製丞 希馬奄

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for(int i = 0; i < absolutes.size(); i++)
    {
        if(signs[i]) answer += absolutes[i];
        else answer -= absolutes[i];
    }

    return answer;
}

*/


/* lv1. 鎧旋

#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    for(int i = 0; i < a.size(); i++)
    {
        answer += a[i] * b[i];
    }

    return answer;
}

numeric拭辞 inner_product 紫遂

#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    return inner_product(a.begin(),a.end(),b.begin(),0);
}

*/


/* lv1. 社呪 幻級奄

#include <vector>

using namespace std;

bool ckeck_prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (ckeck_prime(sum)) answer++;
            }
        }
    }

    return answer;
}

*/


/* lv1. 肉掴佼

政艦滴澗 舛慶 板拭 紫遂背醤 廃陥?

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size() / 2;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    if(n >= nums.size()) answer = nums.size();
    else answer = n;

    return answer;
}

set聖 醗遂

舛慶 板 i 人 i+1聖 搾嘘馬食 掻差 薦暗

背獣?

*/


/* lv1. 刃爽馬走 公廃 識呪

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i = 0; i < participant.size(); i++)
    {
        if(participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }

    return answer;
}

背獣 戚遂

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> names;

    for(int i = 0; i < participant.size(); i++)
    {
        names.insert(participant[i]);
    }

    for(int i = 0; i < completion.size(); i++)
    {
        unordered_multiset<string>::iterator itr = names.find(completion[i]);
        names.erase(itr);
    }

    return *names.begin();
}

@@搾闘 尻至切, 舛慶亀 背獣亀 紫帖陥...?

#include <string>
#include <vector>

using namespace std;
char c[29];
string solution(vector<string> a, vector<string> b) {
    for(int j=0;j<21;j++){
        c[j] = 0;
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            c[j]^=a[i][j];
        }
    }
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            c[j]^=b[i][j];
        }
    }
    return string(c);
}

*/


/* lv1. K腰属呪 @@ 畳短 戚雌馬惟 葱 剰 赤製. 戚 穿 庚薦析 呪亀

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;


    for (int i = 0; i < commands.size(); i++)
    {
        vector <int> tmp = array;

        for (int j = 0; j < (commands[i][0] - 1); j++)
            tmp.erase(tmp.begin());

        for (int j = 0; j < array.size() - commands[i][1]; j++)
            tmp.erase(tmp.end() - 1);

        sort(tmp.begin(), tmp.end());

        answer.push_back(tmp[commands[i][2] - 1]);
    }

    return answer;
}

sort研 働舛 骨是幻 舛慶馬食 舛岩 姥馬奄

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}


*/


/* lv1. 乞税壱紫

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<vector<int>> type{ {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5} };

    vector<int> ok(3, 0);

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == type[0][i % 5])
            ok[0]++;
        if (answers[i] == type[1][i % 8])
            ok[1]++;
        if (answers[i] == type[2][i % 10])
            ok[2]++;
    }


    int max_num = *max_element(ok.begin(), ok.end());


    for (int i = 0; i < 3; i++)
    {
        if (max_num == ok[i])
            answer.push_back(i + 1);
    }

    return answer;
}

*/


/* lv1. 端整差

#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> v(n, 1);

    for (int i = 0; i < lost.size(); i++)
    {
        v[lost[i] - 1]--;
    }

    for (int i = 0; i < reserve.size(); i++)
    {
        v[reserve[i] - 1]++;
    }

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == 0)
        {
            if(i != 0 && v[i - 1] == 2)
            {
                v[i]++;
                v[i - 1]--;
            }
            else if(i != v.size() - 1 && v[i + 1] == 2)
            {
                v[i]++;
                v[i + 1]--;
            }
        }
    }

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] != 0)
        {
            answer++;
        }
    }

    return answer;
}


for庚聖 捉惟 床澗 狛 : 紫遂

#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> v(n, 1);

    for (int i : lost) v[i - 1]--;

    for (int i : reserve) v[i - 1]++;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == 0)
        {
            if(i != 0 && v[i - 1] == 2)
            {
                v[i]++;
                v[i - 1]--;
            }
            else if(i != v.size() - 1 && v[i + 1] == 2)
            {
                v[i]++;
                v[i + 1]--;
            }
        }
    }

    for(int i : v)
    {
        if(i != 0) answer++;
    }

    return answer;
}

*/


/* lv1. 叔鳶晴

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, float> a, pair<int, float> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<int> now_stage(N + 2, 0);
    vector<pair<int, float>> stage_fail;

    for (int i = 0; i < stages.size(); i++)
    {
        now_stage[stages[i]]++;
    }

    int all = stages.size();

    for (int i = 0; i < N; i++)
    {
        if (now_stage[i + 1] == 0)
        {
            stage_fail.push_back({ i, 0 });
        }
        else
        {
        stage_fail.push_back({ i, (float)now_stage[i+1] / all});
        }

        all -= now_stage[i + 1];
    }

    sort(stage_fail.begin(), stage_fail.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        answer.push_back(stage_fail[i].first + 1);
    }

    return answer;
}

*/



/* lv1. 鉦呪税 鯵呪人 機疾

#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for(int i = left; i <= right; i++)
    {
        int tmp = 0;

        for(int j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                tmp ++;
            }
        }

        if(tmp % 2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }

    return answer;
}

*/



/* lv1. 3遭狛 及増奄

照紫遂.

#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;

    while (n) {
        v.push_back(n % 3);
        n /= 3;
    }


    for (int i = 0; i < v.size(); ++i)
    {
    answer = answer * 3 + v[i];
    }

    return answer;
}


pop_back(及拭辞 採斗 域至馬形壱)

#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<int> v;

    while (n)
    {
        v.push_back(n % 3);
        n /= 3;
    }

    int num = 1;

    for (int i = 0; i < v.size(); i++)
    {
        answer += v.back() * num;
        v.pop_back();
        num *= 3;
    }

    return answer;
}


reverse, pow 紫遂.

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<int> v;

    while (n)
    {
        v.push_back(n % 3);
        n /= 3;
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        answer += v[i] * pow(3, i);
    }

    return answer;
}

*/


/* lv1. 森至

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;

    sort(d.begin(), d.end());

    for(int i = 0; i < d.size(); i++)
    {
        sum += d[i];
        answer += 1;

        if(sum > budget)
        {
            answer -= 1;
            break;
        }
    }

    return answer;
}

神酔醤... for庚税 叔楳 繕闇拭 煽係惟...

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int i;
    for (i = 0; (budget=budget-d[i]) >= 0 && i < d.size(); i++) ;
    return i;
}

*/


/* lv1. 砧 鯵 嗣焼辞 希馬奄

set聖 紫遂

#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    set<int> sum;

    for(int i = 0; i < numbers.size(); ++i)
    {
        for(int j = i + 1; j < numbers.size() ;++j)
        {
            sum.insert(numbers[i] + numbers[j]);
        }
    }

    answer.assign(sum.begin(), sum.end());

    return answer;
}


for for sort unique 紫遂

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for(int i = 0; i < numbers.size() - 1; i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(answer.begin(), answer.end());

    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}

*/















/* lv1. 2016鰍

壕伸

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;

    sum += b - 1;

    for(int i = 0; i < a; i++)
    {
        sum += month[i];
    }

    answer = day[sum%7];

    return answer;
}


*/


/* lv1. 置社送紫唖莫

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int w = 0;
    int h = 0;

    for(int i = 0; i < sizes.size(); i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            if(sizes[i][0] > w)
            {
                w = sizes[i][0];
            }

            if(sizes[i][1] > h)
            {
                h = sizes[i][1];
            }
        }
        else
        {
            if(sizes[i][1] > w)
            {
                w = sizes[i][1];
            }

            if(sizes[i][0] > h)
            {
                h = sizes[i][0];
            }
        }
    }

    answer = w * h;

    return answer;
}

alforithm税 max 人 min聖 紫遂

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int w = 0, h = 0;

    for(int i = 0; i < sizes.size(); ++i)
    {
        w = max(w, max(sizes[i][0], sizes[i][1]));
        h = max(h, min(sizes[i][0], sizes[i][1]));
    }

    answer = w * h;

    return answer;
}

*/


/* lv1. 蟹袴走亜 1戚 鞠澗 呪 達奄

#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    for(int i = 2; i < n; i++)
    {
        if(n % i == 1)
        {
            return i;
        }
    }
}

*/


/* lv1. 採膳廃 榎衝 域至馬奄

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;



    if (money - (long long)price * count * (count + 1) / 2 < 0)
    {
        answer = (long long)price * count * (count + 1) / 2 - money;
    }
    else
    {
        answer = 0;
    }

    return answer;
}

廃匝

using namespace std;

long long solution(int price, int money, int count)
{
    long long res = money - (long long)price * count * (count + 1) / 2;

    return res < 0 ? - res : 0;
}

(long long)1 = 1LL

    long long res = money - 1LL * price * count * (count + 1) / 2;

*/


/* lv1. [1託] 搾腔走亀

#include <string>
#include <vector>
#include <cmath>


using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string tmp = "";

        arr1[i] = arr1[i] | arr2[i];

        for (int j = n; j > 0; j--)
        {
            if (arr1[i] - pow(2, j - 1) >= 0)
            {
                tmp.push_back('#');
                arr1[i] -= pow(2, j - 1);
            }
            else
            {
                tmp.push_back(' ');
            }
        }

        answer.push_back(tmp);
    }

    return answer;
}

2税 n渋左陥 笛亜? 及拭陥 蓄亜 -> 2稽 蟹刊嬢 走蟹? 蒋拭陥 細食爽澗 号縦
2税 n渋聖 皐爽澗 号狛聖 搾闘 尻至切研 廃牒梢 耕澗 号狛(>>)生稽

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i <n ; i++)
    {
        string tmp = "";

        arr1[i] = arr1[i] | arr2[i];
        
        for(int j = 0; j < n; j++)
        {
            if(arr1[i] % 2 == 0) 
            {
                tmp = " " + tmp;
            }            
            else
            {
                tmp = "#" + tmp;
            }
            
            arr1[i] = arr1[i] >> 1;
        }

        answer.push_back(tmp);
    }

    return answer;
}

*/


/* lv1. 亜錘汽 越切 亜閃神奄

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    if(s.size() % 2)
    {
        answer += s[s.length() / 2];
    }
    else
    {
        answer += s[s.length() / 2 - 1];
        answer += s[s.length() / 2];
    }

    return answer;
}

substr 紫遂

answer = s.subetr(s.length() / 2 - 1, 2);
answer = s.subetr(s.length() / 2, 1);

廃匝

#include <string>

using namespace std;

string solution(string s) {
    return s.length() & 2 ? s.substr(s.length() / 2, 1) : s.substr(s.length() / 2 - 1, 2);
}

*/


/* lv1. [1託] 陥闘 惟績

#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;


    int arr[3] = { 0, 0, 0}, index = 0;
    string num;

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (isdigit(dartResult[i]))
        {
            num += dartResult[i];
        }

        else
        {
            if (dartResult[i] == 'S')
            {
                arr[index] = stoi(num);
                index++;
            }
            else if (dartResult[i] == 'D')
            {
                arr[index] = stoi(num) * stoi(num);
                index++;
            }
            else if (dartResult[i] == 'T')
            {
                arr[index] = stoi(num) * stoi(num) * stoi(num);
                index++;
            }

            else if (dartResult[i] == '*')
            {
                arr[index - 1] *= 2;

                if (index > 1)
                {
                    arr[index - 2] *= 2;
                }
            }
            else if (dartResult[i] == '#')
            {
                arr[index - 1] *= -1;
            }

            num = "";
        }

    }

    for (int i = 0; i < 3; i++)
    {
        answer += arr[i];
    }

    return answer;
}

stringstream引 switch 紫遂

#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };

    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;

        bonus = ss.get(); // 朕辞研 馬蟹梢 薪奄檎辞 葵聖 鋼発
        option = ss.get(); 

        if (option != '*' && option != '#') {
            ss.unget(); // 朕辞研 蒋生稽 陥獣 薪延陥.
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}

*/


/* lv1. 旭精 収切澗 夙嬢


#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    answer.push_back(arr[0]);

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i-1] != arr[i])
        {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

if 採歳聖 購拭 坦軍 亜管

if(answer.back() != arr[i]) answer.push_back(arr[i]);

unique 紫遂 @@

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{

    arr.erase(unique(arr.begin(), arr.end()),arr.end());

    vector<int> answer = arr;
    return answer;
}


*/


/* lv1. 蟹刊嬢 恭嬢走澗 収切 壕伸

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;


    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] % divisor == 0)
        {
            answer.push_back(arr[i]);
        }
    }

    if(answer.empty())
    {
        answer.push_back(-1);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

if 庚聖 蒸剰壱 return 葵聖 購拭 坦軍 背亀 しせ

return answer.empty() ? vector<int>(1,-1) : answer;

*/


/* lv1. 砧 舛呪 紫戚税 杯

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    return (long long)(a + b) * (abs(a - b) + 1) / 2;;
}

搾闘 尻至切 @@

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a > b) a ^= b ^= a ^= b;

    answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;

    return answer;
}

*/


/* lv1. 庚切伸 鎧 原製企稽 舛馬奄

#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int num;

bool cmp(string a, string b){
    if(a[num] == b[num])
    {
        return a < b;
    }
    else
    {
        return a[num] < b[num];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    num = n;

    sort(strings.begin(), strings.end(), cmp);

    answer = strings;

    return answer;
}

lamda 寓陥 敗呪 紫遂 @@

#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    sort(strings.begin(), strings.end(), [=](string a, string b) -> bool{
        if(a[n] == b[n]) return a < b;
        else return a[n] < b[n];
    });

    answer = strings;

    return answer;
}

たたたたたたた


*/


/* lv1. 庚切伸 鎧 p人 y税 鯵呪

#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int cnt = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'p' || s[i] == 'P')
        {
            cnt++;
        }
        if(s[i] == 'y' || s[i] == 'Y')
        {
            cnt--;
        }
    }
    
    return cnt ? false : true;
}

*/


/* lv1. 庚切伸 鎧顕託授生稽 壕帖馬奄

sort 蒸戚 for 砧腰 紫遂背辞 馬澗 狛

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i + 1; j < s.size(); j++)
        {
            if(s[i] < s[j])
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    answer = s;

    return answer;
}

algorithm sort 紫遂

#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string solution(string s) {
    string answer = "";

    sort(s.rbegin(), s.rend());

    answer = s;

    return answer;
}

*/


/* lv1. 庚切伸 陥欠奄 奄沙

焼什徹 坪球 葵

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if(s.size() != 4 && s.size() != 6)
    {
        answer = false;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] < '0' || s[i] > '9')
        {
            answer = false;
        }
    }

    return answer;
}

isdigit 紫遂

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if(s.size() != 4 && s.size() != 6)
    {
        answer = false;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i]) == false)
        {
            answer = false;
        }
    }

    return answer;
}

*/


/* lv1. 辞随拭辞 沿辞号 達奄

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    for(int i = 0; i < seoul.size(); i++)
    {
        if(seoul[i] == "Kim")
        {
            answer = "沿辞号精 " + to_string(i) + "拭 赤陥";
        }
    }

    return answer;
}

find 紫遂 @@

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    int pos = find(seoul.begin(),seoul.end(),"Kim") - seoul.begin();

    answer = "沿辞号精 " + to_string(pos) + "拭 赤陥";

    return answer;
}


*/


/* lv1. 社呪 達奄

拭虞塘什砺革什税 端 

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<bool> v(n, true);

    for(int i = 2; i <= n; i++){
        if(v[i] == true){
            for(int j = 2; i*j <= n; j++){
                v[j*i] = false;
            }

            answer++;
        }
    }

    return answer;
}

獣娃 差説亀研 繕榎 匝昔 号縦

int numOfPrime(int n)
{
    int answer = 0;
    bool isPrime = true;

  for( int i = 2 ; i <= n ; ++i )
  {
    isPrime = true;
    for( int j = 2 ; j * j <= i ; ++j )
    {
      if( i % j == 0 )
      {
        isPrime = false;
        break;
      }
    }
    if( isPrime )
    {
      answer++;
    }
  }
    return answer;
}

for庚聖 2掻生稽 紫遂馬檎 獣娃 差説亀亜 ^2亜 鞠嬢 獣娃 段引

#include <string>
#include <vector>

using namespace std;

bool prime(int a){
    for(int i = 2; i < a; i++){
        if(a % i == 0) return false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;

    for(int i = 2; i <= n; i++){
        answer += prime(i);
    }

    return answer;
}

*/


/* lv1. 呪酵呪酵呪酵呪酵呪酵呪?

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for(int i = 0; i < n; i++){
        i & 1 ? answer += "酵" : answer += "呪";
    }
    
    return answer;
}

*/


/* lv1. 庚切伸聖 舛呪稽 郊荷奄

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    answer = stoi(s);

    return answer;
}

*/


/* lv1. 獣煽 章硲

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {

        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = (s[i] + n - 'A') % 26 + 'A';
        }

        if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] = (s[i] + n - 'a') % 26 + 'a';
        }
    }

    answer = s;

    return answer;
}

*/


/* lv1. 鉦呪税 杯

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = n;

    while(i >= 1){
        if(n % i == 0){
            answer += i;
        }

        i--;
    }

    return answer;
}

薦咽悦 紫遂 @@

#include <string>
#include <vector>
#include<cmath>

using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            answer += i;
            
            if(n!=i*i){
                answer += n/i; 
            }
        }
    }

    return answer;
}

*/


/* lv1. 戚雌廃 庚切 幻級奄

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int temp = 0;

    for(int i=0; i<s.size(); i++){

        if(s[i] == ' '){
            temp=0;
            continue;
        }

        if(temp & 1){
            s[i] = tolower(s[i]);
        }
        else{
            s[i] = toupper(s[i]);
        }

        temp++;
    }

    answer = s;

    return answer;
}


#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int temp = 0;

    for(int i=0; i<s.size(); i++){

        if(s[i] == ' '){
            temp=0;
            continue;
        }

        if(temp & 1){
            if(s[i] <= 'Z') s[i]+=32;
        }
        else{
            if(s[i] >= 'a') s[i]-=32;
        }

        temp++;
    }

    answer = s;

    return answer;
}

*/


/* lv1. 切鹸呪 希馬奄

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while(n > 0){
    answer += n%10;
    n /= 10;
    }

    return answer;
}

庚切伸稽 -'0'? @@

#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string s = to_string(n);

    for(int i = 0; i < s.size(); i++) answer += (s[i] - '0');

    // [叔楳] 獄動聖 刊牽檎 窒径 葵聖 瑳 呪 赤柔艦陥.
    cout << "Hello Cpp" << endl;

    return answer;
}

*/


/* lv1. 切尻呪 及増嬢 壕伸稽 幻級奄

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    while (n > 0) {
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}

*/


/* lv1. 舛呪 鎧顕託授生稽 壕帖馬奄

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    string temp = to_string(n);

    sort(temp.rbegin(), temp.rend());

    return stoll(temp);
}

*/


/* lv1. 舛呪 薦咽悦 毒紺

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    double x = sqrt(n);

    return x - (int)x ? -1 : (x+1)*(x+1);
}

戚惟 希 娃舘廃亜?

#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);

    return powl(answer, 2) == n ? powl(answer + 1, 2) : -1;
}

*/


/* lv1. 薦析 拙精 呪 薦暗馬奄

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int min = 0;

    for (int i = 0; i < arr.size(); i++) {

        if (arr[min] > arr[i]) {
            min = i;
        }
    }

    arr.erase(arr.begin() + min);

    if(arr.empty()){
        arr.push_back(-1);
    }

    return arr;
}

min_element紫遂 置企廃 娃舘馬惟

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    arr.erase(min_element(arr.begin(), arr.end()));

    return arr.empty() ? vector<int>(1, -1) : arr;
}


*/


/* lv1. 側呪人 筈呪

#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";

    if(num % 2 == 0){
        answer = "Even";
    }
    else{
        answer = "Odd";
    }

    return answer;
}

購拭暗 魚虞廃暗 せせ

#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";

    return num % 2 ? "Odd" : "Even";
}

搾闘 尻至切 戚遂背辞 側呪 @@
側呪 ~~~~~~~~~0 % 0000000001 馬檎 1
筈呪 ~~~~~~~~~1 % 0000000001 馬檎 0

num & 1 ? "Odd" : "Even";

*/


/* lv1. 置企因鉦呪人 置社因壕呪

政適軒球 硲薦狛

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;

    int a, b, c;
    a = n;
    b = m;

    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }

    answer.push_back(a);
    answer.push_back(n * m / a);

    return answer;
}

政適軒球 硲薦狛 蒸戚 姥馬奄

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;

    int min, max;
    if(n<m){
        min = n;
        max = m;
    }
    else{
        min = m;
        max = n;
    }

    for(int i = min; i>=1;i--){
        if(n%i==0 && m%i==0){
            answer.push_back(i);
            break;
        }
    }

    for(int i = max; i<= n*m;i++){
        if(i%n == 0 && i%m == 0){
            answer.push_back(i);
            break;
        }
    }

    return answer;
}

重奄廃 叶戚 廃暗 @@
return拭 誌牌尻至切 床壱 b亜 0析�� 匙閃蟹神艦 true false 馬澗惟 ぞぇ 仙瑛鞠澗暗 猿走

int Euclidean(int a, int b)
{
    return b ? Euclidean(b, a%b) : a;
}

vector<int> gcdlcm(int a,int b)
{
    vector<int> answer;
    // 政適軒球 硲薦狛
  answer.push_back(Euclidean(a,b));

  answer.push_back(a*b / answer[0]);

    return answer;
}

*/


/* lv1. 紬虞苧 蓄著

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;

    long long n = num;

    while (n != 1) {

        if(n % 2 == 00){
            n /= 2;
        }
        else{
            n = n*3 + 1;
        }

        answer +=1;

        if(answer == 500){
            answer = -1;
            break;
        }

    }

    return answer;
}

古酔 捉惟

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;

    long long n = num;

    while (n != 1) {

        n % 2 == 0 ? n /= 2 : n = n * 3 + 1;
        answer++;

        if(answer == 500){
            answer = -1;
            break;
        }

    }

    return answer;
}

*/


/* lv1. 汝液 姥馬奄

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


numeric税 accumulate研 紫遂

#include <string>
#include <vector>
#include <numeric>
using namespace std;

double solution(vector<int> arr) {
    double answer = accumulate(arr.begin(), arr.end(), 0);

    return answer / arr.size();
}

*/



/* lv1. 馬時球 呪

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



/* lv1. 輩球肉 腰硲 亜軒奄

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

庚薦 呪舛照馬壱 馬檎

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



/* lv1. 楳慶税 機疾

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



/* lv1. x幻鏑 娃維戚 赤澗 n鯵税 収切

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



/* lv1. 送紫唖莫 紺啄奄
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

庚切伸聖 紫遂馬食 for聖 廃 腰幻 紫遂.

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


/*
set container(尻淫 珍砺戚格)

<set> 伯希 督析

葛球 奄鋼 珍砺戚格, 液莫 戚草闘軒

key虞 災軒澗 据社級税 増杯生稽 戚欠嬢像.

ket 葵精 掻差戚 買遂鞠走 省澗陥.

insert 呉獄 敗呪拭 税背 諮脊戚 鞠檎 据社澗 切疑生稽 舛慶 吉陥.

default 舛慶奄層精 less(神硯託授)戚陥.

)

set <data type> 痕呪 戚硯

ex) set <int> s;
ex) set <int> s(pred);  // 痕呪 戚硯(舛慶奄層)
ex) set <int> s2(s1);   // s1聖 差紫廃 s2

尻至切 ==, !=, <, >, <=, >= 紫遂 亜管

s.begin()   // 固 湛腰属 据社研 亜軒徹澗 鋼差切研 軒渡.
s.end() // 固 原走厳 据社(税 陥製)研 亜軒徹澗 据社税 魁採歳聖 硝 凶 紫遂? 鋼差切研 軒渡.

s.rbegin();
s.rend();

s.clear();  // 乞窮 据社 薦暗

s.count(k);  // 据社 k税 姐呪研 鋼発(set精 掻差戚 買遂鞠走 省生糠稽 0 or 1)

s.insert(k);    // 据社 k研 諮脊(切疑生稽 舛慶吉 是帖拭)
s.insert(iter, k);  // iter亜 亜軒徹澗 是帖 採斗 k研 諮脊拝 是帖研 貼事馬食 諮脊.

s.erase(iter);  // iter亜 亜軒徹澗 据社研 薦暗. 薦暗 廃 陥製 薦暗 廃 据社 陥製 据社研 亜軒徹澗 鋼差切研 軒渡.
s.erase(start, end);    // [start, end) 骨是税 据社研 乞砧 薦暗

s.fiond(k); // 据社 k研 亜軒徹澗 鋼差切研 鋼発, 酔格社 k亜 蒸陥檎 s.end()人 旭精 鋼差切研 鋼発.

s2.swap(s1);    // s1引 s2研 郊菓陥.

s.upper_biund(k);   // 据社 k亜 魁蟹澗 姥娃税 鋼差切.
s.lower_biund(k);   // 据社 k亜 獣拙馬澗 姥娃税 鋼差切.

s.equal_range(k);   // 据社 k亜 獣拙馬澗 姥娃引 魁蟹澗 姥娃税 鋼差切 pair 梓端研 鋼発.

s.value_comp();
s.key_comp();   // 舛慶 奄層 繕闇切研 鋼発, set 拭辞 砧鯵税 敗呪 鋼発莫戚 旭陥.

s.size(); 紫戚綜(据社税 姐呪) 鋼発.

s.max_size();   // 置企 紫戚綜(害精 五乞軒 滴奄)研 鋼発.

*/


/*

lamda(寓陥)



*/

/*

unique(政艦滴)



*/



/*

ASCII code(焼什徹 坪球)


硝督昏

A~Z : 65~90, a~z : 97~ 122 

企社庚切 32託戚

収切






*/


/*

vector(困斗)


assign

困斗 梓端拭 戚穿拭 赤醸揮 据社級聖 乞砧 肢薦馬壱, 昔切稽 歯稽錘 鎧遂聖 増嬢 隔澗陥.

void assign(inputiterator first, inputiterator last);
first採斗 last郊稽 送穿猿走税 据社級聖 困斗拭 企脊廃陥.

void assign(size_type n, const T& u);
据社 u研 n鯵 亜走澗 困斗稽 幻窮陥.(n精 採硲 蒸澗 舛呪, u澗 鋼差吃 据社稽 T展脊)

軒渡 葵 x










*/