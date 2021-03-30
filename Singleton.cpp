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

	class garbageCollect
	{
		public:
		~garbageCollect()
		{
			delete Singleton::instance_;
			printf("garbage collection !\n");
		}
	};

private:
	static Singleton* instance_;
	static garbageCollect garbage_collector;
};

Singleton* Singleton::instance_ = NULL;
Singleton::garbageCollect Singleton::garbage_collector;

int main ()
{
	Singleton* test1 = Singleton::getSingleton();
	Singleton* test2 = Singleton::getSingleton();
	test1->printAdd();
	test2->printAdd();

	return 0;
}
