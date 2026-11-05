class Solution {
public:
    vector<double> Temperature(double celsius){
    vector<double> ans;
    double kelvin = celsius + 237.15;
    ans.push_back(kelvin);

    double farenheit = celsius*1.80 + 32;
    ans.push_back(farenheit);

    return ans;
    }
};