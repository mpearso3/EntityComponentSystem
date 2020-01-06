#include <iostream>
#include <queue>

#include "Entity.h"
#include "Component.h"
#include "System.h"

entity_id EntityManager::next_entity_id = 0;

void simple_queue_example()
{
  std::queue<int> int_queue;
  int_queue.push(0);
  int_queue.push(1);
  int_queue.push(2);
  int_queue.push(3);
  std::cout << "int_queue.front() " << int_queue.front() << std::endl;
  int_queue.pop();
  std::cout << "int_queue.front() " << int_queue.front() << std::endl;
  int_queue.pop();

  int_queue.push(5);

  std::cout << "int_queue.front() " << int_queue.front() << std::endl;
  int_queue.pop();
  std::cout << "int_queue.front() " << int_queue.front() << std::endl;
  int_queue.pop();
  std::cout << "int_queue.front() " << int_queue.front() << std::endl;
  int_queue.pop();
}

void entity_component_system_example()
{
  Coordinator coordinator;
  Entity *player = coordinator.create_new_entity("player");
  Entity *enemy = coordinator.create_new_entity("enemy");
  Entity *wall = coordinator.create_new_entity("wall");

  coordinator.debug_print_all_entities();

  player->add_component<TransformComponent>(2, 10, 11);
  player->get_component(TRANSFORM_COMPONENT)->print_debug();
  player->add_component<KeyboardComponent>(1, 5);
  player->get_component(KEYBOARD_COMPONENT)->print_debug();

  enemy->add_component<TransformComponent>(2, 3, 8);
  enemy->get_component(TRANSFORM_COMPONENT)->print_debug();

  coordinator.debug_print_all_entities();
}

int main(int argc, char** argv)
{
  //simple_queue_example();

  entity_component_system_example();

  return 0;
}
