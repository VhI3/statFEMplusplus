#pragma once
#include "Constraint.h"

Constraint::Constraint(const std::string& name, BoundaryCase* boundaryCase, const std::array<bool, 6>& constraints)
	: name_(name), boundaryCase_(boundaryCase), free_(constraints) {}


void Constraint::setName(const std::string& name) { name_ = name; }
void Constraint::setConstraints(const std::array<bool, 6>& free) { free_ = free; }
void Constraint::setBoundaryCase(BoundaryCase* boundaryCase) { boundaryCase_ = boundaryCase; }

const std::string& Constraint::getName() const { return name_; }
const std::array<bool, 6>& Constraint::getConstraints() const { return free_; }
BoundaryCase* Constraint::getBoundaryCase() const { return boundaryCase_; }
