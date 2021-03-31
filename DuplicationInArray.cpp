#include <cstdio>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
	if (duplication == NULL) return false;
	
	if (numbers == NULL || length == 0) return false;

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1) return false;
	}

	for (int i = 0; i < length; i++)
	{
		while (i != numbers[i])
		{
			if (numbers[ numbers[i] ] < i)
			{
				*duplication = numbers[ numbers[i] ];
				return true;
			}

			int temp = numbers[ numbers[i] ];
			numbers[ numbers[i] ] = numbers[i];
			numbers[i] = temp;
		}
	}

	return false;
}

int main ()
{
	int length = 7;

	int numbers[length] = {2, 3, 1, 0, 2, 5, 3};
	
	int result;
	
	if (duplicate(numbers, length, &result))
	{
		printf("result is %d\n", result);
	}
	else
	{
		printf("cant find result !");
	}

	return 0;
}
