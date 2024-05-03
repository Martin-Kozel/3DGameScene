#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace gpp;
using namespace glm;
using namespace std;

class Player : public GameObject
{
public:

	~Player();
	Player(TYPE type);

	bool checkCollision(GameObject* obj);

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

	bool isAlive();
	void isNotAlive();

	void update(double dt);

	void moveRight();
	void moveLeft();

private:

	bool lives{ true };
	double dt;
	const float playerSpeed = 800.0f;
};

#endif
