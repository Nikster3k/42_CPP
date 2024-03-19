NAME=	program
FLAGS=	-Wall -Werror -Wextra -pedantic -std=c++98 -g

FILES=	main.cpp AAnimal.cpp Cat.cpp Dog.cpp \
		WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS=	$(FILES:.cpp=.o)

all:	$(NAME)

%.o:		%.cpp
	c++ $(FLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re all