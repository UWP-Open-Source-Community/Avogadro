/**********************************************************************
  Mesh - Primitive class to encapsulate triangular meshes/

  Copyright (C) 2008 Marcus D. Hanwell

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.openmolecules.net/>

  Avogadro is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Avogadro is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
 **********************************************************************/

#ifndef MESH_H
#define MESH_H

#include <avogadro/primitive.h>
#include <Eigen/Core>

#include <vector>

// Forward declarations
class QReadWriteLock;

namespace Avogadro {

  class Molecule;
  class Color3f;
  /**
   * @class Mesh mesh.h <avogadro/mesh.h>
   * @brief Encapsulation of a triangular mesh that makes up a surface.
   * @author Marcus D. Hanwell
   *
   * The Mesh class is a Primitive subclass that provides an Mesh object. All
   * meshes must be owned by a Molecule. It should also be removed by the
   * Molecule that owns it. Meshes encapsulate triangular meshes that can also
   * have colors associated with each vertex.
   */
  class MeshPrivate;
  class A_EXPORT Mesh : public Primitive
  {
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    Mesh(QObject *parent=0);

    /**
     * Destructor.
     */
    ~Mesh();

    /**
     * Reserve the expected space for the mesh. This causes all member vector
     * storage to call the reserve function with the number specified.
     * @param size Expected size of the mesh.
     * @param colors Should the colors vector reserve this space too? Defaults
     * to false.
     * @return True on success.
     */
    bool reserve(unsigned int size, bool colors = false);

    /**
     * This function allows long running calculations to mark the mesh as in
     * progress.
     * @param stable Indicate that the Mesh is currently being modified.
     */
    void setStable(bool stable);

    /**
     * Indicate whether the Mesh is complete or currently being modified. In
     * general using Mesh values from an unstable Mesh is not advisable.
     * @return True if the Mesh is complete, false if it is being modified.
     */
    bool stable();

    /**
     * Set the iso value that was used to generate the Mesh.
     */
    void setIsoValue(float value) { m_isoValue = value; }

    /**
     * @return The iso value used to generate the Mesh.
     */
    float isoValue() const { return m_isoValue; }

    /**
     * Set the unique id of the other Mesh if this Mesh is part of a pair.
     */
    void setOtherMesh(unsigned int other) { m_other = other; }

    /**
     * @return The unique id of the other Mesh if this is part of a pair.
     */
    unsigned int otherMesh() const { return m_other; }

    /**
     * Set the unique id of the Cube the Mesh was generated from.
     */
    void setCube(unsigned int cube) { m_cube = cube; }

    /**
     * @return The unique id of the Cube the Mesh was generated from.
     */
    unsigned int cube() const { return m_cube; }

    /**
     * @return Vector containing all of the vertices in a one dimensional array.
     */
    const std::vector<Eigen::Vector3f> & vertices() const;

    /**
     * @return The number of vertices.
     */
    unsigned int numVertices() const { return m_vertices.size(); }

    /**
     * @return Pointer to the first vertex of the specified triangle.
     */
    const Eigen::Vector3f * vertex(int n) const;

    /**
     * Clear the vertices vector and assign new values.
     */
    bool setVertices(const std::vector<Eigen::Vector3f> &values);

    /**
     * Add one or more vertices, i.e., the vector is expected to be of length
     * 3 x n where n is an integer.
     */
    bool addVertices(const std::vector<Eigen::Vector3f> &values);

    /**
     * @return Vector containing all of the normals in a one-dimensional array.
     */
    const std::vector<Eigen::Vector3f> & normals() const;

    /**
     * @return The number of normals.
     */
    unsigned int numNormals() const { return m_normals.size(); }


    /**
     * @return Pointer to the first normal of the specified triangle.
     */
    const Eigen::Vector3f * normal(int n) const;

    /**
     * Clear the normals vector and assign new values.
     */
    bool setNormals(const std::vector<Eigen::Vector3f> &values);

    /**
     * Add one or more normals, i.e., the vector is expected to be of length
     * 3 x n where n is an integer.
     */
    bool addNormals(const std::vector<Eigen::Vector3f> &values);

    /**
     * @return Vector containing all of the colors in a one-dimensional array.
     */
    const std::vector<Color3f> & colors() const;

    /**
     * @return Pointer to the first color of the specified triangle.
     */
    const Color3f * color(int n) const;

    /**
     * Clear the colors vector and assign new values.
     */
    bool setColors(const std::vector<Color3f> &values);

    /**
     * Add one or more normals, i.e., the vector is expected to be of length
     * 3 x n where n is an integer.
     */
    bool addColors(const std::vector<Color3f> &values);

    /**
     * Sanity checking function - is the mesh sane?
     * @return True if the Mesh object is sane and composed of the right number
     * of elements.
     */
    bool valid() const;

    /**
     * Clear all mesh data.
     * @return True on success.
     */
    bool clear();

    /**
     * Overloaded operator.
     */
    Mesh& operator=(const Mesh& other);

    /**
     * Set the name of the Mesh.
     */
    void setName(QString name) { m_name = name; }

    /**
     * @return The name of the Mesh.
     */
    QString name() { return m_name; }

    /**
     * Provides locking.
     */
    QReadWriteLock *lock() const;

    friend class Molecule;

  protected:
    std::vector<Eigen::Vector3f> m_vertices;
    std::vector<Eigen::Vector3f> m_normals;
    std::vector<Color3f> m_colors;
    QString m_name;
    bool m_stable;
    float m_isoValue;
    unsigned int m_other; // Unique id of the other mesh if this is part of a pair
    unsigned int m_cube; // Unique id of the cube this mesh was generated from
    QReadWriteLock *m_lock;
    Q_DECLARE_PRIVATE(Mesh)
  };
} // End namespace Avogadro

 #endif
