#include <windows.h>
#include <GL/glew.h>
#include "GlobalVars.h"
#include <GL/GL.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include "Player.h"
#include "Maths.h"
#include <thread>

GLfloat light_position[] = { 10.0, 10.0, 10.0, .5 };
int screenWidth;
int screenHeight;
Player player;
std::vector<maths::Vertex> vertices;
Chunk testchunk = Chunk();

std::vector<GLuint> indices;
maths::point3 position;
maths::point3 center;
float angle;
float upangle;
POINT p;
auto start_time = std::clock();
double Time;

Mesh cubemesh;
//Physics physics = Physics(-9.807);//moon is -1.622	mars is -3.711

void initSettings()
{
	for (int i = 0; i < 17; i++) {
		//SettingButtons[i] = Button();
	}
}

std::string readFile(const char *filePath) {
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);

	if (!fileStream.is_open()) {
		std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
		return "";
	}

	std::string line = "";
	while (fileStream.good()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
		//std::cout << line;
	}

	fileStream.close();
	return content;
}


GLuint LoadShader(const char *vertex_path, const char *fragment_path) {
	GLuint vertShader;
	vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader;
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Read shaders
	std::string vertShaderStr = readFile(vertex_path);
	std::string fragShaderStr = readFile(fragment_path);
	const char *vertShaderSrc = vertShaderStr.c_str();
	const char *fragShaderSrc = fragShaderStr.c_str();

	GLint result = GL_FALSE;
	int logLength;

	// Compile vertex shader
	std::cout << "Compiling vertex shader." << std::endl;
	glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
	glCompileShader(vertShader);

	// Check vertex shader
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
	std::cout << &vertShaderError[0] << std::endl;

	// Compile fragment shader
	std::cout << "Compiling fragment shader." << std::endl;
	glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
	glCompileShader(fragShader);

	// Check fragment shader
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
	std::cout << &fragShaderError[0] << std::endl;

	std::cout << "Linking program" << std::endl;
	GLuint program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> programError((logLength > 1) ? logLength : 1);
	glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
	std::cout << &programError[0] << std::endl;
	return program;
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}


int CalculateFrameRate()
{
	static float framesPerSecond = 0.0f;
	static float lastTime = 0.0f;
	float currentTime = GetTickCount() * 0.001f;
	++framesPerSecond;
	if (currentTime - lastTime > 1.0f)
	{
		lastTime = currentTime;
		int FPS = (int)framesPerSecond;
		framesPerSecond = 0;
		fps = FPS;
		return FPS;
	}
}

