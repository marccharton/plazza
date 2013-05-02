#include	"Timer.hpp"

Timer::Timer()
{
	this->_time = 1000;
}

Timer::Timer(int time)
{
	this->_time = time;
}

Timer::Timer(Timer const &other)
{
	this->_time = other._time;
}

Timer&	Timer::operator=(Timer const &other)
{
	if (&other != this)
		this->_time = other._time;
	return (*this);
}

Timer::~Timer()
{
}

int		Timer::getTime() const
{
	return (this->_time);
}

void	Timer::setTime(int time)
{
	this->_time = time;
}

void	Timer::start()
{
}

void	Timer::stop()
{
}
