#include<bits/stdc++.h>

/**
#include<iostream>
#include<vector>
#include<algorithm>
**/

using namespace std;
int main()
{
    /// nameOfTheSTL < data type > variableName;
    vector < int > v;

    /// push back = insert Last
    v.push_back(12);
    v.push_back(13);
    v.push_back(11);
    v.push_back(9);
    v.push_back(3);

    /// pop back = delete Last
    v.pop_back();

    /// printing last element
    cout << "Last Element: " << v.back() << endl;

    v.push_back(17);
    v.push_back(15);
    v.push_back(22);
    v.push_back(3);
    v.push_back(2);

    /// printing the vector
    cout << "Printing the vector: ";
    for(int i=0; i<v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");


    /// sorting the elements of the vector
    /// sort(v.begin(), v.end()); /// ascending
    /// sort(v.begin(), v.end(), greater<int>()); /// descending order

    reverse(v.begin(), v.end()); /// reverse

    /// printing the vector
    cout << "Printing the vector after sorting: ";
    for(int i=0; i<v.size(); i++)
    {
        printf("%d ", v[i]);
    }
}