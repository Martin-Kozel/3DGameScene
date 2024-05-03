#ifndef GAME_H // If the macro GAME_H is not defined
#define GAME_H // Define the macro GAME_H to prevent multiple inclusions of this header file

const int GAME_OBJECTS	= 2;	// Total Number of GamesObjects

// Include necessary standard library headers
#include <string>   // For string manipulation
#include <sstream>  // For string streams
#include <iostream> // For standard input and output operations
#include <fstream> //for reading from file


// Include OpenGL and GLEW headers
#include <GL/glew.h>         // OpenGL Extension Wrangler Library
#include <SFML/Graphics.hpp> // Simple and Fast Multimedia Library (Graphics module)
#include <SFML/OpenGL.hpp>   // OpenGL extension for SFML

// Include GLM headers for mathematics library
#include <glm/glm.hpp>                  // OpenGL Mathematics
#include <glm/gtc/matrix_transform.hpp> // Matrix transformations
#include <glm/gtx/string_cast.hpp>      // String Operations

// Include custom headers
#include <./include/Debug.h>      // Debugging utilities
#include <./include/Player.h>
#include <./include/Enemy.h>
#include <./include/GameObject.h>

#include <vector>
// Using directives to avoid typing std::, sf::, and glm:: prefixes
using namespace std; // Standard C++ namespace
using namespace sf;  // SFML namespace
using namespace glm; // GLM namespace
using namespace gpp; // GPP namespace

class Game
{
public:
    Game(sf::ContextSettings settings); // Constructor with SFML context settings
    ~Game(); // Destructor
    void run(); // Method to run the game

private:
    RenderWindow window;         // SFML RenderWindow for rendering graphics
    Clock clock;                 // SFML Clock for timing
    Time time;                   // SFML Time for time-related operations
    bool isRunning = false;      // Flag to track game state
    void initialise(); // Method to initialize the game
    void update(); // Method to update the game state
    void render(); // Method to render the game
    void unload(); // Method to clean up resources
    void renderObject(GameObject* obj);
    void reinitialise();
    void restart();
    vector<Enemy*> enemies;
    Player* player;
    Time deltaTime;


    char* readFile(std::string filename);


};

#endif // GAME_H
