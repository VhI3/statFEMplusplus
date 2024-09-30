# statFEM++

<!--toc:start-->
- [statFEM++](#statfem)
  - [Features](#features)
  - [Future Goals](#future-goals)
  - [Contributing](#contributing)
  - [License](#license)
  - [Contact](#contact)
<!--toc:end-->

Welcome to the statFEM++ Project! This is a modern objected-oriented C++ 17 code for implementing the <span style="color:red">stat</span>istical <span style="color:red">F</span>inite <span style="color:red">E</span>lement <span style="color:red">M</span>ethod (statFEM) with multiple advanced features.

## Features

1. **Element Library:** This code is designed to handle various elements, including beam elements, shells, 1D Tension bars, Trusses, 2D rectangular elements, and 3D solid elements. There is an extensive library of FEM elements to choose from.

2. **Shape Functions:** The polynomial order of shape functions of elements can be increased to an arbitrary order in each direction, which generates elements with higher polynomial order in every direction.

3. **Material Models Library:** Our library includes a variety of material models, such as linear elastic, St. Veant Kirchhoff, and Hyperelastic models like Moony Rivlin, Neo Hookean, and Ogden, and maybe Elastoplastic material models.

4. **Meshing with Gmsh:** The meshing of elements is performed using Gmsh, a powerful 3D finite element mesh generator with a built-in CAD engine and post-processor. Gmsh's output is a VTK file, which has been read with statFEM++.

5. **Stochastic FEM:** We implement a stochastic FEM for dealing with uncertain material parameters. The code includes sampling methods like Monte Carlo simulation to quantify output displacement, strain, and stress uncertainties.

6. **Polynomial Chaos:** Intrusive and Non-Intrusive polynomial chaos are implemented as surrogate models, providing a more feasible alternative to the computationally expensive Monte Carlo simulation. The stochastic regression is the first method.

7. **Bayesian Updating:** The stochastic FEM (SFEM) is used as prior knowledge for the statistical FEM (statFEM) in a Bayesian formalism to update the displacement field in light of observation data.

8. **Gaussian Process for Model-Reality Mismatch:** The model-reality mismatch is currently modeled using a Gaussian Process with two hyperparameters.

## Future Goals

The rest of the goals for the statFEM++ project will be announced soon. Stay tuned!

## Contributing

Your contributions are always welcome! Please review the [contribution guidelines](CONTRIBUTING.md) first.

## License

It is distributed under the MIT License. See `LICENSE` for more information.

## Contact

<!--[Your Name] - [Your Email] - [Your LinkedIn/Twitter/GitHub]-->

Project Link: [https://github.com/yourusername/statFEMplusplus](https://github.com/yourusername/statFEMplusplus)
