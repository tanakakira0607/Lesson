#include "Game.h"
#include "DxLib.h"

void CGame::Init()
{
    // 初期値の設定
    // ボールのx位置を画面中央の位置で初期化する
    // ボールのy位置を画面上部から40ピクセル下で初期化する
    // 地面判定フラグをfalseで初期化する



}

void CGame::Update()
{
    // ① 落下処理
    // m_Landedがfalseの間、m_BallYをFALL_SPEEDだけ増やす。
    // 【ここに落下処理を書く】

       

        if (m_Y == GROUND_Y-20) {

            m_Y = GROUND_Y-20;
            m_Landed = TRUE;
        }
        else
        {
            m_Y += m_V;
        }
  


    // ② 着地判定
    // 丸の下端がGROUND_Y以上になったら着地。
    // m_BallYを地面にぴったり接する座標へ直し、m_Landedをtrueにする。
    // 【ここに着地判定を書く】



}

void CGame::Draw() const
{
    // 地面の描画
    DrawBox(0, GROUND_Y, 720, 640, GetColor(100, 100, 100), TRUE);

    // ③ 丸の描画
    // 【ここに描画処理を書く】

    DrawCircle(m_X, m_Y, 20, GetColor(173, 216, 230), TRUE);

    // 条件による文字表示：記入済み
    SetFontSize(30);
    DrawString(10, 10, "丸を落下させて、地面で止めよう", 0xffffff);
    if (m_Landed)
    {
        DrawString(300, 250, "着地！", 0xffff00);
    }
}



















// ヒント
// void CGame::Update()
// ① 落下処理
// ・着地していない間だけ、丸のY座標を落下速度の分だけ増やす。















// 
// ② 着地判定
// ・丸の下端は「中心のY座標＋半径」で求める。
// ・下端が地面の上端以上になったら、中心を「地面の上端－半径」へ直す。
// ・着地フラグをtrueにして、それ以降は落下させない。
// void CGame::Draw() const
// ③ 丸の描画
// ・丸の座標を中心に、半径20の水色の塗りつぶした円を描く。
// ・地面と「着地！」の条件表示は記入済みなので変更しない。

/*
【このコードで使用しているC++機能】
クラスのメンバー関数を.cppに定義する。
メンバー変数はprivateに置き、表示だけを行うDrawをconstメンバー関数にする。
*/

/*
【書いていない・省略しているC++の機能】
継承、動的メモリ確保、独自のコンストラクタ・デストラクタは使用しない。
*/