//
// Created by vahab on 3/30/23.
//
#pragma once

#include "Point.h"
// The constructor of template class Node.
template <class T>
Point<T>::Point(const Eigen::Vector<T, 3> &coordinates) : m_coordinates{coordinates} {}
// It gives the coordinates of a Node.
template <class T>
const Eigen::Vector<T, 3> &Point<T>::getCoordinates() const { return m_coordinates; }
// It sets the coordinates of a Node.
template <class T>
void Point<T>::setCoordinates(const Eigen::Vector<T, 3> &coordinates) { m_coordinates = coordinates; }
