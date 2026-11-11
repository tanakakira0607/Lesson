#pragma once

class CGame
{
public:
    // ゲーム開始時の座標と状態を設定する。
    void Init();
    // 1フレーム分の移動や判定を行う。
    void Update();
    // 現在の状態に応じて、図形と文字を描く。
    void Draw() const;

   

private:
    // 定数とメンバー変数：記入済み。
    // メンバー変数名にはm_、定数名にはUPPER_SNAKE_CASEを使う。

    static constexpr int GROUND_Y = 560; // 地面の上端

    // 定数:
    // 画面の横幅、画面の縦幅
    // ボールの半径
    // ボールが下に移動する速さ
    int m_X = { 300 };
    int m_Y = {GROUND_Y -200};
    int m_V = {10};



    bool m_Landed{ false }; // 地面の設置フラグ(着地したらtrueにする。)


};
