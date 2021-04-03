#include <cstdio>
#include <stack>
#include <exception>

using namespace std;

struct MyExp : public exception
{
	const char* what()
	{
		return "queue is empty";
	}
};

template <typename T>
class CQueue
{
public:
	CQueue(){}
	~CQueue(){}
	
	void appendTail(const T& node)
	{
		stack1.push(node);
	}

	T deleteHead()
	{
		if (stack2.size() != 0)
		{
			char temp = stack2.top();
			stack2.pop();
			return temp;
		}

		while (stack1.size() != 0)
		{
			char temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
		
		if (stack2.size() != 0)
		{
			char temp = stack2.top();
			stack2.pop();
			return temp;
		}

		throw MyExp();
	}

private:
	stack<T> stack1;
	stack<T> stack2;
};

int main()
{
	CQueue<char> queue;

	try
	{
		queue.appendTail('a');
		printf("insert a\n");

		queue.appendTail('b');
		printf("insert b\n");

		char temp = queue.deleteHead();
		printf("pop %c\n", temp);

		queue.appendTail('c');
		printf("insert c\n");

        temp = queue.deleteHead();
        printf("pop %c\n", temp);

        temp = queue.deleteHead();
        printf("pop %c\n", temp);
		
        temp = queue.deleteHead();
        printf("pop %c\n", temp);
	}	
	catch(MyExp& e)
	{
		printf("%s\n", e.what());
	}

	return 0;
}
