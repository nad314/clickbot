#include <main/main.h>

int clickbot::onLoad() {
	return 0;
}

int clickbot::onDispose() {
	return 0;
}

int clickbot::onStart() {
	return 0;
}

int clickbot::onStop() {
	return 0;
}
int clickbot::main() {
	bool done = 0;
	bool action = 0;
	if (!form.open())
		return 1;
	while (!done) {
		if (form.peekMessage(done))
			continue;
		if (GetAsyncKeyState(VK_PAUSE)) {
			if (!action) {
				form.invalidate();
				action = 1;
				form.bot.toggle();
			}
		}
		else action = 0;
		Sleep(15);
	}
	form.close();
	return 0;
}
