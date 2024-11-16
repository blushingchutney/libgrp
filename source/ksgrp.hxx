#pragma once

#include <vector>
#include <cstdint>

class KSGRP {
    private:
        struct header_t {
            uint8_t signature[12];
            int32_t filecount;
        };

        struct entry_t {
            uint8_t filename[12];
            int32_t size;
        };

        header_t header;
        std::vector<entry_t> entries;
        
    public:
        KSGRP();
        ~KSGRP();

        void loadFromFile(const char *path);
};
