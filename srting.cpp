#include <iostream>
#include <string>
using namespace std;

bool canTransform(string s1, string s2, int i, int j) {
    if (i == s1.length() && j == s2.length())
        return true;

    if (i == s1.length())
        return false;

    if (s1[i] >= 'a' && s1[i] <= 'z') {

        if (j < s2.length() && 
            (s1[i] - 'a' + 'A') == s2[j]) {
            if (canTransform(s1, s2, i + 1, j + 1))
                return true;
        }

        return canTransform(s1, s2, i + 1, j);
    }

    if (j < s2.length() && s1[i] == s2[j])
        return canTransform(s1, s2, i + 1, j + 1);

    return false;
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    if (canTransform(s1, s2, 0, 0))
        cout << "YES, transformation is possible.";
    else
        cout << "NO, transformation is not possible.";

    return 0;
}