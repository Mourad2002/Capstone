/**
 * @file DataCollector.h
 * @brief Singleton class for collecting, retrieving, and exporting data.
 *
 * Provides functionality for data collection, retrieval, and export within the system.
 * This class follows the singleton pattern to ensure only one instance exists.
 */

#ifndef DATA_COLLECTOR_H_
#define DATA_COLLECTOR_H_

#include <vector>
#include <string>
#include <string.h>
#include <iostream>

/**
 * @class DataCollector
 * @brief Singleton class that handles data collection, storage, and export.
 * 
 * The DataCollector class is designed to collect, store, and export data. 
 * It provides methods to collect data from various strategies,
 * retrieve the collected data, export the data, and manage timing information for data collection intervals.
 */
class DataCollector {
 public:
    /**
     * @brief Returns the singleton instance of the DataCollector.
     * @return Reference to the singleton DataCollector instance.
     */
    static DataCollector& getInstance();

    /**
     * @brief Collects data based on the provided strategy.
     * @param strategy A string describing the strategy used for data collection.
     */
    void collectData(const std::string& strategy);

    /**
     * @brief Retrieves all stored data.
     * @return A vector containing the stored strings.
     */
    std::vector<std::string> retrieveData() const;

    /**
     * @brief Exports the collected data.
     */
    void exportData() const;

    /**
     * @brief Retrieves the initial time of the data collection session.
     */
    void getInitTime();

    /**
     * @brief Retrieves the final time of the data collection session.
     */
    void getFinalTime();

    /**
     * @brief Updates the total time spent in data collection.
     * @param dt The time increment to add to the total time.
     */
    void updateTotalTime(double dt);

    // Copy and assignment operations are deleted to enforce singleton property.
    DataCollector(DataCollector const&) = delete;
    DataCollector& operator=(DataCollector const&) = delete;

 private:
    /**
     * @brief Constructor for DataCollector.
     * Constructor is private to prevent instantiation outside of getInstance().
     */
    DataCollector();

    /**
     * @brief Destructor for DataCollector.
     */
    ~DataCollector();

    double total_time;
    double start_time;
    double end_time;
    std::vector<std::string> dataStorage;
};

#endif  // DATA_COLLECTOR_H_
