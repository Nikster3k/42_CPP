NAME=	program
FLAGS=	-Wall -Werror -Wextra -pedantic -std=c++98 -g

FILES=	main.cpp Base.cpp A.cpp B.cpp C.cpp
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
