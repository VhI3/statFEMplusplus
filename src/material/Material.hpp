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

#pragma once

#include <Eigen/Dense>
#include <string>
#include <stdexcept>

class Material
{
public:
    /* Static variables for the type of material and coefficients matrix */
    static const int ISOTROPIC = 0;
    static const int ORTHOTROPIC = 1;
    static const int THREE_D = 0;
    static const int PLAIN_STRESS = 1;
    static const int PLAIN_STRAIN = 2;

    /** An argument-free (default) constructor **/
    explicit Material() : name_(), d_(1.0), dg_(1.0) {}

    /**
     * Creates Material object.
     *
     * @param name
     *            Name of material.
     * @param d
     *            The mass per unit volume of material.
     * @param dg
     *            The weight per unit volume of material.
     */
    Material(const std::string &name, double d, double dg);

    /**
     * Sets name to material.
     *
     * @param name
     *            The name to be set.
     */
    void setName(const std::string &name);

    /**
     * Sets mass per unit volume to material.
     *
     * @param d
     *            Mass per unit volume.
     */
    void setVolumeMass(double d);

    /**
     * Sets weight per unit volume to material.
     *
     * @param dg
     *            Weight per unit volume.
     */
    void setVolumeWeight(double dg);

    /**
     * Returns the name of the material.
     *
     * @return The name of the material.
     */
    const std::string &getName() const;

    /**
     * Returns mass per unit volume of material.
     *
     * @return Mass per unit volume of material.
     */
    double getVolumeMass() const;

    /**
     * Returns weight per unit volume of material.
     *
     * @return Weight per unit volume of material.
     */
    double getVolumeWeight() const;

    /** Returns the type of material. */
    virtual int getType() const = 0;

    /**
     * Returns the stiffness matrix (C).
     *
     * @param type
     *            The state (type) of the stiffness matrix.
     * @return The stiffness matrix.
     */
    virtual Eigen::MatrixXd getC(int type) const = 0;

    /**
     * Returns the compliance matrix (S = C^-1).
     *
     * @param type
     *            The state (type) of the compliance matrix.
     * @return The compliance matrix.
     */
    virtual Eigen::MatrixXd getS(int type) const = 0;

    /**
     * Returns the thermal influence vector of the material.
     *
     * @param type
     *            The state (type) of the influence vector.
     * @return The thermal influence vector of material.
     */
    virtual Eigen::VectorXd getAlpha(int type) const = 0;

private:
    /** Mass per unit volume of material. */
    double d_;
    /** Weight per unit volume of material. */
    double dg_;
    /** The name of the material. */
    std::string name_;
};