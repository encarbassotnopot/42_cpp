SOURCES = megaphone.cpp
SRC_FILES = $(addprefix $(SRC_DIR),$(SOURCES))
OBJ_FILES = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEP_FILES = $(patsubst %.cpp,$(BUILD_DIR)/%.d,$(SOURCES))

SRC_DIR = $(CURDIR)
BUILD_DIR = $(CURDIR)/build
OUT_DIR = $(CURDIR)/bin

DIRS = $(BUILD_DIR) $(OUT_DIR)

NAME = megaphone
TARGET = $(OUT_DIR)/$(NAME)

CXX = g++
CXXFLAGS = -Wall -Wextra -g -MMD -std=c++98 

all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile | $(DIRS)
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

$(DIRS): 
	mkdir -p $@

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

clean reclean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(OUT_DIR)

re: fclean all reclean

-include $(DEP_FILES)

.PHONY: all clean fclean re reclean
