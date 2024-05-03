
#include <./include/GameObject.h>

using namespace gpp; // GPP namespace

GameObject::GameObject(TYPE type)
{
    // Copy the Cube contents into GameObject
    memcpy(this->vertex, vertices, sizeof(this->vertex));
    memcpy(this->colour, colours, sizeof(this->colour));
    memcpy(this->uv, uvs, sizeof(this->uv));

    // Copy UV's to all faces
    for (int i = 1; i < 6; i++)
        memcpy(&uv[i * 4 * 2], &uv[0], 2 * 4 * sizeof(GLfloat));

    memcpy(this->index, indices, sizeof(this->index));

    this->type = type;

    // Initialize MVP matrix as Identity Matrix
	this->mvp = mat4(
		1.0f // Identity Matrix
	);

    // Initialize Model matrix as Identity Matrix
	this->model = mat4(
		1.0f // Identity Matrix
	);
}

GameObject::~GameObject()
{
    delete this;
}

string GameObject::enumToString()
{
    switch (this->type)
    {
    case TYPE::RED:
        return "RED GameObject";
    case TYPE::BLUE:
        return "BLUE GameObject";
    case TYPE::GREEN:
        return "GREEN GameObject";
    case TYPE::WIN:
        return "WIN GameObject";
    default:
        return "Unknown GameObject";
    }
}