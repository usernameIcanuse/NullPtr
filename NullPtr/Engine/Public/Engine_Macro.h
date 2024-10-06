#pragma once

#define DECLARE_SINGLETON(ClassType)					\
public:													\
	ClassType() {}										\
	virtual ~ClassType() { Free(); }					\
	static shared_ptr<ClassType> Create_Instance();		\
	static shared_ptr<ClassType> Get_Instance();		\
	static void Destroy_Instance();						\
														\
private:												\
	static shared_ptr<ClassType> instance;				

#define IMPLEMENT_SINGLETON(ClassType)					\
shared_ptr<ClassType> ClassType::instance = shared_ptr<ClassType>();\
shared_ptr<ClassType> ClassType::Create_Instance()		\
{														\
	if(instance.get() != nullptr)						\
		assert(false);									\
														\
	instance = make_shared<ClassType>();				\
}														\
shared_ptr<ClassType> ClassType::Get_Instance()			\
{														\
	if (instance.get() == nullptr)						\	
		assert(false);									\
														\
	return instance;									\
}														\
void ClassType::Destroy_Instance()						\
{														\
	if (instance.get() == nullptr)						\
		return;											\
	instance->OnDestroy()								\
	instance.reset();									\
}														