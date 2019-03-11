#include "IO_Thread.h"



IO_Thread::IO_Thread(int max_con_num, int time_out):Thread_Base(),\
												m_max_con_num(max_con_num),\
												m_time_out(time_out)
{
	p_thread = new std::thread(&IO_Thread::run, this);
	m_thread_id = p_thread->get_id();
	p_thread->detach();
}


IO_Thread::~IO_Thread()
{
	this->stop();
	if (p_thread != nullptr)
	{
		delete p_thread;
		p_thread = nullptr;
	}
}


bool IO_Thread::do_Work()
{

}


void IO_Thread::run()
{
	while (m_running_flag)
	{
		try {
			do_Work();
		}
		catch (std::exception e)
		{
			exception_Handle(e);
			stop();
			if (p_thread != nullptr)
			{
				delete p_thread;
				p_thread = nullptr;
			}
		}
	}
}


bool add_Con(int sock_fd)
{

}


bool remove_Con(int sock_fd)
{

}


void handle_Read(int sock_fd)
{

}


void handle_Write(int sock_fd)
{

}


std::thread::id IO_Thread::get_Thread_Id()
{
	return m_thread_id;
}