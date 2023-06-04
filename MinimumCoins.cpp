#include<bits/stdc++.h>
#include<iostream>

int count(int coins[], int n, int sum)
{
    int table[n][sum+1];

    int rows = 0, cols = 0; 
    for(rows = 0; rows < n; rows++){
        table[rows][0] = 0; 
    }

    for(cols = 1; cols <= sum; cols++)
    {
        if(cols % coins[0] == 0)
            table[0][cols] = cols / coins[0];
    }

    for(rows = 1; rows < n; rows++)
    {
        for(cols = 1; cols <= sum; cols++)
        {
            if(coins[rows] > cols)
                table[rows][cols] = table[rows -1][cols]; 
            else 
                table[rows][cols] = std::min(table[rows -1][cols], 1 + table[rows][cols - coins[rows]]);
        }
    }

    int k = sum; 
    int i = 0;
    std::vector<int> v;
    while(k > 0)
    {
        if(table[n-1][k] == table[n-2][k])
            n--;
        else
        {
            v.push_back(coins[n-1]);
            i++;
            k = k - coins[n-1]; 
        }
    }

    int size = (int) v.size();

    for( i = 0; i < size; i++)
    {
        std::cout << "denominations: " << v[i] << std::endl;  
    }

    std::cout << std::endl;

    return table[n-1][sum];
}

int main()
{
    int sum = 0, numCoins = 0, minNumCoins = 0;
    
    std:: cout << "Enter the sum: ";
    std::cin >> sum;
    std::cout << std::endl << "Enter the mumber of denominations: ";
    std::cin>> numCoins;
    std::cout<< std::endl;
    int coins[numCoins];

    for(int i = 0; i < numCoins; i++)
    {
        int coin = 0;
        std::cout << "Enter the denomination: ";
        std::cin>>coin;
        std::cout << std::endl;
        coins[i] = coin;
    }

    minNumCoins = count(coins, numCoins, sum );
    std::cout << "Minimum number of coins: " << minNumCoins << std:: endl;
    
    std::cin.get();
    return minNumCoins;
   
}