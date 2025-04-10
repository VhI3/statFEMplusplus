/*
MIT License

Copyright (c) 2023 VHI3

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once
#include "BoundaryCase.hpp" // Adjust the include path as necessary
#include <array>            // For std::array
#include <string>           // For std::string

class Constraint {
public:
  // Constructors
  explicit Constraint() = default;
  Constraint(std::string name, BoundaryCase boundaryCase,
             const std::array<bool, 6> &constraints);

  // Setters
  void setName(const std::string &name);
  void setConstraints(const std::array<bool, 6> &free);
  void setBoundaryCase(const BoundaryCase &boundaryCase);

  // Getters
  [[nodiscard]] const std::string &getName() const noexcept;
  [[nodiscard]] const std::array<bool, 6> &getConstraints() const noexcept;
  [[nodiscard]] const BoundaryCase &getBoundaryCase() const noexcept;

private:
  std::string name_;
  BoundaryCase boundaryCase_;
  std::array<bool, 6> free_{};
};
