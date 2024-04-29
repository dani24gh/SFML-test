#include "rectangle.hpp"

Rectangle::Rectangle(Vector2f size, RenderWindow &window){
    this->shape = RectangleShape(size);
    this->shape.setPosition({Mouse::getPosition(window).x,Mouse::getPosition(window).y});
    this->shape.setFillColor(Color::Red);
    this->speed =Vector2f(0.f,-4.f);//.f para indicarle que es un numero con decimal
     this->acc = Vector2f(0.f,-2.f);
    this->shape.setOutlineThickness(4);
    this->shape.setOutlineColor(Color::White);

}   


void Rectangle::update()
{
    if(this->shape.getPosition().y + this->shape.getSize().y <= 600 )
    {
    this->speed += this->acc;
    this->shape.move(this->speed);
    }
/*
      if(this->shape.getPosition().x + this->shape.getSize().x <= 800 )
    {
    this->speed += this->acc;
    this->shape.move(this->speed);
    }
    */
     if(this->shape.getPosition().x + this->shape.getSize().x >800 || this->shape.getPosition().x < 0)
     {
        this->shape.setFillColor(Color::Red);
        this->speed.x *= -1;
     }
     
        
     if(this->shape.getPosition().y + this->shape.getSize().y >= 600 || this->shape.getPosition().y < 0)
     {
         this->shape.setFillColor(Color::Red);
        this->speed.y *= -1;
     }

      if(this->shape.getPosition().y + this->shape.getSize().y > 600 )
    {

        this->shape.setFillColor(Color::Red);
         this->shape.setPosition(this->shape.getPosition().x,600-this->shape.getSize().y);
        this->speed.y *= -1;


    }
}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}
void Rectangle::changeColorIfClicked(Vector2i position){
    float x= this->shape.getPosition().x;
    float y= this->shape.getPosition().y;
     float w= this->shape.getPosition().x;
     float h= this->shape.getPosition().y;
     int mouseX = position.x;
      int mouseY = position.y;    

    if(mouseX >= x && mouseX<=x+w && mouseY>=y && mouseY <= y+h){
this->shape.setFillColor(Color::Green);

    }

}


