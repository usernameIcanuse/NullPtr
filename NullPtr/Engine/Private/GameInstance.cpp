#include "GameInstance.h"

IMPLEMENT_SINGLETON(GameInstance)

void GameInstance::Initial_Engine()
{
    //�Ŵ��� �ν��Ͻ� ����
    //initialize;
}

void GameInstance::Tick_Engine()
{
    //tick
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
}

void GameInstance::OnEnable()
{
}

void GameInstance::OnDisable()
{
}

void GameInstance::OnDestroy()
{
}

void GameInstance::Free()
{
}
