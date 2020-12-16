void quick_sort1(int *num,int l,int r) {
    while( l < r ) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do 
        {
            while(x <= y && num[x] < z) x++;
            while(x <= y && num[y] > z) y--;
            if(x <= y) {
                swap(num[x],num[y]);
                x++,y--;
          
            }
        } while( x <= y );
        quick_sort1(num,x,r);
        r = y;
    }
    return ;
}
