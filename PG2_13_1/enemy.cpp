#include "enemy.h"
#include <Novice.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include<math.h>

Enemy::Enemy()
{
	for (int i = 0; i < enemyNum; i++)
	{
		enemy_[i] = enemyIni_;
		enemy_[i].pos.x = rand() % 800 + 1.0f;
		enemy_[i].pos.y = 25.0f * (i + 1);
		enemy_[i].speed.x = rand() % 20 + 10.0f;
		attackTime_[i] = attackTimeIni_;

		for (int j = 0; j < bulletNum; j++)
		{
			bullet_[i] = new Bullet;
			bullet_[i]->bullet_[j] = bullet_[i]->EnemyBullteIni();
			bullet_[i]->timer_ = 0;
		}
	}
	time_ = timeIni_;
	enemyIsAlive_ = true;
}

void Enemy::Update()
{
	for (int i = 0; i < enemyNum; i++)
	{
		if (enemyIsAlive_ == true)
		{
			enemy_[i].pos.x += enemy_[i].speed.x;

			if (enemy_[i].pos.x <= enemy_[i].radius || enemy_[i].pos.x + enemy_[i].radius >= 800.0f)
			{
				enemy_[i].speed.x *= -1.0f;
			}

			if (attackTime_[i] >= 0)
			{
				//攻撃のクールタイム
				attackTime_[i]--;
			}
			else  if (attackTime_[i] <= 0)
			{
				for (int j = 0; j < bulletNum; j++)
				{
					if (bullet_[i]->bullet_[j].isAlive == false)
					{
						bullet_[i]->bullet_[j] = bullet_[i]->EnemyBullteIni();
						bullet_[i]->bullet_[j].pos = enemy_[i].pos;
						bullet_[i]->bullet_[j].isAlive = true;
						attackTime_[i] = attackTimeIni_;
						break;
					}
				}

			}
		}

		//Bulletのエネミー用更新処理
		bullet_[i]->EnemyUpdate();

	}

}

void Enemy::Drow()
{
	for (int i = 0; i < enemyNum; i++)
	{
		if (enemyIsAlive_ == true)
		{
			bullet_[i]->Drow();
			Novice::DrawEllipse(enemy_[i].pos.x, enemy_[i].pos.y, enemy_[i].radius, enemy_[i].radius, 0.0f, BLUE, kFillModeSolid);
		}
	}
}
