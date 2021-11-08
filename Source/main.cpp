#include "UltraEngine.h"
#include "_Global.h"

using namespace UltraEngine;

void PopulateTree(shared_ptr<Widget> node)
{
    
}

//Downloading JSON from GitHub
void dlReloadJSON() {
    Print("Downloading...");
    if (DownloadFile(c_JSON_URL, c_DEFAULT_DOC_PATH))
    {
        Print("Download complete.");

    }
    else
    {
        Notify(L"Could not download json file from Github's servers");
        Print("Failed to download file.");
    }
}


//Function to load the set-up window (progress bar)
//Disable the main window
//First: load the main interface
//Download the .JSON file from GitHub
//Load the JSON file 
//Populate the tree view
static void AppSetupManager(std::shared_ptr<Window> setupWindow, std::shared_ptr<Window> mainWindow,std::shared_ptr<Widget> advLabel, std::shared_ptr<Widget> advPB, bool GUISetup, bool dlJsonGithub, bool loadJson, bool populateTree) {
    setupWindow->Activate();
    
    float progressVal = 0;
    short totalProgressPart = GUISetup + dlJsonGithub + loadJson + populateTree;
    Print(totalProgressPart);
    if (GUISetup) {
        advLabel->SetText(L"Interface initialization...");

        progressVal += 1;
        advPB->SetProgress(progressVal / totalProgressPart);
        Print(L"Progress = " + WString(progressVal / totalProgressPart));
    }
    if (dlJsonGithub) {
        advLabel->SetText(L"Downloading question JSON file from GitHub's servers...");
        
        dlReloadJSON();

        progressVal += 1;
        advPB->SetProgress(progressVal / totalProgressPart);
        Print(L"Progress = " + WString(progressVal / totalProgressPart));
    }
    if (loadJson) {
        advLabel->SetText(L"Loading questions from JSON files...");



        progressVal += 1;
        advPB->SetProgress(progressVal / totalProgressPart);
        Print(L"Progress = " + WString(progressVal / totalProgressPart));
    }
    if (populateTree) {
        advLabel->SetText(L"Populating treeview...");



        progressVal += 1;
        advPB->SetProgress(progressVal / totalProgressPart);
        Print(L"Progress = " + WString(progressVal / totalProgressPart));
    }
    setupWindow->Disable();
    setupWindow->Hide();
    mainWindow->Activate();
    mainWindow->Enable();
}


