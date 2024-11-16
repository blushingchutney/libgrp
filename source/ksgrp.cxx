#include <fstream>
#include <string>
#include <cstring>

#include "ksgrp.hxx"

KSGRP::KSGRP() {}
KSGRP::~KSGRP() {}

void KSGRP::loadFromFile(const char *path) {
    std::ifstream fp(path, std::ios::binary);

    fp.read((char*)&header, sizeof(header_t));

    entries.resize(header.filecount);
    fp.read((char*)entries.data(), sizeof(entry_t) * header.filecount);

    fp.close();
}

int32_t KSGRP::find(const char *_name, int32_t start, int32_t end) {
    if(start < 0) start = 0;
    if(end < 0) end = header.filecount;
    
    std::string name = _name;
    name.resize(12, '\0');

    for(int32_t i = start;(i < end) && (i < header.filecount);i++) {
        if(!strncmp(name.c_str(), (char*)entries[i].filename, 12)) {
            return i;
        }
    }

    return -1;
}

