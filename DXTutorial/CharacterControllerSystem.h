#pragma once

#include "ComponentSystem.h"
#include "TransformSystem.h"
#include "Physics.h"
#include "Types.h"
#include "RigidBody.h"
#include "EventBus.h"
#include "VelocitySystem.h"


struct CharacterControllerComponent
{
	U64 transform = 0;
	U64 velocity = 0;
	RigidBody rigidbody;
};


class CharacterControllerSystem : public ComponentSystem<CharacterControllerComponent>
{
public:
	void AddSystemRefs(TransformSystem* transformSystem, EventBus& eventBus)
	{
		m_transformSystem = transformSystem;
	}

	inline void Execute(float deltaTime) override
	{
	}

private:
	TransformSystem* m_transformSystem;
};