#include "Scene.h"
#include "../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#define D_PIVOT_CENTER
//コンストラクタ
Scene::Scene() : objects()
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
	//プレイヤーを上のあたりに生成する
	CreateObject<Player>(Vector2D(320.0f, 240.0f));
	/*CreateObject<Enemy>(Vector2D(320.0f, 400.0f));*/
}

//更新処理
void Scene::Update()
{
	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
	//オブジェクトどうしの当たり判定チェック
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//当たり判定チェック処理
			HitCheckObject(objects[i], objects[j]);
		}
	}

	//ｚきーを押したら、敵を生成する
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Enemy>(Vector2D(100.0f, 400.0f));
	}
}
//描画処理
void Scene::Draw() const
{
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

#ifdef D_PIVOT_CENTER

//当たり判定チェック処理(中心であたり判定をとる)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//２つのオブジェクトのあたり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize()+ b->GetBoxSize()) / 2.0f;

	//距離より大きさ場合、hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//あたったことをオブジェクトに通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#else
//あたり判定チェック処理（左頂点の座標からあたり判定計算を行う）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//右下頂点座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//AとBの位置関係を調べる
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//オブジェクトに対してHit判定を通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#endif // D_PIVOT_CNETER