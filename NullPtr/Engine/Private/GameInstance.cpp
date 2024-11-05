#include "GameInstance.h"

IMPLEMENT_SINGLETON(GameInstance)

void GameInstance::Initial_Engine()
{
    //매니저 인스턴스 생성
    //initialize;
    objectManager = ObjectManager::Create_Instance();
    collisionManager = CollisionManager::Create_Instance();
    levelManager = LevelManager::Create_Instance();

    objectManager->Reserve_Container(1);
}

void GameInstance::Tick_Engine(float deltaTime)
{
    objectManager->StartObject();
    //tick
    levelManager->Tick(deltaTime);
    objectManager->Tick(deltaTime);

    objectManager->LateTick(deltaTime);

    collisionManager->Tick(deltaTime);
}

void GameInstance::Render_Engine()
{
    //preRender
    //Render
    //afterRender
}

void GameInstance::LevelEnter()
{
    objectManager->OnLevelEnter();
}

void GameInstance::LevelExit()
{
    objectManager->OnLevelExit();
}

void GameInstance::Destroy_Engine()
{
    //destroy singleton
    ObjectManager::Get_Instance()->Destroy_Instance();
    CollisionManager::Get_Instance()->Destroy_Instance();
    LevelManager::Get_Instance()->Destroy_Instance();
}

void GameInstance::Free()
{
    __super::Free();

    objectManager.reset();
    levelManager.reset();
    collisionManager.reset();
}
