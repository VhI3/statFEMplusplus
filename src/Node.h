//
// Created by vahab on 3/30/23.
//
#pragma once
#include <Eigen/Dense>
#include <Eigen/Core>
// #include "external/eigen/eigen-src/Eigen/Dense"
// #include "external/eigen/eigen-src/Eigen/Core"

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