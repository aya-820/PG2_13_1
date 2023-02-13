#pragma once
#include "struct.h"
#include "bullet.h"

const int enemyNum = 5;

class Enemy
{
public:
	//クラス関数宣言
	Enemy();
	void Update();
	void Drow();
	Object EnemyIni() { return enemyIni_; }
	int timeIni() { return timeIni_; }
	int attackTimeIni() { return attackTimeIni_; }

	static int enemyIsAlive_;

public:
	//クラス変数宣言
	Object enemy_[enemyNum];
	int time_;
	int attackTime_[enemyNum];


	Bullet* bullet_[enemyNum];

private:
	//初期化用定数
	const Object enemyIni_ = { 1280.0f/2.0f,-200.0f,12.0f,12.0f,20.0f,false };
	const int timeIni_ = 60;
	const int attackTimeIni_ = 60;
};