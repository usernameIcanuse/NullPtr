#pragma once
#include "CBase.h"

class Collider;
class Component;

class GameObject : public CBase
{
protected:
	GameObject();
	virtual ~GameObject();

public:
	virtual void Start();
	virtual void Tick(float deltaTime);
	virtual void LateTick(float deltaTime);

	virtual void OnCollisionStart(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider);
	virtual void OnCollisionStay(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider);
	virtual void OnCollisionExit(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider);

	virtual void OnEnable() {}
	virtual void OnDisable() {}
	virtual void OnDestroy() {}

	virtual void Free() {}

private:
	unordered_map<unsigned int, list<shared_ptr<Component>>> components;
	//컴포넌트 추가 생성중.

public:
	template<typename T>
	weak_ptr<T> Add_Component()
	{
		shared_ptr<T> temp;
		
		components[typeid(T).hash_code()].push_back(temp);
		temp->Set_Owner(weakThis);

		return temp;
	}

	template<typename T>
	weak_ptr<T> Get_Component()
	{
		auto iter = components.find(typeid(T).hash_code());

		if (iter == components.end())
		{
			return weak_ptr<T>();
		}

		if (iter->second.size() == 0)
		{
			return weak_ptr<T>();
		}

		return dynamic_pointer_cast<T>(weak_ptr<CComponent>(iter->second.front());
	}

	template<typename T>
	list<weak_ptr<T>> Get_Components()
	{
		auto iter = components.find(typeid(T).hash_code());
		if (components.end() == iter)
		{
			return list<weak_ptr<T>>();
		}

		if (iter->second.size() == 0)
		{
			return list<weak_ptr<T>>();
		}

		list<weak_ptr<T>> comps;

		for (auto& elem : iter->second)
		{
			comps.push_back(dynamic_pointer_cast<T>(elem));
		}

		return comps;
	}
};

