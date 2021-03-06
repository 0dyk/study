// asoort rock youtube c/c++ study

/*
#include <stdio.h>
int main()
{
	//1강

	// 주석 //로 시작


	// 2~4강 자료형(정수형, 실수형)

	// 자료형(Data Type)은 크게 정수형, 실수형 (크기, byte)     ※ 1byte = 8bit, 1bit는 더 이상 나눌 수 없는 최소 단위, 1bit = 1 or 0     ※ 1024byte = 1KB , 1024KB = 1MB, 1024MB = 1GB
	// 정수형 ex) char(1), short(4), int(4), long(4), long long(8)
	// 실수형 ex) float(4), double(8)

	int i = 0;
	unsigned char c = 0;

	c = 255;

	// 만약 양수만 취급하려고 한다면 앞에 unsigned 붙이기
	// c는 크기가 1byte이기 때문에 0~255 까지 가능
	// 만약 256을 넣으면 0으로 인식

	char c1 = 0;

	c1 = -1;

	// c1은 1bit는 양,음수를 표현함. 그래서 -128~127까지 가능
	// 양음을 표현하는 bit는 MSB(Most Singnificant bit라고 함
	// 음수 표현 : -10의 경우 10이랑 '더해서 0이 되는 값'으로 정의
	// 0111 1111(127)과 더했을 때 0이 되는 1000 0001이 -127이다.
	// 0000 0001(1)과 더 헀을 때 0이 되는 1111 1111이 -1이다.

	// c1 = 255라고 입력을 한다면 비트값은 1111 1111이고 이 수를 음수로 인식하기 때문에 -1로 인식한다.     → 포인터랑 같은 개념?
	// c = -1이라고 입력을 한다면 비트값은 1111 1111이기 이 수를 양수로 인식하기 때문에 255로 인식한다.

	// 음의 정수 찾기(2의 보수법) 양수를 반전 후(0과 1) 1을 더한다.


	// 실수 표현법 = 부동 소수점
	// 실수를 근사값으로 표현
	// 21.8125를 표현한다고 하면 21 = 10101, 0.8125 = 0.5 + 0.25 + (0.125) +0.0625 = 11010 마지막 0은 뭐지?
	// 따라서 21.825 = 10101 11010 이를 정규화하면 0.1010111010 * 2^5
	// 0 / 0000101 / 1010111010
	// 양  2의 5승     21.825
	// 부호 / 지수부분 / 가수부분

	float f = 10.2415f + (float)20;
	// 10.f의 경우 실수가 float 자료형임을 나타냄. 붙이지 않으면 double
	// 실수 + 정수의 계산은 불가능하기 때문에 20을 실수로 명시해주기.



	// 5~7강 연산자(산술, 증감, 논리)



	//산술 연산자
	// +, -, *, /, %(모듈러스, 나머지, 정수형만)

	int data = 10 + 10;
	// +가 =보다 우선순위 연산자이기 때문에 data = 20
	// data = data + 1과 data += 1은 같다.

	data = 10 / 3;
	// data = 3.333333 이기 떄문에 3으로 출력

	// 자료형이 double → int로 바뀌기 때문에 오류 발생

	data = (int)(10. / 3.);
	// 위 처럼 자료형을 명시해주면 오류 x

	// data = 10. / 3.;
	// 실수는 나눌 경우 나머지가 없기 때문에 오류 발생


	// 증감 연산자
	// ++, --
	// 1씩 증가 감소가 아니라 한 단계가 증가 감소한다고 이해하기.

	data = 0;

	data++; // 후치, 모든 우선순위 중 가장 나중에 처리(대입 연산자 보다)
	++data; // 전치, 이유가 없다면 전치를 사용.(클래스나 오퍼레이트 등에서 문제가 발생할 수 있음?)

	i = 10;
	data = ++i; // data = 11 로 인식
	data = i++; // (data = i) + 1로 인식

	// 논리 연산자
	// !(역, 참→거짓, 거짓→참), &&(and, 둘 다 참일 경우 참), ||(or, 둘 중 하나만 참이여도 참)
	// 참(true), 거짓(false)
	// true = 0이 아닌 값, 출력 시 1을 출력
	// false = 0


	// bool(참, 거짓 전용 자료형, 1byte)

	bool istrue = 100; // istrue = true = 1을 저장


	istrue = true;
	istrue = !istrue; // istrue = false = 0

	istrue = 100 && 200; // istrue = 참 = 1
	istrue = 100 && 0; // istrue = 거짓 = 0

	istrue = 100 || 0; // istrue = 참 = 1


	// 비교 연산자
	// ==(같다), !=(다르다), <(왼쪽이 작다), >(왼쪽이 크다), <=(왼쪽이 작거나 같다),>=(왼쪽이 크거나 같다)
	// 결과는 참 또는 거짓으로 나온다.




	// 8, 9강 if / else 구문, switch 구문, 삼항연산자
	// if, else

	if (100 && 200)   // true 이므로 data = 100을 실행
	{
		data = 100;
	}
	else if (0 && 100)
	{
		data = 200;
	}
	else
	{
		data = 300;
	}


	switch (10)
	{
	case 10:

		data = 100; // case = 10이므로 앞의 문장을 실행
		break; // 만약 break가 없으면 오류로 인식하는게 아니라 아래의 문장(case = 20:)을 계속 실행한다.

	case 20:


		break;

	default:


		break;
	}


	// if, switch는 거의 동일하지만 if를 사용해야할 때가 있다.
	// 변수나 특정 값을 넣어야 할 때는 if가 편하다?
	// 조건이 너무 길어질 경우 switch가 간단하다?
	// 알아서 잘 써라~


	int itest = 10;

	switch (itest)
	{
	case 10:
	case 20:
	case 30:

		break;
	}

	if (itest == 10 || itest == 20 || itest == 30)
	{

	}


	// 삼항 연산자(조건 연산자)
	// ?:

	itest == 20 ? itest = 100 : itest = 200;
	// itest가 20이면 itest = 100, itest가 20이 아니면 itest = 200이다.

	if (itest == 20)
	{
		itest = 100;
	}
	else if (itest == 200)
	{
		itest = 200;
	}



	// 10, 11강 define, 비트연산자


	// 비트연산자
	// 쉬프트 <<, >> 비트를 화살표 방향으로 한칸 씩 민다.

	unsigned char b = 1; // b = 0000 0001 = 1

	b <<= 1;  // b = 0000 0010 = 2
	// 2진수가 왼쪽으로 한칸 씩 밀리면 2배가 된다. 2^n배수
	// ex) 1→2, 2→4, 4→8

	b <<= 2; // b = 0000 1000 = 8
	// 2칸 밀면 4배

	b >>= 3; // b = 0000 0100 = 1
	// 반대로 오른쪽으로 밀 경우 1/2배가 된다. 2^n으로 나눈 몫

	b = 5; // b = 0000 0101 = 5
	b >>= 1; // b = 0000 0010 = 2  5를 2로 나눈 몫
	// 홀수라서 마지막 비트가 1일 경우, 마지막 비트는 사라진다.


	// 비트 곱(&), 합(|), xor(^), 역(~)

	// & : 둘다 1이면 1, 하나라도 아니면 0
	// 1101 0010 & 0101 0100 = 0001 0000

	// | : 둘 중 하나라도 1이면 1
	// 1101 0010 | 0101 0100 = 1101 0110

	// ~ : 1은 0으로, 0은 1로
	// ~1101 0010 = 0010 1101

	// ^ : 비트값이 같으면 0 다르면 1
	// 1101 0010 ^ 0101 0100 = 1000 0110


	// 전처리기, #으로 시작, 모든 컴파일 과정 중 가장 먼저 시작

	// #difine
	// 지정한 구문을 특정 숫자로 치환

	#define hungry 1

	int cc = hungry; // c =1

	// 해당 숫자가 무엇을 의미하는지 헷갈릴 수 있는 경우를 없얘준다(가독성)
	// 수정할 일이 있을 때 간단하게 수정 가능(유지보수)


	// int = 4바이트 = 32비트
	// 총 32가지의 상태(1 or 0)을 저장 가능.
	// 마지막 비트는 hungry를 의미.

	#define thirsty 2
	#define tired 4     // 숫자가 커지면 입력하기 힘들기 떄문에 16진수로 표현하는게 편하다?0x(1~14,f)
						//  1   2   4   8   16   32   64  128   256   512
						// 0x1 0x2 0x4 0x8 0x01 0x02 0x04 0x08 0x001 0x002

	// 뒤에서 2번째 비트는 thirsty, 뒤에서 3번쨰 비트는 tired를 의미.

	cc |= thirsty; // cc = 3, ~~~~~ 00000 0011
	cc |= tired;

	if (cc & thirsty)
	{
		// 비트의 곱, thirsty의 2번째 비트 값만 1이기 때문에, cc의 2번째 비트 값이 1이어야만 실행
	}

	// 상태를 제거하고 싶을떄 xor → 같으면 0 다르면 1

	cc ^= tired; // 1,1로 같기 때문에 0으로 바뀜

	cc ^= tired; // 1, 0으로 다르기 때문에 1로 바뀜 → 제거가 아니라 추가되는 문제가 발생

	cc &= ~tired; // 곱과 역을 사용하면, tired는 3번째 값만 0이기 때문에 다른 자리는 모두 그대로고
				  //cc의 3번째 값이 0이면 0, 1이면 0으로 바뀐다.


	// 상태값을 사용하면 함수에 인자를 전달해 줄 수 있다.
	// 대충 조건이 여러개일 때 상태값 하나로 그 여러가지 조건을 다 확인할 수 있다.



	// 12강 변수

	// 지역변수 : main이라는 함수 안에 들어와있는 변수
	// 전역변수 : 함수 바깥에 선언되어 있는 변수
	// 정적변수 : 3가지로 구분?
	// 외부변수 : 분할구현?


	// 함수(Function, 기능)
	// 함수(함수(함수(함수)(함수))) ㅋㅋ
	// 모듈화 → 잘 합치고 잘 쪼개는게 잘하는 거다~


	data = 10 + 20;

	// int main 바깥에 아래와 같은 함수를 입력한 경우
	int add(int left, int right); // int 자료형의 left, right를 입력받고 합한 후 int 자료형으로 반환
	{
		return left + right;     // add 안에서 left, right는 지역변수
	}

	// 위의 식을 아래와 같이 사용할 수 있다.

	data = add(10, 20);


	// 함수 안에서도 지역을 나눌 수가 있다.

	int dup = 0;

	// int dup = 10; 같은 지역에 동일한 변수 이름을 사용하면 오류가 발생, 재정의(이미 있는 오류)

	{		// 변수명 규칙

		int dup = 0;	// 지역을 나눌 경우 같은 이름의 변수를 사용할 수 있다.

		dup = 10; // 지역변수를 우선해서 실행하기 때문에

	}

	dup += 100;  // 위 지역 내부의 dup은 저 안에서만 사용되기 때문에 dup = 0 + 100이 된다.



	// 13강 함수, 반복문

	// 프로그램의 정체성은 함수의 호출이다?

	// main 함수가 실행되고 return으로 종료된다.
	// 프로그램을 실행시켰을 때 보통 동작이 끝나도 자동으로 꺼지지 않는다. →



	// 반복문
	// for, while

	// for (반복문 초기화;반복문 조건 체크(true, false);반복자 변경)

	for (int i = 0; i < 10; ++i) // i = 0, i < 10이 참이므로 실행, ++i 실행, {} 내용 실행
	{                            // i가 10이 되면 종료.

	}

	// printf(), scanf()의 경우 우리가 정의한 적이 없기 때문에
	// 표준라이브러리? #include <stdio.h>를 호출

	printf("test");


	for (int i = 0; i < 4; ++i)
	{
		printf("output test\n");        // \n은 계획문자, 다음 줄로 이동해라는 뜻

	}

	// 아래와 같이 출력 된다.
	// output test
	// output test
	// output test


	// while(조건 체크)

	// 반복자를 따로 관리하지 않기 때문에 조건 선언이 자유롭다.

	int i = 0;

	while (i < 7)
	{
		printf("output test2\n");

		++i;
	}


	// 반복문 내부에서만 사용할 수 있는 키워드
	// continue, break

	// continue; 가 실행되면 뒷 부분을 수행하지 않고 다음 회차로 넘어간다.

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 1)	// i를 2로 나눈 나머지가 1인 경우, 홀수일 때
		{
			continue;	// 아래의 printf를 실행하는게 아니라 처음으로 돌아감
		}

		printf("output test\n");        // \n은 계획문자, 다음 줄로 이동해라는 뜻
	}


	// break;가 실행되면 반복문을 즉시 종료한다.


	// 줄넘저 왼쪽을 클릭해서 중단점을 잡아주면
	// 체크해준 중단점에서 실행을 중지한다.


	return 0;
}
*/


