#include "GlobalVars.h"

GLuint program;
std::string WorldName;
Hud hud;
Settings settings;
Button PlayButton = Button(683, 288, 96, 192);
Button SettingsButton = Button(683, 384, 96, 192);
Button ExitButton = Button(683, 480, 96, 192);
//Button SettingButtons[17];
Texture BackGround = Texture();
HWND hwnd;
bool in_game = false;
int fps;
int old_fps;
GenChunk chunkgenerator = GenChunk();
ChunkManager chunkmanager = ChunkManager(WorldName);
