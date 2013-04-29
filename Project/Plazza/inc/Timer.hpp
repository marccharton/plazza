#ifndef	__TIMER_HPP__
#define	__TIMER_HPP__

class Timer
{
private:
	int		_ellapsed;
	int		_time;

public:
	Timer();
	Timer(int time);
	Timer(Timer const &);
	Timer&	operator=(Timer const &);
	~Timer();

public:
	int		getTime() const;
	void	setTime(int);

public:
	void	start();
	void	stop();
};

#endif