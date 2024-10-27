#pragma once
#include "CBase.h"

class GameObject;
class Component : public CBase
{
public:
	Component();
	virtual ~Component();

public:
	virtual void OnEnable() override;
	virtual void OnDisable() override;
	virtual void OnDestroy() override;

	virtual void Free() override;

	virtual HRESULT Initialize() {};
public:
	weak_ptr<GameObject> Get_OwnerObject();
	void Set_Owner(weak_ptr<GameObject> owner);

protected:
	weak_ptr<GameObject> ownerObject;
};

