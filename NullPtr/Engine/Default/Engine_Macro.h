#pragma once

#define DECLARE_SINGLETON(ClassType)				\
public:												\
GameInstance();										\
virtual ~GameInstance();							\
static shared_ptr<GameInstance> Create_Instance();	\
static shared_ptr<GameInstance> Get_Instance();		\
static void Destroy_Instance();						\
													\
private:											\
	static shared_ptr<GameInstance> instance;		\

#define IMPLEMENT_SINGLETON(ClassType)				\


