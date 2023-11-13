# statFEM++

Welcome to the statFEM++ Project! This is a modern objected-oriented C++ 17 code for implementing a deterministic finite element method (FEM) with multiple advanced features.

## Features

1. **Element Library:** This code is designed to handle various elements, including beam elements, shells, 1D Tension bars, Trusses, 2D rectangular elements, and 3D solid elements. There is an extensive library of FEM elements to choose from.

2. **Shape Functions:** The polynomial order of shape functions of elements can be increased to an arbitrary order in each direction, providing modeling flexibility.

3. **Material Models Library:** Our library includes a variety of material models such as Linear Elastic, St. Veant Kirchhoff, and Hyperelastic material models like Moony Rivlin, Neo Hookean, and Ogden.

4. **Meshing with Gmsh:** The meshing of elements is performed using Gmsh, a powerful 3D finite element mesh generator with a built-in CAD engine and post-processor.

5. **Stochastic FEM:** We implement a stochastic FEM for dealing with uncertain material parameters. The code includes sampling methods like Monte Carlo simulation to quantify the uncertainties in output displacement, strains, and stresses.

6. **Polynomial Chaos:** Intrusive and Non-Intrusive polynomial chaos are implemented as surrogate models, providing a more feasible alternative to the computationally expensive Monte Carlo simulation.

7. **Bayesian Updating:** The stochastic FEM (SFEM) is used as prior knowledge for the statistical FEM (statFEM) in a Bayesian formalism to update the displacement field in light of observation data.

8. **Gaussian Process for Model-Reality Mismatch:** The model-reality mismatch is currently modeled using a Gaussian Process with two hyperparameters.

## Future Goals

The rest of the goals for the statFEM++ project will be announced soon. Stay tuned!

## Contributing

Your contributions are always welcome! Please take a look at the [contribution guidelines](CONTRIBUTING.md) first.

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Contact

[Your Name] - [Your Email] - [Your LinkedIn/Twitter/GitHub]

Project Link: [https://github.com/yourusername/statFEMplusplus](https://github.com/yourusername/statFEMplusplus)
