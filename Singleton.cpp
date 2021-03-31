#include <cstdio>

class Singleton
{
private:
	Singleton(){} // 申明为私有的，禁止直接利用构造函数进行构造

public:
	static Singleton* getSingleton()
	{
		if (instance_)
		{
			return instance_;
		}
		else
		{
			instance_ = new Singleton();
			return instance_;
		}
	}

	~Singleton()
	{
		printf("destruct !\n");
	}

	void printAdd()
	{
		printf("address is %d\n", instance_);
	}

	class memClear // 申明一个清理类，专门用于内存回收，不需要手动释放内存
	{
	public:
		~memClear()
		{
			if (instance_) 
			{
				delete instance_;
				instance_ = NULL;
			}
		}
	};

public:
	static Singleton* instance_;
	static memClear cleaner_;
};

Singleton* Singleton::instance_ = NULL;
Singleton::memClear Singleton::cleaner_;

int main ()
{
	Singleton* test1 = Singleton::getSingleton();
	Singleton* test2 = Singleton::getSingleton();
	test1->printAdd();
	test2->printAdd();
	
	return 0;
}
