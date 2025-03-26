SOURCES = $(wildcard *.cpp)
SRC_FILES = $(addprefix $(SRC_DIR),$(SOURCES))
OBJ_FILES = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEP_FILES = $(patsubst %.cpp,$(BUILD_DIR)/%.d,$(SOURCES))

SRC_DIR = $(CURDIR)
BUILD_DIR = $(CURDIR)/build
OUT_DIR = $(CURDIR)/bin

DIRS = $(BUILD_DIR) $(OUT_DIR)

NAME = animals
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

info:
	@echo $(SOURCES)

unwildcard:
	sed -i '1s/^SOURCES = .*$$/SOURCES = $(SOURCES)/' Makefile

rewildcard:
	sed -i '1s/^SOURCES = .*$$/SOURCES = $$(wildcard *.cpp)/' Makefile

-include $(DEP_FILES)

.PHONY: all clean fclean re reclean info unwildcard rewildcard
