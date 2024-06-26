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
#include <Eigen/Dense>
#include <boundary/BoundaryCase.hpp>
#include <stdexcept>
#include <string>
// Include BoundaryCase class or declaration here.

class NodalMechLoad {
public:
  // Static variables for the coordinate system of load
  static const int GLOBAL = 0;
  static const int LOCAL = 1;

  /**
   * Creates load.
   *
   * @param name
   *            The name of nodal mechanical load.
   * @param boundaryCase
   *            The boundary case of nodal mechanical load.
   * @param components
   *            The component vector of load. It has six components; the first
   * three are forces; the last three are moments.
   */
  NodalMechLoad(const std::string &name, BoundaryCase *boundaryCase,
                const Eigen::VectorXd &components);

  /**
   * Sets boundary case to nodal mechanical load.
   *
   * @param boundaryCase
   *            The boundary case to be set.
   */
  void setBoundaryCase(BoundaryCase *boundaryCase);

  /**
   * Sets coordinate system of nodal mechanical load.
   *
   * @param coordinateSystem
   *            The nodal coordinate system to be set.
   */
  void setCoordinateSystem(int coordinateSystem);

  /**
   * Sets scaling factor for loading values.
   *
   * @param scale
   *            The scaling factor for loading values.
   */
  void setLoadingScale(double scale);

  /**
   * Returns the name of nodal mechanical load.
   *
   * @return The name of nodal mechanical load.
   */
  const std::string &getName() const;

  /**
   * Returns the boundary case of nodal mechanical load.
   *
   * @return The boundary case of nodal mechanical load.
   */
  BoundaryCase *getBoundaryCase() const;

  /**
   * Returns the components vector of load.
   *
   * @return The components vector of load.
   */
  Eigen::VectorXd getComponents() const;

  /**
   * Returns the coordinate system of load.
   *
   * @return The coordinate system of load.
   */
  int getCoordinateSystem() const;

  /**
   * Check the dimension of the load vector.
   *
   * @param components
   *
   * @return The component if the dimension is correct.
   */
  static Eigen::VectorXd validateComponents(const Eigen::VectorXd &components);

private:
  /** The name of nodal mechanical load. */
  std::string name_;

  /** The boundary case of displacement load. */
  BoundaryCase *boundaryCase_;

  /** The component vector of load. */
  Eigen::VectorXd components_;

  /** The value for scaling loading values. */
  double scale_;

  /** The coordinate system of load. */
  int coordinateSystem_;
};