// 14강 단축키 및 편의사항

/*

단축키

주석 처리 : 드래그 후 Ctrl + k, c
주석 해체 : 드래그 후 Ctrl + k, u

Alt 드래그 : 원하는 영역만 드래그(신기 ㅋㅋ)


디버깅 관련 단축키
디버깅 시작 : F5
중단점 생성 및 해체 : F9					중단점이 생성된 줄 실행 x
디버깅 중 구문 수행(중단점이 생선된 한 구문) : F10					프로시저 단위?
디버깅 중 F11 : 한 단계씩 실행(해당 구문이 함수 호출 등의 여러 단계로 진행되는 구문일 떄)
디버깅 중에 종료 : Shift + F5

F12 : 선언, 정의된 위치로 이동




*/


// 15강 printf, scanf

// 16, 17강 함수

/*

자료 구조 Data Structure

Stack : 선입 후출	/	후입 선출

Queue : 선입 선출	/	후입 후출

함수가 사용하는 메모리 공간 = Stack 메모리 영역

함수가 실행되는 순간 모든 변수들의 메모리를 잡아둔다.

*/


// 18, 19강 재귀함수

/*

함수 안에서 자기 자신을 호출하는 함수

호출 스택 : 현재 호출되어 있는 함수들의 메모리 상황

계속해서 함수가 쌓여가기 때문에 호출 이전에 종료하는 구문이 필요하다

만약 스택 한계치에 도달하면 stack overflow라는 에러가 발생한다.

성능이 많이 떨어진다.

계층구조에 되게 편리하다. 트리 자료구조에 좋다.

ex) 피보나치 수열, 하노이 탑?

재귀함수 x

int fibo(int _inum)
{
	if (1 == inum || 2 == inum){
		return 1;
	}

	int iprev1 = 1, iprev2 = 1, ivalue = 0;

	for (int i = 0; i < _num - 2; ++i)
	{
		ivalue = iprev1 + iprev2;
		iprev1 = iprev2;
		iprev2 = ivalue;
	}

	return ivalue;
}

재귀함수

int fibonacci(int _inum)
{
	if ( i == _inum || 1 == _inum){
		return 1;
	}

	return fibonacci(inum - 1) + fibonacci(inum - 2);
}

피보나치를 재귀함수로 구현하면 개ㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐ느리다.
그걸 해결하기 위해서 꼬리재귀?

*/


