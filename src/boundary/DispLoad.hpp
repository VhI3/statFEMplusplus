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
#include <Eigen/Core>
#include <boundary/BoundaryCase.hpp>

class DispLoad {
public:
  // Static variables for the coordinate system of load
  static constexpr int GLOBAL = 0;
  static constexpr int LOCAL = 1;

public:
  /**
   * Default constructor.
   */
  DispLoad() = default;

  /**
   * Creates load.
   *
   * @param name
   *            The name of displacement load.
   * @param boundaryCase
   *            The boundary case of displacement load.
   * @param components
   *            The component vector of load. It has six components; the first
   * three are translations; the last three are rotations.
   */
  DispLoad(std::string name, BoundaryCase boundaryCase,
           const Eigen::VectorXd &components);

  /**
   * Sets name of displacement load.
   *
   * @param name
   *            The name of displacement load.
   */
  void setName(std::string name);

  /**
   * Sets components of displacement load.
   *
   * @param components
   *            The component vector of load. It has three components; the first
   * two are displacements; the last one is rotation.
   */
  void setComponents(const Eigen::VectorXd &components);

  /**
   * Sets boundary case to displacement load.
   *
   * @param boundaryCase
   *            The boundary case to be set.
   */
  void setBoundaryCase(BoundaryCase boundaryCase);

  /**
   * Sets coordinate system of displacement load.
   *
   * @param coordinateSystem
   *            The coordinate system to be set.
   */
  void setCoordinateSystem(const int coordinateSystem);

  /**
   * Sets scale of displacement load.
   *
   * @param scale
   *            The scale to be set.
   */
  void setLoadingScale(const double scale);

  /**
   * Gets name of displacement load.
   *
   * @return The name of displacement load.
   */
  [[nodiscard]] const std::string &getName() const;

  /**
   * Gets boundary case of displacement load.
   *
   * @return The boundary case of displacement load.
   */
  [[nodiscard]] BoundaryCase getBoundaryCase() const;

  /**
   * Gets components of displacement load.
   *
   * @return The components of displacement load.
   */
  [[nodiscard]] Eigen::VectorXd getComponents() const;

  /**
   * Gets coordinate system of displacement load.
   *
   * @return The coordinate system of displacement load.
   */
  [[nodiscard]] int getCoordinateSystem() const;

  /**
   * Gets scale of displacement load.
   *
   * @return The scale of displacement load.
   */
  [[nodiscard]] double getLoadingScale() const;

  /**
   * Check the dimension of the load vector.
   *
   * @param components
   *
   * @return The component if the dimension is correct.
   */
  static Eigen::VectorXd validateComponents(const Eigen::VectorXd &components);

private:
  /** The name of the displacement load. */
  std::string name_;

  /** The boundary case of the displacement load. */
  BoundaryCase boundaryCase_;

  /** The components of the displacement load. */
  Eigen::VectorXd components_;

  /** The scale of the displacement load. */
  double scale_;

  /** The coordinate system of the displacement load. */
  int coordinateSystem_;
};
