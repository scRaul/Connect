all: Play wins

wins: wins.cpp
	g++ -o wins wins.cpp
	



Play: main.o connect.o view.o controller.o
	g++ -o Play main.o connect.o view.o controller.o
main.o: main.cpp Connect.h View.h Include.h
	g++ -c main.cpp
connect.o: connect.cpp Connect.h View.h Controller.h Include.h
	g++ -c connect.cpp
view.o: view.cpp View.h Include.h
	g++ -c view.cpp
controller.o: controller.cpp Controller.h Include.h
	g++ -c controller.cpp


clean:
	rm -f Play wins *.o *~
