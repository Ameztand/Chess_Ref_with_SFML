#include "render.h"

#include <iostream>

//#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

Renderer::Renderer(unsigned int logicW, unsigned int logicH)
    : window_(sf::VideoMode({logicW, logicH}), "Genshen??",
        sf::Style::Titlebar | sf::Style::Close)
{
    window_.setFramerateLimit(60);
}

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

void Renderer::onEnter()
{
    std::cout << "SFML 窗口已启动, 按下Eac退出。" << std::endl;
}

void Renderer::onExit()
{
    std::cout << "执行关闭窗口操作。" << std::endl;
    window_.close();
    std::cout << "SFML 窗口已关闭。" << std::endl;
}