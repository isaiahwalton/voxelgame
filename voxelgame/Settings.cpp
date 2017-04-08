#include "Settings.h"



namespace settings {

	int getFOV() {
		return 1;//Fov;
	}

	void setFOV(int fov) {
		//Fov = fov;
	}

	void setVSync(bool sync)
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
}
