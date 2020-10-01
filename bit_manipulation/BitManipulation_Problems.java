//optimized
    public static int count_All_sets_bits_02(int num)
    {
        int count=0;
        
        // infinte loop i.e for case -1 or -value
        while(num != 0)
        {
            if( (num & 1) != 0)
            {
                count++;
            }

            num >>= 1;
        }

        return count;
    }

    //optimized
    public static int count_All_sets_bits_03(int num)
    {
        int count=0;
        
        // infinte loop i.e for case -1 or -value
        while(num != 0)
        {
            if( (num & 1) != 0)
            {
                count++;
            }

            num >>>= 1;
        }

        return count;
    }

    // leetcode :- 191 Number of 1 bits
    //more optimized
    public static int count_All_sets_bits_04(int num)
    {
        int count=0;
        
        while(num != 0)
        {
            count++;
            num &= (num-1);
        }

        return count;
    }

    public static int Unique_Number_in_Array(int[] arr)
    {
        int res=0;
        for(int ele : arr)
        {
            res ^= ele;
        }
        return res;
    }

    //Leetcode :- 231 Power of two
    public static boolean isPowerOfTwo(int n) 
    {
        return n>0 && (n & (n-1)) == 0;
    }

    //Leetcode :- 338 counting bits
    public static int[] counting_bits(int num)
    {
        int[] ans = new int[num+1];
        for(int i=1; i<=num; i++)
        {
            ans[i] = ans[(i & (i-1))] + 1;
        }

        return ans;
    }



    public static void Bits_Questions_Set_02()
    {
        //System.out.println(count_All_sets_bits_01(13));
        //System.out.println(count_All_sets_bits_02(15));
        //System.out.println(count_All_sets_bits_03(-1));
        //System.out.println(count_All_sets_bits_04(15));
        //System.out.println(count_All_sets_bits_04(00000000000000000000000000001011));

        //int[] arr = {2, 2, 4, 3, 4, 5, 7, 5, 3};
        //System.out.println(Unique_Number_in_Array(arr));

        //System.out.println(isPowerOfTwo(15));

        /*

        int[] res = counting_bits(10);
        for(int i=0; i<res.length; i++)
        {
            System.out.print(res[i] + " ");
        }

        */
    }
