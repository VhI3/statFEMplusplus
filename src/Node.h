//
// Created by vahab on 3/30/23.
//
// The decleration of the classes is performed in a *.h file
#pragma once
#include <Eigen/Dense>
#include <Eigen/Core>
template <class T>
class Node
{
public:
    explicit Node(const Eigen::Vector<T, 3> &coordinates);

    const Eigen::Vector<T, 3> &getCoordinates() const;
    void setCoordinates(const Eigen::Vector<T, 3> &coordinates);

private:
    Eigen::Vector<T, 3> m_coordinates;
};