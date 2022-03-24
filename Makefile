NAME = containers

FILES = \
	main.cpp \

INPUT = ${addprefix sources/, ${FILES}}

OUTPUT = ${addprefix objects/, ${FILES:.cpp=.o}}

all: ${NAME}

objects/%.o: sources/%.cpp
	@mkdir -p ${dir $@}
	c++ -Wall -Wextra -Werror -std=c++98 -g -O3 -I sources -c $< -o $@

${NAME}: ${OUTPUT}
	c++ -Wall -Wextra -Werror -std=c++98 -g -O3 -I sources ${OUTPUT} -o ${NAME}

clean:
	rm -rf objects

fclean:	clean
	rm -f ${NAME}

re:		fclean all

run: $(NAME)
	./$(NAME)

x: re
	rm -rf objects