//归并排序
void merge(int *nums,int l,int mid,int r){
    int *temp = (int *)malloc((r - l + 1)*sizeof(int));
    int x = l, y = mid + 1, z = 0;
    while( x <= mid && y <= r ){
        temp[z++] = nums[y] < nums[x] ? nums[y++] : nums[x++];
    }
    while(x <= mid) temp[z++] = nums[x++];
    for(int i = 0; i < z; ++i){
        nums[l + i] = temp[i];
    }
    free(temp);
}

void merge_sort(int *nums,int l,int r){
    if( l >= r ) return;
    int mid = l + r >> 1;
    merge_sort(nums,l,mid);
    merge_sort(nums,mid+1,r);
    merge(nums,l,mid,r);
}