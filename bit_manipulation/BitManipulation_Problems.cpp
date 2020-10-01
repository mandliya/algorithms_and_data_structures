int off_To_On(int num, int k)
{
    int mask = (1 << k);
    return (num | mask);
}

int on_To_Off_01(int num, int k)
{
    int mask = (~(1 << k)); //1"s Compliment of mask
    return (num & mask); 
}

int on_To_Off_02(int num, int k)
{
    int mask = (1 << k); 
    
    if((num & mask) == 0)
    {
        return num;
    }
    else
    {
        return (num ^ mask);
    }
    
}

// insert from starting is zero => always append zero from left
int count_All_Set_Bits(unsigned num)
{
    int count = 0;
    while (num != 0)
    {
        if((num & 1) != 0)
        {
            count++;
        }
        num >>= 1;
    }
    
    return count;
}


//Leetcode :- 338 conting bits
vector<int> counting_bits(int num)
{
    vector<int> ans(num+1, 0);
    for (int i = 1; i <= num; i++)
    {
        ans[i] = ans[(i & (i-1))] + 1;
    }
    return ans;
    
}


void Bits_Questions_Set_02()
{
    int num = 123;
    int k = 3;

    cout << off_To_On(num, k) << endl;

    cout << (on_To_Off_01(num, k) == on_To_Off_02(num, k)) << endl;

    cout << count_All_Set_Bits(13) << endl;

    vector<int> res = counting_bits(10);
    for(int i=0; i<res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
