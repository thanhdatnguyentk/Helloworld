
#include <SFML/Graphics.hpp>    

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy Bird");

    sf::CircleShape bird(10.f);
    bird.setFillColor(sf::Color::Red);

    sf::RectangleShape obstacle(sf::Vector2f(100, 50));
    obstacle.setFillColor(sf::Color::Green);
    obstacle.setPosition(800, 300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            bird.move(0, -10);
        }
        else
        {
            bird.move(0, 5);
        }

        obstacle.move(-5, 0);

        if (obstacle.getPosition().x < -100)
        {
            obstacle.setPosition(800, 300);
        }

        window.clear();
        window.draw(bird);
        window.draw(obstacle);
        window.display();
    }

    return 0;
}