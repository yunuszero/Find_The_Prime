#include<iostream>
using namespace std;

bool IsPrime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i <= n / 2; i++)	//ในการหา Prime numbers ไม่มีความจำเป็นต้องหาตัวประกอบที่มากกว่า n/2
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int FindPrime(int n)
{
	int mem[10010];	//ค่าใน Project Euler ต้องการหาอยู่ที่ค่า 10001
	mem[0] = 2;	//ประกาศให้ตัวแรกของ Prime numbers คือ 2
	for (int i = 1; i < n; i++)
	{
		int j = mem[i - 1] + 1;
		while (!IsPrime(j))	//เรียหใช้งาน function ที่ใช้ check Prime numbers
		{
			j++;
		}
		mem[i] = j;
	}
	return mem[n - 1];
}

int main()
{
	int n;
	cin >> n;
	cout << FindPrime(n);

	return 0;
}