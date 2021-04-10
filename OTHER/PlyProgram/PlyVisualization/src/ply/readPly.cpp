//
// Created by MagicXin on 2021/4/9.
//

#include "readPly.h"

void read_ply_file(const std::string filepath, std::vector<float3> &verts) {
    try {
        std::ifstream ss(filepath);
        if (ss.fail()) {
            throw std::runtime_error("Failed to open: " + filepath);
        }

        tinyply::PlyFile file;
        file.parse_header(ss);

        std::shared_ptr<tinyply::PlyData> vertices;

        try {
            vertices = file.request_properties_from_element("vertex", {"x", "y", "z"});
        }
        catch (const std::exception &e) {
            std::cerr << "tinyply exception: " << e.what() << std::endl;
        }

        manual_timer read_timer;

        read_timer.start();
        file.read(ss);
        read_timer.stop();

        const float parsing_time = static_cast<float>(read_timer.get()) / 1000.f;
        std::cout << "\tparsing in " << parsing_time << " seconds" << std::endl;

        if (vertices) std::cout << "\tRead " << vertices->count << " total vertices " << std::endl;

        const size_t numVerticesBytes = vertices->buffer.size_bytes();
        verts.resize(vertices->count);
        std::memcpy(verts.data(), vertices->buffer.get(), numVerticesBytes);
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

void manual_timer::start() {
    t0 = std::chrono::high_resolution_clock::now();
}

void manual_timer::stop() {
    timestamp = std::chrono::duration<double>(
            std::chrono::high_resolution_clock::now() - t0).count() * 1000.0;
}

const double &manual_timer::get() {
    return timestamp;
}