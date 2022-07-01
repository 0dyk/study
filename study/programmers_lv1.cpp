/*
1렙 35/55
2렙 0/76
3렙 0/57
4렙 0/21
5렙 0/12
*/



/* lv1. 신고 결과 받기

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


other solution, use unique @@

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


/* lv1. 로또의 최고 순위와 최저 순위



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

실압근 @@

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


/* lv1. 숫자 문자열과 영단어



*/


/* lv1. 키패드 누르기



*/


/* lv1. 크레인 인형뽑기 게임



*/


/* lv1. 없는 숫자 더하기



*/


/* lv1. 음양 더하기



*/


/* lv1. 내적



*/


/* lv1. 소수 만들기



*/


/* lv1. 완주하지 못한 선수



*/


/* lv1. K번째수



*/


/* lv1. 모의고사



*/


/* lv1. 체육복



*/


/* lv1. 폰켓몬



*/


/* lv1. 실패율



*/


/* lv1. 약수의 개수와 덧셈



*/


/* lv1. 3진법 뒤집기



*/


/* lv1. 예산



*/


/* lv1. 두 개 뽑아서 더하기



*/


/* lv1. 2016년



*/


/* lv1. 최소직사각형



*/


/* lv1. 나머지가 1이 되는 수 찾기

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


/* lv1. 부족한 금액 계산하기

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

한줄

using namespace std;

long long solution(int price, int money, int count)
{
    long long res = money - (long long)price * count * (count + 1) / 2;

    return res < 0 ? - res : 0;
}

(long long)1 = 1LL

    long long res = money - 1LL * price * count * (count + 1) / 2;

*/


/* lv1. [1차] 비밀지도

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

2의 n승보다 큰가? 뒤에다 추가 -> 2로 나누어 지나? 앞에다 붙여주는 방식
2의 n승을 빼주는 방법을 비트 연산자를 한칸씩 미는 방법(>>)으로

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


/* lv1. 가운데 글자 가져오기

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

substr 사용

answer = s.subetr(s.length() / 2 - 1, 2);
answer = s.subetr(s.length() / 2, 1);

한줄

#include <string>

using namespace std;

string solution(string s) {
    return s.length() & 2 ? s.substr(s.length() / 2, 1) : s.substr(s.length() / 2 - 1, 2);
}

*/


/* lv1. [1차] 다트 게임

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

stringstream과 switch 사용

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

        bonus = ss.get(); // 커서를 하나씩 옮기면서 값을 반환
        option = ss.get(); 

        if (option != '*' && option != '#') {
            ss.unget(); // 커서를 앞으로 다시 옮긴다.
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


/* lv1. 같은 숫자는 싫어


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

if 부분을 밑에 처럼 가능

if(answer.back() != arr[i]) answer.push_back(arr[i]);

unique 사용 @@

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


/* lv1. 나누어 떨어지는 숫자 배열

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

if 문을 없얘고 return 값을 밑에 처럼 해도 ㅇㅋ

return answer.empty() ? vector<int>(1,-1) : answer;

*/


/* lv1. 두 정수 사이의 합

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    return (long long)(a + b) * (abs(a - b) + 1) / 2;;
}

비트 연산자 @@

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


/* lv1. 문자열 내 마음대로 정하기

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

lamda 함수 사용 @@

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

ㅏㅏㅏㅏㅏㅏㅏ


*/


/* lv1. 문자열 내 p와 y의 개수

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


/* lv1. 문자열 내림차순으로 배치하기

sort 없이 for 두번 사용해서 하는 법

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

algorithm sort 사용

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


/* lv1. 문자열 다루기 기본

아스키 코드 값

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

isdigit 사용

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


/* lv1. 서울에서 김서방 찾기

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    for(int i = 0; i < seoul.size(); i++)
    {
        if(seoul[i] == "Kim")
        {
            answer = "김서방은 " + to_string(i) + "에 있다";
        }
    }

    return answer;
}

find 사용 @@

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    int pos = find(seoul.begin(),seoul.end(),"Kim") - seoul.begin();

    answer = "김서방은 " + to_string(pos) + "에 있다";

    return answer;
}


*/


/* lv1. 소수 찾기

에라토스테네스의 체 

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

시간 복잡도를 조금 줄인 방식

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

for문을 2중으로 사용하면 시간 복잡도가 ^2가 되어 시간 초과

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


/* lv1. 수박수박수박수박수박수?

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for(int i = 0; i < n; i++){
        i & 1 ? answer += "박" : answer += "수";
    }
    
    return answer;
}

*/


/* lv1. 문자열을 정수로 바꾸기

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    answer = stoi(s);

    return answer;
}

*/


/* lv1. 시저 암호

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


/* lv1. 약수의 합

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

제곱근 사용 @@

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


/* lv1. 이상한 문자 만들기

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

아스키 코드로 A~Z : 65~90, a~z : 97~ 122 대소문자 32차이

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


/* lv1. 자릿수 더하기

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

문자열로 -'0'? @@

#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string s = to_string(n);

    for(int i = 0; i < s.size(); i++) answer += (s[i] - '0');

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}

*/


/* lv1. 자연수 뒤집어 배열로 만들기

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


/* lv1. 정수 내림차순으로 배치하기

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


/* lv1. 정수 제곱근 판별

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    double x = sqrt(n);

    return x - (int)x ? -1 : (x+1)*(x+1);
}

이게 더 간단한가?

#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);

    return powl(answer, 2) == n ? powl(answer + 1, 2) : -1;
}

*/


/* lv1. 제일 작은 수 제거하기

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

min_element사용 최대한 간단하게

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


/* lv1. 짝수와 홀수

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

밑에거 따라한거 ㅋㅋ

#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";

    return num % 2 ? "Odd" : "Even";
}

비트 연산자 이용해서 짝수 @@
짝수 ~~~~~~~~~0 % 0000000001 하면 1
홀수 ~~~~~~~~~1 % 0000000001 하면 0

num & 1 ? "Odd" : "Even";

*/


/* lv1. 최대공약수와 최소공배수

유클리드 호제법

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

유클리드 호제법 없이 구하기

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

신기한 놈이 한거 @@
return에 삼항연산자 쓰고 b가 0일떄 빠져나오니 true false 하는게 ㅎㄷ 재귀되는거 까지

int Euclidean(int a, int b)
{
    return b ? Euclidean(b, a%b) : a;
}

vector<int> gcdlcm(int a,int b)
{
    vector<int> answer;
    // 유클리드 호제법
  answer.push_back(Euclidean(a,b));

  answer.push_back(a*b / answer[0]);

    return answer;
}

*/


/* lv1. 콜라츠 추측

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

매우 짧게

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