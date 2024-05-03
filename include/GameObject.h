#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

// Define a macro for calculating the size of an array
#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

// Include necessary headers
#include <stdio.h>	// For standard input and output operations
#include <string.h> // For string manipulation (memcpy)
#include <string> 	// For string manipulation
#include <iostream>
// Include GLM headers for mathematics library
#include <glm/glm.hpp>					// OpenGL Mathematics
#include <glm/gtc/matrix_transform.hpp> // Matrix transformations

// Include custom header
#include <./include/Cube.h> // Header for Cube class

// Using directives to avoid typing glm:: prefix
using namespace glm;
using namespace std;

namespace gpp
{
	// GameObject Type
	enum class TYPE
	{
		RED,
		BLUE,
		GREEN,
		WIN
	};

	class GameObject
	{
	protected:
		// Cube Elements
		GLfloat vertex[ARRAY_SIZE(vertices)]; // Array of vertex positions
		GLfloat colour[ARRAY_SIZE(colours)];  // Array of vertex colours
		GLfloat uv[ARRAY_SIZE(uvs)];		  // Array of texture coordinates
		GLfloat index[ARRAY_SIZE(indices)];	  // Array of vertex indices

		// GameObject Attributes
		vec3 position; // Position of the game object in 3D space
		mat4 model;	   // Model Matrix for GameObject
		mat4 mvp;	   // Model View Project Matrix
		TYPE type;	   // GameOject Type
	public:
		virtual ~GameObject() = 0; // Pure virtual destructor
		GameObject(TYPE type);

		virtual bool checkCollision(GameObject* obj) = 0;
		virtual vec3 getPosition() = 0;
		virtual void setPosition(vec3 position) = 0;
		virtual mat4 getModelMatrix() = 0;
		virtual void setModelMatrix(mat4 model) = 0;
		virtual mat4 getMVPMatrix() = 0;
		virtual void setMVPMatrix(mat4 model) = 0;
		virtual GLfloat* getVertex() = 0;
		virtual int getVertexCount() = 0;
		virtual GLfloat* getColor() = 0;
		virtual int getColorCount() = 0;
		virtual GLfloat* getUV() = 0;
		virtual int getUVCount() = 0;
		virtual GLfloat* getIndex() = 0;
		virtual int getIndexCount() = 0;
		virtual std::string enumToString();
		//virtual void setColor(TYPE type);
		virtual void update(double dt) = 0;
		virtual void moveRight() = 0;
		virtual void moveLeft() = 0;
		virtual TYPE getType() = 0;
	};
}
#endif // GAME_OBJECT_H
