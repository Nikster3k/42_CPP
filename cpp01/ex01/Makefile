NAME=	phonebook
FLAGS=	-Wall -Werror -Wextra -std=c++98

FILES=	main.cpp PhoneBook.cpp Contact.cpp
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