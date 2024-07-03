#pragma once
#include <vector>
#include<string>
#include "../Objects/GameObject.h"

class Scene : public GameObject
{
private:
	int back_image;//背景を描画
	int frame; //フレーム計算
	int tim; //時間
	int tim_image; //時計の画像を描画
	int hi; //ハイスコアの画像描画
	int sc; //スコアの画像描画
	int count; //箱的の確率
	int count1; //羽敵の確率
	int count2; //ハーピーの確率
	int count3; //金敵の確率
	int Enemy_count;  //ハコ敵の数制限
	int Enemy_count1; //羽敵の生成数制限
	int Enemy_count2; //ハーピーの生成数制限
	int Enemy_count3; //金敵の生成数上限
	int cha; //羽敵の座標をランダムに
	int cha1; //ハーピーの座標をランダムに
	int sc_sc; //スコア計算
	int sc_sc1; //スコア計算
	int sc_sc2; //スコア計算
	int bom_fps; //爆発エフェクトを出すためのタイム計算
	int se_bom;//ボム発射のse
	int se_enemy; //箱的撃破のse
	int se_hako;//ハコ敵撃破se
	int se_hapy;//ハーピー撃破se
	int se_kin;//金的撃破se
	int bom_count; //爆弾の生成数制限
	int bom_count_fps;//bom生成のための時間をせってするもの
	int Perfect; //　パーフェクト音源
	int GOOD;  //ぐっとの音源
	int OK;  //おけの音源
	int BAD;//バットの音源
	int hi_sc;//ハイスコア
	

	
	
		

private:
	std::vector<GameObject*>objects;

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();
	void Sc();

private:

	

	void HitCheckObject(GameObject* a, GameObject* d);
	//オブジェクト生成処理
	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを作成する
		T* new_instance = new T();
		//GameObjectクラスを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("ゲームオブジェクトが生成できませんでした");
		}
		
		//初期化処理
		new_object->Initialize();
		//位置情報の設定
		new_object->SetLocation(location);

		//オブジェクトリストに追加
		objects.push_back(new_object);

		//インスタンスのポインタを返却
		return new_instance;
	}
};


