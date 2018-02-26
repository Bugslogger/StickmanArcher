#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include<cstring>
#include<SFML/Window.hpp>
#include"RoundedRect.hpp"
bool hasArrowTouchTarget=false;
const int Bodyx=20;
float Rot=359;
const int Bodyy=100;
const int ARROWX=100;
const int ARROWY=20;
const int WINSIZEX=1000;
const int WINSIZEY=600;
bool isKeyBoardPressed=false;

float xComp;
float yComp;
float ang;
float ang1;
float initialVelocityY=2.2;
float initialVelocity=6.0;
float n=0.1;//n is the equivalent of time
float numberUntilHmax;
const float PowerSelectorInitPosX=50;
const float PowerSelectorInitPosY=30;
const float TarX=25;
const float TarY=100;
int PowerFactor=0;
float temp = initialVelocity/1020.f;
int a=0;
 float b=255;

const float TarCenY=350;
const float TarCenX= WINSIZEX-100;

float moveTar = 0.1;
using namespace std;


    int main(void){
        bool checkCollision(sf::RectangleShape,sf::RectangleShape);
    int toggle = 0;
    int toggle2=0;
    bool RotatorDecider(sf::RectangleShape);
    sf::RenderWindow window(sf::VideoMode(WINSIZEX,WINSIZEY), "SFML works!");


//RoundedRectange rf(12,12);
    sf::RectangleShape body(sf::Vector2f(Bodyx,Bodyy));
    body.setPosition(100,350);
    body.setOrigin(Bodyx/2,Bodyy/2);
    body.rotate(Rot);

    sf::RectangleShape arrow(sf::Vector2f(ARROWX,ARROWY));
    arrow.setOrigin(0,ARROWY/2);
    arrow.setFillColor(sf::Color::Red);
    arrow.setPosition(100,350);

    sf::RectangleShape TarCentre(sf::Vector2f(TarX,TarY));
    TarCentre.setOrigin(TarX/2,TarY/2);
    TarCentre.setFillColor(sf::Color(255,255,255));
    TarCentre.setPosition(TarCenX,TarCenY);

    sf::RectangleShape TarMed(sf::Vector2f(TarX,TarY));
    TarMed.setOrigin(TarX/2,TarY/2);
    TarMed.setFillColor(sf::Color(200,0,0));
    TarMed.setPosition(TarCenX,TarCenY+TarY);

    sf::RectangleShape TarMedu(TarMed);
    TarMedu.setPosition(TarCenX,TarCenY-TarY);

    sf::RectangleShape TarEx(sf::Vector2f(TarX,TarY));
    TarEx.setOrigin(TarX/2,TarY/2);
    TarEx.setFillColor(sf::Color(255,255,255));
    TarEx.setPosition(TarCenX,TarMed.getPosition().y+TarY);

    sf::RectangleShape TarExu(TarEx);
    TarExu.setPosition(TarCenX,TarMedu.getPosition().y-TarY);

    sf::RectangleShape powerSelector(sf::Vector2f(30,20));
    powerSelector.setPosition(PowerSelectorInitPosX,PowerSelectorInitPosY);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                sf::RenderWindow win2(sf::VideoMode(300,300),"haha");
                win2.display();

                window.close();
            }
        }

        window.clear();
        window.draw(arrow);
        window.draw(body);
        window.draw(TarCentre);
        window.draw(TarMed);
        window.draw(TarMedu);
        window.draw(TarEx);
        window.draw(TarExu);
        window.draw(powerSelector);


            window.display();




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
        // Movement of target
        //
            TarCentre.move(0,moveTar);
            TarMed.move(0,moveTar);
            TarMedu.move(0,moveTar);
            TarEx.move(0,moveTar);
            TarExu.move(0,moveTar);

            static bool R=false;

            if(!R)
            {
                PowerFactor++;
                 powerSelector.move(0.1,0);
                b-=0.25;
                if(b<0)
                    R=true;
            }
            if(R)
            {
                PowerFactor--;
                powerSelector.move(-0.1,0);
                b+=0.25;
                if(b>255)
                    R=false;
            }


          powerSelector.setFillColor(sf::Color(255,b,b));


 if(checkCollision(arrow,TarCentre)||checkCollision(arrow,TarEx)||checkCollision(arrow,TarExu)||checkCollision(arrow,TarMed)||checkCollision(arrow,TarMedu))
                hasArrowTouchTarget=true;
if(hasArrowTouchTarget)
    arrow.move(0,moveTar);

            if(TarEx.getPosition().y>WINSIZEY)
                moveTar=-moveTar;
            if(TarExu.getPosition().y<0)
                moveTar=-moveTar;


        //
        //Rotation Code Over
        //
        if(arrow.getPosition().x>WINSIZEX+100 || arrow.getPosition().y>WINSIZEY+100)
            system("pause");
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {

        initialVelocity=temp*PowerFactor;
        cout<<"here the power factor is "<<PowerFactor<<" the temp is constant of value "<<temp<<" and velocity is "<<initialVelocity<<endl;

        isKeyBoardPressed=true;
        arrow.setOrigin(Bodyx,Bodyy/2);
        float angleInDeg=arrow.getRotation();
        float angleInRad= (M_PI*angleInDeg)/(180.f);
       xComp = initialVelocity*fabs(cos(angleInRad));
        yComp = initialVelocityY*fabs(sin(angleInRad));
        ang = arrow.getRotation();
         numberUntilHmax = 2*yComp/(0.009);// analogous to calculating time from Hmax
    }
if(isKeyBoardPressed && !hasArrowTouchTarget)
{

        ang1 = arrow.getRotation()+(2*(360-ang)/(numberUntilHmax));
    arrow.setRotation(ang1);
   arrow.move(xComp,-yComp+0.009*n);
    n++;
}



}
        }




bool checkCollision(sf::RectangleShape ARROW, sf::RectangleShape B)
{

if((ARROW.getPosition().x>(TarCenX-TarX/2))&& (ARROW.getPosition().x<(TarCenX+TarX/2))&&((ARROW.getPosition().y)>(B.getPosition().y-(B.getSize().y)/2))&&(ARROW.getPosition().y<(B.getPosition().y+(B.getSize().y)/2)))
    return true;

}

