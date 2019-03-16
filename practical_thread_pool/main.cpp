#include "Worker_Thread_Manager.h"
#include <iostream>

class test:public Task
{
public :
	Result exec(Helper* m_helper)
	{
		
		for (int i = 0; i < 10000000; i++)
		{
			tmp += 1;
		}
		std::cout << tmp << " "<< std::this_thread::get_id()<< std::endl;
		Result r;
		return r;
	}
private:
	int tmp = 0;
};



void worker_Thread_Test()
{
	Worker_Thread_Manager* manager = new Worker_Thread_Manager(8, 2900);
	Helper _helper;
	time_point start = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
	for (int i = 0; i < 100; i++)
	{
		test t;
		t.exec(&_helper);
	}
	time_point end = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
	std::cout << std::endl << std::endl << end.time_since_epoch().count() - start.time_since_epoch().count() << " ms" << std::endl;


	start = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
	for (int i = 0; i < 100; i++)
	{
		auto t = std::make_shared<test>();
		auto future = std::move(manager->dispatch_Task(t));
		//future.wait();
	}
	end = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
	std::cout << std::endl << std::endl << end.time_since_epoch().count() - start.time_since_epoch().count() << " ms" << std::endl;
}


int main()
{
	worker_Thread_Test();
	int i;
	std::cin >> i;
	return 0;
}