void ManageGame() 
{
	//chunkmanager.DisplayAllChunks();
	std::clock_t end_time = std::clock();
	//std::cout<<1000.0 * (end_time-start_time) / CLOCKS_PER_SEC<<std::endl;
	Time = 1000 * (end_time - start_time) / CLOCKS_PER_SEC;
	start_time = std::clock();
	if (GetAsyncKeyState(VK_ESCAPE)) {
		in_game = false;
	}
	CalculateFrameRate();
		GetCursorPos(&p);
		ScreenToClient(hwnd, &p);
		angle = -p.x;
		upangle = -p.y;
	if (GetAsyncKeyState('W')) {
		float XMove;
		float ZMove;
		XMove = (Time / 20) * .1 * sin((angle * 3.14159265358979323846) / 180);
		ZMove = (Time / 20) * .1 * cos((angle * 3.14159265358979323846) / 180);

		position.x += XMove;
		position.z += ZMove;	
	}
	if (GetAsyncKeyState('S')) {
		float XMove;
		float ZMove;
		XMove = (Time / 20) * -.1 * sin((angle * 3.14159265358979323846) / 180);
		ZMove = (Time / 20) * -.1 * cos((angle * 3.14159265358979323846) / 180);

		position.x += XMove;
		position.z += ZMove;
	}
	if (GetAsyncKeyState('A')) {
		float XMove;
		float ZMove;
		XMove = (Time / 20) * .1 * sin(((angle + 90) * 3.14159265358979323846) / 180);
		ZMove = (Time / 20) * .1 * cos(((angle + 90) * 3.14159265358979323846) / 180);

		position.x += XMove;
		position.z += ZMove;
	}
	if (GetAsyncKeyState('D')) {
		float XMove;
		float ZMove;
		XMove = (Time / 20) * -.1 * sin(((angle + 90) * 3.14159265358979323846) / 180);
		ZMove = (Time / 20) * -.1 * cos(((angle + 90) * 3.14159265358979323846) / 180);

		position.x += XMove;
		position.z += ZMove;
	}
	if (GetAsyncKeyState(VK_SPACE)) {
		position.y += .05;
	}
	if (GetAsyncKeyState(VK_LSHIFT)) {
		position.y -= .05;
	}
	center.x = ((sin(((angle * 3.14159265358979323846) / 180)) + position.x) * 1);
	center.z = ((cos(((angle * 3.14159265358979323846) / 180)) + position.z) * 1);
	center.y = (tan(((upangle * 3.14159265358979323846) / 180))) + position.y;
	gluLookAt(position.x, position.y, position.z, center.x, center.y, center.z, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//player.Update();
	//physics.Update();
	cubemesh.Update();
	hud.Enable2D(true);
	hud.DisplayValue("FPS: ", fps, 2, 10);
	hud.Enable2D(false);
}

void ManageMenu()
{
	//physics.Update(1/60);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, screenWidth, screenHeight, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	//BackGround.Bind();
	//glBegin(GL_QUADS);
	glDisable(GL_LIGHTING);
	PlayButton.DrawButton();
	ExitButton.DrawButton();
	SettingsButton.DrawButton();
	//glEnable(GL_LIGHTING);
	if (PlayButton.IsPressed(hwnd))
	{
		in_game = true;
		glUseProgram(program);
	}
	else {
		glUseProgram(0);
	}
	if (SettingsButton.IsPressed(hwnd))
	{

	}
	if (ExitButton.IsPressed(hwnd))
	{
		glutDestroyWindow(1);
	}
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(1, timer, 0);
}

void initGL(){
	//physics.AddObject(btScalar(1), btVector3(1, 1, 1), btScalar(10), btVector3(0, -1, 0), CollisionTypes::box);
	glewInit();
	glfwWindowHint(GLFW_SAMPLES, 4);
	char result[MAX_PATH];
	uint32_t found;
	GetModuleFileName(NULL, result, MAX_PATH);
	found = std::string(result).find_last_of("\\");
	std::string path = (std::string(result).substr(0, found) + "\\");
	program = LoadShader((path + "shaders\\VertexShader.shader.txt").c_str(), ((path +  "shaders\\FragmentShader.shader.txt").c_str()));
	//glUseProgram(program);
	player.SetPos(0, 0, 0);
	player.SetAngle(0, 0, 0);
	player.Update();
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glFrontFace(GL_CCW);
	PlayButton.LoadButtonTex((path + "textures\\play.bmp").c_str());
	ExitButton.LoadButtonTex((path + "textures\\exit.bmp").c_str());
	SettingsButton.LoadButtonTex((path + "textures\\settings.bmp").c_str());
	glClearColor(.8, .8, 1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GLUT_MULTISAMPLE);//0x809D
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	settings.SetVSync(true);
	settings.SetFOV(70);
	//glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glColor3f(1, 1, 1);

	if (!in_game) {
		//glUseProgram(0);
		ManageGame();
	}
	else {
		//glUseProgram(program);
		ManageGame();
	}

	glLoadIdentity();
	if (glutGetWindow() == NULL) {
		return;
	}
	glutSwapBuffers();

}

void reshape(GLsizei width, GLsizei height)
{
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(settings.GetFOV(), aspect, 0.01f, 500.0f);
}

int main(int argc, char** argv)
{
	//ShowWindow(FindWindow("ConsoleWindowClass", NULL), false);
	glutInit(&argc, argv);
	screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	GenChunk chunkgen = GenChunk();
	unsigned int seed;
	seed = time(nullptr);
	std::cout << "seed: " << seed << std::endl;
	std::clock_t start;
	double duration;
	start = std::clock();
	//std::thread t1(&GenChunk::GenerateChunk, &chunkgen,1, 1, seed);
	//t1.join();
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "time: " << duration << '\n';
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_MULTISAMPLE);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(0, 0);
	chunkgenerator.GenerateChunk(1, 1, time(NULL));

	glutCreateWindow("SOMETHING");
	hwnd = FindWindow(NULL, "SOMETHING");
	long dwStyle;
	dwStyle = GetWindowLong(hwnd, GWL_STYLE);
	dwStyle ^= WS_SIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, dwStyle);
	std::cout<<"window created"<<std::endl;
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	testchunk = chunkgenerator.chunk;
	testchunk.GenMesh();
	std::cout << "test: " << testchunk.m_Indices.size() << std::endl;
	cubemesh = Mesh(testchunk.m_Vertices, testchunk.m_Indices);
	std::cout<<"textures loaded"<<std::endl;
	glutTimerFunc(1, timer, 0);
	glutMainLoop();
	return 0;
}
