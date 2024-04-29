#include "rectangle.hpp"
#include <SFML/Graphics.hpp>
#include<vector>
using namespace std;
using namespace sf;

/*struct vector2f
{
    int x;
    int y;
};*/
Vector2f speed = {4.f, 4.f};
vector<Rectangle>rectangulo;

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    Rectangle rect(Vector2f(80.f,60.f), window);
    
//loop
    while (window.isOpen())
    {
       Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
                 if (event.type == Event::MouseButtonPressed)  //aqui escucha una vez cuando se presiona el click izquierdo del mouse
                 
                 {
                if(event.mouseButton.button == Mouse::Left){
                    float x=float(rand()%100);
                    float y=float(rand()%100);//crea los rectangulos con tamaño random
                Rectangle r= Rectangle(Vector2f(x,y), window);
                rectangulo.push_back(r);
                r.drawTo(window);
               // Mouse::getPosition(window);{}
                
            }
           }
            
        }
  
        if(Mouse::isButtonPressed(Mouse::Left))//entra al if si  esta presionadoel click
        {}

    

        window.clear();
for( auto&r : rectangulo){
    r.update();
    r.drawTo(window);
    }
     //   rect.update();
       // rect.drawTo(window);
        
        window.display();
    }

    return 0;
}

/*
int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    //CircleShape shape(50.f);
     RectangleShape shape({60.f,30.f});
shape.setPosition({400,200});
    shape.setFillColor(Color::White);//color
    window.setFramerateLimit(40);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();//cierra la ventana
        }
if (Mouse::isButtonPressed(Mouse::Left)){
            shape.rotate(15);
                    }
        window.clear();
        
        if(shape.getPosition().x+shape.getSize().x>=800||shape.getPosition().x<0)
        {       
            shape.getPosition().x < 0;
                shape.setFillColor({rand()%255,rand()%255,rand()%255});//color

            speedX *=-1;
            shape.scale({1.1,1.1});
        }

  if(shape.getPosition().y+shape.getSize().y>=600||shape.getPosition().y<0)
        {
            shape.getPosition().y < 0;
         shape.setFillColor({rand()%255,rand()%255,rand()%255});//color aleatorio

            speedY *=-1;
            shape.scale({1.1,1.1});

        }

        shape.move({speedX,speedY});//entre llaves para decirle que es un vector
        window.draw(shape);
        window.display();
        
    }

    return 0;
}*/