#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "json.h"

#include "Plik_1.h"
#include "Plik_2.h"
#include "Plik_3.h"
#include "Algorithm.h"
using namespace std;

 vector<Plik_3> ReadJson(const  string& filename) {
    ifstream input(filename);
   if (input.is_open() == false) {
      cout<<"[ERROR] Couldn't open file.";
   }

   using json = nlohmann::json;
   json data = json::parse(input);

    vector<Plik_3> records{};

   for (const auto& elem : data) {
         Plik_3 record = Plik_3::FromJson(elem);
         records.push_back(record);  
   }

   return records;
}

template<typename RecordType>
 vector<RecordType> ReadCsv(const  string& filename) {

    ifstream input(filename);
   if (input.is_open() == false) {
      cout<<"[ERROR] ReadCsv(): Couldn't open file.";
   }

    string labelsLine{};
    getline(input, labelsLine);

    vector<RecordType> records{};

    string line{};
   while ( getline(input, line)) {
      auto fields = SplitLine(line);

         auto record = RecordType::FromFields(fields);
         records.push_back(record);
    
   }

   return records;
}

int main(int argc, char* argv[]) {

   if (argc <= 1) {
       cout << "Please provide input files in a form of a .txt, .csv or .json file.\n";
      return 1;
   }

    vector< string> myFiles = {
        "data/1.covid_data_min.txt",
        "data/2.china_symptoms.csv",
        "data/3.vacc_vs_death.json"
   };
   for (size_t i = 0; i < myFiles.size(); ++i) {

      const  string filename = myFiles[i];

      if (EndsWith(filename, ".txt")) {
         // Read data
         auto records = ReadCsv<Plik_1>(filename);

         // Prepare data
          vector<Plik_1> filtered{};
         
         for (int i = 0; i < records.size(); i++) {
            const auto& record = records[i];
            if ((record.age < 30) && (record.pneumonia)) {
               filtered.push_back(record);
            }
         }
         vector<int>age{};
         for (int i = 0; i < filtered.size(); i++) {
            const auto& record = filtered[i];
            age.push_back(record.age);
         }

         // Output results
          ofstream output{ "txt.out" };
         output << "People under 30 years old with pneumonia: " << filtered.size() << '\n';
         output << "Stats about their age:\n";
         output << "Mean: " << Algorithm::Mean(age) << "\n";
         output << "Stdandard Deviation: " << Algorithm::StdDev(age) << "\n";
         output << "Median: " << Algorithm::Median(age) << "\n";

         cout << "Dane .txt + wykres\n\n";
            cout << "people under 30 years old with pneumonia: " << distance(filtered.begin(), filtered.end()) << "\n";
            cout << "stats about their age:\n";
            cout << "mean: " << Algorithm::Mean(age) << "\n";
            cout << "stdandard deviation: " << Algorithm::StdDev(age) << "\n";
            cout << "median: " << Algorithm::Median(age) << "\n\n";
         //   cout << "wykres przedstawia zaleznosc zachorowan na zapalenie pluc od wieku badanych.\n na poziomej skali oznaczona jest ilosc zachorowan, na pionowej wiek badanych.\n";
        //    cout << "Zageszczenie wykresu punktowego informuje nas o czestototliwosci wystapien\n\n\n";
         // Visualize data
         PlotData(age);
      }

      if (EndsWith(filename, ".csv")) {
         // Read data
         auto records = ReadCsv<Plik_2>(filename);
         // Prepare data
          vector<Plik_2> filtered{};
         for (int i = 0; i < records.size(); i++) {
            const auto& record = records[i];
            if (record.age_10_19 && record.fever) {
               filtered.push_back(record);
            }
         }
         vector<int>nasalCongestion{};
         for (int i = 0; i < filtered.size(); i++) {
            const auto& record = filtered[i];
            nasalCongestion.push_back(record.nasalCongestion);
         }

         // Output results
          ofstream output{ "csv.out" };
         output << "People aged 10-19 years old with fever: " << filtered.size();

         cout << "Dane .csv\n";
         cout << "People aged 10-19 years old with nasalCongestion: " << filtered.size() << "\n";
         // Visualize data
         PlotData(nasalCongestion);
      }

      if (EndsWith(filename, ".json")) {
         // Read data
         auto records = ReadJson(filename);

         // Prepare data
          vector<Plik_3> filtered;
         for (int i = 0; i < records.size(); i++) {
            const auto& record = records[i];
            if (record.country == "Tunisia") {
               filtered.push_back(record);
            }
         }
          vector<int> newDeaths;
         for (int i = 0; i < filtered.size(); i++) {
            const auto& record = filtered[i];
            newDeaths.push_back(record.new_deaths);
         }
         int newDeathsSum = 0;
         for (int i = 0; i < newDeaths.size(); i++) {
            const auto& record = newDeaths[i];
            newDeathsSum += record;
         }


         // Output results
          ofstream output{ "json.out" };
         output << "Amount of new daily deaths in Tunisia: " << newDeathsSum << '\n';
         output << "Stats about those deaths:\n";
         output << "Mean: " << Algorithm::Mean(newDeaths) << "\n";
         output << "Stdandard Deviation: " << Algorithm::StdDev(newDeaths) << "\n";
         output << "Median: " << Algorithm::Median(newDeaths) << "\n";

         cout << "Dane .json + wykres\n";
         cout << "Amount of new daily deaths in Tunisia: " << newDeathsSum << "\n";
         cout << "Stats about those deaths:\n";
         cout << "Mean: " << Algorithm::Mean(newDeaths) << "\n";
         cout << "Stdandard Deviation: " << Algorithm::StdDev(newDeaths) << "\n";
         cout << "Median: " << Algorithm::Median(newDeaths) << "\n";
       //  cout << "Wykres przedstawia przyrost zgonow w Tunezji w ciagu roku.\n\n";

         // Visualize data
         PlotData1(newDeaths);
      }
   }

   return 0;
}