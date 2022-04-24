#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class UiManager
{
private:
	Font setFont;
	Text textMessage;
	Text textScore;

	int score;

	const float timeMax = 6.0f;
	float timeRemaining = timeMax;
	float timerBarWidthPerSecond = 400 / timeMax;

	RectangleShape timerBar;
public:
	void InitializeUI();

	Text GetTextMessage();

	Text GetTextScore();

	RectangleShape GetTimerBar();

	int GetScore();
	void SetScore(int _score);
	void SetMassage(const char* _str);

	const float GetTimeMax();

	void ResetTimeRemaining();
	float GetTimeRemaining();
	void SetTimeRemaining(float _goesTime);

};

