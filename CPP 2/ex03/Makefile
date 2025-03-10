# Nom de l'exécutable
NAME = BSP

# Compilateur et flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Répertoires
SRC_DIR = .
OBJ_DIR = obj

# Liste des fichiers sources
SRC_FILES = main.cpp Fixed.cpp Point.cpp bsp.cpp

# Génération des fichiers objets correspondants
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

# Règle principale
all: $(NAME)
	@echo "\033[2J\033[1;1H\033[1;36m"
	@echo	" +-+-+-+ +-+-+ "
	@echo	" |C|+|+| |0|2| "
	@echo	" +-+-+-+ +-+-+ "
	@echo	" |E|X|   |0|3| "
	@echo	" +-+-+   +-+-+ "
	@echo	" Binary Space Partitioning"

# Compilation de l'exécutable
$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation des fichiers objets dans obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Création du répertoire obj si nécessaire
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
