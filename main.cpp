#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
class StaticTest
{
private:
	// ����� ����� �� ���� ī��Ʈ
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
	// �̱��� ȣ���ϴ� ���
	static StaticTest* GetInstance()
	{
		// ������� ���Ӱ� ����(�̱��� �������� ���� ���)
		if (Instance == nullptr)
		{
			Instance = new StaticTest();
		}
		// �ִٸ� �״�� �ν��Ͻ� �״�� ��ȯ
		return Instance;
	}
private:
	static void PrintCount()
	{
		cout << Count << endl;
	}

	static int Count;	// �̷��� �ϸ� StaticTest �� �ٸ� �޸� ������ �����մϴ�. ���踸 ���� ��
	// ���� ���� ���� ���� �ٸ� �޸� ������ ��������, StaticTest ��� ����� ���� ������ ����

	// �̱��� �ν��Ͻ� ����
	static StaticTest* Instance;
};

// ���� ��� ������ Ŭ������ ��� ��ü�� �����ϴ� ������, �ݵ�� �� ���� �ʱ�ȭ �ؾ� �մϴ�.
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
	// �ּ� ���簡 �ƴ϶� ���� �����ϴ� �ڵ�(���� ������ �ڵ�)
	// �̴� �ȸ��� �ڵ����� ����� �մϴ�.
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

// ����(Reference)
void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

// default argument �� 0�� �������ִ� ����Դϴ�.
// ������ �� ������ ������ �Ű��������� ���ʴ�� �־���� �մϴ�. ��,
// void Add(int A = 0, int B, int)  <- �̷������� ù ���� �ִ� ���� �Ұ����մϴ�.(������ ����)
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

// �񵿱� ��� .. ??
// delegate			C# �� �����̸� �𸮾� �������� ����� ���ҽ��ϴ�.
// �Լ��� ����ؼ� Ư�� �������� ȣ��Ǽ� �۵��ϰ� �ϴ� ����� �˴ϴ�.
// �̸� �̿��ϸ� Ŭ������ �������� �������ϴ�. ���´� ���� �Լ��� �˸� ȣ���� ����������
// ���п� �������� �νôµ� �����մϴ�. Ŭ������ ȣ�⿡�� ������ ���������ϴ�.
// ��ȯ��, �Լ�(������)��, ����
int (*FunctionPointer)(int A, int B);

void Compute(int A, int B, int (*FunctionPointer)(int A, int B))
{
	FunctionPointer(A, B);
}

// ���� �������� ���ڰ� void ���̶� ��ó�� �մϴ�.
// �̴� ���¸� ������ ���� �ʱ� �����̸�, �̷��� ���·� �޾Ƽ� ������ ���� ó���ϱ� �����Դϴ�.
int Asending(const void* PA, const void* PB)	// ��������
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

int Desending(const void* PA, const void* PB)	// ��������
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
	// qsort �� ���� �� ��ҵ鿡 ���� ����
	// Number(base)			- ������ �迭�� ���� �ּ�
	// 10(nitems)			- �迭�� ��� ���Դϴ�.
	// 4(size)				- �� ����� ũ��(����Ʈ)�Դϴ�. ex) sizeof(Number[0]
	// Desending(compar)	- �� �Լ��� ������

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
	//// �����ڰ� �������� ���� �������� ������ ������ ����ϴ� ���� �����ڶ�� ������ ���Ӱ� ����
	//// ��, ������ �� ���� �����ϴ� ���� �ƴ϶� �ּҸ� �����߱� �����Դϴ�.
	//
	//string A = "World";
	//string B = A;
	//
	//cout << A << endl;
	//A[0] = 'C';
	//cout << B << endl;

