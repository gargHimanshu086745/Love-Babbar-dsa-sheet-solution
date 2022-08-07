string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set <int> s1;
    for(int i=0;i<n;i++)
    {
        s1.insert(a1[i]);
    }
    int count=0;
    for(int i=0;i<m;i++)
    {
        if(s1.find(a2[i])==s1.end())
        continue;
        else
        count++;
    }
    if(count==m)
    return "Yes";
    else
    return "No";
}
