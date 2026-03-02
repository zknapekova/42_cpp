COMP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp

OBJS = $(addprefix object_files/, $(SRCS:.cpp=.o))

NAME = ex02

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -o $@

object_files/%.o: %.cpp
	$(COMP) $(FLAGS) -c $^ -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean all build artifacts
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
