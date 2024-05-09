NAME=	PmergeMe
FLAGS=	-Wall -Werror -Wextra -pedantic -std=c++98 -g

FILES=	main.cpp PmergeMe.cpp
OBJS=	$(FILES:.cpp=.o)

all:	$(NAME)

%.o:		%.cpp
	c++ $(FLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

count:
	make re FLAGS="$(FLAGS) -D COUNT"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

run: $(NAME)
ifdef V
	./$(NAME) `shuf -i 1-100000 -n $(V) | tr "\n" " "`
else
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
endif


.PHONY:	clean fclean re all
