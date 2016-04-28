CC=g++ -std=c++11
CFLAGS=-c -Wall

all: driver

driver: main.o budget_application.o menu.o budget.o budget_item.o account.o envelope.o budget_envelope.o
	$(CC) main.o budget_application.o menu.o budget.o budget_item.o account.o envelope.o budget_envelope.o -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

budget_application.o: budget_application.cpp budget_application.h
	$(CC) $(CFLAGS) budget_application.cpp

menu.o: menu.cpp menu.h
	$(CC) $(CFLAGS) menu.cpp

budget.o: budget.cpp budget.h
	$(CC) $(CFLAGS) budget.cpp

budget_item.o: budget_item.cpp budget_item.h
	$(CC) $(CFLAGS) budget_item.cpp

account.o: account.cpp account.h
	$(CC) $(CFLAGS) account.cpp

envelope.o: envelope.cpp envelope.h
	$(CC) $(CFLAGS) envelope.cpp

budget_envelope.o: budget_envelope.cpp budget_envelope.h
		$(CC) $(CFLAGS) budget_envelope.cpp

clean:
	rm -f *.o driver