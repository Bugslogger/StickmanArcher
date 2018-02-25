#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace std;
const int Bodyx=20;
float Rot=359;
float RotA=Rot;
const int Bodyy=100;
const int ARROWX=100;
const int ARROWY=20;
const int WINSIZEX=1000;
const int WINSIZEY=600;
bool isKeyBoardPressed=false;
float xComp;
float yComp;
float initialVelocityY=2.2;
float initialVelocity=2.0;
int n=0;//n is the equivalent of time

int main()
{
    int toggle = 0;
    bool RotatorDecider(sf::RectangleShape);
    sf::RenderWindow window(sf::VideoMode(WINSIZEX,WINSIZEY), "SFML works!");


    sf::RectangleShape body(sf::Vector2f(Bodyx,Bodyy));
    body.setPosition(100,350);
    body.setOrigin(Bodyx/2,Bodyy/2);
    body.rotate(Rot);

    sf::RectangleShape arrow(sf::Vector2f(ARROWX,ARROWY));
    arrow.setOrigin(0,ARROWY/2);
    arrow.setFillColor(sf::Color::Red);
    arrow.setPosition(100,350);

    sf::Texture texture;
    texture.loadFromFile("stickman.png",sf::IntRect(20,20,32,32));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(arrow);
        window.draw(body);





        //
        // the following code is for rotation
        //
        if(toggle == 0 && isKeyBoardPressed==false)
        {
            Rot-=0.05;
            body.setRotation(Rot);
            arrow.setRotation(Rot);
            if(body.getRotation()<270)
                toggle=1;
        }
        if(toggle == 1 && isKeyBoardPressed==false)
        {
            Rot+=0.05;
            body.setRotation(Rot);
            arrow.setRotation(Rot);
            if(body.getRotation()<30)
                toggle=0;
        }

        //
        // Rotation code over
        //
        if(arrow.getPosition().x>WINSIZEX+100 || arrow.getPosition().y>WINSIZEY+100)
            system("pause");
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        isKeyBoardPressed=true;
        arrow.setOrigin(Bodyx/2,Bodyy/2);
        float angleInDeg=arrow.getRotation();
        float angleInRad= (M_PI*angleInDeg)/(180.f);
       xComp = initialVelocity*fabs(cos(angleInRad));
        yComp = initialVelocityY*fabs(sin(angleInRad));
      //  cout<<"x comp is "<<xComp<<"  y comp is "<<yComp<<"when angle is "<<arrow.getRotation()<<endl;
    }

if(isKeyBoardPressed)
{


   //temp comment arrow.move(xComp,-yComp+0.0001*n);
   //tempmovementy= -yComp+0.001*n;
   arrow.move(xComp,-yComp+0.009*n);
    n++;
    cout<<xComp<<"  "<<yComp<<endl;


}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return 0;
        window.display();
    }

    return 0;
}

