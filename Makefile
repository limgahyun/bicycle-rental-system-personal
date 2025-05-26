CXX = g++
CXXFLAGS = -std=c++14

SRCS = src/main.cpp \
       src/BicycleRentalSystem.cpp \
       src/LoginUI.cpp \
       src/LoginController.cpp \
       src/SignUpUI.cpp \
       src/SignUpController.cpp \
       src/User.cpp \
       src/Member.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = bicycle_rental_system

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean 