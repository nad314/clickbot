class MainForm final : public core::WindowForm {
protected:
	core::Button decInt, incInt;

public:
	Bot bot;

public:
	void onOpening() override;
	void onOpened() override;
	void onEndPaint(const core::eventInfo& e) override;
	void onStartPaint(const core::eventInfo& e) override;

};