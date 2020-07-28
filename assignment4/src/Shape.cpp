#include "Shape.hpp"

int Shape::count = 1;

Shape::Shape(std::string name, std::string description) : name{name}, description{description}
{
  this->id = count++;
}

// 2.
int Shape::getId() const
{
  return this->id;
}

std::string Shape::getName() const
{
  return this->name;
}

std::string Shape::getDescription() const
{
  return this->description;
}

// 3.
void Shape::setName(std::string name)
{
  this->name = name;
}

void Shape::setDescription(std::string name)
{
  this->description = description;
}

// 4.
std::string Shape::toString() const
{
  std::stringstream ss;
  
  ss << "Shape Information" << std::endl;
  ss << "-----------------" << std::endl;

  ss << std::left << std::setw(15) << "id: "  << this->getId() << std::endl;
  ss << std::left << std::setw(15) << "Shape name: " << this->getName() << std::endl;
  ss << std::left << std::setw(15) << "Description: " << this->getDescription() << std::endl;
  ss << std::left << std::setw(15) << "B. box width: " << this->getBoundingBoxWidth() << std::endl;
  ss << std::left << std::setw(15) << "B. box height: " << this->getBoundingBoxHeight() << std::endl;
  ss << std::left << std::setw(15) << "Scr area: " << this->computeScreenArea() << std::endl;
  ss << std::left << std::setw(15) << "Geo area: " << std::setprecision(2) << std::fixed << this->computeArea() << std::endl;
  ss << std::left << std::setw(15) << "Scr perimeter: " << this->computeScreenPerimeter() << std::endl;
  ss << std::left << std::setw(15) << "Geo perimeter: " << std::setprecision(2) << std::fixed << this->computePerimeter() << std::endl;
  ss << std::left << std::setw(15) << "Static type: " << typeid(this).name() << std::endl;
  ss << std::left << std::setw(15) << "Dynamic type: " << typeid(*this).name() << std::endl;

  return ss.str();
}

// requirements specified from page 6
std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
  os << shape.toString();
  return os;
}
