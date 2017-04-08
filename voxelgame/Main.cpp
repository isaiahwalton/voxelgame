#include <windows.h>
#include <GL/glew.h>
#include <noise.h>
#include <GL/GL.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include "Hud.h"
#include "GLShader.h"
#include "Settings.h"
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "ChunkManager.h"
#include "Button.h"

std::string WorldName;
ChunkManager chunkmanager = ChunkManager(WorldName);
Hud hud;
Button PlayButton = Button(320, 104, 96, 192);
Button ExitButton = Button(320, 240, 96, 192);
Texture BackGround = Texture();
HWND hwnd;
bool in_game = false;

int CalculateFrameRate()
{
	static float framesPerSecond = 0.0f;
	static float lastTime = 0.0f;
	float currentTime = GetTickCount() * 0.001f;
	++framesPerSecond;
	if (currentTime - lastTime > 1.0f)
	{
		lastTime = currentTime;
		//std::cout<<"fps: "<<(int)framesPerSecond<<std::endl;
		int fps = (int)framesPerSecond;
		framesPerSecond = 0;
		return fps;
	}
}

void ManageGame() 
{
	chunkmanager.DisplayAllChunks();
	hud.Enable2D(true);
	hud.DisplayValue("FPS: ", CalculateFrameRate(), 5, 5);
	hud.Enable2D(false);
}

void ManageMenu()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	//BackGround.Bind();
	//glBegin(GL_QUADS);
	glDisable(GL_LIGHTING);
	PlayButton.DrawButton();
	ExitButton.DrawButton();
	glEnable(GL_LIGHTING);
	if (PlayButton.IsPressed(hwnd))
	{
		in_game = true;
	}
	if (ExitButton.IsPressed(hwnd))
	{
		exit(0);
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
	glewInit();
	GLfloat light_position[] = { 10.0, 10.0, 10.0, 0 };
	glfwWindowHint(GLFW_SAMPLES, 4);

	char result[MAX_PATH];
	uint32_t found;
	GetModuleFileName(NULL, result, MAX_PATH);
	found = std::string(result).find_last_of("\\");
	std::string path = (std::string(result).substr(0, found) + "\\");
	GLuint program = LoadShader((path + "shaders\\VertexShader.shader.txt").c_str(), ((path +  "shaders\\FragmentShader.shader.txt").c_str()));
	glUseProgram(program);

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	PlayButton.LoadButtonTex((path + "textures\\play.bmp").c_str());
	ExitButton.LoadButtonTex((path + "textures\\exit.bmp").c_str());
	glClearColor(0, 0, 0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GLUT_MULTISAMPLE);//0x809D
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	settings::setVSync(true);
	//settings::setFOV(70);
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(0.5, 0.5, 0.0);
	glRotatef(180, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, -0.5, 0.0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	if(GetAsyncKeyState(VK_ESCAPE)){
		glutPositionWindow(50, 50);
		glutReshapeWindow(640, 480);
	}
	//
	if (!in_game) {
		ManageMenu();
	}
	else {
		ManageGame();
	}
	glLoadIdentity();
	glutSwapBuffers();

	if (glutGetWindow() == NULL) {
		return;
	}
}

void reshape(GLsizei width, GLsizei height)
{
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(70, aspect, 0.01f, 500.0f);
   if ((glutGet(GLUT_WINDOW_HEIGHT) != glutGet(GLUT_SCREEN_HEIGHT)) || (glutGet(GLUT_WINDOW_WIDTH) != glutGet(GLUT_SCREEN_WIDTH))) {
	   glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
   }
}
int main(int argc, char** argv)
{

	//Physics physics(0,-9.81,0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_MULTISAMPLE);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
	glutInitWindowPosition(0, 0);
	glutCreateWindow("SOMETHING");
	hwnd = FindWindow(NULL, "SOMETHING");
	SetWindowLong(hwnd, GWL_STYLE, (GetWindowLong(hwnd, GWL_STYLE) | WS_MAXIMIZE));
	ShowWindowAsync(hwnd, SW_SHOWMAXIMIZED);
	std::cout<<"window created"<<std::endl;
	//ShowWindow(FindWindow("ConsoleWindowClass", NULL), false);
	//glutFullScreen();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	//BackGround.Load("textures\\menubackground.bmp");

	std::cout<<"textures loaded"<<std::endl;
	glutTimerFunc(1, timer, 0);
	glutMainLoop();
	return 0;
}