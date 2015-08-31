/*
 * Stock span Problem
 *
 *   Given :   We have series of n daily price quotes for a stock. 
 *
 *   Required: We need to calculate **span** of stock's price for all n days.
 *             Span for ith day is defined as **maximum** number of consecutive days,
 *             for which the price of the stock was less than or equal to ith day.
 *
 *   Example:  For stock quotes {100, 60, 70, 65, 80, 85} span will be {1, 1, 2, 1, 4, 5}.
 *             Span for day 1 is always 1, now for day 2 stock is at 60, and there is no day befor it when stock was less than 60.
 *             So span remains 1. For day 3, the stock is priced at 70, so its span is 2, as previous day it was 60, and so on.
 *   Refer readme of for approaches.
 */  

#include <iostream>
#include <stack.h>

void stock_spans( int *prices, int *spans, int days )
{
    algo::Stack<int> st;

    //pushing day one to stack ( days are 0 indexed )
    st.push(0);

    //span for day 1
    spans[0] = 1;

    //span for rest of the days
    for ( int i = 1; i < days; ++i )
    {
        // Pop till the day stock price was greater than today and stack is not emptuy.
        while ( !st.empty() &&  prices[i] >= prices[st.top()] )
        {
            st.pop();
        }
        
        /*
         * If stack has emptied, then price[i] is the largest of price we have seen
         * so far, else price[i] is greater than price on the day which is on top
         * of stack.
         */
        spans[i] = (st.empty()) ? ( i + 1 ) : (i - st.top()) ;

        //push today on stack.
        st.push(i);
    }
}


void printPricesSpans( int *prices, int *spans, int days )
{
    for ( int i = 0; i < days; ++i )
    {
        std::cout << "Day: " << (i+1)
                  << " Price: " << prices[i]
                  << " Span: " << spans[i]
                  << std::endl;
    }
}


int main()
{
    int prices[]= { 100, 60, 70, 65, 80, 85 }; 
    int *spans = new int[6];
    stock_spans(prices, spans, 6);
    printPricesSpans( prices, spans, 6 );
    return 0;
}
