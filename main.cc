#include <iostream>
#include <queue>

#include "ECS.h"

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

int main(int argc, char** argv)
{
  simple_queue_example();

  return 0;
}
