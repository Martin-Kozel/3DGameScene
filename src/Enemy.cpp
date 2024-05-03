#include <./include/Enemy.h>

Enemy::~Enemy()
{
}

Enemy::Enemy(TYPE type, float positionZ) : GameObject(type)
{
    switch (type)
    {
    case gpp::TYPE::RED:
        this->position = vec3(0.0f, 0.0f, -10.0f - positionZ);
        break;
    case gpp::TYPE::BLUE:
        this->position = vec3(-4.0f, 0.0f, -10.0f - positionZ);
        break;
    case gpp::TYPE::GREEN:
        this->position = vec3(4.0f, 0.0f, -10.0f - positionZ);
        break;
    case gpp::TYPE::WIN:
        this->position = vec3(0.0f, 0.0f, -20.0f - positionZ);
        break;
    default:
        break;
    }
    this->start = this->position;
}



bool Enemy::checkCollision(GameObject* object)
{
    vec3 position1 = object->getPosition();
    vec3 position2 = this->getPosition();

    // Calculate the distances between the centers of the two cubes
    float distanceX = abs(position1.x - position2.x);
    float distanceY = abs(position1.y - position2.y);
    float distanceZ = abs(position1.z - position2.z);

    // Calculate the minimum distance needed for collision
    float minimumDistance = 2.0f; // Sum of the lengths of the sides of two cubes

    // Check if the cubes are colliding
    if (distanceX < minimumDistance && distanceY < minimumDistance
        && distanceZ < minimumDistance)
    {
        if (this->getType() != object->getType())
        {
            return true; // Collision detected
        }
    }

    return false; // No collision detected
}

vec3 Enemy::getPosition()
{
    return position;
}

void Enemy::setPosition(vec3 position)
{
    this->position = position;
    model = glm::translate(glm::mat4(1.0f), position);
}

mat4 Enemy::getModelMatrix() 
{ 
    return this->model; 
}

void Enemy::setModelMatrix(mat4 model) 
{ 
    this->model = model; 
}

mat4 Enemy::getMVPMatrix() 
{ 
    return this->mvp; 
}

void Enemy::setMVPMatrix(mat4 mvp) 
{ 
    this->mvp = mvp; 
}

GLfloat* Enemy::getVertex() 
{ 
    return this->vertex; 
}

int Enemy::getVertexCount() 
{ 
    return ARRAY_SIZE(vertex) / 3; 
}

GLfloat* Enemy::getColor() 
{ 
    return this->colour; 
}

int Enemy::getColorCount() 
{ 
    return ARRAY_SIZE(colours) / 4; 
}

GLfloat* Enemy::getUV() 
{ 
    return this->uv; 
}

int Enemy::getUVCount() 
{ 
    return ARRAY_SIZE(uv); 
}

GLfloat* Enemy::getIndex() 
{ 
    return this->index; 
}

int Enemy::getIndexCount() 
{ 
    return ARRAY_SIZE(index) / 3; 
}

TYPE Enemy::getType() 
{ 
    return type; 
}


void Enemy::update(double dt)
{
    vec3 translationVector(0.0f, 0.0f, 20.0f*dt);
    this->setModelMatrix(translate(this->getModelMatrix(), this->getPosition()));
    this->setModelMatrix(translate(this->getModelMatrix(), translationVector));
    this->setPosition(this->getPosition() + translationVector);


    if (this->position.z > 10)
    {
        isDrawable = false;
    }
}

void Enemy::setOriginalPosition()
{
    this->position = this->start;
}
void Enemy::setDrawable(bool r)
{
    isDrawable = r;
}
bool Enemy::drawable()
{
    return isDrawable;
}