// dushi-cli

#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

#include <dushi.h>

int main(int argc, char *argv[]) {
    if(argc <= 1){
        std::cout << "jammr :-P!";
        exit(1);
    }

    dushi_load();
    cout << dushi_bezem(argv[1], 2, 5);
    return 0;
}