// 20강 배열

/*

포인터 : c, c++에서 핵심?

int 변수를 10개 만들고 싶을 때, 변수 이름을 하나씩 지정해주는게 아니라
int i_1, i_2, --- 가 아니라 int iarray[10]로 한다.

irray[4] = 10;

irray[10] = 10;

[10]의 경우 자료 10개를 가질 수 있는데
이것이 0~9를 의미하기 떄문에 10을 사용하면 오류가 날 수 있다.

배열은 메모리가 연속적인 변수.

동일한 자료형으로 변수를 한 번에 여러개 할당하고 싶을 때 사용

int arr[5] = {};	// 배열 초기화

int arr[5] = {1,2,3};		// 를 입력하면 arr 0~2는 1,2,3 나머지는 0이 들어간다.



*/


// 21강 구조체

/*

C를 기반으로 설명하고 이후에 C++에서 바뀐 부분을 설명하신다네요

구조체 : 사용자 정의 자료형

C 스타일로 구조체를 만든다면

typedef struct _tagMYST
{
	int a;
	float f;
}MYST;

// myst가 하나의 자료형

typedef struct _tagBIG
{
	MYST k;
	int a;
	float f;
}BIG;


int main()
[
	MYST t;          //

	sizeof(t);       // 데이터의 크기를 알려줌 -> 8(byte)

	 t.a = 10;		// t 안의 a, f에 자료를 넣어준다~
	 t.f = 10.2312f;
}

typedefine : 타입을 재정의

typedef int TNT;	//이 이후로는 TNT a;로 사용


c에서는

struct NewStruct
{
	int a;
	float f;
};

NewStruct a;	// 오류 발생

struct NewStruct a;	// 구조체라는 것을 명시해 줘야 한다.

그래서 typedef를 추가하고 마지막에 구조체이름을 다시 입력하면 struct를 생략해도 된다.

c++에서는 typedef가 없어도 struct를 생략할 수 있다.


MYST = {100, 3.14f}; 이렇게 입력 가능.

.cpp 파일 속성 → 구조 속성 → 일반 → 빌드에서 제외

하면 제외됨 ㅋㅋ..

*/


