#pragma once
#include <SFML/Audio.hpp>
#include "SoundID.h"

using namespace sf;
class SoundManager
{
private:
	SoundBuffer chopBuffer;
	SoundBuffer deathBuffer;
	SoundBuffer ootBuffer;
	Sound chop;
	Sound death;
	Sound oot;

public:
	void InitializeSound();
	void PlaySound(SoundID _id);
};

	