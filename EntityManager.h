#pragma once
#include <queue>
#include <bitset>
#include <vector>

#include "ECS.h"

class EntityManager
{
public:
  EntityManager();

  Entity create_entity();
  void destroy_entity(Entity entity);
  void set_signature(Entity entity, std::bitset<MAX_COMPONENTS> signature);
  std::bitset<MAX_COMPONENTS> get_signature(Entity entity);

private:
  std::queue<Entity> available_entities;
  std::vector<std::bitset<MAX_COMPONENTS> > signatures;
  uint32_t living_entity_count;
};
