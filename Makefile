CXX = g++
CXXFLAGS = -std=c++11 \
    -I/opt/homebrew/opt/glew/include \
    -I/opt/homebrew/opt/glfw/include

LDFLAGS = -L/opt/homebrew/opt/glew/lib \
  -L/opt/homebrew/opt/glfw/lib \
  -lGLEW -lglfw -framework OpenGL
  
main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main $(LDFLAGS)