#include "Scene.h"
#include "DxLib.h"
#include "../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Objects/PlayerBomb/Bom.h"
#include"../Utility/InputControl.h"
#include"../Objects/Enemy/Enemy_hane.h"
#include"../Objects/Enemy/Enemy_Harpy.h"
#include"../Objects/Enemy/Enemy_bullet.h"
#include"../Objects/Bom_FX.h"
#include"../Objects/Enemy/Enemy_kin.h"



#define D_PIVOT_CENTER
//コンストラクタ
Scene::Scene() : objects(),back_image(NULL),frame(0),tim(), tim_image(),sc(),hi(),count(),count1(),count2(),count3(),Enemy_count(4),Enemy_count1(4),Enemy_count2(4),Enemy_count3(1), cha(), cha1(), sc_sc(), sc_sc1(),sc_sc2(), bom_fps(),se_bom(),se_enemy(),se_hako(),se_hapy(),se_kin(),bom_count(1), bom_count_fps(), Perfect(), GOOD(), OK(), BAD(),hi_sc()

{
	
}

Scene::~Scene()
{
	//忘れ防止
	Finalize();
}

//初期化処理
void Scene::Initialize()
{
	back_image = LoadGraph("Resource/Images/BackGround.png");
	tim_image = LoadGraph("Resource/Images/TimeLimit/timer-03.png");
    hi = LoadGraph("Resource/Images/Score/hs.png");
	sc = LoadGraph("Resource/Images/Score/font-21.png");
	se_bom = LoadSoundMem("Resource/Sounds/pan.wav");
	se_enemy = LoadSoundMem("Resource/Sounds/teki_gahee.wav");
	se_kin = LoadSoundMem("Resource/Sounds/arrows_perfect03_short.wav");
	se_hako =  LoadSoundMem("Resource/Sounds/arrows_perfect03_short.wav");
	se_hapy = LoadSoundMem("Resource/Sounds/pokan.wav");
	Perfect = LoadSoundMem("Resource/Sounds/Evaluation/SE_perfect.wav");
	GOOD = LoadSoundMem("Resource/Sounds/Evaluation/SE_good.wav");
	OK = LoadSoundMem("Resource/Sounds/Evaluation/SE_ok.wav");
	BAD = LoadSoundMem("Resource/Sounds/Evaluation/SE_bad.wav");
	

//プレイヤーやエネミーの生成
	CreateObject<Player>(Vector2D(320.0f, 50.0f));

	//箱敵の確率
	count = GetRand(100);

	//羽敵の確率
	count1= GetRand(100);

	//ハーピーの確率
	count2 = GetRand(100);

	//金敵の確率
	count3 = GetRand(100);

	//羽敵の座標をランダムにする
	cha = GetRand(2);

	//はーぴーの座標をランダムにする
	cha1 = GetRand(2);

}

