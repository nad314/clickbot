#pragma once
class Bot {
public:
	std::thread handle;
	int delay;
	int state;

	Bot(): state(0), delay(50) {}
	inline bool running() const { return (bool)(state & 1); }
	inline bool done() const { return (bool)(state & 2); }
	operator int() { return delay; }

	void start();
	void stop();
	void kill();
	void click (bool dir); // 1 = down, 0 = up
	void toggle();

	
};
