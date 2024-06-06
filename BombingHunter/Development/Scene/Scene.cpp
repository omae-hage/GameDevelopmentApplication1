#include "Scene.h"
#include "DxLib.h"
#include "../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Objects/PlayerBomb/Bom.h"
#include"../Utility/InputControl.h"
#include"../Objects/Enemy/Enemy_hane.h"
#include"../Objects/Enemy/Enemy_Harpy.h"
#include"../Objects/Enemy/Enemy_bullet.h"

//コンストラクタ
Scene::Scene() : objects(), back_image(NULL)
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

	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(320.0f, 50.0f));
	CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
	/*if (GetRand(100) <= 50)
	{
		CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
	}*/

	/*if(GetRand(100) < 40)
	{
		CreateObject<Enemy_hane>(Vector2D(0.0f, 120.0f));
	}

	if (GetRand(100) < 60)
	{
		CreateObject<Enemy_Harpy>(Vector2D(0.0f, 200.0f));
	}*/
	
	


}

//更新処理
void Scene::Update()
{
	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
	
	/*zを押すと爆弾が出る*/
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Bom>(objects[0]->GetLocation());
	}
	
	//sを押すと敵の弾を箱的で出す
	if (GetRand(20000) <= 33)
	{
		CreateObject<Enemy_bullet>(objects[1]->GetLocation());

		
	}

	if (GetRand(100) <= 2)
	{
		CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
	}
}

//描画処理
void Scene::Draw() const
{
	 DrawRotaGraphF(320.0f,195.0f,0.8,0,back_image,TRUE,0);
	

	//シーンに存在するブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
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
	//動的配列の解放
	objects.clear();
}
