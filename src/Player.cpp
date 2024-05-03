#include <./include/Player.h>


Player::~Player()
{
    delete this;
}

Player::Player(TYPE type) : GameObject(type)
{
    switch (type)
    {
    case gpp::TYPE::RED:
        this->position = vec3(0.0f, 0.0f, -10.0f);
        break;
    case gpp::TYPE::BLUE:
        this->position = vec3(-4.0f, 0.0f, -10.0f);
        break;
    case gpp::TYPE::GREEN:
        this->position = vec3(4.0f, 0.0f, -10.0f);
        break;
    case gpp::TYPE::WIN:
        this->position = vec3(-4.0f, 0.0f, -10.0f);
        break;
    default:
        break;
    }
}

bool Player::checkCollision(GameObject* obj)
{
    vec3 pos1 = obj->getPosition();
    vec3 pos2 = this->getPosition();

    // Calculate the distances between the centers of the two cubes
    float XDistance = abs(pos1.x - pos2.x);
    float YDistance = abs(pos1.y - pos2.y);
    float ZDistance = abs(pos1.z - pos2.z);

    // Calculate the minimum distance needed for collision
    float minDist = 2.0f; // Sum of the lengths of the sides of two cubes

    // Check if the cubes are colliding
    if (XDistance < minDist && YDistance < minDist && ZDistance < minDist)
    {
        if (this->getType() != obj->getType()) 
        {
            // Check if the collision is with an enemy cube
            if (dynamic_cast<Player*>(obj) != nullptr) 
            {
                std::cout << "Game Over!" << std::endl;
            }
            return true; // Collision detected
        }
        else if (this->getType() == gpp::TYPE::WIN) 
        {
            std::cout << "You Win!" << std::endl;
            return true; // Collision detected
        }
    }
    return false; // No collision detected
}

vec3 Player::getPosition()
{
    return position;
}

void Player::setPosition(vec3 position)
{
    this->position = position;
    model = glm::translate(glm::mat4(1.0f), position);
}

mat4 Player::getModelMatrix() 
{ 
    return this->model; 
}

void Player::setModelMatrix(mat4 model) 
{ 
    this->model = model; 
}

mat4 Player::getMVPMatrix() 
{ 
    return this->mvp; 
}

void Player::setMVPMatrix(mat4 mvp) 
{ 
    this->mvp = mvp; 
}

GLfloat* Player::getVertex() 
{ 
    return this->vertex; 
}

int Player::getVertexCount() 
{ 
    return ARRAY_SIZE(vertex) / 3; 
}

GLfloat* Player::getColor() 
{ 
    return this->colour; 
}

int Player::getColorCount() 
{ 
    return ARRAY_SIZE(colours) / 4; 
}

GLfloat* Player::getUV() 
{ 
    return this->uv; 
}

int Player::getUVCount() 
{ 
    return ARRAY_SIZE(uv); 
}

GLfloat* Player::getIndex() 
{ 
    return this->index; 
}

int Player::getIndexCount() 
{ 
    return ARRAY_SIZE(index) / 3; 
}

TYPE Player::getType() 
{ 
    return type;
}

bool Player::isAlive()
{
    return lives;
}

void Player::isNotAlive()
{
    lives = false;
}

void Player::update(double dt)
{
    this->dt=dt;
}

void Player::moveRight()
{
    if (lives)
    {
        this->setModelMatrix(translate(this->getModelMatrix(), glm::vec3(playerSpeed *dt, 0.0f, 0.0f)));
        this->setPosition(this->getPosition() + vec3(playerSpeed *dt, 0.0f, 0.0f));
        std::cout << "PLAYER MOVED RIGHT" << std::endl;
    }

}

void Player::moveLeft()
{
    if (lives)
    {
        this->setModelMatrix(translate(this->getModelMatrix(), glm::vec3(-playerSpeed *dt, 0.0f, 0.0f)));
        this->setPosition(this->getPosition() + vec3(-playerSpeed *dt, 0.0f, 0.0f));
        std::cout << "PLAYER MOVED LEFT" << std::endl;
    }

}