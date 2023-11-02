#pragma once

#include <string> // For std::string

class BoundaryCase
{
public:
	explicit BoundaryCase(const std::string &name);

	void setName(const std::string &name);

	const std::string &getName() const;

private:
	std::string name_;
};