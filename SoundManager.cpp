#include "SoundManager.h"

void SoundManager::InitializeSound()
{
	chopBuffer.loadFromFile("sound/chop.wav");
	deathBuffer.loadFromFile("sound/death.wav");
	ootBuffer.loadFromFile("sound/out_of_time.wav");

	chop.setBuffer(chopBuffer);
	death.setBuffer(deathBuffer);
	oot.setBuffer(ootBuffer);
}



void SoundManager::PlaySound(SoundID _id)
{
	switch (_id)
	{
	case SoundID::chop:
		chop.play();
		break;
	case SoundID::death:
		death.play();
		break;
	case SoundID::oot:
		oot.play();
		break;
	default:
		break;
	}
}
