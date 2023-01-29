# ProjektZaliczeniowy<br>
Projekt z zakresu inżynierii danych <br><br>

  Tematem projektu jest analiza danych z zakresu COVID-19.
  

Program przyjmuje 3 zbiory danych, każdy ze swoim rozszerzeniem <br>
<ul>
.txt : <li><a href="https://www.kaggle.com/datasets/meirnizri/covid19-dataset" target="_blank">COVID-19 dataset</a></li>
.csv : <li><a href="https://www.kaggle.com/datasets/iamhungundji/covid19-symptoms-checker?select=Cleaned-Data.csv
" target="_blank">COVID-19 Symptoms Checker</a></li>
.json : <li><a href="https://www.kaggle.com/datasets/sinakaraji/covid-vaccination-vs-death?select=covid-vaccination-vs-death_ratio.csv">COVID vaccination vs. mortality</a></li>
</ul>
Opis techniczny:<br>
Środowisko: Windows, Visual Studio, Gnuplot<br>
Używane biblioteki: nlohmann::json, biblioteki standardowe C++20 m.in. array, vector, views, algortihms<br><br>

Dokumentacja implementatora:<br>
Dane .txt, .csv, .json zostają odpowiednio wczytane do struktur Plik_1, Plik_2 oraz Plik_3.<br>
Wpisy niekompletne są pomijane.<br>

Filtrowanie danych oparte jest o moduł <ranges> z biblioteki standardowej, pozwalający na leniwe wykonywanie<br>
operacji na zbiorach danych, operacji takich jak filtrowanie danych czy ich transformacje.<br><br>

Wizualizowane dane to pojedyncze kolumny danych, <br>
np. dla danych .txt, pokazany zostaje wykres wieku osób młodszych niż 30 lat z zapaleniem płuc.<br><br>

Na wyjściu jest plik zawierający proste statystyki, w tym:<br>
Suma wartości<br>
Średnia<br>
Standardowe odchylenie<br>
Mediana<br><br><br>


Program na wejściu przyjmuje listę plików zgodnych z wyżej opisanym formatem.<br>
Dla każdego pliku zostaje przeprowadzona analiza, wyświetlane zostają wykresy,<br>
a wyjście zostaje zapisane w plikach [txt,csv,json].out .<br>
Dane wyjściowe to wybrane pomiary opisane w pliku wyjściowym<br>
np. dla danych .json, skumulowana ilość zmarłych w Tunezji z powodu Covid-19.<br>
