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
#include <boundary/BoundaryCase.hpp>
#include <string>
class ElementTemp {
public:
  /**
   * Create element temperature load.
   *
   * @param name
   *            The name of the load.
   * @param boundaryCase
   *            The boundary case of load.
   * @param value
   *            The value of load.
   */
  explicit ElementTemp(std::string name, BoundaryCase boundaryCase,
                       const double &value);

  /**
   * Sets name of element temperature load.
   *
   * @param name
   *            The name of element temperature load.
   */
  void setName(const std::string &name);

  /**
   * Sets boundary case to element temperature load.
   *
   * @param boundaryCase
   *              The boundary case to be set.
   */
  void setBoundaryCase(const BoundaryCase &boundaryCase);

  /**
   * Sets scaling factor for loading values.
   *
   * @param scale
   *            The scaling factor for loading values.
   */
  void setLoadingScale(double scale);

  /**
   * Returns the name of element temperature load.
   *
   * @return The name of element temperature load.
   */
  [[nodiscard]] const std::string &getName() const;

  /**
   * Returns the boundary case of element temperature load.
   *
   * @return The boundary case of element temperature load.
   */
  [[nodiscard]] const BoundaryCase &getBoundaryCase() const noexcept;

  /**
   * Returns the loading value.
   *
   * @return The loading value of temperature load.
   */
  [[nodiscard]] double getValue() const;

  /**
   * Returns the scaling factor for loading values.
   *
   * @return The scaling factor for loading values.
   */
  [[nodiscard]] double getLoadingScale() const;

private:
  /** The name of element temperature load. */
  std::string name_;

  /** The boundary case of element temperature load. */
  BoundaryCase boundaryCase_;

  /** The value for scaling loading values. */
  double scale_;

  /** The loading value. */
  double value_;
};
