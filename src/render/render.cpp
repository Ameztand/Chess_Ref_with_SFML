#include "render.h"

//#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

void Renderer::render()
{
// 创建绿色的圆
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({300.f, 200.f});

    window_.clear();
    window_.draw(shape);
    window_.display();
}

void Renderer::initRender()
{

}
