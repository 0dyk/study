#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;

	for (int i = 0; i < 26; ++i) {




	}





	return 0;
}





// 알파벳을 입력받고
// a알파벳부터 z까지 개수를 확인
// 비교해서 가장 큰 알파벳을 찾고
// 그 수를 출력 or 같으면 ? 출력





/*
번


*/


/*
번


*/


/*
번


*/


/*
번


*/


/*
번


*/


/*
10809번

#include <iostream>
#include <string>			// find : 입력 문자열이 최초로 등장하는 위치의 인덱스를 반환하는 함수
using namespace std;

int main()
{
	string s;
	string az = "abcdefghijklmnopqrstuvwxyz";

	cin >> s;

	for (int i = 0; i < az.length(); ++i) {
		cout << (int)s.find(az[i]) << " ";
	}

	return 0;
}


#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char s[100];
	char az[] = "abcdefghijklmnopqrstuvwxyz";
	int k = 0;

	cin >> s;

	for (int i = 0; i < strlen(az); ++i) {

		for (int j = 0; j < strlen(s); ++j) {

			if (az[i] == s[j]) {
				cout << j << " ";
				k = 0;
				break;
			}
			else k = 1;
		}

		if (k == 1) cout << "-1 ";

	}

	return 0;
}
*/


/*					아스키코드에서 0 = 48이므로 -48
11720번

#include <iostream>
using namespace std;

int main()
{
	int n, t = 0;
	char ch;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> ch;
		t += int(ch) - 48;
	}

	cout << t;

	return 0;
}
*/


/*
11654번

#include <iostream>
using namespace std;

int main()
{
	char a;

	cin >> a;
	cout << (int)a;

	return 0;
}
*/


/*
1065번

#include <iostream>
using namespace std;

int cnt(int a)
{
	if (a < 100) {
		return true;
	}

	if (a / 100 - a / 10 % 10 == a / 10 % 10 - a % 10) {
		return true;
	}

	return false;
}


int main()
{
	int n, t = 0;
	cin >> n;

	for (int i = 1; i < n + 1; ++i) {
		if (cnt(i)) ++t;
	}

	cout << t;

	return 0;
}
*/


/*					요건 이해는 했는데 약간 헷갈림
4673번

#include <iostream>
using namespace std;

int sum(int n)
{
	int ans = n;
	while (n > 0)
	{
		ans += n % 10;
		n /= 10;
	}

	return ans;
}

int main(void)
{
	int d[10001] = {0, }, t;

	for (int i = 0; i < 10001; ++i) {
		t = sum(i);
		if (t < 10001) {
			d[t] = 1;
		}
	}
	for (int i = 0; i < 10001; ++i) {
		if (d[i] != 1) {
			cout << i << "\n";
		}
	}

	return 0;
}
*/


/*					잘 모르겠다...
15596번

#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int>& a)
{
	long long ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans = ans + a[i];
	}
	return ans;
}
*/


/*					정수와 실수가 같이 있을 경우의 계산 헷갈린다...
4344번

#include <iostream>
using namespace std;

int main()
{
	int c;

	cin >> c;

	for (int i = 0; i < c; ++i) {
		int n, t = 0, avg = 0, a[1000];
		double rt = 0;

		cin >> n;

		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			avg += a[j];
		}

		avg = avg / n;

		for (int j = 0; j < n; ++j) {
			if (a[j] > avg) ++t;
		}

		rt = (double)t / n * 100;

		cout << fixed;
		cout.precision(3);
		cout << rt << "%\n";
	}

	return 0;
}
*/


/*
8958번

#include <iostream>
using namespace std;

int main()
{
	int n;
	string s;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> s;

		int sum = 0, cnt = 0;

		for (int t = 0; t < s.length(); t++) {
			if (s[t] == 'O') {
				++cnt;
				sum += cnt;
			}
			else {
				cnt = 0;
			}
		}
		cout << sum << "\n";
	}

	return 0;
}
*/


/*
1546번

#include <iostream>
using namespace std;

int main()
{
	int n, a[1000], max = 0;
	double sum = 0;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		if (max < a[i]) max = a[i];

	}

	sum = sum / max * 100 / n;

	cout << fixed;
	cout.precision(2);
	cout << sum;;

	return 0;
}
*/


/*
3052번

#include <iostream>
using namespace std;

int main()
{
	int a[10], c;

	c = 1;

	for (int i = 0; i < 10; ++i) {
		cin >> a[i];

		for (int t = 0; t < i + 1; ++t) {
			if ((a[i] % 42) == (a[t] % 42)) break;
			if (t == i-1) ++c;
		}
	}

	cout << c;

	return 0;
}


#include <iostream>
using namespace std;

int main()
{
	int a, c[42] = {};

	for (int i = 0; i < 10; i++) {
		cin >> a;

		c[a % 42]++;
	}

	int t = 0;

	for (int a : c) {
		if (a > 0) {
			++t;
		}
	}
	cout << t;

	return 0;
}
*/


