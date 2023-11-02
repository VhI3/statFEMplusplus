#pragma once
#include "BoundaryCase.h"

BoundaryCase::BoundaryCase(const std::string& name) : name_(name) {};

void BoundaryCase::setName(const std::string& name) { name_ = name; }

const std::string& BoundaryCase:: getName() const { return name_; }