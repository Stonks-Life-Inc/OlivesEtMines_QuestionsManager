#pragma once
#ifndef _GLOBAL_H
#define _GLOBAL_H

//App & window name
const UltraEngine::WString c_APP_NAME = L"Olives & Mines - Questionnaire Manager";

const UltraEngine::WString c_WINDOW_SETUP = c_APP_NAME + L" - Set-up";
const UltraEngine::WString c_APP_VERSION = L"v.0.1.0";



//Sizes & pos
const short c_DEFAULT_BORDER = 8;
const short c_TOOLBARHEIGHT = 48;
const short c_STATUSBARHEIGHT = 32;
const short c_SIDEPANELWIDTH = 300;
const short c_CONSOLEHEIGHT = 120;

const float c_ICONS_SIZE_MULT = .25F;


//Paths & URLS
const UltraEngine::WString c_JSON_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/questions.json";
const UltraEngine::WString c_DEFAULT_DOC_PATH = UltraEngine::GetPath(UltraEngine::PATH_DOCUMENTS) + L"/Olives Et Mines - Questionnaire Manager/";
//Icons
const UltraEngine::WString c_ICON_ADD_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/add.svg";
const UltraEngine::WString c_ICON_COG_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/cog.svg";
const UltraEngine::WString c_ICON_DL_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/dl.svg";
const UltraEngine::WString c_ICON_ERASER_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/eraser.svg";
const UltraEngine::WString c_ICON_HELP_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/help.svg";
//const UltraEngine::WString c_ICON_IMPORT_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/import.svg"; //Unused import icon. Replaced by c_ICON_SAVES_URL icon
const UltraEngine::WString c_ICON_PUSH_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/push.svg";
const UltraEngine::WString c_ICON_REFRESH_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/refresh.svg";
const UltraEngine::WString c_ICON_SAVES_URL = L"https://raw.githubusercontent.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/main/Resources/icons/saves.svg";
#endif // !_GLOBAL_H