COMP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS = ./inc/

SRCS = Contact.cpp main.cpp PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = phone_book

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) -I$(HEADERS) $(OBJS) -o $@

%.o: %.cpp
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
