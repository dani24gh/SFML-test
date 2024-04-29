#ifndef rectangle_h
#define rectangle_h
#include <SFML/Graphics.hpp>
using namespace sf;

class Rectangle 
{ 
private:
    Vector2f speed; //un vector de dos floats
    Vector2f acc;
    RectangleShape shape;

public:
    Rectangle (Vector2f size, RenderWindow &window, Vector2i position);

    void update();
    void drawTo(RenderWindow &window);
};

#endif
