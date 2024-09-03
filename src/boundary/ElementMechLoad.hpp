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
#include "boundary/BoundaryCase.hpp"
#include <Eigen/Dense>
#include <string>

class ElementMechLoad {
public:
  // Static variables for the coordinate system of load
  static constexpr int GLOBAL = 0;
  static constexpr int LOCAL = 1;

  // Static constants for the type of load
  static constexpr int LINE = 0, AREA = 1, VOLUME = 2;

  // Static constants for the component of mechanical load
  static constexpr int FX = 0, FY = 1, FZ = 2, MX = 3, MY = 4, MZ = 5;

  // Static constants for the geometry of 2D loading function
  static constexpr int QUADRANGULAR = 0, TRIANGULAR = 1;

  // Static constants for the geometry of 3D loading function
  static constexpr int HEXAHEDRAL = 0, TETRAHEDRAL = 1;

  /**
   * Default constructor.
   */
  ElementMechLoad() = default;

  /**
   * Creates element mechanical load.
   *
   * @param name
   *            The name of mechanical load.
   * @param boundaryCase
   *            The boundary case of mechanical load.
   * @param type
   *            The type of mechanical load.
   * @param component
   *            The component of mechanical load.
   * @param loadingValues
   *            The values of mechanical load.
   */
  ElementMechLoad(std::string name, BoundaryCase boundaryCase, int type,
                  int component, const Eigen::VectorXd &loadingValues);

  /**
   * Sets load as self weight depending on the given parameter.
   *
   * @param isSelfWeight
   *             True if the load is self weight. False otherwise.
   *
   *             The default value is false.
   */
  void setIsSelfWeight(bool isSelfWeight);

  /**
   * Sets boundary case to element mechanical load.
   *
   * @param boundaryCase
   *            The boundary case to be set.
   */
  void setBoundaryCase(const BoundaryCase &boundaryCase);

  /**
   * Sets loading values to element mechanical load.
   *
   * @param loadingValues
   *            The loading values to be set.
   */
  void setLoadingValues(const Eigen::VectorXd &loadingValues);

  /**
   * Sets scaling factor for loading values.
   *
   * @param scale
   *            The scaling factor to be set.
   */
  void setLoadingScale(const double scale);

  /**
   * Sets the coordinate system of element mechanical load.
   *
   * @param coordinateSystem
   *            The coordinate system to be set.
   */
  void setCoordinateSystem(int coordinateSystem);

  /**
   * Sets the name of element mechanical load.
   *
   * @param name
   *            The name to be set.
   */
  void setName(std::string name);

  /**
   * Gets the name of element mechanical load.
   *
   * @return The name of element mechanical load.
   */
  [[nodiscard]] std::string getName() const;

  /**
   * Gets the boundary case of element mechanical load.
   *
   * @return The boundary case of element mechanical load.
   */
  [[nodiscard]] BoundaryCase getBoundaryCase() const;

  /**
   * Gets the type of element mechanical load.
   *
   * @return The type of element mechanical load.
   */
  [[nodiscard]] int getType() const;

  /**
   * Gets the component of element mechanical load.
   *
   * @return The component of element mechanical load.
   */
  [[nodiscard]] int getComponent() const;

  /**
   * Gets the coordinate system of element mechanical load.
   *
   * @return The coordinate system of element mechanical load.
   */
  [[nodiscard]] int getCoordinateSystem() const;

  /**
   * Gets the values of element mechanical load.
   *
   * @return The values of element mechanical load.
   */
  [[nodiscard]] Eigen::VectorXd getLoadingValues() const;

  /**
   * Returns the degree of loading function.
   *
   * @return The degree of loading function.
   */
  [[nodiscard]] int getDegree() const;

  /**
   * Returns the function value of element mechanical load.
   *
   * @param geometry
   *             The geometry of 2D/3D element that this load will be applied.
   * @param eps1
   *             Natural coordinate in the 1st direction.
   * @param eps2
   *             Natural coordinate in the 2nd direction.
   * @param eps3
   *             Natural coordinate in the 3rd direction.
   *
   * @return The value of element mechanical load.
   */
  [[nodiscard]] double getFunction(int geometry, double eps1, double eps2,
                                   double eps3) const;

  /**
   * This method returns the loading scale of element mechanical load.
   *
   * @return The loading scale of element mechanical load.
   */
  [[nodiscard]] double getLoadingScale() const;

  /**
   * Returns True if the load is self weight. False otherwise.
   *
   * @return True if the load is self weight. False otherwise.
   */
  [[nodiscard]] bool getIsSelfWeight() const;

  /**
   * Checks the number of parameters given.
   *
   * @param values
   *            The parameter vector of element mechanical load
   *
   * @return True if the number of parameters is correct. False otherwise.
   */
  static bool checkValues(const Eigen::VectorXd &values);

  /**
   * Throws an exception with the related message.
   *
   * @param message
   *            The message to be thrown
   */
  static void exceptionHandler(const std::string &message);

private:
  // The name of mechanical load
  std::string name_;

  // The boundary case of mechanical load
  BoundaryCase boundaryCase_;

  // The type of mechanical load
  int type_;

  // The component of mechanical load
  int component_;

  // Coordinate system of load
  int coordinateSystem_;

  // The value for scaling loading values.
  double scale_;

  // The values of mechanical load
  Eigen::VectorXd loadingValues_;

  // Boolean variable indicating if load is self weight or not.
  bool isSelfWeight_;
};
