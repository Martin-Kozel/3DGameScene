#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

using namespace gpp;
using namespace glm;
using namespace std;

class Enemy : public GameObject {

public:

	~Enemy();
	Enemy(TYPE type, float positionZ);

	bool checkCollision(GameObject* object);

	vec3 getPosition();
	void setPosition(vec3 position);
	mat4 getModelMatrix();
	void setModelMatrix(mat4 model);
	mat4 getMVPMatrix();
	void setMVPMatrix(mat4 model);
	GLfloat* getVertex();
	int getVertexCount();
	GLfloat* getColor();
	int getColorCount();
	GLfloat* getUV();
	int getUVCount();
	GLfloat* getIndex();
	int getIndexCount();

	TYPE getType();

	void update(double dt);

	void setOriginalPosition();

	void moveRight() {}
	void moveLeft() {}

	void setDrawable(bool r);
	bool drawable();

private:

	vec3 start; // starting position
	bool isDrawable{ true };
	GLfloat* colour;

};

#endif