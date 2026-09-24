#pragma once  // 防止重复包含

#include "IInputLayer.h"

#include <array>
#include <chrono>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace sf { class RenderWindow; class Event; }


class Input : public IInputLayer{
private:
    static constexpr int KEY_COUNT = static_cast<int>(sf::Keyboard::KeyCount);//101个按键

    //帧快照-原始数据
    std::array<bool,KEY_COUNT> rawKeys_ = {};
    sf::Vector2i rawMousePos_ = {};//保持原始数据
    bool rawMouseL_ = false;

    std::array<bool, KEY_COUNT> prevKeys_ = {};//上一帧按下情况
    std::array<std::chrono::steady_clock::time_point, KEY_COUNT> pressTime_ = {};// 按下时间戳
    //bool prevMouseL_ = false;

    //帧快照-加工数据
    std::array<IInputLayer::KeySta,  KEY_COUNT> keySta_ = {};
    //Position mousePos_ = {};
    bool mouseStaL_ = false;
    
    IInputLayer::MsgData msgData;//输出数据
    sf::RenderWindow& window_;//窗口事件

    void onEvent(const sf::Event& event);
    void translate();
    void updateMsgData();
    
public:
    explicit Input(sf::RenderWindow& window);//构造

    void poll() override;
    
    const IInputLayer::MsgData& getMsgData() const override;
};