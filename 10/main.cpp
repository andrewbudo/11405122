#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Если нашли целевое значение
            if (nums[mid] == target) return true;

            // Если левая, правая или средняя граница совпадают
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            } 
            // Левая половина отсортирована
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Ищем в левой части
                } else {
                    left = mid + 1; // Ищем в правой части
                }
            } 
            // Правая половина отсортирована
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Ищем в правой части
                } else {
                    right = mid - 1; // Ищем в левой части
                }
            }
        }
        return false; // Цель не найдена
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
    cout << (solution.search(nums, target) ? "true" : "false") << endl;

    return 0;
}
