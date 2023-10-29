#pragma once
#include <Eigen/Dense>
#include <Eigen/Core>

template <class T>
class Node
{
public:
	explicit Node(const Eigen::Matrix<T, 3, 1>& coordinates);

	const Eigen::Matrix<T, 3, 1>& getCoordinates() const;

	void setCoordinates(const Eigen::Matrix<T, 3, 1>& coordinates);

private:
	Eigen::Matrix<T, 3, 1> coordinates_;
};