// 22강 지역 변수 / 전역 변수

/*

변수의 종류

1. 지역변수 : 함수 안에 선언된 변수

함수 stack 내에 들어 있음.


2. 전역변수 : 함수 밖에 선언하는 변수

사용하는 메모리 영역이 다름 → Data 영역


3. 정적변수(static)

Data 영역


4. 외부변수(extern)

Data 영역



메모리 영역

1. 스택 영역

지역변수가 사용


2. 데이터 영역

전역변수, 정적변수, 외부변수가 사용

최초로 함수가 호출될 때 데이터 영역이 만들어진다.(아무 함수나)

→ 프로그램 시작 시 생성, 프로그램 종료 시 해제


3. 읽기 전용(코드.RDM)


4. 힙 영역

동적할당


*/


/*

함수의 반환타입이 없을 때는 void를 사용

void test()
{

}

*/


// 23, 24강 분할 구현, 분할 구현의 문제점

/*

헤더파일과 cpp파일을 분리해서 구현


헤더파일 func.h

int add(int a, intb);	// 이런 함수가 있다고만 선언하고, 어떤 함수인지는 x


cpp파일 func.cpp

함수를 사용하기 전에 선언하지 않으면 컴파일 단계에서 오류 발생 → 문법에 오류가 있다.

void add(); 로 선언한 뒤 사용하고 뒤쪽에 함수를 설명해주면 추후에 링크단계에서 연결해준다.

만약 뒤쪽에 구현하지 않으면 컴파일을 한 뒤에 링크 단계에서 오류 발생 → 문법에는 오류가 없다.


#include "fun.h"	// include는 전처리기. func.h를 참조

참조하면 컴파일단계에서 오류 x, 링크단계에서 오류 발생


func.cpp에서 add에 대해서 구현을 하면


추후에 실행파일을 만들 때 모두 합쳐지기 때문에

main.cpp에서는 func.h만 참조해주면 add를 구현하지 않아도 사용할 수 있다.


→ 자주 사용하는 함수 등을 따로 파일을 만들어 관리할 수 있다.

분할구현을 하면 속도저하가 생길 수 밖에 없지만 관리하기가 편해진다.


헤더파일의 역할 : 이런 함수가 있다 선언만하고 cpp를 연결하는 역할?

헤더파일에다가 함수를 구현하면 안되나?

→

한 cpp파일 안에 같은 이름으로 함수를 구현하면 오류 발생


헤드 파일에 함수를 구현하면

각 cpp파일에 전처리를 통해 함수가 들어가고 이후에 합쳐지면

동일한 이름으로 구현된 함수가 중복되게 된다.


cpp에서 전역변수를 선언했을 때 다른 cpp파일에는 그 변수를 사용할 수 없다.

만약 사용할 경우 오류 발생.

→ 정적변수, 외부변수

*/


