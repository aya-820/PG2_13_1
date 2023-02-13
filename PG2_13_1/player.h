#pragma once
#include "bullet.h"
#include "struct.h"

class Player
{
public:
	//�N���X�֐��錾
	Player();

	void Update(const char key[]);
	void PlayerInScreen();
	void Drow();
	Object PlayerIni() { return playerIni_; }

public:
	//�N���X�ϐ��錾
	Object player_;
	Bullet* bullet_;

private:
	//�������p�萔
	Object playerIni_ = { 1280.0f / 2.0f,720.0f / 2.0f,8.0f,8.0,25.0f,true };
	const int kMaxLife_ = 3;
};
