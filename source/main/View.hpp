#pragma once
// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
#include <vector>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;
#include "common/objloader.hpp"
#include "common/vboindexer.hpp"
#include <glm/gtx/transform.hpp>
#include "common/shader.hpp"
#include "common/controls.hpp"
#include "common/text2D.hpp"

class View {
private:

	GLuint vertexbuffer;//wall 1
	GLuint colorbuffer;

	GLuint vertexbuffer1;//wall 2
	GLuint colorbuffer1;

	GLuint vertexbuffer2;//wall 3
	GLuint colorbuffer2;

	GLuint vertexbuffer3;//wall 4
	GLuint colorbuffer3;

	GLuint vertexbuffer4;//wall 5
	GLuint colorbuffer4;

	GLuint vertexbuffer5;//wall 6
	GLuint colorbuffer5;

	GLuint vertexbuffer6;//wall 7
	GLuint colorbuffer6;

	GLuint vertexbuffer7;//plane
	GLuint colorbuffer7;

	GLuint vertexbuffer8;//player
	GLuint colorbuffer8;


	GLuint Texture;
	GLuint TextureID;
	GLuint uvbuffer;


	GLFWwindow* window;

	GLuint programID;
	GLuint MatrixID1;


	GLuint VertexArrayID;//wall 1
	GLuint VertexArrayID1;//wall 2
	GLuint VertexArrayID2;//wall 3
	GLuint VertexArrayID3;//wall 4
	GLuint VertexArrayID4;//wall 5
	GLuint VertexArrayID5;//wall 6
	GLuint VertexArrayID6;//wall 7
	GLuint VertexArrayID7;//plane
	GLuint VertexArrayID8;//player


	// Read our .obj file

	std::vector<glm::vec3> vertices;//wall 1
	std::vector<glm::vec3> vertices1;//wall 2
	std::vector<glm::vec3> vertices2;//wall 3
	std::vector<glm::vec3> vertices3;//wall 4
	std::vector<glm::vec3> vertices4;//wall 5
	std::vector<glm::vec3> vertices5;//wall 6
	std::vector<glm::vec3> vertices6;//wall 7
	std::vector<glm::vec3> vertices7;//plane
	std::vector<glm::vec3> vertices8;//player

	std::vector<glm::vec3> colorsforvertices;//wall 1
	std::vector<glm::vec3> colorsforvertices1;//wall 2
	std::vector<glm::vec3> colorsforvertices2;//wall 3
	std::vector<glm::vec3> colorsforvertices3;//wall 4
	std::vector<glm::vec3> colorsforvertices4;//wall 5
	std::vector<glm::vec3> colorsforvertices5;//wall 6
	std::vector<glm::vec3> colorsforvertices6;//wall 7
	std::vector<glm::vec3> colorsforvertices7;//plane
	std::vector<glm::vec3> colorsforvertices8;//player

	std::vector<glm::vec2> uvs; // wall 1
	std::vector<glm::vec2> uvs1; //wall 2
	std::vector<glm::vec2> uvs2; //wall 3
	std::vector<glm::vec2> uvs3; //wall 4
	std::vector<glm::vec2> uvs4; //wall 5
	std::vector<glm::vec2> uvs5; //wall 6
	std::vector<glm::vec2> uvs6; //wall 7
	std::vector<glm::vec2> uvs7; //plane
	std::vector<glm::vec2> uvs8; // player

	std::vector<glm::vec3> normals; // wall 1
	std::vector<glm::vec3> normals1; // wall 2
	std::vector<glm::vec3> normals2; // wall 3
	std::vector<glm::vec3> normals3; // wall 4
	std::vector<glm::vec3> normals4; // wall 5
	std::vector<glm::vec3> normals5; // wall 6
	std::vector<glm::vec3> normals6; // wall 7
	std::vector<glm::vec3> normals7; // plane
	std::vector<glm::vec3> normals8; // player

	bool plane;
	bool wall_1;
	bool wall_2;
	bool wall_3;
	bool wall_4;
	bool wall_5;
	bool wall_6;
	bool wall_7;
	bool player;

	//screen size
	int width;
	int height;





public:
	View(int widtht, int heightt);
	~View();
	int initialise();
	void update();


};

