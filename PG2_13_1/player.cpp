#include <Novice.h>
#include "player.h"

Player::Player()
{
	player_ = playerIni_;
	bullet_ = new Bullet;
}

void Player::Update(const char key[])
{
	//Bullet�̃N�[���^�C��
	if (bullet_->timer_ > 0)
	{
		bullet_->timer_--;
	}

	//�΂߈ړ��p�̕ϐ�
	Vector2 speed = player_.speed;

	//�΂߈ړ����̑��x�ύX
	if (key[DIK_UP] && key[DIK_LEFT] || key[DIK_UP] && key[DIK_RIGHT] ||
		key[DIK_DOWN] && key[DIK_LEFT] || key[DIK_DOWN] && key[DIK_RIGHT])
	{
		speed.x *= 0.7f;
		speed.y *= 0.7f;
	}

	//���L�[�ňړ�
	if (key[DIK_UP])
	{
		player_.pos.y -= speed.y;
	}
	else if (key[DIK_DOWN])
	{
		player_.pos.y += speed.y;
	}

	if (key[DIK_LEFT])
	{
		player_.pos.x -= speed.x;
	}
	else if (key[DIK_RIGHT])
	{
		player_.pos.x += speed.x;
	}

	//�v���C���[����ʓ��ɔ[�߂�
	PlayerInScreen();

	//Bullet����
	if (key[DIK_X] && bullet_->timer_ <= 0)
	{
		for (int i = 0; i < bulletNum; i++)
		{
			if (bullet_->bullet_[i].isAlive == false)
			{
				bullet_->bullet_[i].isAlive = true;
				bullet_->bullet_[i].pos = player_.pos;
				bullet_->timer_ = bullet_->TimerIni();
				break;
			}
		}
	}

	//Bullet�̍X�V����
	bullet_->Update();
}

void Player::PlayerInScreen()
{
	if (player_.pos.x <= player_.radius)
	{
		player_.pos.x = player_.radius;
	}
	else if (player_.pos.x + player_.radius >= 1280.0f)
	{
		player_.pos.x = 1280.0f - player_.radius;
	}

	if (player_.pos.y <= player_.radius)
	{
		player_.pos.y = player_.radius;
	}
	else if (player_.pos.y + player_.radius >= 720.0f)
	{
		player_.pos.y = 720.0f - player_.radius;
	}
}

void Player::Drow()
{
	bullet_->Drow();
	Novice::DrawEllipse(player_.pos.x, player_.pos.y, player_.radius, player_.radius, 0.0f, WHITE, kFillModeSolid);
}
