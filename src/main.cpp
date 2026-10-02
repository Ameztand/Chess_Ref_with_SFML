//#include <windows.h>
#include <iostream>

#include "config.h"

#include "./input/input.h"
#include "./render/render.h"
#include "./include/utils/time_clock.h"

int main() {
    //加载数据

    //创建对象
    Renderer render(kLogicWidth, kLogicHeight);//创建窗口，逻辑像素
    Input input(render.getWindow());
    TimeClock clock;

    render.onEnter();

    while (render.isOpen()) {
        input.poll();
        const auto& msgData = input.getMsgData();

        if (msgData.Esc == IInputLayer::KeySta::Falling) {
            std::cout << "执行Esc退出。" << std::endl;
            render.onExit();
            break;
        }

        //logic(data, clock.now());
        render.render();
    }

    std::cout << "程序正常退出。" << std::endl;

    return 0;
}