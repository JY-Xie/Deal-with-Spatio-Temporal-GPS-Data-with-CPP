//
// Created by XieJiYe on 2024/3/20.
//
#include "CsvLoopAnalysis.hpp"
#include "Csv.hpp"


int main(){
    CsvLoopAnalysis csvLoopAnalysis(104.461712, 103.761194, 30.857668, 30.298933, 8640, 64);
    std::vector<std::vector<std::vector<long long>>> result_matrix(csvLoopAnalysis.time_span_number, std::vector<std::vector<long long>>(64, std::vector<long long>(64, 0)));
    auto time_begin = CsvLoopAnalysis::string_to_time("2021-01-01 00:00:00");


    io::CSVReader<3> in("../metro_d_data.csv");
    in.read_header(io::ignore_extra_column, "DESTDATE", "lng", "lat");
    std::string DESTDATE; std::string lng; std::string lat;

    int i = 0;
    int j = 1;
    while(in.read_row(DESTDATE, lng, lat)){
        // 计算属于哪个时间片
        auto time_point = CsvLoopAnalysis::string_to_time(DESTDATE);
        auto duration = time_point - time_begin;
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
        auto time_span = seconds / 900;

        // 计算属于哪个网格空间
        double LAT = std::stod(lat);
        double LNG = std::stod(lng);

        if (csvLoopAnalysis.lat_min <= LAT <= csvLoopAnalysis.lat_max && csvLoopAnalysis.lng_min <= LNG <= csvLoopAnalysis.lng_max) {
            int x_idx = csvLoopAnalysis.get_grid_x_idx(LNG);
            int y_idx = csvLoopAnalysis.get_grid_y_idx(LAT);
            if (x_idx < 64 && y_idx < 64){
            result_matrix[time_span][x_idx][y_idx]++;
            }
        }
        ++i;
        if (i == 500000) {
            printf("already finish %d * 50w row\n", j);
            j++;
            i = 0;
        }
    }

    csvLoopAnalysis.write_to_csv("../data.csv", result_matrix);

    return 0;
}
