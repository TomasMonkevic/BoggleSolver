#pragma once

#include <chrono>

namespace TomasMo {

	class Timer
	{
	private:
		typedef std::chrono::high_resolution_clock Clock;

		Clock::time_point _start;

	public:
		Timer();

		void Reset();
		long long ElapsedMs();
	};
}
