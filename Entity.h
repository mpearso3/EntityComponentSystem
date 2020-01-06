#pragma once
#include <stdint.h>
#include <stdarg.h>
#include <assert.h>
#include <vector>
#include <bitset>
#include <string>

#include "Component.h"

typedef uint32_t entity_id;

const uint32_t MAX_ENTITIES = 5000;

class Entity
{
public:
  Entity(entity_id id, std::string name) : id(id), name(name) 
  {
    components.resize(MAX_COMPONENTS);
  }

  entity_id get_entity_id() const { return id; }
  std::string get_entity_name() const { return name; }

  template <typename T>
  void add_component(int n_args, ...)
  {
    std::cout << "add_component n_args " << n_args << std::endl;

    T *component;
    va_list args;
    va_start(args, n_args);
    component = new T(n_args, args);
    va_end(args);

    int id = component->get_id();

    components[id] = component;
    component_biset.set(id, 1);
  }
  std::bitset<MAX_COMPONENTS> get_components()
  {
    return component_biset;
  }
  Component* get_component(component_id id)
  {
    return components[id];
  }


private:
  entity_id id;
  std::string name;

  std::bitset<MAX_COMPONENTS> component_biset;
  std::vector<Component*> components;
};

class EntityManager
{
public:
  static entity_id next_entity_id;

  EntityManager() {}

  entity_id get_next_entity_id()
  {
    next_entity_id++;
    return next_entity_id-1;
  }

private:
};

class Coordinator
{
public:
  Coordinator() {}

  Entity* create_new_entity(std::string name)
  {
    entity_id id = entity_manager.get_next_entity_id();
    Entity *entity = new Entity(id, name);
    entities.push_back(entity);
    return entity;
  }

  void debug_print_all_entities()
  {
    std::cout << std::endl;
    for(std::vector<Entity*>::const_iterator vec_it = entities.begin(); vec_it != entities.end(); ++vec_it)
    {
      std::cout << "id " << (*vec_it)->get_entity_id() << std::endl;
      std::cout << "  name " << (*vec_it)->get_entity_name() << std::endl;

      if((*vec_it)->get_component(TRANSFORM_COMPONENT)) {
        (*vec_it)->get_component(TRANSFORM_COMPONENT)->print_debug();
      }

      if((*vec_it)->get_component(KEYBOARD_COMPONENT)) {
        (*vec_it)->get_component(KEYBOARD_COMPONENT)->print_debug();
      }
    }
  }
private:
  EntityManager entity_manager;
  std::vector<Entity*> entities;
};
