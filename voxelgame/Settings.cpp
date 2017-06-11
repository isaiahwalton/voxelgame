#include "Settings.h"


int Settings::GetFOV() {
	return Fov;
}

void Settings::SetFOV(int fov) {
	Fov = fov;
}

void Settings::SetVSync(bool sync)
{
	typedef BOOL(APIENTRY *PFNWGLSWAPINTERVALPROC)(int);
	PFNWGLSWAPINTERVALPROC wglSwapIntervalEXT = 0;

	const char *extensions = (char*)glGetString(GL_EXTENSIONS);

	if (strstr(extensions, "WGL_EXT_swap_control") == 0)
	{
		return;
	}
	else
	{
		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALPROC)wglGetProcAddress("wglSwapIntervalEXT");

		if (wglSwapIntervalEXT)
			wglSwapIntervalEXT(sync);
	}
}

void Settings::SetRenderDistance(int dist)
{
	RenderDistance = dist;
}

int Settings::GetRenderDistance(int dist)
{
	return RenderDistance;
}

int Settings::GetCurrentKeyPressed()
{

	GetNumberOfConsoleInputEvents(hInput, &NumInputs);

	ReadConsoleInput(hInput, &irInput, 1, &InputsRead);

	return irInput.Event.KeyEvent.wVirtualKeyCode;

}

void Settings::SetKey(Inputs input, int key)
{
	switch (input) 
	{
	case Inputs::MoveForward:
		Slot0Key = key;
		break;
	case Inputs::MoveBackward:
		Slot0Key = key;
		break;
	case Inputs::StraffLeft:
		Slot0Key = key;
		break;
	case Inputs::StraffRight:
		Slot0Key = key;
		break;
	case Inputs::BreakBlock:
		Slot0Key = key;
		break;
	case Inputs::PlaceBLock:
		Slot0Key = key;
		break;
	case Inputs::Sprint:
		Slot0Key = key;
		break;
	case Inputs::Jump:
		Slot0Key = key;
		break;
	case Inputs::Slot0:
		Slot0Key = key;
		break;
	case Inputs::Slot1:
		Slot0Key = key;
		break;
	case Inputs::Slot2:
		Slot0Key = key;
		break;
	case Inputs::Slot3:
		Slot0Key = key;
		break;
	case Inputs::Slot4:
		Slot0Key = key;
		break;
	case Inputs::Slot5:
		Slot0Key = key;
		break;
	case Inputs::Slot6:
		Slot0Key = key;
		break;
	case Inputs::Slot7:
		Slot0Key = key;
		break;
	case Inputs::Slot8:
		Slot0Key = key;
		break;
	case Inputs::Slot9:
		Slot0Key = key;
		break;
	default:
		break;
	}
}