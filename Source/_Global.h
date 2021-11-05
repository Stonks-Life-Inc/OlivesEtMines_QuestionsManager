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
const UltraEngine::WString c_JSON_URL = L"https://github.com/Stonks-Life-Inc/Stonks-Life-Inc.github.io/blob/main/olivesetmines_questionnaire.json";
const UltraEngine::WString c_DEFAULT_DOC_PATH = UltraEngine::GetPath(UltraEngine::PATH_DOCUMENTS) + L"Olives Et Mines - Questionnaire Manager";
#endif // !_GLOBAL_H