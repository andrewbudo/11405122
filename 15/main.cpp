#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Если строки разной длины, они не могут быть анаграммами
        if (s.length() != t.length()) {
            return false;
        }

        // Массив для подсчета количества вхождений символов
        vector<int> count(26, 0);

        // Подсчитываем частоту символов в первой строке и вычитаем для второй
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // Увеличиваем счётчик для символа в строке s
            count[t[i] - 'a']--; // Уменьшаем счётчик для символа в строке t
        }

        // Если все элементы массива равны нулю, значит строки являются анаграммами
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s, t;
    
    // Ввод строк
    cin >> s >> t;
    
    // Вывод результата
    cout << (solution.isAnagram(s, t) ? "true" : "false") << endl;
    
    return 0;
}
