#include <fstream>
#include <cstring>

#include "ksgrp.hxx"

KSGRP::KSGRP() {}
KSGRP::~KSGRP() {}

void KSGRP::loadFromFile(const char *path) {
    std::ifstream fp(this->path = path, std::ios::binary);

    fp.read((char*)&header, sizeof(header_t));

    entries.resize(header.filecount);
    fp.read((char*)entries.data(), sizeof(entry_t) * header.filecount);

    positions.resize(header.filecount);
    for(int32_t i = 0;i < header.filecount;i++) {
        positions[i] = fp.tellg();
        fp.seekg(entries[i].size, std::ios::cur);
    }

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

std::vector<uint8_t> KSGRP::getData(int32_t index) {
    std::ifstream fp(path, std::ios::binary);

    std::vector<uint8_t> data;
    data.resize(entries[index].size);

    fp.seekg(positions[index]);

    fp.read((char*)data.data(), entries[index].size);

    fp.close();
    return data;
}

const char* KSGRP::getIndexName(int32_t index) {
    std::string s = entries[index].filename;
    return s.c_str();
}
