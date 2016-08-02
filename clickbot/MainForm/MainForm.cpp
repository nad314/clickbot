#include <main/main.h>

void MainForm::onOpening() {
	WindowForm::onOpening();
	setSize(200, 120);
	setTitle("Clicker Spammer");
	allowResize(false);
}

void MainForm::onOpened() {
	WindowForm::onOpened();
	push(decInt.make(core::vec4i(20, 50, 40, 70), "<", *this, [](core::Form& f)->void {
		MainForm& mf = dynamic_cast<MainForm&>(f);
		if (!mf) return;
		mf.bot.delay = std::max(0, mf.bot.delay-25);
	}));
	push(incInt.make(core::vec4i(160, 50, 180, 70), ">", *this, [](core::Form& f)->void {
		MainForm& mf = dynamic_cast<MainForm&>(f);
		if (!mf) return;
		mf.bot.delay += 25;
	}));
	Reshape();
}

void MainForm::onStartPaint(const core::eventInfo& e) {
	WindowForm::onStartPaint(e);
}

void MainForm::onEndPaint(const core::eventInfo& e) {
	WindowForm::onEndPaint(e);
	core::Font& font = core::Font::get();
	char text[256];

	sprintf(text, "Delay: %dms", (int)bot);
	core::Core2D::fillRect(core::Rect(41, 50, 159, 70), backColor, *this);
	font.print(text, this->img, 100 - font.width(text) / 2, 55);

	core::Core2D::fillRect(core::Rect(10, 80, 190, 100), backColor, *this);
	core::Font::get().print("Hotkey: Pause/Break", this->img, 20, 85);

	core::Core2D::drawRect(getClientRect(), bot.running()? core::vec4b(140, 0, 180, 0): (active ? core::vec4b(0, 122, 204, 255) : core::vec4b(84, 84, 84, 255)), *this);
}
