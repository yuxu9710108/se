OBJS =  create-iiconstr.o \

PROGRAM = iic 

CC = gcc

all: $(OBJS)
	$(CC) $^ -o $(PROGRAM)
	@echo "done!"

clean:
	rm -f $(OBJS) $(PROGRAM) 
	@echo "delete ok"

test:
	./$(PROGRAM) < test_file

tag:
	rm -f tags cscope.*
	ctags -R *.[ch]
	find -name "*.[ch]" > cscope.files
	cscope -bk

