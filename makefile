ULTRAENGINEPATH = G:/Programmes (x86)/SteamLibrary/steamapps/common/Ultra App Kit
SRC = Source/*.cpp
FLAGS = -I/usr/include/freetype2 -I/usr/include/fontconfig -D_ULTRA_APPKIT "-I$(ULTRAENGINEPATH)/Include"
LFLAGS = -no-pie -lX11 -lpthread -lXft -lXext -lXrender -lXcursor -ldl
OUT = OlivesEtMines_QuestionsManager$(PRODUCT_SUFFIX)

x64: $(SRC)
	g++ $(SRC) "$(ULTRAENGINEPATH)/Library/Linux/x64/$(CONFIGNAME)/AppKit.o" -o "$(OUT)" $(LFLAGS) $(FLAGS) $(CONFIGFLAGS)

clean:
	rm -f "$(OUT)"