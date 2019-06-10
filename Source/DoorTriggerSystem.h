#pragma once

#include "ComponentSystem.h"
#include "WriteLog.h"
#include "AppEvents.h"
#include <DirectXMath.h>
using namespace DirectX;

struct DoorTriggerComponent
{
	Entity door;
	bool activated = false;
};


class DoorTriggerSystem : public ComponentSystem<DoorTriggerComponent>
{
public:

	bool StartUp(U32 numComponents, EntityManager& em, EventBus& bus)
	{
		ComponentSystem<DoorTriggerComponent>::StartUp(numComponents, em);

		SubscribeToCollisionEvents(bus);
		m_eventBus = &bus;

		return true;
	}

	inline void Execute(float deltaTime) override
	{
		for (int i = 0; i < m_pool.Size(); ++i)
		{
		}
	}

	inline DoorTriggerComponent* operator[] (I32 idx)
	{
		return m_pool[idx];
	}

	void OnCollision(CollisionInfo* collision) override
	{
		DoorTriggerComponent* comp = FindComponent(collision->self.GetEntity());

		m_eventBus->Publish(&OpenDoorEvent(comp->door));
	}

private:
	EventBus* m_eventBus;
};