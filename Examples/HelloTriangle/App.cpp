#define FR_ENTRY_POINT
#include <glad/glad.h>
#include <OpenGL-Framework.h>

using namespace GLFramework;

uint32_t VBO;
uint32_t IBO;
uint32_t VAO;

void GLFramework::OnCreate()
{
	float vertices[]
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	uint32_t indices[]
	{
		0, 1, 2
	};

	// create and bind vertex array
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// create and bind vertex buffer
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// create and bind index buffer
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

	// shaders
	const char* vertexShaderSource = R"(

	layout(location = 0) in vec4 position;

	void main()
	{
		gl_Position = position;
	}
)";

	const char* fragmentShaderSource = R"(

	out vec4 outColor;

	void main()
	{
		outColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	}

	)";

	// create shaders
	uint32_t program = glCreateProgram();
	uint32_t vshader = glCreateShader(GL_VERTEX_SHADER);
	uint32_t fshader = glCreateShader(GL_FRAGMENT_SHADER);

	// compile vertex shader
	glShaderSource(vshader, 1, &vertexShaderSource, NULL);
	glCompileShader(vshader);

	int success;
	char infoLog[512];
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vshader, 512, NULL, infoLog);
		ASSERT(false, "FAILED TO COMPILE VERTEX SHADER. ERROR: {0}", infoLog);
	}

	// compile fragment shader
	glShaderSource(fshader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fshader);

	glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fshader, 512, NULL, infoLog);
		ASSERT(false, "FAILED TO COMPILE FRAGMENT SHADER. ERROR: {0}", infoLog);
	}

	// link program
	glAttachShader(program, vshader);
	glAttachShader(program, fshader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		ASSERT(false, "FAILED TO LINK SHADER PROGRAM. ERROR: {0}", infoLog);
	}

	glDeleteShader(vshader);
	glDeleteShader(fshader);

	// use the shader
	glUseProgram(program);
}

void GLFramework::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

void GLFramework::OnEvent()
{
}

void GLFramework::OnDestroy()
{
}