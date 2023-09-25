  // for (int i = 1; i <= n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     int l = 1, r = n, pos = n;
    //     while (l <= r)
    //     {
    //         int m = (l + r) >> 1;
    //         if (query(1, 1, n, 1, m) >= x)
    //         {
    //             pos = min(pos, m);
    //             r = m - 1;
    //         }
    //         else
    //         {
    //             l = m + 1;
    //         }
    //     }
    //     cout << a[pos] << " ";
    //     update(1, 1, n, pos, 0);
    // }
    // cout << endl;