#include "lib/MP3_Metadata.h"

#include <iostream>
#include <fstream>



void CreateOutput(const std::list<std::unique_ptr<mp3_idv2_4::Frame>>& frames) {
    std::ofstream out("output.txt");
    for (const auto& frame: frames) {
        if (frame != nullptr) {
            out << *frame << std::endl;
        }
    }
    out.close();
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "You have to enter filepath" << std::endl;
        return -1;
    }
    std::string file_path = argv[1];
    if (!file_path.ends_with(".mp3")) {
        std::cout << "Only mp3 files supported" << std::endl;
        return -1;
    }

    std::ifstream fin(file_path);
    if (!fin) {
        std::cout << "There's no such file" << std::endl;
        return -1;
    }
    mp3_idv2_4::MP3_Metadata metadata(fin);
    fin.close();
    CreateOutput(metadata.GetFrames());
    return 0;
}
