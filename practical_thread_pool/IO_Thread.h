#pragma once

#ifndef IO_THREAD_H
#define IO_THREAD_H

#include "Thread_Base.h"
#include <thread>
#include <mutex>
#include <unordered_map>


class tcp_con
{
public:
	explicit tcp_con();
	virtual ~tcp_con();

	std::vector<char> send_buff;
	std::vector<char> write_buff;
};

class IO_Thread :public Thread_Base
{
public:
	explicit IO_Thread(int max_con_num = 200, int time_out = 200);
	virtual ~IO_Thread();

	bool do_Work();
	std::thread::id get_Thread_Id();
	bool add_Con(int);
	bool remove_Con(int);

	void handle_Read(int);
	void handle_Write(int);

private:
	void run();

	std::unordered_map<int, tcp_con> m_con_map;
	std::mutex m_con_map_mutex;

	std::thread* p_thread;

	int m_max_con_num;
	int m_time_out;

	std::atomic<int> m_thread_status;
	std::thread::id m_thread_id;
};


#endif // ! 



