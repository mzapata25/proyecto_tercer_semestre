class Solution {
public:
    int partition(std::vector<int>& vec, int bajo, int alto) {
        int pivote = vec[alto];
        int i = bajo - 1;

        for (int j = bajo; j < alto; j++) {
            if (vec[j] <= pivote) {
                i++;
                std::swap(vec[i], vec[j]);
            }
        }
        std::swap(vec[i + 1], vec[alto]);
        return i + 1;
    }
    void quicksort(std::vector<int>& vec, int bajo, int alto) {
        if (bajo < alto) {
            int pi = partition(vec, bajo, alto);

            quicksort(vec, bajo, pi - 1);
            quicksort(vec, pi + 1, alto);
        }
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
    quicksort(nums, 0, nums.size() - 1);

    int suma = nums[0] + nums[1] + nums[2];

    for (size_t i = 0; i < nums.size() - 2; ++i) {
        size_t left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int sumaActual = nums[i] + nums[left] + nums[right];

            if (std::abs(target - sumaActual) < std::abs(target - suma)) {
                suma = sumaActual;
            }

            if (sumaActual < target) {
                ++left;
            } else if (sumaActual > target) {
                --right;
            } else {
                return sumaActual;
            }
        }
    }

    return suma;
    }
};
