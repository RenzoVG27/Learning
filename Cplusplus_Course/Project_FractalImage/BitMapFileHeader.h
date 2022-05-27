#ifndef BIT_MAP_FILE_HEADER_H_
#define BIT_MAP_FILE_HEADER_H_

#include <cstdlib>

#pragma pack(push,2)

namespace fractal{
    
    struct sBitMapFileHeader{
        int8_t header[2]{'B','M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
    };

}

#pragma pack(pop)



#endif