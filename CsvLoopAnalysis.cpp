//
// Created by XieJiYe on 2024/3/21.
//


#include "CsvLoopAnalysis.hpp"

CsvLoopAnalysis::CsvLoopAnalysis(double lng_max, double lng_min, double lat_max, double lat_min, int time_span_number, int grid_size) {
    this->lng_max = lng_max;
    this->lng_max = lng_max;
    this->lng_max = lng_max;
    this->lng_max = lng_max;
    this->grid_size = grid_size;
    this->time_span_number = time_span_number;
}

std::chrono::system_clock::time_point CsvLoopAnalysis::string_to_time(const std::string& time_str) {
    std::istringstream ss(time_str);
    std::tm tm = {};
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        // Handle error, e.g. by throwing an exception
        return std::chrono::system_clock::from_time_t(0);
    }
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

int CsvLoopAnalysis::get_grid_y_idx(double y) {
    auto height = this->lat_max - this->lat_min;

    auto unit_height = height / this->grid_size;

    int y_idx = floor((this->lat_max - y) / unit_height);
    return y_idx;
}

int CsvLoopAnalysis::get_grid_x_idx(double x) {
    auto width = this->lng_max - this->lng_min;

    auto unit_width = width / this->grid_size;

    int y_idx = floor((x - this->lng_min) / unit_width);
    return y_idx;
}

void CsvLoopAnalysis::write_to_csv(const std::string &filename, const std::vector<std::vector<std::vector<long long int>>> &data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& matrix : data) {
            for (const auto& row : matrix) {
                std::stringstream ss;
                for (size_t i = 0; i < row.size(); ++i) {
                    ss << row[i];
                    if (i != row.size() - 1) {
                        ss << ",";
                    }
                }
                file << ss.str();
                file << "\n";
            }
            if (&matrix != &data.back()) {
                file << "\n";
            }
        }
        file.close();
    } else {
        throw std::runtime_error("Unable to open file for writing.");
    }

}
