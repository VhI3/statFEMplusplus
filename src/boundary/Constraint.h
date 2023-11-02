#pragma once

#include <array>  // For std::array
#include <string>  // For std::string
#include <stdexcept>  // For std::invalid_argument
#include <boundary/BoundaryCase.h>

class Constraint {
public:
explicit Constraint() : name_(), boundaryCase_(nullptr), free_{} {}

	Constraint(const std::string& name, BoundaryCase* boundaryCase, const std::array<bool, 6>& constraints);
	

	void setName(const std::string& name);
	void setConstraints(const std::array<bool, 6>& free);
	void setBoundaryCase(BoundaryCase* boundaryCase);

	const std::string& getName() const;
	const std::array<bool, 6>& getConstraints() const;
	BoundaryCase* getBoundaryCase() const;

private:
	std::array<bool, 6> free_;
	std::string name_;
	BoundaryCase* boundaryCase_;
};
