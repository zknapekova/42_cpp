CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS = ./inc/

SRCS = main.cpp Bureaucrat.cpp

OBJS = $(addprefix object_files/, $(SRCS:.cpp=.o))

NAME = ex00

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(HEADERS) $(OBJS) -o $@

object_files/%.o: %.cpp
	@mkdir -p object_files
	$(CXX) $(CXXFLAGS) -I$(HEADERS) -c $^ -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean all build artifacts
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
