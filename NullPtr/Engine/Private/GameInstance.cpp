#include "GameInstance.h"

IMPLEMENT_SINGLETON(GameInstance)

void GameInstance::Initial_Engine()
{
    //매니저 인스턴스 생성
    //initialize;
    objectManager = ObjectManager::Create_Instance();
    collisionManager = CollisionManager::Create_Instance();

    objectManager->Reserve_Container(1);
}

void GameInstance::Tick_Engine(float deltaTime)
{
    objectManager->StartObject();
    //tick
    objectManager->Tick(deltaTime);

    objectManager->LateTick(deltaTime);
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
