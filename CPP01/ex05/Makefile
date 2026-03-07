COMP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS = ./inc/

SRCS = main.cpp Harl.cpp

OBJS = $(addprefix object_files/, $(SRCS:.cpp=.o))

NAME = ex05

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) -I$(HEADERS) $(OBJS) -o $@

object_files/%.o: %.cpp
	$(COMP) $(FLAGS) -I$(HEADERS) -c $^ -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean all build artifacts
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
