#pragma once
#include "player.h"
#include "enemy.h"

class Play
{
public:
	Play();
	void Update(const char key[]);
	void Drow();
	int GetClearScore() { return kMaxScore_; };

public:
	Player* player_;
	Enemy* enemy_;

private:
	const int kMaxScore_ = 30;
};
