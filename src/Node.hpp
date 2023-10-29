#pragma once
#include "Node.h"

// The constructor of template class Node.
template <class T>
Node<T>::Node(const Eigen::Matrix<T, 3, 1>& coordinates) : coordinates_(coordinates) {}

// It gives the coordinates of a Node.
template <class T>
const Eigen::Matrix<T, 3, 1>& Node<T>::getCoordinates() const { return coordinates_; }

// It sets the coordinates of a Node.
template <class T>
void Node<T>::setCoordinates(const Eigen::Matrix<T, 3, 1>& coordinates) { coordinates_ = coordinates; }
