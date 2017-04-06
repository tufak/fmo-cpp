#include "test-data.hpp"

extern const char* const IM_4x2_FILE = "assets/4x2.png";

extern const fmo::Dims IM_4x2_DIMS = {4, 2};

extern const std::array<uint8_t, 24> IM_4x2_BGR = {{
    0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, // RGBC
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, // MYKW
}};

extern const std::array<uint8_t, 6> IM_2x1_BGR = {{
    0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00 // YK
}};

extern const std::array<uint8_t, 8> IM_4x2_GRAY = {{
    0x1D, 0x95, 0x4C, 0xB2, // RGBC gray
    0x69, 0xE1, 0x00, 0xFF, // MYKW gray
}};

// IM_4x2_GRAY < 0x95
extern const std::array<uint8_t, 8> IM_4x2_LESS_THAN = {{
    0xFF, 0x00, 0xFF, 0x00, // FFTF
    0xFF, 0x00, 0xFF, 0x00, // FFFF
}};

// IM_4x2_GRAY > 0x95
extern const std::array<uint8_t, 8> IM_4x2_GREATER_THAN = {{
    0x00, 0x00, 0x00, 0xFF, // FFFT
    0x00, 0xFF, 0x00, 0xFF, // FTFT
}};

// abs(IM_4x2_GRAY - IM_4x2_LESS_THAN)
extern const std::array<uint8_t, 8> IM_4x2_ABSDIFF = {{
    0xE2, 0x95, 0xB3, 0xB2, // 1-R G 1-B C gray
    0x96, 0xE1, 0xFF, 0xFF, // 1-M Y 1-K W gray
}};

extern const std::array<uint8_t, 8> IM_4x2_RANDOM_1 = {{
    0xD3, 0xC1, 0xA6, 0x78, 0x89, 0x05, 0x37, 0x9D,
}};

extern const std::array<uint8_t, 8> IM_4x2_RANDOM_2 = {{
    0xB0, 0x0D, 0x43, 0x31, 0x88, 0x81, 0x35, 0x80,
}};

extern const std::array<uint8_t, 8> IM_4x2_RANDOM_3 = {{
    0x71, 0xB8, 0x6D, 0xA8, 0xD6, 0xC2, 0x80, 0x5C,
}};

// diff3(IM_4x2_RANDOM_1, IM_4x2_RANDOM_2, IM_4x2_RANDOM_3)
extern const std::array<uint8_t, 8> IM_4x2_MEDIAN3 = {{
    0xB0, 0xB8, 0x6D, 0x78, 0x89, 0x81, 0x37, 0x80,
}};

extern const std::array<uint8_t, 4> IM_2x2_GRAY = {{
    0x95, 0x4C, // GB gray
    0xE1, 0x00, // YK gray
}};

extern const std::array<uint8_t, 24> IM_4x2_GRAY_3 = {{
    0x1D, 0x1D, 0x1D, 0x95, 0x95, 0x95, 0x4C, 0x4C, 0x4C, 0xB2, 0xB2, 0xB2, // RGBC gray 3x
    0x69, 0x69, 0x69, 0xE1, 0xE1, 0xE1, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, // MYKW gray 3x
}};

extern const std::array<uint8_t, 12> IM_4x2_YUV420SP = {{
    0x1D, 0x95, 0x4C, 0xB2, // RGBC gray
    0x69, 0xE1, 0x00, 0xFF, // MYKW gray
    0x80, 0x80, 0x80, 0x80, // UVUV gray
}};

// YUV-to-RGB conversion is slightly more involved than just assuming that the Y value is
// brightness -- the Y value is assumed to be between 16 and 235.
extern const std::array<uint8_t, 24> IM_4x2_YUV2BGR = {{
    0x0F, 0x0F, 0x0F, 0x9B, 0x9B, 0x9B, 0x46, 0x46, 0x46, 0xBD, 0xBD, 0xBD,
    0x68, 0x68, 0x68, 0xF3, 0xF3, 0xF3, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
}};