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
#include <Eigen/Dense>
#include <Eigen/Core>
#include <boundary/Constraint.h>
#include <node/LocalAxis.h>
#include <boundary/NodalMechLoad.h>
#include <vector>

/**
 * Class for Node.
 *
 * @author VHI3
 *
 */
template <class T>
class Node
{
public:
	/** Static variable for the coordinate system of node. */
	static const int GLOBAL = 0;
	static const int LOCAL = 1;

	/**
	 * Creates Node.
	 *
	 * @param pos
	 *           The position vector of a node with x,y and z coordinates.
	 */
	explicit Node(const Eigen::Matrix<T, 3, 1> &position);

	/**
	 * Gets position vector of the node.
	 */
	const Eigen::Matrix<T, 3, 1> &getPosition() const;

	/**
	 * Sets position vector to node.
	 *
	 * @param pos
	 *            The position vector to be set.
	 */
	void setPosition(const Eigen::Matrix<T, 3, 1> &position);

	/**
	 * Sets available dofs to the node.
	 *
	 * @param dofs
	 *            Array storing the dofs of the node. Dofs given as -1 are
	 *            considered as unavailable.
	 */
	void setAvailableDofs(const Eigen::VectorXi &dofs);

	/**
	 * Sets constraint to node.
	 *
	 * @param constraint
	 *            Constraint to be applied.
	 */
	void setConstraint(const Constraint &constraint);

private:
	/** The position vector of node. */
	Eigen::Matrix<T, 3, 1> position_;

	/** Array for storing avaible dofs of node. */
	Eigen::VectorXi availableDofs_;

	/** The constraint of node. */
	Constraint constraint_;

	/** The transformation matrix of node. */
	Eigen::MatrixXd trans_;

	/** Vector for storing mechanical loads of node. */
    std::vector<NodalMechLoad> mechLoads_;

	/** The local axis system of node. */
	LocalAxis localAxis_;
};
