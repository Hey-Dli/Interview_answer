#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

int resolve(const char* input)
{
	size_t size = strlen(input);
	if(size == 0)
		return 0;
		
	int num = input[0] - '0';
	int a = 1;
	vector< vector<int> > number;
	for(int i = 1; i <= num; i++)
	{
		vector<int> tmp;
		for(int j = 0; j < 3; j++)
		{
			int n = 2 * (a++);
			tmp.push_back(input[n] - '0');
		}
		number.push_back(tmp);
	}
	
	int count = 0; 
	int length = number[num-1][1];
	int high = number[0][2];
	
	for(int i = 1; i < num; i++)
	{
		if(number[i][0] <= number[i-1][1])
			high += abs(number[i][2] - number[i-1][2]);
		else
			high += number[i][2] + number[i-1][2];
	}
	count = length + high +number[num-1][2];
    return count;
}

int main() 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
         "",
        "1\n0,2,1",
        "2\n0,2,1\n1,4,2",
        "3\n0,2,1\n1,4,2\n2,4,2",
        "4\n0,2,1\n1,4,2\n2,4,2\n5,7,2",
        "5\n0,2,1\n1,4,2\n2,4,2\n5,7,2\n6,7,1",
        "1\n0,2,2",
        "2\n0,2,2\n1,3,1\n",
        "3\n0,2,2\n1,3,1\n2,4,1",
        "4\n0,2,2\n1,3,1\n2,4,1\n5,6,1",
        "5\n0,2,2\n1,3,1\n2,4,1\n5,6,1\n5,7,1",
        "1\n0,1,1",
        "2\n0,1,1\n1,3,3",
		"3\n0,1,1\n1,3,2\n2,3,1",
    };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20, 0, 4, 8, 8, 15, 15, 6, 7, 8, 12, 13, 3, 9, 7};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}