#include <SFML/Graphics.hpp>

using namespace sf;

class PLAYER {
public:
    float dx,dy;
    FloatRect rect;
    bool onGround, down=false;
    Sprite sprite;
    float currentFrame;
    int ground=190, position=0; //0-static, 1-right, 2-left.

    PLAYER (Texture &Image)
    {
        sprite.setTexture(Image);
        rect = FloatRect(0,0,17,34);
        dx=dy=0;
        currentFrame=0;
    }

    void update(float time)
    {
        rect.left +=dx*time;
        if(!onGround) dy=dy+0.005*time;
        rect.top += dy*time;
        onGround=false;
        if(rect.top>ground){
            rect.top = ground; dy=0; onGround=true;
        }

        currentFrame +=0.01*time;
        if (currentFrame>3) currentFrame -=3;

        if (dx==0) sprite.setTextureRect(IntRect(257,0,17,34));                                         ///STATIC RIGHT
        if (dx==0 && position==2) sprite.setTextureRect(IntRect(257+17,0,-17,34));                      ///STATIC LEFT
        if (dx>0) {sprite.setTextureRect(IntRect(294+(int (currentFrame)*19),0,17,34)); position=1;}    ///RIGHT
        if (dx<0) {sprite.setTextureRect(IntRect(294+(int (currentFrame)*19)+17,0,-17,34)); position=2;}  ///LEFT
        if (dy<0 && dx>0)
            if(onGround==false) sprite.setTextureRect(IntRect(367,0,17,34));                      ///JUMP RIGHT
        if (dy<0 && dx<0)
            if(onGround==false) sprite.setTextureRect(IntRect(367+17,0,-17,34));                 ///JUMP LEFT
        if (position==1 && dy<0) sprite.setTextureRect(IntRect(367,0,17,34));                  ///STATIC
            else if(position==2 && dy<0) sprite.setTextureRect(IntRect(367+17,0,-17,34));
        if (position==1 && down && (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)))
            sprite.setTextureRect(IntRect(276,0,17,34));                            ///DOWN RIGHT
        if (position==2 && down && (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)))
            sprite.setTextureRect(IntRect(276+17,0,-17,34));                       ///DOWN LEFT

        sprite.setPosition(rect.left, rect.top);
        dx=0;
    }
};

int main()
{
    RenderWindow window(VideoMode(400,250), "Test!");
    Texture t;
    t.loadFromFile("characters.png");

    float currentFrame=1;

    PLAYER p(t);

    Clock clock;

     while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && p.down==false)
        {
            p.dx = -0.1;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && p.down==false)
        {
            p.dx =0.1;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) && p.down==false)
        {
           if (p.onGround){p.dy=-0.8; p.onGround=false;}
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
        {
            if (p.onGround) p.down=true;
        }
        if (!(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)))
        {
            if (p.onGround) p.down=false;
        }

        p.update(time);

        window.clear();
        window.draw(p.sprite);
        window.display();
    }

    return 0;
}
