#include <cstdio>

bool Find( int **matrix, int rows, int cols, int number)
{
	if (matrix == NULL) return false;
	
	int rux = cols - 1; // 右上角x索引
	int ruy = 0; // 右上角y索引
	while (rux >= 0 && ruy < rows)
	{
		if (number == matrix[rux][ruy]) return true;

		// 如果数组元素大于检索值，则该列数值都大于检索值，可以跳过这一列
		if (number < matrix[rux][ruy])
		{
			--rux;
			continue;
		}
		// 如果数组元素小于检索值，则该行数值都小于检索值，可以跳过这一行
		if (number > matrix[rux][ruy])
		{
			++ruy;
			continue;
		}
	}
	
	return false;
}

int main ()
{
	const int rows = 4;
	const int cols = 4;
	const int number = 7;

	int matrix_arr[rows][cols] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

	int **matrix = new int*[rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = matrix_arr[i];
	
	if (Find(matrix, rows, cols, number)) printf("search success\n");
	else printf("search fail !!!\n");

	delete[] matrix;

	return 0;
}
