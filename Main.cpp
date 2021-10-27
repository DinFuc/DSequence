long long min(long long a, long long b)
{
    return a < b ? a : b;
}
long long dSequence(int d, std::vector<int> a)
{
    long long pot = a[0] + d, k3 = 0, kq = 1e18;
    int n = a.size();
    vector<long long>k1{0}, k2, key; 
    for (int i = 1; i < n; i++){
        int p = pot - a[i];
        if (p < 0) k1.push_back(p);
        else if (p > 0) 
            k2.push_back(p);
        else 
            k3 += 1;
        pot += d;
    }
    int l1 = k1.size(), l2 = k2.size();
    sort(k1.begin(), k1.end());
    sort(k2.begin(), k2.end());
    int i = l2 - n / 2;
    if (i > 0)
        for (int j = max(0, i - 6); j < min(i + 6, l2); j++){
            key.push_back(k2[j] + 1); 
            key.push_back(k2[j]);
        }
    else if (i < 0){
        i = abs(i);
        for (int j = max(0, i - 6); j < min(i + 6, l1); j++){
            key.push_back(k1[j] + 1); 
            key.push_back(k1[j]);
        }
    }
    else
        return 0;
    for (long long x : key){
        x = a[0] - x;
        long long pile = 0;
        for (int j : a){
            pile += (abs(j - x));
            x += d;
        }
        kq = min(kq, pile);
    }
    return kq;
}
