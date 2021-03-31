#include <cstdio>

class Singleton
{
private:
	Singleton(){} // 申明为私有的，禁止直接利用构造函数进行构造

public:
	static Singleton* getSingleton()
	{
		static std::shared_ptr<Singleton> instance = std::make_shared<Singleton>();
		return instance;
		
	}

	~Singleton()
	{
		printf("destruct !\n");
	}

	void printAdd()
	{
		printf("address is %d\n", instance);
	}

};


int main ()
{
	auto test1 = Singleton::getSingleton();
	auto test2 = Singleton::getSingleton();
	test1->printAdd();
	test2->printAdd();
	
	return 0;
}
