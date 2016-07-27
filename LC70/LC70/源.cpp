#include<cmath>
#include<iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		const double sqfive = sqrt(5);
		const double phi = (1 + sqfive) / 2;
		const double psi = (1 - sqfive) / 2;
		return round((pow(phi, n + 1) + pow(psi, n + 1)) / sqfive);
	}
};