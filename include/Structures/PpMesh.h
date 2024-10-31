//
// Created by Roger on 09/10/2024.
//

#ifndef MODEL3D_H
#define MODEL3D_H

#include "KMeshBase.h"
#include <vector>

#include "assimp/mesh.h"

// Mesh para pipeline programable
struct PpMesh : kMeshBase
{
public:
    static GLuint dataValsInVBO;

    explicit PpMesh(const aiMesh* mesh);
    ~PpMesh();

    void Render(const Shader* shaderProgram) const override;
    void Render(GLuint shaderProgram) const override;

    std::vector<GLfloat> mainData;
    std::vector<GLuint> indices;
    std::vector<GLfloat> UVs;
    

    GLuint texture_id = 0; // ID de textura a aplicar

private:

    void SetUpMesh();

    static void GenerateBuffer(GLenum type, GLuint& bufferID, const void* data, GLsizeiptr dataSize, GLenum usage);
    
};

#endif //MODEL3D_H