#pragma once
#include <stdint.h>
#include <stdarg.h>

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

  virtual int get_id() const = 0;

  virtual void print_debug() const = 0;
};

class TransformComponent : public Component
{
public:
  TransformComponent(int n_args, va_list args) 
  {
    position_x = va_arg(args, int);
    position_y = va_arg(args, int);
  }

  int get_id() const
  {
    return TRANSFORM_COMPONENT;
  }

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
  KeyboardComponent(int n_args, va_list args)
  {
    key_pressed = va_arg(args, int);
  }

  int get_id() const
  {
    return KEYBOARD_COMPONENT;
  }

  void print_debug() const 
  {
    std::cout << "  key_pressed " << key_pressed << std::endl;
  }

private:
  int key_pressed;
};
