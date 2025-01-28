NAME = libasm.a

SRC_FILES = src/add.s       \
			src/ft_strlen.c \

OBJ_FILES = obj/add.o       \
			obj/ft_strlen.o \

C_FLAGS = -Wall -Werror -Wextra

all: $(NAME)
	
obj/%.o : src/%.s obj
	nasm -f elf64 -o $@ $<

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

clean:
	-rm -r $(NAME) obj tst 

re : clean $(NAME)

tst: $(NAME) test/main.c
	gcc $(C_FLAGS) test/main.c -L. -lasm -o tst

obj:
	mkdir obj

