#ifndef BIT_MAP_INFO_HEADER_H_
#define BIT_MAP_INFO_HEADER_H_

#include <cstdlib>


#pragma pack(push,2)

namespace fractal{

    struct sBitMapInfoHeader{
        int32_t headerSize{40};
        int32_t width;
        int32_t height;
        int16_t planes{1};
        int16_t bitPerPixel{24};
        int32_t compression{0};
        int32_t dataSize{0};
        int32_t horizontalResolution{2400};
        int32_t verticalResolution{2400};
        int32_t colors{0};
        int32_t importantColors{0};
    };


}

#pragma pack(pop)


#endif