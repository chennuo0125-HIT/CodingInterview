#include <cstdio>

int countRange(const int* numbers, size_t length, size_t st, size_t et)
{
	if (numbers == NULL) return 0;

	size_t count = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (numbers[i] >= st && numbers[i] <= et) count++;
	}

	return count;
}

int getDuplication(const int* numbers, size_t length)
{
	if (numbers == NULL || 0 == length) return -1;

	size_t sidx = 1;
	size_t eidx = length - 1;
	while (sidx != eidx)
	{
		size_t mid = (sidx + eidx) >> 1;

		int count_left = countRange(numbers, length, sidx, mid);
		if (count_left > mid - sidx + 1)
		{
			eidx = mid;
			continue;
		}

		int count_right = countRange(numbers, length, mid + 1, eidx);
		if (count_right > eidx - mid)
		{
			sidx = mid + 1;
			continue;
		}

		return -1;
	}

	return sidx;
}

int main ()
{
	size_t length = 8;
	int numbers[length] = {2, 3, 5, 4, 3, 2, 6, 7};
	
	int result = getDuplication(numbers, length);

	if (result < 0)
	{
		printf("cant find duplication number !!!");
		return 0;
	}	

	printf ("find duplication number %d\n", result);

	return 0;
}
