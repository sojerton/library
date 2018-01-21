#include <SFML/Graphics.hpp>

using namespace sf;

class PLAYER {
public:
    float dx,dy;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;
    int ground=150;

    PLAYER (Texture &Image)
    {
        sprite.setTexture(Image);
        rect = FloatRect(0,0,40,50);

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

        if (dx>0)sprite.setTextureRect(IntRect(294+(int (currentFrame)*19),0,17,34));
        if (dx<0)sprite.setTextureRect(IntRect(294+(int (currentFrame)*19)+17,0,-17,34));
        if (dy>0 && dx>0)sprite.setTextureRect(IntRect(367,0,17,34));
        if (dy<0 && dx<0)sprite.setTextureRect(IntRect(367+17,0,-17,34));

        sprite.setPosition(rect.left, rect.top);
        dx=0;
    }
};

int main()
{
    RenderWindow window(VideoMode(200,200), "Test!");

    CircleShape MyCircle(100.f);
    MyCircle.setFillColor(Color::Green);

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

        if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
        {
            p.dx = -0.1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
        {
            p.dx =0.1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
        {
           if (p.onGround){p.dy=-0.8; p.onGround=false;}
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
        {

        }

        p.update(time);

        window.clear();
        window.draw(p.sprite);
        window.display();
    }

    return 0;
}
