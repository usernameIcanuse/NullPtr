#include "GameInstance.h"

IMPLEMENT_SINGLETON(GameInstance)

void GameInstance::Initial_Engine()
{
    //매니저 인스턴스 생성
    //initialize;
}

void GameInstance::Tick_Engine(float deltaTime)
{
    ObjectManager::Get_Instance()->StartObject();
    //tick
    ObjectManager::Get_Instance()->Tick(deltaTime);

    ObjectManager::Get_Instance()->LateTick(deltaTime);
}

void GameInstance::Render_Engine()
{
    //preRender
    //Render
    //afterRender
}

void GameInstance::Destroy_Engine()
{
    //destroy singleton
    ObjectManager::Destroy_Instance();
}

void GameInstance::Free()
{
}
