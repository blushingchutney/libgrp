#pragma once

#include <vector>
#include <cstdint>
#include <string>

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
        std::vector<std::streampos> positions;
        std::string path;
        
    public:
        KSGRP();
        ~KSGRP();

        void loadFromFile(const char *path);

        int32_t find(const char *name, int32_t start = -1, int32_t end = -1);

        std::vector<uint8_t> getData(int32_t index);
};
