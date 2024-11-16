#include <ksgrp.hxx>

int main() {
    KSGRP grp;
    grp.loadFromFile("test.grp");

    std::vector<uint8_t> README_dot_md = grp.getData(grp.find("README.md"));
    README_dot_md.push_back('\0');

    printf("\n== README.md START ==\n");
    printf("%s", README_dot_md.data());
    printf("\n== README.md END ==\n");
    
    return 0;
}
