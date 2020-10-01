    static int rows=0;
    static int cols=0;
    static int diag=0;
    static int adiag=0;
    public static int N_Queen_Problem_combination_07(int n, int m, int idx, int tnq, String ans)
    {
        if (tnq==0)
        {
            System.out.println(ans);
            return 1;
        }
        
        int count = 0;
        for(int r=idx; r<n*m; r++)
        {
            int x = r / m;
            int y = r % m;
            if((rows & (1<<x))==0 && (cols & (1<<y))==0 && (diag & (1<<(x+y)))==0 && (adiag & (1<<(x-y+(m-1))))==0)
            {
                rows ^= (1<<x);
                cols ^= (1<<y);
                diag ^= (1<<(x+y));
                adiag ^= (1<<(x-y + (m-1)));

                count+=N_Queen_Problem_combination_07(n, m, r+1, tnq-1, ans+"("+x+","+y+") ");
                
                rows ^= (1<<x);
                cols ^= (1<<y);
                diag ^= (1<<(x+y));
                adiag ^= (1<<(x-y + (m-1)));
            }
        }
        return count;
    }