int main(int argc, const char* argv[])
{
    //Get the displays
    auto displays = GetDisplays();
    

#pragma region startupSetupWindow
    //Create a window
    auto setupWindow = CreateWindow(c_WINDOW_SETUP, 0, 0, 512, 64, displays[0], WINDOW_CENTER);

    //Create User Interface
    auto ui_setup = CreateInterface(setupWindow);

    //Create widget
    auto sz_setup = ui_setup->root->GetSize();

    auto advancmentLabel = CreateLabel(L"", c_DEFAULT_BORDER, c_DEFAULT_BORDER, sz_setup.x, 16, ui_setup->root, LABEL_MIDDLE);
    advancmentLabel->SetLayout(1, 1, 1, 0);

    auto advancementProgressbar = CreateProgressBar(c_DEFAULT_BORDER, sz_setup.y-(20+c_DEFAULT_BORDER), sz_setup.x-c_DEFAULT_BORDER*2, 20, ui_setup->root, PROGRESSBAR_DEFAULT);
    
#pragma endregion startupSetupWindow Startup window for set-up

#pragma region mainWindow
    //Create a window
    auto mainWindow = CreateWindow(c_APP_NAME, 0, 0, 1024, 768, displays[0], WINDOW_CENTER | WINDOW_TITLEBAR | WINDOW_RESIZABLE);
    mainWindow->Disable();
    mainWindow->SetMinSize(1024, 768);
    //Create User Interface
    auto ui = CreateInterface(mainWindow);

    //Create widget
    auto sz = ui->root->GetSize();

    //-------------------------------------------------------
    // Create main menu
    //-------------------------------------------------------
#pragma region topMenu
    auto mainmenu = CreateMenu("", ui->root);

    //File menu
    auto menu_file = CreateMenu("File", mainmenu);
    auto menu_file_dlReloadJSON = CreateMenu("Download & reload JSON", menu_file);
    auto menu_file_push = CreateMenu("Save JSON to GitHub's servers", menu_file);
    CreateMenu("", menu_file);
    auto menu_file_saveJSON = CreateMenu("Save JSON", menu_file);
    CreateMenu("", menu_file);
    auto menu_file_exit = CreateMenu("Exit", menu_file);

    //Edit menu
    auto menu_edit = CreateMenu("Edit", mainmenu);
    auto menu_edit_newquestion = CreateMenu("New question", menu_edit);
    auto menu_edit_newcategory = CreateMenu("New category", menu_edit);
    CreateMenu("", menu_edit);
    auto menu_edit_options = CreateMenu("Options", menu_edit);

    //Tools menu
    auto menu_tools = CreateMenu("Tools", mainmenu);
    auto menu_tools_dljson = CreateMenu("Download JSON", menu_tools);
    auto menu_tools_pushjson = CreateMenu("Push JSON", menu_tools);

    //Help menu
    auto menu_help = CreateMenu("Help", mainmenu);
    auto menu_help_helpcontents = CreateMenu("Help Contents", menu_help);
    auto menu_help_about = CreateMenu("About", menu_help);
#pragma endregion topMenu topbar menu

    //-------------------------------------------------------
    // Create toolbar
    //-------------------------------------------------------
#pragma region toolBar
    auto toolbar = CreatePanel(0, mainmenu->size.y, sz.x, c_TOOLBARHEIGHT, ui->root);
    toolbar->SetLayout(1, 1, 1, 0);

    int x = 4, y = 4;

    auto toolbarbutton_dl = CreateButton("", x, y, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, toolbar, BUTTON_TOOLBAR);
    toolbarbutton_dl->SetFontScale(2);
    toolbarbutton_dl->SetIcon(LoadIcon(c_ICON_DL_URL), PIXMAP_CENTER, c_ICONS_SIZE_MULT);
    x += c_TOOLBARHEIGHT;

    auto toolbarbutton_push = CreateButton("", x, y, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, toolbar, BUTTON_TOOLBAR);
    toolbarbutton_push->SetFontScale(2);
    toolbarbutton_push->SetIcon(LoadIcon(c_ICON_PUSH_URL), PIXMAP_CENTER, c_ICONS_SIZE_MULT);
    x += c_TOOLBARHEIGHT;

    auto toolbarbutton_save = CreateButton("", x, y, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, toolbar, BUTTON_TOOLBAR);
    toolbarbutton_save->SetFontScale(2);
    toolbarbutton_save->SetIcon(LoadIcon(c_ICON_SAVES_URL), PIXMAP_CENTER, c_ICONS_SIZE_MULT);
    x += c_TOOLBARHEIGHT;

    auto toolbarbutton_options = CreateButton("", x, y, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, toolbar, BUTTON_TOOLBAR);
    toolbarbutton_options->SetFontScale(2);
    toolbarbutton_options->SetIcon(LoadIcon(c_ICON_COG_URL), PIXMAP_CENTER, c_ICONS_SIZE_MULT);
    x += c_TOOLBARHEIGHT;

    auto toolbarbutton_help = CreateButton("", x, y, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, c_TOOLBARHEIGHT - c_DEFAULT_BORDER, toolbar, BUTTON_TOOLBAR);
    toolbarbutton_help->SetIcon(LoadIcon(c_ICON_HELP_URL), PIXMAP_CENTER, c_ICONS_SIZE_MULT);
    toolbarbutton_help->SetFontScale(2);
#pragma endregion toolBar

    //-------------------------------------------------------
    // Create status bar
    //-------------------------------------------------------

    auto statusbar = CreatePanel(0, sz.y - c_STATUSBARHEIGHT, sz.x, c_STATUSBARHEIGHT, ui->root);
    statusbar->SetLayout(1, 1, 0, 1);
    auto statusbarlabel_view = CreateLabel(L"YOLO", c_DEFAULT_BORDER, 0, 300, statusbar->size.y, statusbar, LABEL_LEFT | LABEL_MIDDLE);
    auto statusbarlink_version = CreateLabel(c_APP_VERSION, statusbar->size.x - 300-c_DEFAULT_BORDER, 0, 300, statusbar->size.y, statusbar, LABEL_RIGHT | LABEL_MIDDLE);
    statusbarlink_version->SetColor(Vec4(.25, .25, 1, 1), WIDGETCOLOR_FOREGROUND);


    //-------------------------------------------------------
    // Create side panel
    //-------------------------------------------------------

    auto sidepanel = CreatePanel(0, toolbar->position.y + toolbar->size.y, c_SIDEPANELWIDTH, sz.y - toolbar->size.y - toolbar->position.y - statusbar->size.y, ui->root);
    sidepanel->SetLayout(1, 0, 1, 1);

    auto questionsTreeView = CreateTreeView(c_DEFAULT_BORDER, 0, c_SIDEPANELWIDTH - c_DEFAULT_BORDER, sz.y - toolbar->size.y - toolbar->position.y - statusbar->size.y, sidepanel);
    questionsTreeView->SetLayout(1, 1, 1, 1);

    //-------------------------------------------------------
    // Create main panel
    //-------------------------------------------------------
#pragma region mainSectionPanel
    auto mainpanel = CreatePanel(c_SIDEPANELWIDTH + c_DEFAULT_BORDER, toolbar->position.y + toolbar->size.y, sz.x - c_SIDEPANELWIDTH - c_DEFAULT_BORDER * 2, sz.y - toolbar->size.y - toolbar->position.y - statusbar->size.y, ui->root, PANEL_BORDER);
    mainpanel->SetLayout(1, 1, 1, 1);

    y = c_DEFAULT_BORDER;

    auto category_radio_btn_panel = CreatePanel(mainpanel->GetSize().x - 350, 0, 300, 128, mainpanel);
    //category_radio_btn_panel->SetText(L"Category");
    CreateLabel("Category :", c_DEFAULT_BORDER, y, 300, 20, category_radio_btn_panel, LABEL_LEFT | LABEL_MIDDLE);
    
    CreateLabel("ID :", c_DEFAULT_BORDER, y, 300, 20, mainpanel, LABEL_LEFT | LABEL_MIDDLE);
    y += 20;
    auto question_id = CreateTextField(c_DEFAULT_BORDER, y, 128, 20, mainpanel);
    question_id->SetLayout(1, 1, 1, 0);

    //Button radio for categories
    short y_cat = y;
    short x_cat = c_DEFAULT_BORDER;
    short sizex_cat = category_radio_btn_panel->GetSize().x / 2 - c_DEFAULT_BORDER;
    auto category_radio_sp = CreateButton(L"Singleplayer", x_cat, y_cat, sizex_cat, 20, category_radio_btn_panel, BUTTON_RADIO);
    x_cat += sizex_cat;
    auto category_radio_mp = CreateButton(L"Two players", x_cat, y_cat, sizex_cat, 20, category_radio_btn_panel, BUTTON_RADIO);
    x_cat -= sizex_cat;
    y_cat += 20;
    auto category_radio_all = CreateButton(L"All players", x_cat, y_cat, sizex_cat, 20, category_radio_btn_panel, BUTTON_RADIO);
    x_cat += sizex_cat;
    auto category_radio_game = CreateButton(L"Game", x_cat, y_cat, sizex_cat, 20, category_radio_btn_panel, BUTTON_RADIO);
    x_cat -= sizex_cat;
    y_cat += 20;

    y += question_id->GetSize().y;
    CreateLabel("Title :", c_DEFAULT_BORDER, y, 300, 20, mainpanel, LABEL_LEFT | LABEL_MIDDLE);
    y += 20;
    auto question_title = CreateTextField(c_DEFAULT_BORDER, y, 300, 20, mainpanel);
    question_id->SetLayout(1, 1, 1, 0);

    y += question_title->GetSize().y;
    CreateLabel("Question :", c_DEFAULT_BORDER, y, 300, 20, mainpanel, LABEL_LEFT | LABEL_MIDDLE);
    y += 20;
    auto question_question = CreateTextField(c_DEFAULT_BORDER, y, mainpanel->GetSize().x - c_DEFAULT_BORDER*2, 32, mainpanel);
    question_id->SetLayout(1, 1, 1, 0);

    auto register_panel = CreatePanel(0, mainpanel->GetSize().y - c_STATUSBARHEIGHT - c_DEFAULT_BORDER, mainpanel->GetSize().x, c_STATUSBARHEIGHT, mainpanel);
    register_panel->SetLayout(1, 1, 0, 1);

    auto register_refreshForm = CreateButton("", c_DEFAULT_BORDER, 0, 32, 32, register_panel);
    register_refreshForm->SetIcon(LoadIcon(c_ICON_REFRESH_URL), PIXMAP_CENTER, c_ICONS_SIZE_MULT*.5);
    auto register_addQuestion = CreateButton("", c_DEFAULT_BORDER *2 + register_refreshForm->GetSize().x, 0, 32, 32, register_panel);
    register_addQuestion->SetIcon(LoadIcon(c_ICON_ADD_URL), PIXMAP_CENTER, c_ICONS_SIZE_MULT*.5);



    y += question_question->GetSize().y + 32;
    auto shortcut_panel = CreatePanel(0, y, mainpanel->GetSize().x, mainpanel->GetSize().y - y - c_DEFAULT_BORDER- c_STATUSBARHEIGHT, mainpanel, PANEL_GROUP);
    shortcut_panel->SetText("Shortcuts");

    x = c_DEFAULT_BORDER; y = c_DEFAULT_BORDER;
    auto shortcut_currentPlayer = CreateButton("Current Player", x, y, 96, 32, shortcut_panel, BUTTON_DEFAULT);
    x += 96+c_DEFAULT_BORDER;
    auto shortcut_randomPlayer = CreateButton("Random player", x, y, 96, 32, shortcut_panel, BUTTON_DEFAULT);
    x += 96 + c_DEFAULT_BORDER;
    auto shortcut_nbSip = CreateButton("# sips", x, y, 48, 32, shortcut_panel, BUTTON_DEFAULT);
#pragma endregion mainSectionPanel Main form section panel 

    //Startup setting window switched to main window
    
    AppSetupManager(setupWindow, mainWindow, advancmentLabel, advancementProgressbar, 1, 1, 1, 1);
   

#pragma endregion mainWindow
 
#pragma region mainLoop
    while (true)
    {
        const Event ev = WaitEvent();
        switch (ev.id)
        {
            case EVENT_WIDGETACTION:

                //Topbar menu actions
                //Files menu
#pragma region menuActions
                //File menu
                if(ev.source == menu_file_dlReloadJSON) 
                {
                    AppSetupManager(setupWindow, mainWindow, advancmentLabel, advancementProgressbar,0,1,1,1);
                }
                else if(ev.source == menu_file_push) 
                {

                }
                else if(ev.source == menu_file_saveJSON) 
                {

                }
                else if(ev.source == menu_file_exit) 
                {
                    EmitEvent(EVENT_WINDOWCLOSE, mainWindow);
                }
                
                //Edit menu
                else if(ev.source == menu_edit_newquestion) 
                {

                }
                else if(ev.source == menu_edit_newcategory) 
                {
                    
                }
                else if(ev.source == menu_edit_options) 
                {

                }
                 
                //Tools menu
                else if(ev.source == menu_tools_dljson) 
                {
                    EmitEvent(EVENT_WIDGETACTION, menu_file_dlReloadJSON);
                }
                else if(ev.source == menu_tools_pushjson) 
                {
                    EmitEvent(EVENT_WIDGETACTION, menu_file_push);
                }
                 
                //Help menu
                else if(ev.source == menu_help_helpcontents) 
                {
                    RunFile("https://github.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/wiki");
                }
                else if(ev.source == menu_help_about)
                {
                    RunFile("https://github.com/Stonks-Life-Inc/OlivesEtMines_QuestionsManager/wiki");
                }

               
                
#pragma endregion menuActions Topbar menu actions

                //Toolbar buttons actions
 #pragma region toolbarButtonsActions
                else if (ev.source == toolbarbutton_dl)
                {
                    EmitEvent(EVENT_WIDGETACTION, menu_file_dlReloadJSON);
                }
                else if (ev.source == toolbarbutton_push)
                {
                    EmitEvent(EVENT_WIDGETACTION, menu_file_push);
                }
                else if (ev.source == toolbarbutton_save)
                {
                    EmitEvent(EVENT_WIDGETACTION, menu_file_saveJSON);
                }
                else if (ev.source == toolbarbutton_options)
                {
                    EmitEvent(EVENT_WIDGETACTION, menu_edit_options);
                }
                else if (ev.source == toolbarbutton_help)
                {
                    EmitEvent(EVENT_WIDGETACTION, menu_help_helpcontents);
                }
#pragma endregion toolbarButtonsActions Tool bar buttons actions
                break;
            case EVENT_WIDGETSELECT:
                
            case EVENT_QUIT:
            case EVENT_WINDOWCLOSE:
                if (ev.source == mainWindow)
                {
                    if (Confirm("Are you sure you want to quit?")) return 0;
                }
                break;
            default: break;
        }
    }
#pragma endregion mainLoop main loop events
    return 0;
}