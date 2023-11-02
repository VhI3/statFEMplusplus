#pragma once
#include "Node.h"

// The constructor of template class Node.
template <class T>
Node<T>::Node(const Eigen::Matrix<T, 3, 1> &position) : position_(position) {}

// It gives the coordinates of a Node.
template <class T>
const Eigen::Matrix<T, 3, 1> &Node<T>::getPosition() const
{
	return position_;
}

// It sets the coordinates of a Node.
template <class T>
void Node<T>::setPosition(const Eigen::Matrix<T, 3, 1> &position)
{
	position_ = position;
}

template <class T>
void Node<T>::setAvailableDofs(const Eigen::VectorXi &dofs)
{
	// Check the size of the vector
	if (dofs.size() != 6)
	{
		// Handle the error (e.g., throw an exception)
		throw std::invalid_argument("Illegal dimension for available dofs!");
	}
	// Set the dofs
	availableDofs_ = dofs;
}

template <class T>
void Node<T>::setConstraint(const Constraint &constraint)
{
	constraint_ = constraint;
}
