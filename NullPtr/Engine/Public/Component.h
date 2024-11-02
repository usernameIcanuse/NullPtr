#pragma once
#include "CBase.h"

class GameObject;
class Component : public CBase
{
public:
	Component();
	virtual ~Component();

public:
	virtual HRESULT Initialize_Prototype() PURE;
	virtual HRESULT Initialize(void* Arg) PURE;

	virtual void OnEnable() override;
	virtual void OnDisable() override;
	virtual void OnDestroy() override;

	virtual shared_ptr<Component> Clone(unsigned int LevelIndex, void* pArg = nullptr) PURE;
	virtual void Free() override;

public:
	weak_ptr<GameObject> Get_OwnerObject();
	void Set_Owner(weak_ptr<GameObject> owner);

protected:
	weak_ptr<GameObject> ownerObject;
	unsigned int createdLevel;
};

