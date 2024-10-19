#pragma once

#define DECLARE_SINGLETON(ClassType)									\
private:																\
	static shared_ptr<ClassType> m_pInstance;							\
public:																	\
	ClassType() {}														\
	virtual ~ClassType() { Free(); }									\
	static shared_ptr<ClassType> Create_Instance();						\
	static shared_ptr<ClassType> Get_Instance();						\
	static void Destroy_Instance();										\

#define IMPLEMENT_SINGLETON(ClassType)									\
shared_ptr<ClassType> ClassType::m_pInstance = shared_ptr<ClassType>();	\
shared_ptr<ClassType> ClassType::Get_Instance()							\
{																		\
	if (nullptr == m_pInstance.get())									\
		assert(false);													\
																		\
	return m_pInstance;													\
}																		\
shared_ptr<ClassType> ClassType::Create_Instance()						\
{																		\
	if (nullptr != m_pInstance.get())									\
		assert(false);													\
	m_pInstance = make_shared<ClassType>();								\
																		\
	return m_pInstance;													\
}																		\
void ClassType::Destroy_Instance()										\
{																		\
	if(nullptr == m_pInstance.get())									\
		return;															\
	m_pInstance->OnDestroy();											\
	m_pInstance.reset();												\
}

