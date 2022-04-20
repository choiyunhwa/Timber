#include "UiManager.h"

void UiManager::InitializeUI()
{
	setFont.loadFromFile("fonts/KOMIKAP_.ttf");
	textMessage.setFont(setFont);
	textScore.setFont(setFont);

    textMessage.setString("Press Enter to start!"); // 글씨 입력
    textScore.setString("Score = 0");
    score = 0;

    textMessage.setCharacterSize(75); //폰트사이즈
    textScore.setCharacterSize(100);

    textMessage.setFillColor(Color::White); //글씨 색상 지정
    textScore.setFillColor(Color::White);

    textScore.setPosition(20, 20);

    FloatRect textRect = textMessage.getLocalBounds(); //구조체 - 중앙점 계산
    textMessage.setOrigin(
        textRect.left + textRect.width * 0.5f,
        textRect.top + textRect.height * 0.5f
    );

    textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f); // 초기화가 됨

	float timerBarWidth = 400;
	float timerBarHeight = 80;

	Vector2f timerBarSize = Vector2f(timerBarWidth, timerBarHeight);
	timerBar.setSize(timerBarSize);
	Vector2f timerPos = Vector2f(1920 * 0.5f - timerBarWidth * 0.5f, 980.f);
	timerBar.setPosition(timerPos);
	timerBar.setFillColor(Color::Red);
}

Text UiManager::GetTextMessage()
{
    return textMessage;
}

Text UiManager::GetTextScore()
{
    return textScore;
}

RectangleShape UiManager::GetTimerBar()
{
    return timerBar;
}

int UiManager::GetScore()
{
    return score;
}

void UiManager::SetScore(int _score)
{
    score = _score;
}

const float UiManager::GetTimeMax()
{
    return timeMax;
}

void UiManager::ResetTimeRemaining()
{
    timeRemaining = timeMax;
}

float UiManager::GetTimeRemaining()
{
    return timeRemaining;
}

void UiManager::SetTimeRemaining(float _goesTime)
{
    timeRemaining = _goesTime;
}
