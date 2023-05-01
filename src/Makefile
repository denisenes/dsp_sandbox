# apt-get install libsdl2-dev

#CXX = g++
#CXX = clang++

EXE = main
IMGUI_DIR = ../libs/imgui/
IMNODES_DIR = ../libs/ImNodes/
IMGUI_KNOBS_DIR = ../libs/imgui-knobs/

# Application sources
SOURCES = main. JackSetup.cpp SDLSetup.cpp

# Processing logic sources
SOURCES += processing/GlobalClock.cpp processing/Jack.cpp processing/Oscillator.cpp processing/StepSequencer.cpp
SOURCES += processing/Utils.cpp processing/Wavetable.cpp processing/OscilloscopeBlock.cpp

# GUI sources
SOURCES += gui/GUI.cpp gui/JackNode.cpp gui/OscNode.cpp gui/SourceNode.cpp gui/AdderNode.cpp
SOURCES += gui/Oscilloscope.cpp

# ImGui sources
SOURCES += $(IMGUI_DIR)/imgui.cpp  $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl2.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp

# ImNodes sources
SOURCES += $(IMNODES_DIR)/ImNodes.cpp $(IMNODES_DIR)/ImNodesEz.cpp

# Imgui-Knobs sources
SOURCES += $(IMGUI_KNOBS_DIR)/imgui-knobs.cpp

OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
UNAME_S := $(shell uname -s)
LINUX_GL_LIBS = -lGL

CXXFLAGS = -std=c++11 -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends -I$(IMNODES_DIR) -I$(IMGUI_KNOBS_DIR) -Igui -Iprocessing
CXXFLAGS += -g -Wall -Wformat
LIBS =

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	LIBS += $(LINUX_GL_LIBS) -ldl `sdl2-config --libs` -lm

	CXXFLAGS += -ggdb `sdl2-config --cflags` `pkg-config --cflags --libs jack`
	CFLAGS = $(CXXFLAGS)
endif

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

%.o:processing/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:gui/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:$(IMNODES_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:$(IMGUI_KNOBS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:$(IMGUI_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:$(IMGUI_DIR)/backends/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(OBJS) imgui.ini
