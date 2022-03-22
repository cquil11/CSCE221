// #include <iostream>
// #include <string>
// #include "DecisionLogic.h"
// #include "DecisionLogic.cpp"
// #include "DTree.h"

// using namespace std;

// int main()
// {

//     string trainfile = "train_cancer.csv";
//     vector<string> attributes;
//     vector<vector<double>> data;
//     vector<int> outcomes;
//     vector<int> instances;
//     readData(trainfile, attributes, data, outcomes, instances);
//     DTree dt;
//     Decision top = dt.getMaxInformationGain(attributes, data, outcomes, instances);

//     return 0;
// }