#include "../Include/Timer.h"

using namespace std::chrono;

namespace TomasMo {

	Timer::Timer()
		: _start(Clock::now())
	{

	}

	void Timer::Reset()
	{
		_start = Clock::now();
	}

	long long Timer::ElapsedMs()
	{
		Clock::time_point finish = Clock::now();
		milliseconds elapsed = duration_cast<milliseconds>(finish - _start);
		return elapsed.count();
	}
}