// 25강 정적 변수 & 외부 변수

/*

정적변수 : static, 데이터 영역 메모리 사용

함수 바깥에 작성 = 해당 cpp파일에 선언

각자 선언된 파일 안에서 움직이지 않음(정적, static)

파일이 합쳐지더라도 각자의 출신으로 구별해줌.


static int g_istatic;

위 문장을 다른 cpp에 똑같이 입력해도 오류 발생 x



함수 안에 선언,

void test()
{
	static int i = 0;		// 함수 내에서만 사용할 수 있지만, 함수의 호출에 상관없이 상시 유지된다.
							// = 함수 바깥에서 변수를 건드릴 수 없다.
	++i;					// 위의 i = 0은 최초 실행시에만 실행되고 이후에는 x(초기화되지 않음)

}



int main()
{
	g_istatic;

	test();

	g_i = 100;

	i = 50;				// 오류 발생
}


외부변수 :

extern int g_iExtern;		// 절대 = 0; 등으로 초기화하면 안됨. 단지 있다고 선언만 해야 된다.


int g_iExtern = 0;

아무 파일에나 1곳에 위와 같이 작성해줘야 한다.(없을 경우 참조할게 없기 때문에)


*/


// 26강 운영 체제

/*

비쥬얼 스튣디오 → 솔루션 생성 → 프로젝트 생성

솔루션 플랫폼(위 메뉴창의 x64)


윈도우 운영체제에서 실행되도록 개발.(64비트, 32비트 등)

게임을 만든다고 하면 윈도우 안에서도 스팀, 에픽 게임즈, orizin 등에 맞추어 개발


62비트 ,32비트 = 데이트를 처리하는 단위

32비트 = 4바이트씩, 64비트 = 8비트씩

*/



