#include <iostream>

int bestProfit(int stockPrices[], int size)
{
    if (size <= 1) {
        return 0;
    }
    
 	int lowestPriceSeenIndex = 0;
    int highestProfit = stockPrices[1] - stockPrices[0];
    
    for (int i = 2; i < size; i++) {
        if (stockPrices[i] - stockPrices[lowestPriceSeenIndex] > highestProfit) {
            highestProfit = stockPrices[i] - stockPrices[lowestPriceSeenIndex];
        }
        if (stockPrices[i] < stockPrices[lowestPriceSeenIndex]) {
         	lowestPriceSeenIndex = i;   
        }
    }
    
    return highestProfit;
}

// Test Driver program
int main()
{
    int stock_prices_yesterday[] = {4,3,2,6,7,8,1,10};
    int size = 8;

    int profit = bestProfit(stock_prices_yesterday, size);

    int actualMax = 9;

 	std::cout << "Max Profit should be " << actualMax << '\n';
    std::cout << "Calculated Max Profit is " << profit << '\n';
    return 0;
}

/* Problem description on Interview Cake */