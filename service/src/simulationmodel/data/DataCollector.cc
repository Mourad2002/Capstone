#include "DataCollector.h"
#include <fstream>
#include <iostream>

DataCollector& DataCollector::getInstance() {
    static DataCollector instance;
    return instance;
}

DataCollector::DataCollector() {
    start_time = 0.0;
    end_time = 0.0;
}

DataCollector::~DataCollector() {}

void DataCollector::updateTotalTime(double dt) {
    total_time += dt;
}

void DataCollector::getInitTime() {
    start_time = total_time;
}

void DataCollector::getFinalTime() {
    end_time = total_time;
}

void DataCollector::collectData(const std::string& strategy) {
    std::string formattedData = strategy + "," +
    std::__cxx11::to_string(start_time) + "," +
    std::__cxx11::to_string(end_time) + "," +
    std::__cxx11::to_string(end_time - start_time);
    dataStorage.push_back(formattedData);
}

std::vector<std::string> DataCollector::retrieveData() const {
    return dataStorage;
}

void DataCollector::exportData() const {
    std::string filename = "speed.csv";
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    file << "Strategy,Start Time,End Time,Time Taken\n";  // headers

    for (const std::string& data : dataStorage) {
        file << data << std::endl;
    }
    file.close();
}
