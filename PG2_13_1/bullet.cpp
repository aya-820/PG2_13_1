#include <Novice.h>
#include "bullet.h"
#include "player.h"

Bullet::Bullet()
{
	for (int i = 0; i < bulletNum; i++)
	{
		bullet_[i] = bulletIni_;
	}
	timer_ = 0;
}

void Bullet::Update()
{
	for (int i = 0; i < bulletNum; i++)
	{
		//Bulletを移動
		if (bullet_[i].isAlive == true)
		{
			bullet_[i].pos.y -= bullet_[i].speed.y;
		}

		//画面外に出たら初期化
		if (bullet_[i].pos.y <= bulletIni_.radius)
		{
			bullet_[i] = bulletIni_;
		}
	}
}

//エネミー用battleの更新処理
void Bullet::EnemyUpdate()
{
	for (int i = 0; i < bulletNum; i++)
	{
		//Bulletを移動
		if (bullet_[i].isAlive == true)
		{
			bullet_[i].pos.y += bullet_[i].speed.y;
		}

		//画面外に出たら初期化
		if (bullet_[i].pos.y - bulletIni_.radius >= 600.0f)
		{
			bullet_[i] = enemyBulletIni_;
		}
	}
}

void Bullet::Drow()
{
	for (int i = 0; i < bulletNum; i++)
	{
		if (bullet_[i].isAlive == true)
		{
			Novice::DrawEllipse(bullet_[i].pos.x, bullet_[i].pos.y, bullet_[i].radius, bullet_[i].radius, 0.0f, RED, kFillModeSolid);
		}
	}
}
