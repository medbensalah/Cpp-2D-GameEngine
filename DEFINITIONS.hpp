#pragma once

#include <SFML/Audio.hpp>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 663
#define MOUSE_CURSOR_PATH "Resources/cur/Cursor.png"

extern sf::Sprite _mouse;

//***************************************************Splash
#define SPLASH_STATE_SHOW_TIME 3500
#define BLACK_PATH "Resources/res/Black.png"
#define WHITE_PATH "Resources/res/White.png"
#define SPLASH_SCENE8_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

//***************************************************Main
#define MAIN_MENU_SCENE8_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"
#define MAIN_MENU_TITLE_PATH "Resources/res/Game Title.png"
#define MAIN_MENU_NEW_GAME_BUTTON_PATH "Resources/res/New Game Button.png"
#define MAIN_MENU_LOAD_GAME_BUTTON_PATH "Resources/res/Load Game Button.png"

#define MAIN_MENU_BGM "Resources/snd/sfx/Main Lobby.wav"

//***************************************************Login
#define LOGIN_SCENE_LOGIN_GATE "Resources/res/Login Gate.png"
#define LOGIN_SCENE_BACKGROUND "Resources/res/Login Background.png"
#define LOGIN_SCENE_INPUT_CONFIRM_BUTTON "Resources/res/input/Confirm Button.png"
#define LOGIN_SCENE_INPUT_DEL_BUTTON "Resources/res/input/Del Button.png"
#define LOGIN_SCENE_INPUT_A "Resources/res/input/A.png"
#define LOGIN_SCENE_INPUT_B "Resources/res/input/B.png"
#define LOGIN_SCENE_INPUT_C "Resources/res/input/C.png"
#define LOGIN_SCENE_INPUT_D "Resources/res/input/D.png"
#define LOGIN_SCENE_INPUT_E "Resources/res/input/E.png"
#define LOGIN_SCENE_INPUT_F "Resources/res/input/F.png"
#define LOGIN_SCENE_INPUT_G "Resources/res/input/G.png"
#define LOGIN_SCENE_INPUT_H "Resources/res/input/H.png"
#define LOGIN_SCENE_INPUT_I "Resources/res/input/I.png"
#define LOGIN_SCENE_INPUT_J "Resources/res/input/J.png"
#define LOGIN_SCENE_INPUT_K "Resources/res/input/K.png"
#define LOGIN_SCENE_INPUT_L "Resources/res/input/L.png"
#define LOGIN_SCENE_INPUT_M "Resources/res/input/M.png"
#define LOGIN_SCENE_INPUT_N "Resources/res/input/N.png"
#define LOGIN_SCENE_INPUT_O "Resources/res/input/O.png"
#define LOGIN_SCENE_INPUT_P "Resources/res/input/P.png"
#define LOGIN_SCENE_INPUT_Q "Resources/res/input/Q.png"
#define LOGIN_SCENE_INPUT_R "Resources/res/input/R.png"
#define LOGIN_SCENE_INPUT_S "Resources/res/input/S.png"
#define LOGIN_SCENE_INPUT_T "Resources/res/input/T.png"
#define LOGIN_SCENE_INPUT_U "Resources/res/input/U.png"
#define LOGIN_SCENE_INPUT_V "Resources/res/input/V.png"
#define LOGIN_SCENE_INPUT_W "Resources/res/input/W.png"
#define LOGIN_SCENE_INPUT_X "Resources/res/input/X.png"
#define LOGIN_SCENE_INPUT_Y "Resources/res/input/Y.png"
#define LOGIN_SCENE_INPUT_Z "Resources/res/input/Z.png"
#define LOGIN_SCENE_INPUT_HOVER "Resources/res/input/hover.png"

#define LOGIN_SCENE_GATE_AFX_FILEPATH "Resources/snd/AFX/Gate.wav"

#define CLICK_AFX "Resources/snd/AFX/UI/Click.wav"

#define LOGIN_BGM "Resources/snd/sfx/Digmon Theme.wav"

//***************************************************Digimon Selection
#define DIGIMON_SELECTION_SCENE_BACKGROUND "Resources/res/Digimon Selection Background.png"
#define TERRIERMON_ANIMATION "Resources/res/Digimon Choose/Terriermon.png"
#define VEEMON_ANIMATION "Resources/res/Digimon Choose/Veemon.png"
#define IMPMON_ANIMATION "Resources/res/Digimon Choose/Impmon.png"
#define SELECTION_BOX "Resources/res/Digimon Choose/Box.png"
#define SELECTION_BOX_HOVER "Resources/res/Digimon Choose/Hover Box.png"
#define TYPING_SFX_FILEPATH "Resources/snd/AFX/Typing.wav"


//***************************************************Introduction scene
#define INTRO_SCENE_CITY "Resources/res/ingame/intro/Intro City.png"
#define INTRO_SCENE_ROOM "Resources/res/ingame/intro/Room.png"
#define INTRO_SCEN_BGM "Resources/snd/SFX/Intro City.wav"


//***************************************************Player info
#define PLAYER_TILESET "Resources/res/ingame/player/player.png"
extern sf::Text playerName;
extern int playerDigimon;

//**************************************************Maps

//**************************************************Pause
#define PAUSE_MENU_BACKGROUNDI "Resources/res/PauseMenu/MenuBackground0.png"
#define PAUSE_MENU_BACKGROUND "Resources/res/PauseMenu/MenuBackground.png"
#define PAUSE_MENU_ITEM "Resources/res/PauseMenu/MenuItem.png"

//**************************************************Digimon
#define TERRIERMON 1
#define VEEMON 2
#define IMPMON 3