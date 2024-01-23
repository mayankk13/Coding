/*

Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] 
is a subset of a1[] or not. Both the arrays can be sorted or unsorted. There can be duplicate elements.

a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output : Yes

a1[] = {1, 2, 3, 4, 5, 6, 7, 8}
a2[] = {1, 2, 3, 1, }
Output : No
*/

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        mp[a1[i]]++;
    }
    
    for (int i = 0; i < m; i++) {
        if (mp.find(a2[i]) != mp.end()){
            mp[a2[i]]--;
            if (mp[a2[i]] == 0) {
                mp.erase(a2[i]);
            }
        }
        else {
            return "No";
        }
    }
    
    return "Yes";
}