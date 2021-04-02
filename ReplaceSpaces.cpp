#include <cstdio>

void ReplaceBlank(char* str, int length)
{
	if (NULL == str || length <= 0) return;
	
	// 确定空格数量，字符串长度
	int blank_size = 0;
	int str_length = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == '\0') break;
		
		if (str[i] == ' ') blank_size++;

		str_length++;
	}

	// 确定填充空格后的字符串长度
	int new_length = str_length + 2 * blank_size;

	// 从后往前填充空格
	int str_idx = str_length; // 指向原字符串的末尾
	int new_idx = new_length; // 指向新字符串的末尾
	while (str_idx >= 0 && str_idx < new_idx)
	{
		if (str[str_idx] == ' ')
		{
			str[new_idx--] = '0';
			str[new_idx--] = '2';
			str[new_idx--] = '%';
		}
		else
		{
			str[new_idx--] = str[str_idx];
		}

		str_idx--;
	}
}

int main ()
{
	int length = 1000;
	char str[length] = "we are the world !";
	ReplaceBlank(&str[0], length);

	printf("result : %s\n", str);

	return 0;
}
