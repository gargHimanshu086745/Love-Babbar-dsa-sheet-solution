int PalinArray(int a[], int n)
{  //add code here.
    int num;
    for(int i=0;i<n;i++)
    {
        int temp=a[i];
        num=0;
        while(temp>0)
        {
            num=num*10 + (temp%10);
            temp=temp/10;
        }
        if(num!=a[i])
        return 0;
    }
    return 1;
}
