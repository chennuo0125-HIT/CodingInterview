#include <cstdio>

class Singleton
{
private:
	Singleton(){} // 申明为私有的，禁止直接利用构造函数进行构造

public:
	static Singleton* getSingleton()
	{
		static Singleton* instance = new Singleton();;
		return instance_;
	}

	~Singleton()
	{
		printf("destruct !\n");
	}

	void printAdd()
	{
		printf("address is %d\n", instance_);
	}

};

int main ()
{
	Singleton* test1 = Singleton::getSingleton();
	Singleton* test2 = Singleton::getSingleton();
	test1->printAdd();
	test2->printAdd();

	if (Singleton::instance_) delete Singleton::instance_;
	
	return 0;
}
