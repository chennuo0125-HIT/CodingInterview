#include <cstdio>
#include <stack>
#include <list>

int main()
{
	// 建立链表
	std::list<int> numbers;
	numbers.push_back(9);
	numbers.push_back(8);
	numbers.push_back(7);
	numbers.push_back(6);
	numbers.push_back(5);
	numbers.push_back(4);
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(1);
	numbers.push_back(0);

	// 用stack存储链表从头到尾的数据
	std::stack<int> num_stack;
	std::list<int>::iterator node = numbers.begin();
	while (node != numbers.end())
	{
		num_stack.push(*node);
		node++;
	}

	// 打印结果
	while (!num_stack.empty())
	{
		printf("%d", num_stack.top());
		num_stack.pop();
	}

	printf("\n");

	return 0;
}
