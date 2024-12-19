#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        while (nums.size() != 0) {
            if (nums.back() != target) 
                nums.pop_back(); // Убираем последний элемент
            else 
                return (nums.size() - 1); // Возвращаем индекс найденного элемента
        }
        return -1; // Если элемент не найден
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int n, target;

    // Ввод данных
    cin >> n; // Количество элементов в массиве
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x; // Элемент массива
        nums.push_back(x);
    }

    cin >> target; // Целевое значение

    // Вывод результата
    cout << solution.search(nums, target) << endl;

    return 0;
}
