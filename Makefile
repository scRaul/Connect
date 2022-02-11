Connect: main.o connect.o view.o controller.o
	g++ -o Connect main.o connect.o view.o controller.o
main.o: main.cpp Connect.h View.h
	g++ -c main.cpp
connect.o: connect.cpp Connect.h View.h Controller.h
	g++ -c connect.cpp
view.o: view.cpp View.h
	g++ -c view.cpp
controller.o: controller.cpp Controller.h
	g++ -c controller.cpp


clean:
	rm -f Connect *.o *~