//更新処理
void Scene::Update()
{
	/*PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, FALSE);*/
	/*if (count >= 60)
	{
		CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
	}*/

	frame++;
	if (frame >= 180) //3秒に１回
	{

		//箱敵生成
		if (Enemy_count > 0) //画面上に４体まで
		{
			if (count <= 40)
			{
				CreateObject<Enemy>(Vector2D(0.0f, 380.0f));
				Enemy_count--;

			}
		}
		//羽敵生成
		if (Enemy_count1 > 0)
		{
			if (count1 <= 30)
			{
				
				if (cha == 0)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 120.0f));
				}
				else if (cha == 1)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 200.0f));
				}

				else if (cha == 2)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 260.0f));
				}

				Enemy_count1--;



			}
		}

		//ハーピー生成
		if (Enemy_count2 > 0)
		{
			if (count2 <= 50)
			{
				if (cha1 == 0)
				{
					CreateObject<Enemy_Harpy>(Vector2D(0.0f, 200.0f));
				}

				else if (cha1 == 1)
				{
					CreateObject<Enemy_Harpy>(Vector2D(0.0f, 120.0f));
				}

				else if (cha1 == 2)
				{
					CreateObject<Enemy_Harpy>(Vector2D(0.0f, 260.0f));
				}
				Enemy_count2--;
			}
		}

		//金敵の生成
		if (Enemy_count3 > 0)
		{
			if (count <= 10)
			{
				CreateObject<Enemy_kin>(Vector2D(0.0f, 400.0f));
				Enemy_count3--;
			}
		}




		count = GetRand(100);
		count1 = GetRand(100);
		count2 = GetRand(100);
		count3 = GetRand(100);

		cha = GetRand(2);
		cha1 = GetRand(2);

		frame = 0;

	}

	if (bom_count == 1)
	{
		if (InputControl::GetKeyDown(KEY_INPUT_SPACE))
		{

			CreateObject<Bom>(objects[0]->GetLocation())->SetType(1);
			bom_count = 0;
			PlaySoundMem(se_bom, DX_PLAYTYPE_BACK);

		}
	}

	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	
	
	/*zを押すと爆弾が出る*/
	


	//オブジェクどうしのあたり判定チェック
	for (int i = 1; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//同じオブジェクトどうしは干渉しない
			if (objects[i]->GetType() != objects[j]->GetType())
			{
			/*if (objects[i]->GetType() == enemy != objects[j]->GetType() == enemy_kin)*/
				/*{*/
					HitCheckObject(objects[i], objects[j]);
				/*}*/
				//当たり判定チェック処理

			}
		}
	}


	//敵の弾を出す処理
		/*tim++;
		if (tim > 120)
		{
			 CreateObject<Enemy_bullet>(objects[1]->GetLocation());
			tim =0;
		}*/

		//壁に行くと消去
		for (int i = 1; i < objects.size(); i++)
		{
			if (objects[i]->GetLocation().x < 0)
			{
				objects.erase(objects.begin() + i);
			}
		}

		for (int i = 1; i < objects.size(); i++)
		{
			if (objects[i]->GetLocation().y > 440)
			{
				bom_count = 1;
				objects.erase(objects.begin() + i);
			}
		}

		
		//敵を倒すとスコアを加算
		for (int i = 1; i < objects.size(); i++)
		{
			if (objects[i]->sc_count() == true)
			{
	
				//箱的を倒した時のスコア獲得
				if (objects[i]->GetType() == enemy)
				{
					PlaySoundMem(se_hako, DX_PLAYTYPE_BACK);
					sc_sc1 += 200;
				}
				//羽敵を倒した時のスコア獲得
				else if (objects[i]->GetType() == enemy_hane)
				{
					PlaySoundMem(se_enemy, DX_PLAYTYPE_BACK);
					sc_sc1 += 40;
				}
				//ハーピーを倒した時のスコア減少
				else if (objects[i]->GetType() == enemy_Harpy)
				{
					PlaySoundMem(se_hapy, DX_PLAYTYPE_BACK);
					sc_sc1 += -200;
				}
				//金的を倒した時のスコア獲得
				else if (objects[i]->GetType() == enemy_kin)
				{
					PlaySoundMem(se_kin, DX_PLAYTYPE_BACK);
					sc_sc1 += 1000;
				}
				
				//スコアを計算
				sc_sc2 = sc_sc + sc_sc1;
				hi_sc = sc_sc2;
			}
		}

		//オブジェクト消去
	for (int i = 0; i < objects.size(); i++)
	{
		//判定チェック処理
		if (objects[i]->deleteObject() == true)
		{
			
			//箱的の出現数をプラス
			if (objects[i]->GetType() == enemy)
			{
				bom_count = 1;
				Enemy_count++; 
				/*CreateObject<Bom_FX>(objects[i]->GetLocation());
				bom_fps++;
				if (bom_fps >= 60)
				{
					objects.erase(objects.begin() + i);
				}*/
			}
			//羽敵の出現数をプラス
			else if (objects[i]->GetType() == enemy_hane)
			{
				bom_count = 1;
				Enemy_count1++;
				
			}
			//ハーピーの出現数をプラス
			else if (objects[i]->GetType() == enemy_Harpy)
			{
				bom_count = 1;
				Enemy_count2++;
				
			}

			//金的の出現数をプラス
			else if (objects[i]->GetType() == enemy_kin)
			{
				bom_count = 1;
				Enemy_count3++;

			}
			//オブジェクト消去
			objects.erase(objects.begin() + i);
		}
	}
}




//描画処理
void Scene::Draw() const
{
	 DrawRotaGraphF(320.0f,195.0f,0.8,0,back_image,TRUE,0);
	 DrawRotaGraphF(30.0f, 460.0f, 0.6, 0, tim_image, TRUE, 0);
	 DrawRotaGraphF(300.0f, 460.0f, 1, 0, hi, TRUE, 0);
	 DrawRotaGraphF(170.0f, 460.0f, 1, 0, sc, TRUE, 0);
	 
	//シーンに存在するブジェクトの描画処
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}

	//スコアを描画
	DrawFormatString(200.0f, 460.0f, GetColor(255, 255, 255), "%d", sc_sc2);
	DrawFormatString(340.0f, 460.0f, GetColor(255, 255, 255), "%d", hi_sc);
}

void Scene::Sc()
{
	if (sc_sc2 >= 3000)
	{
		PlaySoundMem(Perfect, DX_PLAYTYPE_BACK);
		LoadGraphScreen(30, 150, "Resource/Images/Evaluation/Perfect.png",TRUE);
	}

	else if (sc_sc2 >= 1500)
	{
		PlaySoundMem(GOOD, DX_PLAYTYPE_BACK);
		LoadGraphScreen(40, 130, "Resource/Images/Evaluation/GOOD.png",TRUE);
	}

	else if (sc_sc2 >= 1000)
	{
		PlaySoundMem(OK, DX_PLAYTYPE_BACK);
		LoadGraphScreen(40, 50, "Resource/Images/Evaluation/OK.png",TRUE);
	}

	else
	{
		PlaySoundMem(BAD, DX_PLAYTYPE_BACK);
		LoadGraphScreen(100, 150, "Resource/Images/Evaluation/BAD.png",TRUE);
	}
}

//終了処理
void Scene::Finalize()
{
	//動的配列が空なら処理を終了する
	if (objects.empty())
	{
		return;
	}

	//各オブジェクトを消去する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	/*DeleteSoundMem(bgm);*/
	//動的配列の解放
	objects.clear();

	Initialize();
}

//当たり判定チェック処理(中心であたり判定をとる)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//２つのオブジェクトのあたり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//距離より大きさ場合、hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//あたったことをオブジェクトに通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

