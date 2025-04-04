Name = coldwar
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp
OBJ = $(SRC:.cpp=.o)
C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(Name)

$(Name): $(OBJ) $(HEADERS)
	$(C) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re