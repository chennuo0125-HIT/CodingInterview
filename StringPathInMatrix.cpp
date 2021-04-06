#include <cstdio>
#include <string.h>

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& depth, bool* visited)
{
   if ('\0' == matrix[depth]) return true;

    if (row > 0 && row < rows && col > 0 && col < cols && visited[col + row * cols])
    {
        depth++;
        visited[col + row * cols] = true;
        bool has_path = (hasPathCore(matrix, rows, cols, row-1, col, str, depth, visited)
                        || hasPathCore(matrix, rows, cols, row+1, col, str, depth, visited)
                        || hasPathCore(matrix, rows, cols, row, col-1, str, depth, visited)
                        || hasPathCore(matrix, rows, cols, row, col+1, str, depth, visited));
        if (!has_path)
        {
            visited[col + row * cols] = false;
            depth--;
            return false;
        }

        return true;
    }
}

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
    if (NULL == matrix || 0 == rows || 0 == cols || NULL == str) return false;

    // 初始化"已查看"数组，记录哪些数据已被查看过，不能再继续查看
    bool* visited = new bool[rows*cols];
    memset(visited, false, rows*cols);

    // 遍历数组中的每一个元素，直到找到路径为止
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int depth = 0; // 初始化探索深度为0
            if (hasPathCore(matrix, rows, cols, row, col, str, depth, visited))
            {
                if (visited) delete[] visited;
                return true;
            }
        }
    }

    if (visited) delete[] visited;

    return false;
}

int main()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";
    const int rows = 5;
    const int cols = 8;

    if (hasPath(matrix, rows, cols, str))
    {
        printf("find path success :)");
    }
    else
    {
        printf("cant find path !!!");
    }
	
	return 0;
}
