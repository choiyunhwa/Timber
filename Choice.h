#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#define MAX_NUMBER_OF_ITEMS 3

class Choice
{
public :
	Choice(float width, float height);
	~Choice();

	void draw(sf::RenderWindow& window);
	void MoveLeft();
	void MoveRight();
	int GetPressedItem()
	{
		return selectedItemIndex;
	}

private:
	int selectedItemIndex;
	RectangleShape choice[MAX_NUMBER_OF_ITEMS];	
};

