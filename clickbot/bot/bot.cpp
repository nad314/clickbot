#include <main/main.h>

void Bot::stop() { state |= 2; if (handle.joinable())handle.join(); state &= ~2; }
void Bot::kill() {
	if (state == 0)
		return;
	state = 0;
	handle.~thread(); // or std::terminate()
}

void Bot::start() {
	handle = std::thread([](Bot* bot)->void {
		if (!bot) return;
		bot->state |= 1;
		while (!bot->done()) {
			bot->click(1); //down
			Sleep(25);
			bot->click(0); //up
			Sleep(bot->delay-25);
		}
		bot->state &= ~1;
	}, this);
}

void Bot::click(bool dir) {
	INPUT    Input = { 0 };
	if (dir) {
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput(1, &Input, sizeof(INPUT));
	}
	else {
		ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &Input, sizeof(INPUT));
	}
}

void Bot::toggle() {
	if (running())
		stop();
	else
		start();
}

