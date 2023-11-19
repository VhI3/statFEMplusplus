/*
MIT License

Copyright (c) 2023 VHI3

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
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
#include <string> // For the string
#include <Eigen/Dense>

/**
 * Class for Local axis systems of nodes and one dimensional elements.
 *
 * @author VHI3
 *
 */
class LocalAxis
{
public:
	// Static constants for the type of local axis
	static const int POINT = 0;
	static const int LINE = 1;

	/** An argument-free (default) constructor **/
	explicit LocalAxis() : name_(), type_(), values_() {}

	/**
	 * Creates LocalAxis object.
	 *
	 * @param name
	 *            Name of local axis.
	 * @param type
	 *            The type of local axis.
	 * @param values
	 *            Rotation angles of local axis (point -> length = 3, line ->
	 *            length = 1). For point type, the angle sequence is rotations
	 *            about x, y' and z'' in degrees, respectively. For line type,
	 *            the axial rotation in degrees.
	 */
	LocalAxis(const std::string &name, int type, const Eigen::VectorXd &values);

	/**
	 * Returns name of the local axis.
	 *
	 * @return Name of local axis.
	 */
	const std::string &getName() const;

	/**
	 * Returns type of the local axis.
	 *
	 * @return Type of local axis.
	 */
	int getType() const;

	/**
	 * Returns rotation angles of the local axis.
	 *
	 * @return Rotation angles of the local axis (point -> length = 3, line ->
	 *         length = 1).
	 */
	const Eigen::VectorXd &getValues() const;

	static int validateType(int type);

	static Eigen::VectorXd validateValues(int type, const Eigen::VectorXd &values);

private:
	// The name of local axis.
	std::string name_;
	// The type of local axis.
	int type_;
	// The values of local axis (point -> length = 3, line -> length = 1).
	Eigen::VectorXd values_;
};