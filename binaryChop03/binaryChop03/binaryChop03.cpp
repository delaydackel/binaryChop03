// binaryChop03.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// Implementierung via Interpolation

#include "stdafx.h"
#include <iostream>
using namespace std;

int chop(int target, int volume[], int left, int right) {
	
	int dividingElement;
	int numberOfElements;
	int totalElements;
	totalElements = (volume[right] - volume[left]);
	numberOfElements = (target - volume[left]);
	dividingElement = left + (numberOfElements/totalElements) * (right - left);

	if (volume[dividingElement]==target)
	{
		return dividingElement;
	}
	else if(left>right)
	{
		return -1;
	}
	else if (volume[dividingElement]>target)
	{
		return chop(target, volume, left, (dividingElement - 1));
	}
	else
	{
		return chop(target, volume, (dividingElement + 1), right);
	}

	

	
}

int main()
{
	int target = 8;
	int volume[10] = { 1,2,3, 4,5, 6, 7, 13, 22 ,125 };
	int left = 0;
	int right;
	right = (sizeof(volume) / sizeof(*volume));
	cout << target << " was found at position " << chop(target, volume, left, right);
	cin >> target;
    return 0;
}

