#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <iostream>
#include <array>
#include <stdlib.h>

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Rhombus.hpp"
#include "AcuteTriangle.hpp"
#include "RightTriangle.hpp"

#include "Grid.hpp"

class SlotMachine
{
  std::array<std::unique_ptr<Shape>, 3> reel{};
  void make_shapes(); // Step 6-19
  void make_shape(int k); // Steps 7-18
  void display(); // Step 23
public:
  SlotMachine() = default;
  SlotMachine(const SlotMachine&) = delete; // copy ctor
  SlotMachine(SlotMachine&&) = delete; // move ctor
  SlotMachine& operator=(const SlotMachine & ) = delete; // copy assignment
  SlotMachine& operator=( SlotMachine && ) = delete; // move assignment
  virtual ~SlotMachine() = default;
  void run(int initial_tokens = 10);
  
};

#endif /* SLOTMACHINE_H */
