#source: https://oregonstate.instructure.com/courses/1719543/pages/lecture-makefiles?module_item_id=18712398
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGs += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -w

SRCS = main.cpp barbarian.cpp character.cpp blueMen.cpp game.cpp harryPotter.cpp intNumChoice.cpp medusa.cpp vampire.cpp

HEADERS = barbarian.hpp character.hpp blueMen.hpp game.hpp harryPotter.hpp intNumChoice.hpp medusa.hpp vampire.hpp

OBJS = main.o

output: ${SRCS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o output

${OBJS}: ${SRCS} 
	${CXX} ${CXXFLAGS} -c $(@: .o = .cpp)

clean:
	rm output
