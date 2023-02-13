#include <Novice.h>
#include "play.h"
#define _USE_MATH_DEFINES
#include<math.h>

int Enemy::enemyIsAlive_;

//当たり判定用関数
int IsHit(const Object player, const Object enemy)
{
	float hitDist = player.radius + enemy.radius;
	Vector2 dist = { enemy.pos.x - player.pos.x,enemy.pos.y - player.pos.y };
	float toDist = sqrtf(powf(dist.x, 2.0f) + powf(dist.y, 2.0f));

	int isHit = false;
	if (toDist <= hitDist)
	{
		isHit = true;
	}
	else
	{
		isHit = false;
	}

	return isHit;
}

Play::Play()
{
	player_ = new Player;
	enemy_ = new Enemy;
}

void Play::Update(const char key[])
{
	if (Enemy::enemyIsAlive_ == false)
	{
		enemy_->time_--;
	}
	if (enemy_->time_ <= 0 && Enemy::enemyIsAlive_ == false)
	{
		Enemy::enemyIsAlive_ = true;
		enemy_->time_ = enemy_->timeIni();

		for (int i = 0; i < enemyNum; i++)
		{
			enemy_->enemy_[i] = enemy_->EnemyIni();
			enemy_->enemy_[i].pos.x = rand() % 800 + 1.0f;
			enemy_->enemy_[i].pos.y = 25.0f * (i + 1);
			enemy_->enemy_[i].speed.x = rand() % 20 + 10.0f;
			enemy_->attackTime_[i] = enemy_->attackTimeIni();
		}

	}

	//プレイヤーとエネミーの更新処理
	player_->Update(key);
	enemy_->Update();

	//プレイヤーのbattleとエネミーの接触判定
	for (int i = 0; i < bulletNum; i++)
	{
		for (int j = 0; j < enemyNum; j++)
		{
			if (Enemy::enemyIsAlive_ == true && player_->bullet_->bullet_->isAlive == true)
			{
				if (IsHit(player_->bullet_->bullet_[i], enemy_->enemy_[j]) == true)
				{
					player_->bullet_->bullet_[i] = player_->bullet_->BulletIni();
					Enemy::enemyIsAlive_ = false;
				}
			}
		}
	}

	for (int i = 0; i < enemyNum; i++)
	{
		//プレイヤーとエネミーのbattleの接触判定
		for (int j = 0; j < bulletNum; j++)
		{
			if (enemy_->bullet_[i]->bullet_[j].isAlive == true)
			{
				if (IsHit(player_->player_, enemy_->bullet_[i]->bullet_[j]) == true)
				{
					enemy_->bullet_[i]->bullet_[j] = enemy_->bullet_[i]->EnemyBullteIni();
				}
			}
		}

		//プレイヤーとエネミーの接触判定
		if (Enemy::enemyIsAlive_ == true)
		{
			if (IsHit(player_->player_, enemy_->enemy_[i]) == true)
			{
				enemy_->enemy_[i].isAlive = false;
			}
		}
	}
}

void Play::Drow()
{
	player_->Drow();
	enemy_->Drow();

}
