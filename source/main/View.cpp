#include "View.hpp"
#include "common/texture.hpp"
#include <vector>

#include "common/objloader.hpp"

#include <iostream>
#include "glm/ext.hpp"


View::View(int widtht, int heightt) {
	width = widtht;
	height = heightt;

}
View::~View() {

}
glm::mat4 getMVPMatrix(glm::mat4 ProjectionMatrix, glm::mat4 ViewMatrix, glm::mat4 ModelMatrix) {

	glm::mat4 Projection = ProjectionMatrix;

	glm::mat4 View = ViewMatrix;
	//std::cout << glm::to_string(View) << std::endl;
	


	glm::mat4 Model = ModelMatrix;

	glm::mat4 mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around

	return mvp;

}



int View::initialise() {

	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	// Open a window and create its OpenGL context
	window = glfwCreateWindow(width, height, "My Game", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Ensure we can capture the escape key being pressed below

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Hide the mouse and enable unlimited mouvement

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set the mouse at the center of the screen

	glfwPollEvents();

	glfwSetCursorPos(window, width / 2, height / 2);


	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);



	// Initialize GLEW										
	glewExperimental = true; // Needed for core profile
	
	//-------------------

	wall_1 = loadOBJ("wall_1.obj", vertices, uvs, normals);
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	for (int i = 0;i < vertices.size();i++) {
		colorsforvertices.push_back(glm::vec3(1, 0, 0));
	

		glGenBuffers(1, &colorbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glBufferData(GL_ARRAY_BUFFER, colorsforvertices.size() * sizeof(glm::vec3), &colorsforvertices[0], GL_STATIC_DRAW);

		//----------------------------------

	wall_2 = loadOBJ("wall_2.obj", vertices1, uvs1, normals1);

	glGenBuffers(1, &vertexbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
	glBufferData(GL_ARRAY_BUFFER, vertices1.size() * sizeof(glm::vec3), &vertices1[0], GL_STATIC_DRAW);


	for (int i = 0;i < vertices1.size();i++) {
		colorsforvertices1.push_back(glm::vec3(1, 0, 0));
	}



	glGenBuffers(1, &colorbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer1);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices1.size() * sizeof(glm::vec3), &colorsforvertices1[0], GL_STATIC_DRAW);


	//------------------

	wall_3 = loadOBJ("wall_3.obj", vertices2, uvs2, normals2);

	glGenBuffers(1, &vertexbuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
	glBufferData(GL_ARRAY_BUFFER, vertices2.size() * sizeof(glm::vec3), &vertices2[0], GL_STATIC_DRAW);


	for (int i = 0;i < vertices2.size();i++) {
		colorsforvertices2.push_back(glm::vec3(1, 0, 0));
	}



	glGenBuffers(1, &colorbuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer2);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices2.size() * sizeof(glm::vec3), &colorsforvertices2[0], GL_STATIC_DRAW);


	//-----------------------

	wall_4 = loadOBJ("wall_4.obj", vertices3, uvs3, normals3);

	glGenBuffers(1, &vertexbuffer3);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);
	glBufferData(GL_ARRAY_BUFFER, vertices3.size() * sizeof(glm::vec3), &vertices3[0], GL_STATIC_DRAW);


	for (int i = 0;i < vertices3.size();i++) {
		colorsforvertices3.push_back(glm::vec3(1, 0, 0));
	}



	glGenBuffers(1, &colorbuffer3);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer3);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices3.size() * sizeof(glm::vec3), &colorsforvertices3[0], GL_STATIC_DRAW);


	//-----------------------

	wall_5 = loadOBJ("wall_5.obj", vertices4, uvs4, normals4);

	glGenBuffers(1, &vertexbuffer4);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer4);
	glBufferData(GL_ARRAY_BUFFER, vertices4.size() * sizeof(glm::vec3), &vertices4[0], GL_STATIC_DRAW);


	for (int i = 0;i < vertices4.size();i++) {
		colorsforvertices4.push_back(glm::vec3(1, 0, 0));
	}



	glGenBuffers(1, &colorbuffer4);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer4);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices4.size() * sizeof(glm::vec3), &colorsforvertices4[0], GL_STATIC_DRAW);


	//-----------------------

	wall_6 = loadOBJ("wall_6.obj", vertices5, uvs5, normals5);

	glGenBuffers(1, &vertexbuffer5);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer5);
	glBufferData(GL_ARRAY_BUFFER, vertices5.size() * sizeof(glm::vec3), &vertices5[0], GL_STATIC_DRAW);


	for (int i = 0;i < vertices5.size();i++) {
		colorsforvertices5.push_back(glm::vec3(1, 0, 0));
	}



	glGenBuffers(1, &colorbuffer5);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer5);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices5.size() * sizeof(glm::vec3), &colorsforvertices5[0], GL_STATIC_DRAW);


	//-----------------------

	wall_7 = loadOBJ("wall_7.obj", vertices6, uvs6, normals6);

	glGenBuffers(1, &vertexbuffer6);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer6);
	glBufferData(GL_ARRAY_BUFFER, vertices6.size() * sizeof(glm::vec3), &vertices6[0], GL_STATIC_DRAW);


	for (int i = 0;i < vertices6.size();i++) {
		colorsforvertices6.push_back(glm::vec3(1, 0, 0));
	}



	glGenBuffers(1, &colorbuffer6);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer6);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices6.size() * sizeof(glm::vec3), &colorsforvertices6[0], GL_STATIC_DRAW);


	//-----------------------



	plane = loadOBJ("plane.obj", vertices7, uvs7, normals7);

	glGenBuffers(1, &vertexbuffer7);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer7);
	glBufferData(GL_ARRAY_BUFFER, vertices7.size() * sizeof(glm::vec3), &vertices7[0], GL_STATIC_DRAW);


	for (int i = 0;i < vertices7.size();i++) {
		colorsforvertices7.push_back(glm::vec3(1, 1, 0));
	}



	glGenBuffers(1, &colorbuffer7);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer7);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices7.size() * sizeof(glm::vec3), &colorsforvertices7[0], GL_STATIC_DRAW);


	//-----------------------

	player = loadOBJ("player.obj", vertices8, uvs8, normals8);

	glGenBuffers(1, &vertexbuffer8);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer8);
	glBufferData(GL_ARRAY_BUFFER, vertices8.size() * sizeof(glm::vec3), &vertices8[0], GL_STATIC_DRAW);


	for (int i = 0;i < vertices8.size();i++) {
		colorsforvertices8.push_back(glm::vec3(0, 1, 1));
	}



	glGenBuffers(1, &colorbuffer8);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer8);
	glBufferData(GL_ARRAY_BUFFER, colorsforvertices8.size() * sizeof(glm::vec3), &colorsforvertices8[0], GL_STATIC_DRAW);


	//-----------------------
	





	//std::cout << vertices.size() << std::endl;

	


	//glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	
	
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);



	//remove 1

	}

	
		

	programID = LoadShaders("SimpleVertexShader.hlsl", "SimpleFragmentShader.hlsl");
	MatrixID1 = glGetUniformLocation(programID, "MVP");

