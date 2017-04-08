#include "Hud.h"

std::string Hud::double_to_string(double val)
{
	std::stringstream s;
	s << val;
	return s.str();
}

void Hud::DisplayText(int x, int y, std::string text , void* font)
{
	glColor3d(1, 1, 1);
	glRasterPos2i(x, y);
	for (std::string::iterator i = text.begin(); i != text.end(); ++i)
	{
	  char c = *i;
	  glutBitmapCharacter(font, c);
	}
}

void Hud::DisplayValue(std::string name, double val , double x, double y)
{
	Hud::DisplayText(x, y, name + double_to_string(val), (void*)3);
}

void Hud::Enable2D(bool enable)
{
	if(enable){
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho( 0, /*glutGet(GLUT_WINDOW_WIDTH)*/640, 480/*glutGet(GLUT_WINDOW_HEIGHT)*/  , 0, -1, 1 );
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
	}else if(!enable){
		glDisable(GL_TEXTURE_2D);
		glMatrixMode( GL_PROJECTION );
		glPopMatrix();
		glMatrixMode( GL_MODELVIEW );
		glPopMatrix();
	}
}

void Hud::DisplayBar(POINT center, updown UpDown, dim size, double val)
{
	glBegin(GL_QUADS);
	glEnd();
}
