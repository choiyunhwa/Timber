#include "Choice.h"
using namespace sf;


Choice::Choice(float width, float height)
{
	choice[0].setFillColor(Color::Transparent);
	choice[0].setOutlineThickness(5);
	choice[0].setOutlineColor(Color::Green);
	choice[0].setSize(Vector2f(150, 192));
	choice[0].setPosition(Vector2f(600 ,500));

	choice[1].setFillColor(Color::Transparent);
	choice[1].setOutlineThickness(0);
	choice[1].setSize(Vector2f(150, 192));
	choice[1].setPosition(Vector2f(800, 500));

	choice[2].setFillColor(Color::Transparent);
	choice[2].setOutlineThickness(0);
	choice[2].setSize(Vector2f(150, 192));
	choice[2].setPosition(Vector2f(1000, 500));

	selectedItemIndex = 0;
}

Choice::~Choice()
{
}

void Choice::draw(RenderWindow &window)
{
	for (int i = 0; i <MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(choice[i]);
	}
}

void Choice::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		choice[selectedItemIndex].setFillColor(Color::Transparent);
		choice[selectedItemIndex].setOutlineThickness(0);
		selectedItemIndex--;
		choice[selectedItemIndex].setOutlineThickness(5);
		choice[selectedItemIndex].setOutlineColor(Color::Green);
		
	}
}

void Choice::MoveRight()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS )
	{
		choice[selectedItemIndex].setFillColor(Color::Transparent);
		choice[selectedItemIndex].setOutlineThickness(0);
		selectedItemIndex++;
		choice[selectedItemIndex].setOutlineThickness(5);
		choice[selectedItemIndex].setOutlineColor(Color::Green);
		
	}
}