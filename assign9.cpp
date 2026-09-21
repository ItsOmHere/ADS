#include <iostream>
using namespace std;

bool canTransform(const char s1[], const char s2[], int i, int j) {
    if (s1[i] == '\0' && s2[j] == '\0')
        return true;

    if (s1[i] == '\0')
        return false;

    if (s1[i] >= 'a' && s1[i] <= 'z') {
        if (s2[j] != '\0' && (s1[i] - 'a' + 'A') == s2[j]) {
            if (canTransform(s1, s2, i + 1, j + 1))
                return true;
        }

        return canTransform(s1, s2, i + 1, j);
    }

    if (s2[j] != '\0' && s1[i] == s2[j])
        return canTransform(s1, s2, i + 1, j + 1);

    return false;
}

int main() {
    char s1[1000], s2[1000];

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