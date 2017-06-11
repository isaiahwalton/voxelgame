#pragma once

#include "ChunkManager.h"
#include "Button.h"
#include "Hud.h"
#include "Settings.h"
#include "GenChunk.h"
#include "Physics.h"
#include "TextureAtlas.h"

extern GLuint program;
extern std::string WorldName;
extern Hud hud;
extern Settings settings;
extern Button PlayButton;
extern Button SettingsButton;
extern Button ExitButton;
//extern Button SettingButtons[17];
extern Texture BackGround;
extern HWND hwnd;
extern bool in_game;
extern GenChunk chunkgenerator;
extern int fps;
extern ChunkManager chunkmanager;