/*
2577번

#include <iostream>
using namespace std;

int main()
{

	int a, b, c, sum;
	int t[10] = {};

	cin >> a >> b >> c;

	sum = a * b * c;

	while (sum != 0) {
		++t[sum % 10];
		sum /= 10;
	}

	for (int i = 0; i < 10; ++i) {
		cout << t[i] << "\n";
	}

	return 0;
}
*/


/*
2562번

#include <iostream>
using namespace std;

int main()
{

	int a[9], max = 1, c = 0;

	for (int i = 0; i < 9; ++i) {
		cin >> a[i];
		if (max < a[i]) {
			max = a[i];
			c = i;
		}
	}

	cout << max << "\n" << c+1;

	return 0;
}
*/


/*					여기서는 실행이 안되는데 채점은 맞았다는데?? ;;; + a[n]으로 사용해도 되는데? ;;
10818번

#include <iostream>
using namespace std;

int main()
{
	int n, max = -1000001, min = 10000001;

	cin >> n;

	int a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];

		if (min > a[i]) min = a[i];
		if (max < a[i]) max = a[i];
	}

	cout << min << " " << max;

	return 0;
}
*/


/*
1110번

#include <iostream>
using namespace std;

int main()
{
	int a, b, i = 0;

	cin >> a;
	b = a;

	do {
		b = (b % 10) * 10 + (b / 10 + b % 10) % 10;

		++i;
	} while (a != b);

	cout << i;

	return 0;
}
*/


/*
10951번         while안에서 입력받을 경우 a, b에 정상적인 값이 들어오지 않을 경우 false로 종료된다.
				다른 방법 : while(!cin(cin >> a >> b).eof())
						  : while(scanf("%d %d"), &a, &b) !=-1) 등

#include <iostream>
using namespace std;

int main()
{
	int a, b;

	while (cin >> a >> b) {
		cout << a + b << "\n";
	}

	return 0;
}
*/


/*                      밑에 코드 한번에 입력받는 줄 알고 한건데 문제; 아 각 케이스마다;; 아래놈이 더...
10952번

#include <iostream>
using namespace std;

int main()
{
	int a, b;

	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		cout << a + b << "\n";
	}

	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int a[10], b[10];

	for (int i = 0; i < 10; ++i) {
		cin >> a[i] >> b[i];
		if (a[i] == 0) {
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		if (a[i] + b[i] == 0) {
			break;
		}

		cout << a[i] + b[i] << "\n";
	}

	return 0;
}
*/


/*
10871번

#include <iostream>
using namespace std;

int main()
{
	int n, x, a[10000];

	cin >> n >> x;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] < x) {
			cout << a[i] << " ";
		}
	}

	return 0;
}
*/


/*
2439번

#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {

		for (int t = 0; t < n - i; ++t) {
			cout << " ";
		}
		for (int t = 0; t < i; ++t) {
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}
*/


/*
2438번

#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {

		for (int t = 0; t < i; ++t) {
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}
*/


/*
11022번

#include <iostream>
using namespace std;

int main()
{
	int t, a, b;

	cin >> t;

	for (int i = 1; i <= t; ++i) {
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
	}

	return 0;
}
*/


/*
11021번

#include <iostream>
using namespace std;

int main()
{
	int t, a, b;

	cin >> t;

	for (int i = 1; i <= t; ++i) {
		cin >> a >> b;
		cout << "Case #" << i << ": " << a+b << "\n";
	}

	return 0;
}
*/


/*
2742번

#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << n-i << "\n";
	}

	return 0;
}
*/


/*
2741번

#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cout << i << "\n";
	}

	return 0;
}
*/


/*     빠른 a+b / 무슨 말인지 70%만 이해함 ㅋㅋ

ios_nase ~ : c++와 c 표준 스트림의 동기화를 해제해준다.
cie.tie ~ : 기본적으로 입력과 출력은 연결되어 있어서 입력을 할 경우
			이전의 출력 작업들을 콘솔창에 띄어주고 입력을 받는데
			이런 것 없이 바로바로 작동하게 해준다.

15552번

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, a, b;

	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}
*/


/*
8393번

#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		sum += i;
	}

	cout << sum;

	return 0;
}
*/


/*
10950번

#include <stdio.h>

int main()
{
	int t, a, b;

	scanf("%d", &t);

	while (t > 0) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);

		t -= 1;
	}

	return 0;
}
*/


/*
2739번

#include <stdio.h>

int main()
{
	int a;

	scanf("%d", &a);

	for (int i = 1; i < 10; ++i) {
		printf("%d * %d = %d\n", a, i, a * i);
	}

	return 0;
}
*/


