all: main.o change.o errors.o file_reader.o file_writer.o game.o neighbourhood.o settings.o writer.o change.h errors.h file_reader.h file_writer.h game.h neighbourhood.h settings.h writer.h
	gcc  main.o change.o errors.o file_reader.o file_writer.o game.o neighbourhood.o settings.o writer.o

main.o: main.c file_reader.c settings.c game.c file_reader.h settings.h game.h
	cc -c main.c file_reader.c  settings.c game.c

change.o: change.c neighbourhood.c neighbourhood.h settings.h
	cc -c  change.c neighbourhood.c

errors.o: errors.c settings.c errors.h settings.h
	cc -c errors.c settings.c

file_reader.o: file_reader.c errors.c file_reader.h errors.h settings.h
	cc -c file_reader.c errors.c

file_writer.o: file_writer.c settings.c file_writer.h settings.h
	cc -c file_writer.c settings.c

game.o: game.c change.c settings.c writer.c file_writer.c game.h change.h settings.h writer.h file_writer.h
	cc -c  game.c change.c settings.c writer.c file_writer.c

neighbourhood.o: neighbourhood.c neighbourhood.h settings.h
	cc -c neighbourhood.c

settings.o: settings.c errors.c settings.h errors.h
	cc -c settings.c errors.c

writer.o: writer.c writer.h settings.h
	cc -c writer.c
