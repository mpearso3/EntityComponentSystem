#pragma once
#include <stdint.h>

typedef uint16_t component_id;

const uint16_t MAX_COMPONENTS = 32;

enum component_ids
{
  TRANSFORM_COMPONENT = 0,
  KEYBOARD_COMPONENT  = 1
};

class Component
{
public:
  Component() {}

  virtual void print_debug() const = 0;
};

class TransformComponent : public Component
{
public:
  TransformComponent(int x, int y) : position_x(x), position_y(y) {}

  void print_debug() const 
  {
    std::cout << "  position_x " << position_x << " position_y " << position_y << std::endl;
  }

private:
  int position_x;
  int position_y;
};

class KeyboardComponent : public Component
{
public:
  KeyboardComponent(int key_pressed) : key_pressed(key_pressed) {}

  void print_debug() const 
  {
    std::cout << "  key_pressed " << key_pressed << std::endl;
  }

private:
  int key_pressed;
};
