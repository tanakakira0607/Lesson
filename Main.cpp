#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SetWindowText("落下ボールの着地"); // ウィンドウのタイトル
    SetGraphMode(720, 640, 32); // ウィンドウの大きさとカラービット数の指定
    ChangeWindowMode(TRUE); // ウィンドウモードで起動

    if (DxLib_Init() == -1)
    {
        return -1; // ライブラリ初期化 エラーが起きたら終了
    }

    SetBackgroundColor(0, 0, 0); // 背景色の指定
    SetDrawScreen(DX_SCREEN_BACK); // 描画面を裏画面にする

    CGame game{};
    game.Init();

    while (1) // メインループ
    {
        ClearDrawScreen(); // 画面をクリアする

        game.Update(); // ゲームの状態を更新する。
        game.Draw();   // 更新した状態を描画する。

        ScreenFlip(); // 裏画面の内容を表画面に反映させる
        WaitTimer(16); // 一定時間待つ

        if (ProcessMessage() == -1)
        {
            break; // Windowsから情報を受け取りエラーが起きたら終了
        }

        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
        {
            break; // ESCキーが押されたら終了
        }
    }

    DxLib_End(); // ＤＸライブラリ使用の終了処理
    return 0; // ソフトの終了
}
