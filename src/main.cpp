//#include <optional>
#include <iostream>
//#include <windows.h>
#include "./input/input.h"
#include "./render/render.h"

int main() {
    Renderer render;
    Input input(render.getWindow());

    render.initRender();

    std::cout << "SFML 窗口已启动, 按下Eac退出。" << std::endl;

    while (render.isOpen()) {
        input.poll();
        const auto& data = input.getMsgData();

        if (data.Esc == IInputLayer::KeySta::Falling) {
            render.close();
            std::cout << "Esc退出。" << std::endl;
            break;
        }

        render.render();
    }

    std::cout << "程序正常退出。" << std::endl;
    return 0;
}