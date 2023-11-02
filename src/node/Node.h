#pragma once
#include <Eigen/Dense>
#include <Eigen/Core>
#include <boundary/Constraint.h>

template <class T>
class Node
{
public:
	explicit Node(const Eigen::Matrix<T, 3, 1> &position);

	const Eigen::Matrix<T, 3, 1> &getPosition() const;

	void setPosition(const Eigen::Matrix<T, 3, 1> &position);

	void setAvailableDofs(const Eigen::VectorXi& dofs);

	void setConstraint(const Constraint& constraint);

private:
	Eigen::Matrix<T, 3, 1> position_;
	Eigen::VectorXi availableDofs_;
	Constraint constraint_;
};
