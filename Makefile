NAME = libasm.a

SRC_FILES = src/add.s
OBJ_FILES = obj/add.o


all: obj $(NAME)
	
obj/%.o : src/%.s
	nasm -f elf64 -o $@ $<

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

clean:
	rm $(NAME) $(OBJ_FILES)

tst: $(NAME)
	gcc test/main.c $(NAME) -o tst

obj:
	mkdir obj
