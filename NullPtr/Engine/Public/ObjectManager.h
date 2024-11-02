#pragma once
#include "CBase.h"

class GameObject;
class ObjectManager final : public CBase
{
	DECLARE_SINGLETON(ObjectManager)

public:
	HRESULT Reserve_Container(unsigned int iNumLevels);
	void StartObject();
	void Tick(float deltaTime);
	void LateTick(float deltaTime);
	
	virtual void Free() override;
private:
	vector<list<shared_ptr<GameObject>>> StartObjects;
	vector<list<shared_ptr<GameObject>>> ObjectLayers;

	unordered_map<unsigned int, class shared_ptr<GameObject>> Prototypes;

	int currentLevel;
	int levelNum;

public:
	template<typename T>
	weak_ptr<T> Add_Prototype()
	{
		auto iter = Prototypes.find(typeid(T).hash_code());

		if (Prototypes.end() == iter)
		{
			shared_ptr<T> instance = T::Create();
			Prototypes.emplace(typeid(T).hash_code(), instance);
			return instance;
		}

		return dynamic_pointer_cast<T>((*iter).second);
	}

	template<typename T>
	weak_ptr<T> Add_GameObject(unsigned int levelIndex, void* pArg = nullptr)
	{
		weak_ptr<GameObject> prototypeObject;
		auto iter = Prototypes.find(typeid(T).hash_code());
		if (iter != Prototypes.end())
		{
			prototypeObject = (*iter).second;
		}

		if (!prototypeObject.lock())
		{
			prototypeObject = Add_Prototype<T>();
		}

		if (!prototypeObject)
			return weak_ptr<T>();

		shared_ptr<GameObject> cloneObject = prototypeObject.lock()->Clone(LevelIndex, pArg);
		StartObjects[LevelIndex].push_back(cloneObject);

		return dynamic_pointer_cast<T>(cloneObject);
	}
};

