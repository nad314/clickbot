#pragma once
class clickbot : public core::Module {
protected:
	MainForm form;
	core::Timer<float> timer;
public:
	int onLoad() override;
	int onDispose() override;
	int onStart() override;
	int onStop() override;
	int main() override;
};
