SOURCES = main.cpp Contact.cpp PhoneBook.cpp
SRC_FILES = $(addprefix $(SRC_DIR),$(SOURCES))
OBJ_FILES = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEP_FILES = $(patsubst %.cpp,$(BUILD_DIR)/%.d,$(SOURCES))

SRC_DIR = $(CURDIR)
BUILD_DIR = $(CURDIR)/build

NAME = phonebook

CXX = g++
CXXFLAGS = -Wall -Wextra -g -MMD -std=c++98 

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

$(BUILD_DIR): 
	mkdir -p $@

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ_FILES)

clean reclean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all reclean

-include $(DEP_FILES)

.PHONY: all clean fclean re reclean
