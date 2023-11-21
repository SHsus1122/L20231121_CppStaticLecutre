#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
class StaticTest
{
private:
	// 생기고 사라질 때 마다 카운트
	StaticTest()
	{
		Count++;
		PrintCount();
	};
public:
	~StaticTest()
	{
		Count--;
		PrintCount();
	};
	// 싱글톤 호출하는 방법
	static StaticTest* GetInstance()
	{
		// 비었으면 새롭게 생성(싱글톤 존재하지 않을 경우)
		if (Instance == nullptr)
		{
			Instance = new StaticTest();
		}
		// 있다면 그대로 인스턴스 그대로 반환
		return Instance;
	}
private:
	static void PrintCount()
	{
		cout << Count << endl;
	}

	static int Count;	// 이렇게 하면 StaticTest 와 다른 메모리 공간에 존재합니다. 관계만 가질 뿐
	// 시작 하자 마자 따로 다른 메모리 공간에 만들지만, StaticTest 라는 관계로 인해 접근은 가능

	// 싱글톤 인스턴스 생성
	static StaticTest* Instance;
};

// 정적 멤버 변수는 클래스의 모든 객체가 공유하는 변수로, 반드시 한 번만 초기화 해야 합니다.
int StaticTest::Count = 0;
StaticTest* StaticTest::Instance = nullptr;

class ConstructSample
{
public:
	ConstructSample(int NewNumber, char* NewName)
	{
		Number = NewNumber;
		Name = NewName;
	}
	// 주소 복사가 아니라 값을 복사하는 코드(복사 생성자 코드)
	// 이는 안만들어도 자동으로 생기긴 합니다.
	ConstructSample(const ConstructSample& Origin)
	{
		cout << "Copy" << endl;
		Number = Origin.Number;
		Name = new char[100];
		strcpy(Name, Origin.Name);
	}
	virtual ~ConstructSample()
	{

	}

	int Number;
	char* Name;
};

// 참조(Reference)
void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

// default argument 로 0을 지정해주는 방식입니다.
// 하지만 이 순서가 마지막 매개변수부터 차례대로 넣어줘야 합니다. 즉,
// void Add(int A = 0, int B, int)  <- 이런식으로 첫 값만 넣는 것은 불가능합니다.(컴파일 에러)
void Add(int A, int B, int c = 0) 
{

}*/

int Add(int A, int B)
{
	return A + B;
}

int Sub(int A, int B)
{
	return A - B;
}

// 비동기 방식 .. ??
// delegate			C# 의 문법이며 언리얼 엔진에서 만들어 놓았습니다.
// 함수를 등록해서 특정 지점에서 호출되서 작동하게 하는 방법이 됩니다.
// 이를 이용하면 클래스의 의존성이 없어집니다. 형태는 몰라도 함수만 알면 호출이 가능해지며
// 덕분에 의존성을 부시는데 유용합니다. 클래스간 호출에서 굉장히 유용해집니다.
// 반환형, 함수(포인터)명, 인자
int (*FunctionPointer)(int A, int B);

void Compute(int A, int B, int (*FunctionPointer)(int A, int B))
{
	FunctionPointer(A, B);
}

// 내부 로직에서 인자가 void 형이라서 이처럼 합니다.
// 이는 형태를 가지고 있지 않기 때문이며, 이러한 형태로 받아서 본인이 직접 처리하기 때문입니다.
int Asending(const void* PA, const void* PB)	// 오름차순
{
	int A = *(int*)PA;
	int B = *(int*)PB;

	if (A > B)
	{
		return 1;
	}
	else if (A < B)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int Desending(const void* PA, const void* PB)	// 내림차순
{
	int A = *(int*)PA;
	int B = *(int*)PB;

	if (A < B)
	{
		return 1;
	}
	else if (A > B)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int Number[10] = { 1, 10 ,2 ,5, 4, 5, 87, 64, 54, 8 };
	qsort(Number, 10, 4, Desending);
	// qsort 에 대한 각 요소들에 대한 설명
	// Number(base)			- 정렬할 배열의 시작 주소
	// 10(nitems)			- 배열의 요소 수입니다.
	// 4(size)				- 각 요소의 크기(바이트)입니다. ex) sizeof(Number[0]
	// Desending(compar)	- 비교 함수의 포인터

	for (auto D : Number)
	{
		cout << D << endl;
	}

	FunctionPointer = [](int A, int B)
	{ 
		return 1;
	};
	//FunctionPointer = Sub;
	FunctionPointer(10, 20);

	Compute(10, 20, Add);
	Compute(10, 20, Sub);

	return 0;
}

	//int A = 10;
	//int B = 20;
	//
	//Swap(A, B);
	//
	//cout << A << endl;
	//cout << B << endl;
	//
	//char Message[] = "HelloWorld";
	//ConstructSample C1(300, Message);
	//ConstructSample C2 = C1;
	//cout << C1.Name << endl;
	//Message[5] = 'A';
	//cout << C2.Name << endl;
	//
	//cout << C1.Number << endl;
	//C1.Number = 100;
	//
	//cout << C2.Number << endl;
	//// 생성자가 여러개인 것이 원인으로 포인터 개념을 사용하는 복사 생성자라는 개념이 새롭게 생김
	//// 즉, 복사할 때 값을 복사하는 것이 아니라 주소를 복사했기 때문입니다.
	//
	//string A = "World";
	//string B = A;
	//
	//cout << A << endl;
	//A[0] = 'C';
	//cout << B << endl;

