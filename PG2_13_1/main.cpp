#include <Novice.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "enemy.h"
#include "play.h"

const char kWindowTitle[] = "GC1C_ﾄﾐﾀ_ｱﾔﾅ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Vector2 window = { 800.0f,600.0f };
	Novice::Initialize(kWindowTitle, window.x, window.y);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//プレイ用のクラスを宣言
	Play* play;
	play = new Play;

	unsigned int current_time = time(nullptr);
	srand(current_time);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓処理ここから
		///

		///
		///更新処理
		/// 

		play->Update(keys);

		///
		///描画処理
		/// 

		Novice::DrawBox(0, 0, window.x, window.y, 0.0f, 0xC0C0C0ff, kFillModeSolid);

		play->Drow();

		Novice::ScreenPrintf(10, 10, "enemyIsAlive = %d", Enemy::enemyIsAlive_);
		Novice::ScreenPrintf(10, 70, "move : arrow key");
		Novice::ScreenPrintf(10, 90, "shot : X key");
		Novice::ScreenPrintf(10, 110, "reset ; R key");


		///
		///更新処理
		///

		//リセット処理
		if (keys[DIK_R] && preKeys[DIK_R])
		{
		}

		///
		///描画処理
		/// 

		///
		/// ↑処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
