#pragma once
#include <stdint.h>

struct Transform
{
  int position_x;
  int position_y;
  float rotation;
  int scale;
};

typedef uint8_t ComponentType;

const ComponentType MAX_COMPONENTS = 32;
