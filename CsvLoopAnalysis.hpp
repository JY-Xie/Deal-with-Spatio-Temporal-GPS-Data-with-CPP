//
// Created by XieJiYe on 2024/3/21.
//

#ifndef TRANSFERDATAMMP_CSVLOOPANALYSIS_HPP
#define TRANSFERDATAMMP_CSVLOOPANALYSIS_HPP
#pragma once

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <vector>
#include "cmath"
#include "fstream"

class CsvLoopAnalysis {
public:
    double lng_max;
    double lng_min;
    double lat_max;
    double lat_min;
    int time_span_number;
    int grid_size;


    CsvLoopAnalysis(double lng_max=104.461712, double lng_min=103.761194, double lat_max=30.857668, double lat_min=30.298933, int time_span_number=8640, int grid_size=64);
    static std::chrono::system_clock::time_point string_to_time(const std::string& begin_time);
    int get_grid_y_idx(double y);
    int get_grid_x_idx(double x);
    void write_to_csv(const std::string& filename, const std::vector<std::vector<std::vector<long long>>>& data);

};


#endif //TRANSFERDATAMMP_CSVLOOPANALYSIS_HPP



//std::string read_csv() {
//    std::string filename = R"(..\metro_d_data.csv)";
//    std::ifstream file(filename);
//    std::string content;
//
//    // 检查文件是否成功打开
//    if (file.is_open()) {
//        // 一次性读取整个文件内容
//        std::stringstream buffer;
//        buffer << file.rdbuf();
//        content = buffer.str(); // 获取文件内容
//
//        // 关闭文件
//        file.close();
//
//        // 使用istringstream来按行分割内容
//        std::istringstream linesStream(content);
//        std::string line;
//
//        // 遍历每一行
////        while (std::getline(linesStream, line)) {
////            lineCount++;
////            std::istringstream lineStream(line);
////            std::string field;
////            std::vector<std::string> row;
////
////            // 遍历每一列（字段）
////            while (std::getline(lineStream, field, ',')) {
////                // 移除字段前后的空白字符（如空格、制表符等）
////                field.erase(std::remove_if(field.begin(), field.end(), ::isspace), field.end());
////                // 添加字段到当前行的vector中
////                row.push_back(field);
////            }
////
////            // 处理每一行的数据
////            for (const auto& col : row) {
////                std::cout << col << " | "; // 打印每个字段，用" | "分隔
////            }
////            std::cout << std::endl;
////        }
////    } else {
////        std::cerr << "Unable to open file" << std::endl;
////    }
//    }
//    return content;
//}

//std::vector<std::vector<std::vector<double>>> create_grid(int size=64){
//    double lng_max = 104.461712;
//    double lng_min = 103.761194;
//    double lat_max = 30.857668;
//    double lat_min = 30.298933;
//
//    auto width = lng_max - lng_min;
//    auto height = lat_max - lat_min;
//
//    auto unit_width = width / size;
//    auto unit_height = height / size;
//
//    std::vector<std::vector<std::vector<double>>> grid_mtx(4, std::vector<std::vector<double>>(64, std::vector<double>(64, 0.0)));
//    for (int i = 0; i < 64; ++i) {
//        double begin_lat = lat_max - i * unit_height;
//        for (int j = 0; j < 64; ++j) {
//            grid_mtx[0][i][j] = lng_min + (j + 1) * unit_width;
//            grid_mtx[1][i][j] = lng_min + j * unit_width;
//            grid_mtx[2][i][j] = begin_lat;
//            grid_mtx[3][i][j] = begin_lat - unit_height;
//        }
//    }
//    return grid_mtx;
//}