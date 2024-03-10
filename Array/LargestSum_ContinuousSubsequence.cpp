// from given array of integers return continuous subsequence having largest sum

#include <iostream>
#include <vector>

std::vector<int> largestSumSubsequence(const std::vector<int>& array) {
    int n = array.size();
    int currentSum = array[0];
    int maxSum = array[0];
    int start = 0;
    int tempStart = 0;
    int end = 0;

    for (int i = 1; i < n; ++i) {
        if((currentSum < 0) && (array[i] > currentSum)){ 
        // if (array[i] > (currentSum + array[i])) {
            currentSum = array[i];
            tempStart = i;
        } else {
            currentSum += array[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    std::vector<int> result;
    for (int i = start; i <= end; ++i) {
        result.push_back(array[i]);
    }

    return result;
}

int main() {
    // Example usage
    std::vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::vector<int> result = largestSumSubsequence(array);

    std::cout << "Largest Sum Subsequence: ";
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
