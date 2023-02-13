#pragma once
#include "struct.h"

const int bulletNum = 4;

class Bullet
{
public:
	//クラス関数宣言
	Bullet();

	void Update();
	void EnemyUpdate();
	void Drow();
	Object BulletIni() { return bulletIni_; }
	int TimerIni() { return timerIni_; }
	Object EnemyBullteIni() { return enemyBulletIni_; }

public:
	//クラス変数宣言
	Object bullet_[bulletNum];
	int timer_;

private:
	//初期化用定数
	const Object bulletIni_ = { -200.0f,-200.0f,16.0f,16.0f,5.0f,false };
	const int timerIni_ = 10;
	const Object enemyBulletIni_ = { -200.0f,-200.0f,6.0f,6.0f,10.0f,false };
};
#pragma once