//remove 2
	return 1;
}

void View::update() {

	do {
		//-------------

			// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw nothing, see you in tutorial 2 !
		// Use our shader
		glUseProgram(programID);




		//--------------


		computeMatricesFromInputs(window, width, height);



		glm::mat4 mvp = getMVPMatrix(

			getProjectionMatrix(),

			getViewMatrix(),

			glm::mat4(1.0f));

		glUniformMatrix4fv(MatrixID1, 1, GL_FALSE, &mvp[0][0]);


		//----------------------------------------------------------

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer7);

		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer7);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices1.size() * sizeof(glm::vec3));



		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);

		//------------------------




		//glDisableVertexAttribArray(0);
		/*
		// Bind our texture in Texture Unit 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);

		// Set our "myTextureSampler" sampler to use Texture Unit 0
		glUniform1i(TextureID, 0);
		// 2nd attribute buffer : textures
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		
		*/






		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	
		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);



		// 2nd attribute buffer : colors
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);



		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices.size() * sizeof(glm::vec3));
		//glDrawArrays(GL_TRIANGLES, 0, vertices1.size() * sizeof(glm::vec3));
		


		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);


//---------------




		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);

		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer1);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices1.size() * sizeof(glm::vec3));



		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);
		

//----------------




		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);

		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer2);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices1.size() * sizeof(glm::vec3));



		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);


		//------------------------




		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);

		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer3);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices1.size() * sizeof(glm::vec3));



		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);

		//------------------------





		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer4);

		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer4);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices1.size() * sizeof(glm::vec3));



		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);

		//------------------------





		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer5);

		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer5);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices1.size() * sizeof(glm::vec3));



		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);

		//------------------------



		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer6);

		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer6);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices1.size() * sizeof(glm::vec3));



		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);

		//------------------------

	



		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer8);

		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the vertex shader.
			3,                  // size
			GL_FLOAT,     // type
			GL_FALSE,    // normalized?
			0,                   // stride
			(void*)0           // array buffer offset
		);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer8);
		//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles

		//glDrawArrays(GL_TRIANGLES, 0, vertices7.size() * sizeof(glm::vec3));



		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// The following code draws a triangle using the function void glDrawArrays(     GLenum mode,      GLint first,      GLsizei count);
		glDrawArrays(GL_TRIANGLES, 0, 36); // first vertex: 0, count: 1 triangle is drawn. 1 triangle x 3 vertices = 3

		glDisableVertexAttribArray(0);

		glDisableVertexAttribArray(1);

		//------------------------





		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

		
	} // Check if the ESC key was pressed or the window was closed

	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);




	// Cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &colorbuffer);

	glDeleteBuffers(1, &vertexbuffer1);
	glDeleteBuffers(1, &colorbuffer1);

	glDeleteBuffers(1, &vertexbuffer2);
	glDeleteBuffers(1, &colorbuffer2);

	glDeleteBuffers(1, &vertexbuffer3);
	glDeleteBuffers(1, &colorbuffer3);

	glDeleteBuffers(1, &vertexbuffer4);
	glDeleteBuffers(1, &colorbuffer4);

	glDeleteBuffers(1, &vertexbuffer5);
	glDeleteBuffers(1, &colorbuffer5);

	glDeleteBuffers(1, &vertexbuffer6);
	glDeleteBuffers(1, &colorbuffer6);

	glDeleteBuffers(1, &vertexbuffer7);
	glDeleteBuffers(1, &colorbuffer7);

	glDeleteBuffers(1, &vertexbuffer8);
	glDeleteBuffers(1, &colorbuffer8);



	glDeleteBuffers(1, &uvbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteVertexArrays(1, &VertexArrayID1);
	glDeleteVertexArrays(1, &VertexArrayID2);
	glDeleteVertexArrays(1, &VertexArrayID3);
	glDeleteVertexArrays(1, &VertexArrayID4);
	glDeleteVertexArrays(1, &VertexArrayID5);
	glDeleteVertexArrays(1, &VertexArrayID6);
	glDeleteVertexArrays(1, &VertexArrayID7);
	glDeleteVertexArrays(1, &VertexArrayID8);
	
	// Close OpenGL window and terminate GLFW
	glClear(GL_COLOR_BUFFER_BIT);

	

	glfwTerminate();
	

}