// 27~29강 포인터, 포인터 배열

/*

포인터 : 주소를 저장하는(가르키는) 기능

포인터 변수 : 주소를 저장하는 변수

int* pint = nullptr;		// nullptr는 아무것도 가르키지 않는다는 의미. = 0;과 같음.

int = 4바이트 정수 자료형, int* = int자료형의 변수를 가르키는 변수


int i = 100;

int* pint = &i;			// pint = i의 주소

*pint = 200;			// i = 200;			// *pint = 주소에 접근, 참조


포인터형의 변수는 정수타입.

포인터의 단위는 byte


포인터에 int 등으로 선언해주는 이유.

그 주소로 이동해도 int(4byte)의 크기만큼 사용

만약 *pint에 다른 자료형을 넣으면 오류 발생.


float f = 3.f;

*pint = (*int)&f;	// 같은 자료형만 받기 때문에 오류 발생, (*int)를 넣어주면 강제로 가능

i = *pint;			// i는 3이 아니라 완전 다른 숫자가 됨, 실수 자료형의 3을 정수 자료형으로 읽어서.



포인터 변수

자료형 변수명

int* pInt = nullptr;  // int* : 정수형 자료형, 주소를 해석하는 단위 = 4byte
char* pChar = nullptr;
short* pshort = nullptr;	// p~ 는 주소의 이름(변수)

주소를 정수형을 본다는 말이 x, 그 주소번지에 해당하는 곳으로 이동해서 int(4byte)로 보겠다



32비트 운영체제 = 4byte, 한번에 처리하는 명령 단위?
4비트씩 처리하는데 8비트 짜리를 주면 처리 x, 8비트씩 처리하는데 4비트씩 주면 낭비일 뿐 가능.

64비트가 일반적으로 사용되므로 8비트?

4비트의 가지수 = 2의 32승, 8비트의 가지수 = 2의 64승

2의 32승은 총 4Gbyte, 그래서 32비트 컴퓨터는 4g 램만?

64비트 컴퓨터는 2의 32승 x 2의 32승 = 4g램 42억개 가능? ㅎㄷ


64비트 플랫폼 기준의 프로그래밍을 하면 8비트의 처리 단위를 가지기 때문에 포인트 변수의 크기는 8byte

int isize = sizeof(int*); // isize = 8(64비트 기준, 32비트로 바꿀 경우 4)


int i = 0;

pint = &i;	// pint : i의 주소 ex) 100~104

pint += &i;	// 1을 더할 경우, 104~108

포인터는 정수지만 포인터의 연산은 일반적인 정수의 연산 x

pint는 int 형식으로 보고 있고, +1은 다음 주소의 위치로 이동으로 해석해서 sizeof(int)단위로 증가.


포인터와 배열

int iArr[10] = {};	// 메모리가 연속적인 구조, 배열의 이름은 배열의 시작 주소이다.

나중에 설명( int(&iArr2)[10] = iArr; )

*(iArr + 0) = 1;	// iArr[0] = 1;
*(iArr + 1) = 10;	// iArr[1] = 10;


Q1.

short sArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int* pI = (int*)sArr;

int iData = *((short*)(pI+2));

iData = ?

// short는 2바이트 단위, int는 4바이트 단위 int 단위로 +2 이므로 총 4칸 이동 1 → 5
// 값으로 읽을 때 int로 읽으면 5, 6 이므로 (short*)로 읽어주게해서 5

Q2.

char cArr[2] = {1, 1};

short* pS = (short*)cArr;

iData = *pS;

iData = ?

// short 단위로 읽을 경우 1, 1을 둘다 읽게 됨.
(1, 1) = 00000001 00000001 = 257



다른 함수를 호출하여 사용할 때

값을 넘길 경우 그 함수 내에서 연산하고 끝나기 때문에 반환하지 않으면 값 변환 x(지역변수)

주소 값을 넘길 경우 ㄱㄴ


scanf_s("%d", &a);	// &a : a의 주소값에 입력.


*/


// 30, 31, 32강 const, const 포인터

