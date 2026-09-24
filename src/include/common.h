#pragma once
#include <array>

// ========== 坐标 ==========
struct Position {
    int x = 0;
    int y = 0;

    // 成员函数形式重载 ==
    constexpr bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
    constexpr bool operator!=(const Position& other) const {
        return !(*this == other);
    }
};

//单位坐标(-1,-1)
inline constexpr Position Epos{-1, -1};

//默认棋盘ID表（初始化）白色在下
inline constexpr std::array<std::array<int, 8>, 8> EpieceID = {{
    {{ -5, -4, -3, -2, -1, -3, -4, -5 }},
    {{ -6, -6, -6, -6, -6, -6, -6, -6 }},
    {{ 0, 0, 0, 0, 0, 0, 0, 0 }},
    {{ 0, 0, 0, 0, 0, 0, 0, 0 }},
    {{ 0, 0, 0, 0, 0, 0, 0, 0 }},
    {{ 0, 0, 0, 0, 0, 0, 0, 0 }},
    {{ 6, 6, 6, 6, 6, 6, 6, 6 }},
    {{ 5, 4, 3, 2, 1, 3, 4, 5 }}
}};