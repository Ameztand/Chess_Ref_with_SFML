#pragma once  // 防止重复包含

//#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
//#include <SFML/Graphics.hpp>

class Renderer{
private:
    sf::RenderWindow window_;//窗口事件

public:
    Renderer(unsigned int w = 1080, unsigned int h = 720) //初始化创建
        : window_(sf::VideoMode({w, h}), "Genshen??",
            sf::Style::Titlebar | sf::Style::Close) 
    {
        window_.setFramerateLimit(60);
    }

    void render();
    void initRender();

    //控制器
    bool isOpen() const { return window_.isOpen(); }
    void close()      { window_.close(); }
    sf::RenderWindow& getWindow() { return window_; }//不可以const
};