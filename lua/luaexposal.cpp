#include "lua/luaexposal.h"
#include <SFML/System/Vector2.hpp>
#include "entities/entity.h"
#include "../world.h"


void exposeVector()
{
    SLB::Class<sf::Vector2f>("Vector2f")
            .constructor<float, float>()
            .property("x", &sf::Vector2f::x)
            .property("y", &sf::Vector2f::y);
}

void exposeSceneNode()
{
    /*SLB::Class<SceneNode, SLB::Instance::NoCopy>("SceneNode")
            .constructor<Category::Type>()
            .set("getWorldPosition", &SceneNode::getWorldPosition);*/
}

void exposeEntity()
{
    /*SLB::Class<Entity, SLB::Instance::NoCopy>("Entity")
            .constructor<int>()
            .inherits<SceneNode>()
            .set("damage", &Entity::damage)
            .set("heal", &Entity::heal)
            .set("destroy", &Entity::destroy)
            .set("getHealthpoints", &Entity::getHealthpoints)
            .set("isDestroyed", &Entity::isDestroyed)
            .set("playLocalSound", &Entity::playLocalSound);*/
}

void exposeWorld()
{
    SLB::Class<World, SLB::Instance::NoCopyNoDestroy>("World")
            .set("SetPlayerInvincible", &World::setPlayerInvincible)
            .set("SkipTutorial", &World::skipTutorial)
            .set("SetLevel", &World::setLevel)
            .set("Instance", World::instance);
}


void exposeToLua()
{
    exposeVector();
    exposeSceneNode();
    exposeEntity();
    exposeWorld();
}
