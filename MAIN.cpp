#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include<cstring>
using namespace std;
const int Bodyx=20;
float Rot=359;
float Rot2=3;
const int Bodyy=100;
const int ARROWX=100;
const int ARROWY=20;
const int WINSIZEX=1000;
const int WINSIZEY=600;
bool isKeyBoardPressed=false;
bool isEnterPressed=false;
float xComp;
float yComp;
float xComp2;
float yComp2;
float ang;
float ang1;
float angp;
float angp2;
float initialVelocityY=2.2;
float initialVelocity=3.0;
float n=0.1;//n is the equivalent of time
float n2=0.1;//n2 is the n equivalent for second
float numberUntilHmax;
float numberUntilHmax2;
int main()
{
    int toggle = 0;
    int toggle2=0;
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

    sf::RectangleShape body2(sf::Vector2f(Bodyx,Bodyy));
    body2.setPosition(900,350);
    body2.setOrigin(Bodyx/2,Bodyy/2);
    body2.rotate(Rot2);
      body2.setFillColor(sf::Color(255,0,124));

      sf::RectangleShape arrow2(sf::Vector2f(ARROWX,ARROWY));
      arrow2.setPosition(900,350);
      arrow2.setOrigin(ARROWX,ARROWY/2);
      arrow2.rotate(Rot2);
      arrow2.setFillColor(sf::Color(255,255,0));


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
        window.draw(body2);
        window.draw(arrow2);





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

        //
        //Rotation for body2
        //

        if(toggle2==0 && !isEnterPressed)
        {
            Rot2+=0.05;
            body2.setRotation(Rot2);
            arrow2.setRotation(Rot2);
            if(body2.getRotation()>89)
                toggle2=1;

        }
        if(toggle2==1 && !isEnterPressed)
        {
            Rot2-=0.05;
            arrow2.setRotation(Rot2);
            body2.setRotation(Rot2);
            if(body2.getRotation()<2)
                toggle2=0;
        }


        //
        //Rotation Code Over
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
        ang = arrow.getRotation();
         numberUntilHmax = 2*yComp/(0.009);// analogous to calculating time from Hmax
    }
if(isKeyBoardPressed)
{

        angp = arrow.getRotation()+(2*(360-ang)/(numberUntilHmax));
    arrow.setRotation(angp);
   arrow.move(xComp,-yComp+0.009*n);
    n++;
}

//
// if enter is pressed
//

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        isEnterPressed=true;
       arrow2.setOrigin(Bodyx/2,Bodyy/2);
        float angleInDeg=arrow2.getRotation();
        float angleInRad= (M_PI*angleInDeg)/(180.f);
       xComp2 = initialVelocity*fabs(cos(angleInRad));
        yComp2 = initialVelocityY*fabs(sin(angleInRad));
        angp = arrow2.getRotation();
         numberUntilHmax2 = 2*yComp2/(0.009);// analogous to calculating time from Hmax
        }
if(isEnterPressed)
{
    angp2 = arrow2.getRotation()-(2*(angp)/(numberUntilHmax2));
   arrow2.setRotation(angp2);
   arrow2.move(-xComp2,-yComp2+0.009*n2);
    n2++;
   }

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return 0;
        window.display();
}
    return 0;
    }





