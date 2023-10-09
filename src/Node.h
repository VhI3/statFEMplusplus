#pragma once
#include <Eigen/Dense>
#include <Eigen/Core>

template <class T>
class Node
{
public:
	explicit Node(const Eigen::Matrix<T, 3, 1>& coordinates) : coordinates_(coordinates) {}

	const Eigen::Matrix<T, 3, 1>& getCoordinates() const {
		return coordinates_;
	}

	void setCoordinates(const Eigen::Matrix<T, 3, 1>& coordinates) {
		coordinates_ = coordinates;
	}

private:
	Eigen::Matrix<T, 3, 1> coordinates_;
};