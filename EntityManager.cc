#include "EntityManager.h"
#include <assert.h>

EntityManager::EntityManager() 
{
  signatures.resize(MAX_ENTITIES);
  for(Entity entity = 0; entity < MAX_ENTITIES; ++entity)
  {
    available_entities.push(entity);
  }
}

Entity EntityManager::create_entity()
{
  assert(living_entity_count < MAX_ENTITIES && "Too many entities in create_entity.");

  Entity id = available_entities.front();
  available_entities.pop();
  living_entity_count++;

  return id;
}
void EntityManager::destroy_entity(Entity entity)
{
  assert(entity < MAX_ENTITIES && "Entity out of range in destroy_entity.");

  signatures[entity].reset();
  available_entities.push(entity);
  living_entity_count--;
}
void EntityManager::set_signature(Entity entity, std::bitset<MAX_COMPONENTS> signature)
{
  assert(entity < MAX_ENTITIES && "Entity out of range in set_signature.");

  signatures[entity] = signature;
}
Signature EntityManager::get_signature(Entity entity)
{
  assert(entity < MAX_ENTITIES && "Entity out of range in get_signature.");
  
  return signatures[entity];
}

