#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
    string str1, str2;
    map<string, double> grade;
    double d;
    double sum = 0.0, forAvSum = 0, res;

    grade.insert({"A+", 4.5});
    grade.insert({"A0", 4.0});
    grade.insert({"B+", 3.5});
    grade.insert({"B0", 3.0});
    grade.insert({"C+", 2.5});
    grade.insert({"C0", 2.0});
    grade.insert({"D+", 1.5});
    grade.insert({"D0", 1.0});
    grade.insert({"F", 0.0});

    for (int i = 0; i < 20; i++) {
        cin >> str1 >> d >> str2;
    
        if (str2 == "P") {
            continue;
        }
        else {
            sum += d;
            forAvSum += (d * grade[str2]);
        }
    }
    
    res = forAvSum / sum;
    cout << res;

    return 0;
}