# C++ β-4 Travelling Salesman Problem

This collection of programs computes a solution to the Travelling Salesman Problem.

All the programs work on the Symmetric travelling salesman problem, which means that
all edges (roads/connections) can be traversed in both directions.

On top of this, every solution must begin and end at the same city.


| Version | Method                | Threading | City Limit | Description                                                                        |
| ------- | --------------------- | --------- | ---------- | ---------------------------------------------------------------------------------- |
| 1.0     | Bruteforce            | ❌         | 13         | A simple bruteforce approach to finding the best solution.                         |
| 2.0     | Bruteforce threaded   | ✔         | 14         | Using as many threads as the CPU has, we speed up the calculation.                 |
| 3.0     | Approximate threaded  | ❌         | ?          | Using the nearest fragment algorithm we can calculate a good solution much faster. |
| 4.0     | Distributed computing | ?         | ?          | Not implemented.                                                                   |

## Usage

1. Pick the method you want to use
2. Pick the branch which corresponds to the method you want to use:
3. ![image](https://user-images.githubusercontent.com/102226166/221526537-8fd78002-c4ff-47c3-b338-ca47010c5302.png)
4. Click the Code button and click Download ZIP:
5. ![image](https://user-images.githubusercontent.com/102226166/221527329-d9b1a9aa-1ede-412b-bef4-b31576df2d8a.png)
6. Unzip it and run the provided executable found in x64/Release/Beta4.exe
7. If the executable does not work, open the provided Visual Studio solution file (Beta4.sln) in Visual Studio (with MSVC++ installed) and compile it for your machine, then run it.

## Performance

| Version | 10 cities | 11 cities | 12 cities | 13 cities | 14 cities | 15 cities | 100 cities | 1 000 cities | 10 000 cities | 100 000 cities | 1 000 000 cities |
| ------- | --------- | --------- | --------- | --------- | --------- | --------- | ---------- | ------------ | ------------- | -------------- | ---------------- |
| 1.0     | 0.12 s    | 1.10 s    | 13.50 s   | 172.04 s  | ❌        | ❌         | ❌         | ❌           | ❌             | ❌             | ❌                |
| 2.0     | 0.11 s    | 0.45 s    | 4.45 s    | 56.32 s   | 455.17 s  | ❌         | ❌         | ❌           | ❌             | ❌             | ❌                |
| 3.0     | 0.6 ms    | 0.9 ms    | 0.001 s   | 0.0013 s  | 0.0035 s  | 0.0028 s  | 0.032 s    | 0.002 s      | 0.15 s        | 15.334 s       | ❌                |
