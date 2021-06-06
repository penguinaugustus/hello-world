obj = main.o Game.o God.o User.o log.o bonus.o

edit : $(obj)
	g++ -o edit $(obj)
	
main.o : Game.h God.h User.h log.h bonus.h
Game.o : Game.h
God.o : Game.h God.h User.h log.h bonus.h
User.o : User.h
bonus.o : bonus.h User.h
log.o : log.h 

	
.PHONY : clean
clean :
	-rm edit $(obj)