NAME = interface

SRCS = main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp  ICharacter.cpp

HEADERS = AMateria.hpp Character.hpp Ice.hpp Cure.hpp MateriaSource.hpp \
		IMateriaSource.hpp ICharacter.hpp

OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re