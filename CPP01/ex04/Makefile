COMP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

HEADERS = ./inc/

SRCS = main.cpp 

OBJS = $(addprefix object_files/, $(SRCS:.cpp=.o))

NAME = ex04

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

test: $(NAME)
	@echo "#############################"
	@echo "Before test:\n"
	@echo "Line1\nLine2\nrandomstring\n75387583758\n" > input_test
	@cat input_test
	./$(NAME) input_test random 123
	@echo "After test:\n"
	@cat input_test.replace
	
	@echo "#############################"
	@echo "Before test:\n"
	@cat input_test
	./$(NAME) input_test Line '~Worddd'
	@echo "After test:\n"
	@cat input_test.replace
		
	@echo "#############################"
	@echo "Before test:\n"
	@cat input_test
	./$(NAME) input_test 'Line' ''
	@echo "After test:\n"
	@cat input_test.replace
	
	

	
	

.PHONY: all clean fclean re test
