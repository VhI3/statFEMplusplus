//
// Created by vahab on 3/30/23.
//
#pragma once

#include "Node.h"
// The constructor of template class Node.
template <class T>
Node<T>::Node(const Eigen::Vector<T, 3> &coordinates) : m_coordinates{coordinates} {}
// It gives the coordinates of a Node.
template <class T>
const Eigen::Vector<T, 3> &Node<T>::getCoordinates() const { return m_coordinates; }
// It sets the coordinates of a Node.
template <class T>
void Node<T>::setCoordinates(const Eigen::Vector<T, 3> &coordinates) { m_coordinates = coordinates; }