/*

변수 앞에 const를 붙여서 사용

const int cint = 100;	// 상수화가 된다.(값이 바뀔 수 없는 상태)


상수 : r-value
변수 : l-value


절대 바뀔수 없는 건 아니다.

pint = (*int)&cint;
*pint = 300;			// cint는 300으로 바뀌지만 레지스터리에 저장해놓은 100을 출력(상수니까 바뀌지 않을거라고 생각해서)
						// 100이 나오네? volatile을 const 앞에 붙이면 300이 출력
						// volatile : 레지스터리 최적화 x?, 레지스터리 사용 x?


const와 포인터의 관계

int a = 0;
int* pint = &a;

*pint = 1;	// 가르키는 곳의 값을 변경, a = 1;, *는 주소로 접근
pint = nullptr;	// 가르키는 곳(위치)을 변경


const int* pconstint = &a;
*pconstint = 10;	// 오류 발생(식이 수정할 수 있는 lvalue여야 합니다.)

= 포인터 변수가 상수화 된게 아니라 가르키는 곳의 값이 상수화

int b = 0;
pconstint = &b;	// 가르키는 주소를 바꾸는 것은 오류 없음.



int* const pintconst = &a;	// const를 int 뒤에 붙일 경우 주소를 상수화(다른 위치를 가르키지 못한다.

const int* pconstint = &a;	// 주소는 변경 가능, 값은 변경 x

const int* const pconstintconst = nullptr;	// 주소도 변경 x 값도 변경 x


int const* p = nullptr;	// 만약 이런 경우? = const int* p = nullptr; 와 동일, *보다 앞이냐 뒤로 구분



int a = 0;
const int* pint = &a;	// 포인터의 기능을 이용해서 주소를 수정하는 것을 금지한 것.

*pint = 100;	// 오류
a = 100;	// 오류 x



ex)

함수가 실행될 때 값을 전달받아야 할 때, 

그 값이 거~~~~~~~~~대 하거나, 2개 이상 존재할 수 없는 경우(값이 너무 커서) 사용



거~~~~~~~~~대한 크기의 변수를 복사해서 사용하고 함수가 끝나면 다시 삭제하고 하면 너무 메모리 낭비.

그래서 주소를 전달해서 사용.


그런데 받은 함수에서 포인터를 이용해서 기존 값을 변경할 수 있음.

준 사람은 잠깐 값 좀 알려달라고 해서 알려줬는데 지 맘대로 바꿨네? 어이가 없네


그래서 아래처럼 값을 변경할 수 없는 주소를 받아서 사용.

void output(const int* pi)
{

int i = *pi;	// *pi값 받아오기 가능
*pi = 100;		// *pi값 변경하는 건 불가능

int* pint = (int*)pi;	// 강제로 변경 가능
*pint = 1000;

}

// const : 개발자의 의도를 나타낸다?, 강제로 변경은 가능



// 단축키 ctrl + shirt + space : 함수 선언 원형

*/


// 33강 void

/*

함수가 반환할게 없을 경우 void를 사용

void와 포인터


point앞의 자료형의 의미 = 크기

float* pfloat = nullptr;	// pfloat의 크기는 float


void* pvoid = nullptr;	// void* : 크기를 정하지 않는 포인터, 어떤 변수의 주소든지 다 받을 수 있다.


모든 타입의 변수를 받을 수 있지만 역참조, 주소 연산 불가능(정해진 형태가 없기 떄문에)

*pvoid;	// 오류


*/


// 34~39강, 문자, 문자열

/*



*/


// 40강 구조체 포인터

/*



*/


// 41, 42강 동적할당

/*



*/


// 43~45강 가변 배열

/*



*/


// 46강 리스트

/*



*/


// 47강 과제 풀이(정렬)

/*



*/


// 48강 함수 포인터

/*



*/


// 49~50강 리스트

/*



*/


// 51~54강 클래스, 클래스를 이용한 배열

/*



*/


// 55강 함수 템플릿

/*



*/


// 56~57강 클래스 템플릿, 큼래스 템플릿 리스트 구현

/*



*/


// 58강 namespace, 입출력 구현(cin, cout)

/*



*/


// 59강 STL (vector, list)

/*



*/


// 60~64강 iterator

/*



*/


// 65, 66강 erase

/*



*/


// 67, 68강 list iterator

/*



*/


// 69~79강 tree

/*



*/


// 75강 enum

/*



*/


// 80, 82강 상속

/*



*/


// 81강 오버라이딩

/*



*/


// 83, 84강 다형성

/*



*/


