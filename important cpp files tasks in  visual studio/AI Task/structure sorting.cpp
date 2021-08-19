#include <algorithm>
struct a
{
	int num1;
	int num2;
};

bool acompare(a lhs, a rhs) { return lhs.num1 < rhs.num1; }

int main()
{
	a array[5];
	array[0].num1 = 12;
	array[0].num2 = 2;
	array[1].num1 = 24;
	array[1].num2 = 0;
	array[2].num1 = 1;
	array[2].num2 = 5;

	std::sort(array, array + 4, acompare);
	return 0;

}