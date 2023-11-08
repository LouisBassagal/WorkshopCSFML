SRC	=	source/GameLoop.c	\
		source/Launch.c	\
		source/EventManager.c	\
		source/PlayerManager.c	\
		source/Destroy.c	\
		main.c

OBJ	=	${SRC:.c=.o}

NAME	=	WorkshopCSFML

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS	=	-I./include/

GRAPHICS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) -g $(CFLAGS) $(OBJ) $(GRAPHICS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all clean