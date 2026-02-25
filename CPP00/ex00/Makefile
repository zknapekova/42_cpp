COMP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -o $@

%.o: %.cpp
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