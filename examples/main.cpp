#include "statFEMplusplus.hpp"
#include <cmath>
#include <vtkCell.h>
#include <vtkIdList.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridReader.h>

int main(int argc, char **argv) {

  Node<double> myNode({1., 2, 3});
  std::cout << myNode.getPosition() << std::endl;

  myNode.setPosition({1, 22, 33});
  std::cout << myNode.getPosition() << std::endl;

  // Create nodes 1 to 3
  Node<double> node1({1, 2, 3}), node2({4, 5, 6}), node3({7, 8, 9});

  std::cout << "--------------------------------------------------------------"
            << std::endl;
  vtkSmartPointer<vtkUnstructuredGridReader> reader =
      vtkSmartPointer<vtkUnstructuredGridReader>::New();

  reader->SetFileName(
      "/home/vahab/development/statFEMpp/examples/mesh/plate.vtk");
  reader->Update();

  vtkSmartPointer<vtkUnstructuredGrid> grid = reader->GetOutput();

  vtkIdType numCells = grid->GetNumberOfCells();
  std::cout << "Total number of elements: " << numCells << std::endl;

  // Count the number of quadrilateral (quad) elements
  int quadCount = 0;
  for (vtkIdType cellId = 0; cellId < numCells; ++cellId) {
    vtkCell *cell = grid->GetCell(cellId); // Get the cell (element)

    // Check if the cell is a quad
    if (cell->GetCellType() == VTK_QUAD) {
      ++quadCount;
    }
  }

  std::cout << "Number of quadrilateral (QUAD) elements: " << quadCount
            << std::endl;

  // Print number of nodes
  std::cout << "Number of nodes: " << grid->GetNumberOfPoints() << std::endl;

  // Extract nodes from the grid
  std::vector<Node<double>> nodes;
  for (vtkIdType i = 0; i < grid->GetNumberOfPoints(); i++) {
    double point[3]; // Array to hold point coordinates
    grid->GetPoint(i, point);

    // Create a Node<double> with the extracted coordinates
    nodes.push_back(Node<double>({point[0], point[1], point[2]}));
  }

  // Extract nodes belonging to each element
  std::vector<std::vector<Node<double>>>
      elements; // Vector to store elements with their nodes

  for (vtkIdType cellId = 0; cellId < grid->GetNumberOfCells(); ++cellId) {

    vtkCell *cell = grid->GetCell(cellId); // Get the cell (element)

    if (cell->GetCellType() == VTK_QUAD) {
      vtkIdList *pointIds =
          cell->GetPointIds(); // Get the point IDs of the cell

      std::vector<Node<double>>
          elementNodes; // Vector to store nodes for this element

      for (vtkIdType i = 0; i < pointIds->GetNumberOfIds(); ++i) {
        vtkIdType pointId =
            pointIds->GetId(i); // Get the i-th point ID of the cell

        // Extract the coordinates of the point
        double point[3];
        grid->GetPoint(pointId, point);

        // Create a Node<double> for each point in the element
        Node<double> node({point[0], point[1], point[2]});
        elementNodes.push_back(node);
      }

      // Store the element with its nodes
      elements.push_back(elementNodes);
    }
  }

  // Print all nodes in each element
  for (size_t elemIndex = 0; elemIndex < elements.size(); ++elemIndex) {
    std::cout << "Element " << elemIndex + 1 << " nodes:" << std::endl;
    for (const auto &node : elements[elemIndex]) {
      std::cout << node.getPosition().x() << " " << node.getPosition().y()
                << std::endl;
    }
  }

  return 0;
}
