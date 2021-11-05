#pragma once
#ifndef _GLOBAL_H
#define _GLOBAL_H

//App & window name
const UltraEngine::WString c_APP_NAME = L"Olives & Mines - Questionnaire Manager";

const UltraEngine::WString c_WINDOW_SETUP = c_APP_NAME + L" - Set-up";
const UltraEngine::WString c_APP_VERSION = L"v.0.1.0";



//Sizes & pos
const int c_DEFAULT_BORDER = 8;
const int c_TOOLBARHEIGHT = 48;
const int c_STATUSBARHEIGHT = 32;
const int c_SIDEPANELWIDTH = 300;
const int c_CONSOLEHEIGHT = 120;


//Paths & URLS
const UltraEngine::WString c_JSON_URL = L"https://github.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/blob/main/Resources/questions.json";
const UltraEngine::WString c_DEFAULT_DOC_PATH = UltraEngine::GetPath(UltraEngine::PATH_DOCUMENTS) + L"Olives Et Mines - Questionnaire Manager";
//Icons
const UltraEngine::WString c_ICON_ADD_URL = L"";
const UltraEngine::WString c_ICON_DL_URL = L"";
const UltraEngine::WString c_ICON_ERASER_URL = L"";
const UltraEngine::WString c_ICON_IMPORT_URL = L"";
const UltraEngine::WString c_ICON_PUSH_URL = L"";
const UltraEngine::WString c_ICON_REFRESH_URL = L"";
const UltraEngine::WString c_ICON_SAVES_URL = L"";
#endif // !_GLOBAL_H