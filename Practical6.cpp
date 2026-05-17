/*
Practical 6:
Expert System for Hospitals and Medical Facilities
*/
/*
Sample Input:

Enter your symptom: fever

Sample Output:

========================================
 Hospital Expert System
========================================

Available symptoms:
- chest pain
- cough
- fever
- headache
- stomach pain

Enter your symptom: fever

Possible Disease: Flu
Medical Advice: Take rest and drink plenty of fluids.
*/
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert string to lowercase
string toLowerCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main()
{
    cout << "========================================" << endl;
    cout << " Hospital Expert System " << endl;
    cout << "========================================" << endl;

    // Knowledge base using map
    map<string, pair<string, string>> disease_data;

    disease_data["fever"] = {"Flu", "Take rest and drink plenty of fluids."};
    disease_data["cough"] = {"Cold", "Use cough syrup and stay hydrated."};
    disease_data["headache"] = {"Migraine", "Take proper sleep and avoid stress."};
    disease_data["stomach pain"] = {"Acidity", "Avoid oily food and drink more water."};
    disease_data["chest pain"] = {"Heart Problem", "Consult a doctor immediately."};

    cout << "\nAvailable symptoms:" << endl;

    for (auto item : disease_data)
    {
        cout << "- " << item.first << endl;
    }

    string user_symptom;

    cout << "\nEnter your symptom: ";
    getline(cin, user_symptom);

    user_symptom = toLowerCase(user_symptom);

    // Expert system logic
    if (disease_data.find(user_symptom) != disease_data.end())
    {
        cout << "\nPossible Disease: "
             << disease_data[user_symptom].first << endl;

        cout << "Medical Advice: "
             << disease_data[user_symptom].second << endl;
    }
    else
    {
        cout << "\nSorry! Symptom not found in database." << endl;
        cout << "Please consult a doctor." << endl;
    }

    return 0;
}