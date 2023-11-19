/*
MIT License

Copyright (c) 2023 VHI3 

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the "Software"), to deal in 
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the 
Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR 
THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Node.hpp"

#ifdef _MSC_VER // This block will be used if MSVC is the compiler
template class Node<double>;
#elif defined(__GNUC__) || defined(__clang__) // This block will be used if GCC or Clang is the compiler
template class __attribute__((visibility("default"))) Node<double>;
#else
#error "Unsupported compiler"
#endif


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
