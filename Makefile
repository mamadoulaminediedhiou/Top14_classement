all:main_top14_etu

main_top14_etu.o:main_top14_etu.c Equipe.h Match.h
	gcc -c -Wall main_top14_etu.c
	
Equipe.o:Equipe.c Equipe.h
	gcc -c -Wall Equipe.c
	
Match.o:Match.c Match.h
	gcc -c -Wall Match.c
	
main_top14_etu: main_top14_etu.o Equipe.o Match.o
	gcc -o main_top14_etu main_top14_etu.o Equipe.o Match.o
clean:
	rm -fr*.o Equipe.o Match

