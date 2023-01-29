#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <string>
#include <fstream>
#include <sstream>
#include <ranges>
#include <numeric>

#include "json.h"

#include "Plik_1.h"
#include "Plik_2.h"
#include "Plik_3.h"
#include "Algorithm.h"


 vector<Plik_3> ReadJson(const  string& filename) {
     ifstream input(filename);
    if (input.is_open() == false) {
        throw  runtime_error("[ERROR] Couldn't open file.");
    }

    using json = nlohmann::json;
    json data = json::parse(input);

     vector<Plik_3> records{};

    size_t id = 1;
    for (const auto& elem : data) {

        try {
            Plik_3 record = Plik_3::FromJson(elem); //³apiemy wyjatki kiedy brakuje danych 
            records.push_back( move(record)); //jesli przeczyta¹³ wartosc to jest wpisaywana do wektora 
        }
        catch ( exception&) {
             cout << "[ERROR] ReadJson(): Missing data in json object with id " << id << ".\n";
        }

        ++id;
    }

    return records;
}

template<typename RecordType>
 vector<RecordType> ReadCsv(const  string& filename) {

     ifstream input(filename);
    if (input.is_open() == false) {
        throw  runtime_error("[ERROR] ReadCsv(): Couldn't open file.");
    }

     string labelsLine{};
     getline(input, labelsLine);

   

    size_t id = 1;
     vector<RecordType> records{};

     string line{};
    while ( getline(input, line)) {
        auto split = line |  ranges::views::split(',');

         vector< string> fields{};
        for (const auto& field : split) {
            fields.push_back({ field.begin(), field.end() });
        }

        
            auto record = RecordType::FromFields(fields);
            records.push_back( move(record));
       
        ++id;
    }

    return records;
}

int main(int argc, char* argv[]) {
    
    if (argc <= 1) {
         cout << "Please provide input files in a form of a .txt, .csv or .json file.\n";
        return EXIT_FAILURE;
    }

     vector< string> myFiles = {
        "data/1.covid_data_min.txt",
        "data/2.china_symptoms.csv",
        "data/3.vacc_vs_death.json"
    };
    for (size_t i = 0; i < myFiles.size(); ++i) {

       const  string filename = myFiles[i];

        if (filename.ends_with(".txt")) {
            // Read data
            auto records = ReadCsv<Plik_1>(filename);

            // Prepare data
            auto filtered = records |  views::filter([](auto record) {return record.age < 30; }) |  views::filter([](auto record) {return record.pneumonia; });
            auto age = filtered |  views::transform([](auto record) {return record.age; });

            // Output results
             ofstream output{ "txt.out" };
            output << "People under 30 years old with pneumonia: " <<  distance(filtered.begin(), filtered.end()) << "\n";
            output << "Stats about their age:\n";
            output << "Mean: " <<                Algorithm::Mean({age.begin(), age.end()}) << "\n";
            output << "Stdandard Deviation: " << Algorithm::StdDev({ age.begin(), age.end() }) << "\n";
            output << "Median: " <<              Algorithm::Median({ age.begin(), age.end() }) << "\n";

            // Visualize data
            PlotData({ age.begin(), age.end() });
        }

        if (filename.ends_with(".csv")) {
           // Read data
           auto records = ReadCsv<Plik_2>(filename);

           // Prepare data
           auto filtered = records |  views::filter([](auto record) {return record.age_10_19; }) |  views::filter([](auto record) {return record.fever; });
           auto nasalCongestion = filtered |  views::transform([](auto record) {return record.nasalCongestion; });

           // Output results
            ofstream output{ "csv.out" };
           output << "People aged 10-19 years old with fever: " <<  distance(filtered.begin(), filtered.end());

           // Visualize data
           PlotData({ nasalCongestion.begin(), nasalCongestion.end() });
        }

        if (filename.ends_with(".json")) {
            // Read data
            auto records = ReadJson(filename);

            // Prepare data
            auto filtered = records |  views::filter([](auto record) {return record.country == "Tunisia"; });
            auto newDeahts = filtered |  views::transform([](auto record) {return record.new_deaths; });

            auto newDeathsSum =  accumulate(newDeahts.begin(), newDeahts.end(), 0, [](int a, int new_deaths) { return a + new_deaths; });

            // Output results
             ofstream output{ "json.out" };
            output << "Amount of new daily deaths in Tunisia: " << newDeathsSum << "\n";
            output << "Stats about those deaths:\n";
            output << "Mean: " << Algorithm::Mean({ newDeahts.begin(), newDeahts.end() }) << "\n";
            output << "Stdandard Deviation: " << Algorithm::StdDev({ newDeahts.begin(), newDeahts.end() }) << "\n";
            output << "Median: " << Algorithm::Median({ newDeahts.begin(), newDeahts.end() }) << "\n";

            // Visualize data
            PlotData({ newDeahts.begin(), newDeahts.end() });
        }
    }
    
    return 0;
}