/*
2480번

#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c) {
		printf("%d", 10000 + a * 1000);
	}
	else if (a == c || a == b || b == c) {
		if(a == b || a == c)
			printf("%d", 1000 + a * 100);
		else
			printf("%d", 1000 + c * 100);
	}
	else {
		if (a>b && a>c)
			printf("%d", a * 100);
		else if(b>c)
			printf("%d", b * 100);
		else
			printf("%d", c * 100);
	}

	return 0;
}
*/


/*
2525번

#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d %d", &a, &b);
	scanf("%d", &c);

	b += c;

	while (b >= 60) {
		b -= 60;
		++a;
	}

	if (a >= 24) {
		a -= 24;
	}

	printf("%d %d", a, b);

	return 0;
}
*/


/*
2884번

#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	if (b < 45)
	{
		b += 15;
		--a;
	}
	else
	{
		b -= 45;
	}

	if (a < 0)
	{
		a = 23;
	}

	printf("%d %d", a, b);

	return 0;
}
*/


/*
14681번

#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d \n %d", &a, &b);

	if (a > 0 && b > 0)
		printf("1");
	else if (a < 0 && b > 0)
		printf("2");
	else if (a < 0 && b < 0)
		printf("3");
	else
		printf("4");

	return 0;
}
*/


/*
2753번

#include <stdio.h>

int main()
{
	int a;

	scanf("%d", &a);

	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
		printf("1");
	else
		printf("0");

	return 0;
}
*/


/*
9498번

#include <stdio.h>

int main()
{
	int a;

	scanf("%d", &a);

	if(a >= 90 && a <= 100)
		printf("A");
	else if (a >= 80 && a <= 89)
		printf("B");
	else if (a >= 70 && a <= 79)
		printf("C");
	else if (a >= 60 && a <= 69)
		printf("D");
	else
		printf("F");

	return 0;
}
*/


/*
1330번

#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	if (a > b)
	{
		printf(">");
	}
	else if (a < b)
	{
		printf("<");
	}
	else
	{
		printf("==");
	}

	return 0;
}
*/


/*
2588번

#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d \n %d", &a, &b);

	printf("%d\n", a*(b%10));
	printf("%d\n", a * ((b/10)%10));
	printf("%d\n", a * (b / 100));
	printf("%d\n", a*b);

	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	char b[4];

	scanf("%d \n %s", &a, &b);

	printf("%d\n", a * (b[2] - '0'));
	printf("%d\n", a * (b[1] - '0'));
	printf("%d\n", a * (b[0] - '0'));
	printf("%d", a*atoi(b));

	return 0;
}
*/


/*
10430번

#include <stdio.h>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", (a + b) % c);
	printf("%d\n", ((a % c) + (b % c)) % c);
	printf("%d\n", (a*b) % c);
	printf("%d\n", ((a % c) * (b % c)) % c);

	return 0;
}
*/


/*
18108번

#include <stdio.h>

int main()
{
	int a;

	scanf("%d", &a);
	printf("%d", a-543);

	return 0;
}
*/


/*
10926번

#include <stdio.h>

int main()
{
	char a[51];

	scanf("%s", &a);
	printf("%s??!", a);

	return 0;
}
*/


/*
10869번

#include <stdio.h>
int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d\n", a+b);
	printf("%d\n", a-b);
	printf("%d\n", a*b);
	printf("%d\n", a/b);
	printf("%d\n", a%b);

	return 0;
}
*/


/*
1008번

#include <iostream>

using namespace std;
int main()
{
	double a, b;

	cin >> a >> b;
	cout.precision(10);
	cout << fixed;
	cout << a / b;

	return 0;
}


#include <stdio.h>

int main()
{
	double a, b;

	scanf("%lf %lf", &a, &b);
	printf("%.10lf", a / b);

	return 0;
}
*/


/*
10998번

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << a * b;

	return 0;
}
*/


/*
1001번

#include <iostream>

using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << a - b;

	return 0;
}
*/


/*
1000번

#include <iostream>

using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << a + b;

	return 0;
}
*/


/*
10172번

#include <iostream>

int main()
{
	printf("|\\_/|\n|q p|   /}\n( 0 )\"\"\"\\\n|\"^\"`    |\n||_/=\\\\__|");

	return 0;
}
*/


/*
10171번

#include <iostream>

int main()
{
	printf("\\    /\\\n )  ( ')\n(  /  )\n \\(__)|\n");

	return 0;
}
*/


/*
10718번

#include <iostream>

int main()
{
	printf("강한친구 대한육군\n");
	printf("강한친구 대한육군");

	return 0;
}
*/


/*
2557번

#include <stdio.h>

int main()
{
	printf("Hello World!");
	return 0;
}


#include <iostream>

int main()
{
	std::cout << "Hello World!" << std::endl;
	return 0;
}


#include <iostream>

using namespace std;
int main()
{
	cout << "Hello World!";

	return 0;
}
*/