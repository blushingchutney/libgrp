#include <fstream>
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
