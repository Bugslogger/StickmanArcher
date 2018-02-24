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
const int WINSIZEX=600;
const int WINSIZEY=400;
bool isKeyBoardPressed=false;
float xComp;
float yComp;
float initialVelocity=1;
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


  sf::Image image;
    //image.loadFromFile("stickman.png");
    sf::Texture texture;

    sf::Sprite sprite(texture);
//    texture.loadFromFile("D:/proj/GarbageSFML/images/stickman.png");

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
        cout<<arrow.getRotation()<<endl;



  //      std::cout<<body.getRotation()<<std::endl;
        //
        // the following code is for rotation
        //
        if(toggle == 0 && isKeyBoardPressed==false)
        {
            Rot-=0.05;
            body.setRotation(Rot);
            arrow.setRotation(Rot);
            if(body.getRotation()<290)
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        isKeyBoardPressed=true;
        arrow.setOrigin(Bodyx/2,Bodyy/2);
        float angleInDeg=arrow.getRotation();
        float angleInRad= (M_PI*angleInDeg)/(180.f);
       xComp = initialVelocity*fabs(cos(angleInRad));
        yComp = initialVelocity*fabs(sin(angleInRad));
   // cout<<"The angle in Rad is  : "<<angleInRad<<endl<<angleInDeg<<endl;
    cout<<"the xComponent is   "<<xComp<<"   and the y component is "<<yComp<<endl;
    cout<<"thus the initial velocity must be "<<sqrt(xComp*xComp+yComp*yComp);
    }
if(isKeyBoardPressed)
{
    xComp=0.1;
    yComp=0.1;
    arrow.move(xComp,-yComp+0.0001*n);
    n++;
}



        window.display();
    }

    return 0;
}

